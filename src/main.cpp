#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

#define SSID                             "REPLACE_ME"
#define PASS                             "REPLACE_ME"
#define WIFI_RECONNECT_TIMEOUT_IN_SEC    10
#define API_URL                          "REPLACE_ME"
#define API_HEADER                       "REPLACE_ME"
#define API_SECRET                       "REPLACE_ME"
#define API_TIMEOUT_IN_SEC               2
#define POLLING_INTERVAL_IN_SEC          1

#define GREEN                           0x00B200
#define RED                             0xFF0000
#define GREY                            0x303030
#define ORANGE                          0xE08700

HTTPClient http;
TFT_eSPI tft = TFT_eSPI();

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 170;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

int wifi_elapsed_time = 0;
String state = "";
String since = "";
String odometer = "";
String battery_level = "";
String battery_range = "";
String temp_inside = "";
String temp_outside = "";
bool status_healthy = false;
bool status_locked = false;
bool status_sentry = false;
bool status_windows = false;
bool status_doors = false;
bool status_trunk = false;
bool status_frunk = false;
bool status_present = false;

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();
    lv_disp_flush_ready( disp );
}

void wifi_connection() {
    Serial.println("Start wifi connection");
    lv_disp_load_scr(ui_wifi);
    lv_label_set_text(ui_ssidtext, SSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASS);
    for (int i = 0; i < WIFI_RECONNECT_TIMEOUT_IN_SEC * 100 ; i++) {
        if (WiFi.status() == WL_CONNECTED)
            break ;
        Serial.print('.');
        if (i % 100 == 0) {
            wifi_elapsed_time += 1;
            lv_label_set_text(ui_elapsedtime, (String(wifi_elapsed_time) + "s").c_str());
        }
        lv_timer_handler();
        delay(10);
    }
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.disconnect();
        wifi_connection();
    }
    wifi_elapsed_time = 0;
    lv_disp_load_scr(ui_main);
    lv_timer_handler();
}

void setup()
{
    Serial.begin( 115200 );
    lv_init();
    tft.begin();
    tft.setRotation( 1 );
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
    ui_init();
    wifi_connection();
}

void update() {
    Serial.println("Query data");
    http.begin(API_URL);
    http.setTimeout(API_TIMEOUT_IN_SEC * 1000);
    http.addHeader(API_HEADER, API_SECRET);
    int httpCode = http.GET();
    String payload = http.getString();
    http.end();
    Serial.println("Response code: " + String(httpCode));
    if (httpCode == 200) {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, payload);
        state = String((const char *)doc["state"]);
        since = String((const char *)doc["since"]);
        odometer = String((const char *)doc["odometer"]);
        battery_level = String((const char *)doc["battery"]["level"]);
        battery_range = String((const char *)doc["battery"]["range"]);
        temp_inside = String((const char *)doc["temp"]["inside"]);
        temp_outside = String((const char *)doc["temp"]["outside"]);
        status_healthy = (bool)doc["status"]["healthy"];
        status_locked = (bool)doc["status"]["locked"];
        status_sentry = (bool)doc["status"]["sentry"];
        status_windows = (bool)doc["status"]["windows"];
        status_doors = (bool)doc["status"]["doors"];
        status_trunk = (bool)doc["status"]["trunk"];
        status_frunk = (bool)doc["status"]["frunk"];
        status_present = (bool)doc["status"]["present"];
    }
}

void set_display() {
    lv_label_set_text(ui_status, state.c_str());
    lv_label_set_text(ui_kmstotal, (odometer + " Kms").c_str());

    lv_label_set_text(ui_tempinsidenumber, (temp_inside).c_str());
    lv_arc_set_value(ui_tempinsidearc, temp_inside.toInt());
    lv_label_set_text(ui_tempoutsidenumber, (temp_outside).c_str());
    lv_arc_set_value(ui_tempoutsidearc, temp_outside.toInt());

    lv_obj_set_style_bg_color(ui_healthpanel, lv_color_hex(status_healthy ? GREEN : RED), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_lockedpanel, lv_color_hex(status_locked ? GREEN : RED), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_sentrypanel, lv_color_hex(status_sentry ? GREEN : GREY), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_userpanel, lv_color_hex(status_present ? GREEN : GREY), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_windowspanel, lv_color_hex(status_windows ? RED : GREEN), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_doorspanel, lv_color_hex(status_doors ? RED : GREEN), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_frunkpanel, lv_color_hex(status_frunk ? RED : GREEN), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(ui_trunkpanel, lv_color_hex(status_trunk ? RED : GREEN), LV_PART_MAIN | LV_STATE_DEFAULT );

    lv_color_t battery_color = lv_color_hex(GREEN);
    if (battery_level.toInt() <= 10) {
        battery_color = lv_color_hex(RED);
    }
    else if (battery_level.toInt() <= 20) {
        battery_color = lv_color_hex(ORANGE);
    }
    lv_obj_set_style_bg_color(ui_Panel3, battery_color, LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_label_set_text(ui_pctnumber, battery_level.c_str());

    lv_obj_set_style_bg_color(ui_pctbar, battery_color, LV_PART_INDICATOR | LV_STATE_DEFAULT );
    lv_bar_set_value(ui_pctbar, battery_level.toInt() ,LV_ANIM_OFF);
    lv_label_set_text(ui_kmsestimated, (battery_range + " Kms").c_str());

}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
        wifi_connection();
    update();
    set_display();
    lv_timer_handler();
    delay(POLLING_INTERVAL_IN_SEC * 1000);
}
