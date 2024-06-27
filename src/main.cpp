#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

#define WIFI_SSID        "REPLACE_ME"
#define WIFI_PASS        "REPLACE_ME"
#define WIFI_TIMEOUT     5

#define API_URL          "REPLACE_ME"
#define API_TIMEOUT      2
#define API_AUTH         true
#define API_USER         "REPLACE_ME"
#define API_PASS         "REPLACE_ME"
#define POLLING_INTERVAL 30

#define GREEN            0x00B200
#define RED              0xFF0000
#define GREY             0x303030
#define ORANGE           0xE08700

HTTPClient http;
TFT_eSPI tft = TFT_eSPI();

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 170;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

int wifi_elapsed_time = 0;
String state = "";
String since = "";
int odometer = 0;
int battery_level = 0;
int battery_range = 0;
int temp_inside = 0;
int temp_outside = 0;
bool status_healthy = false;
bool status_locked = false;
bool status_sentry = false;
bool status_windows = false;
bool status_doors = false;
bool status_trunk = false;
bool status_frunk = false;
bool status_present = false;
String unit_length = "";

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
    lv_label_set_text(ui_ssidtext, WIFI_SSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    for (int i = 0; i < WIFI_TIMEOUT * 100 ; i++) {
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
    Serial.println("> Querying data");
    http.begin(API_URL);
    http.setTimeout(API_TIMEOUT * 1000);
    if (API_AUTH)
        http.setAuthorization(API_USER, API_PASS);
    int httpCode = http.GET();
    String payload = http.getString();
    http.end();
    Serial.println("> Response code: " + String(httpCode) + ", size: " + payload.length() + "\n> Received: " + payload);
    if (httpCode == 200) {
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, payload);
        if (error) {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
            return;
        }
        state =              (const char *)doc["data"]["status"]["state"];
        since =              (const char *)doc["data"]["status"]["state_since"];
        odometer =                    (int)doc["data"]["status"]["odometer"];
        battery_level =               (int)doc["data"]["status"]["battery_details"]["battery_level"];
        battery_range =               (int)doc["data"]["status"]["battery_details"]["est_battery_range"];
        temp_inside =                 (int)doc["data"]["status"]["climate_details"]["inside_temp"];
        temp_outside =                (int)doc["data"]["status"]["climate_details"]["outside_temp"];
        status_healthy =             (bool)doc["data"]["status"]["car_status"]["healthy"];
        status_locked =              (bool)doc["data"]["status"]["car_status"]["locked"];
        status_sentry =              (bool)doc["data"]["status"]["car_status"]["sentry_mode"];
        status_windows =             (bool)doc["data"]["status"]["car_status"]["windows_open"];
        status_doors =               (bool)doc["data"]["status"]["car_status"]["doors_open"];
        status_trunk =               (bool)doc["data"]["status"]["car_status"]["trunk_open"];
        status_frunk =               (bool)doc["data"]["status"]["car_status"]["frunk_open"];
        status_present =             (bool)doc["data"]["status"]["car_status"]["is_user_present"];
        unit_length = String((const char *)doc["data"]["units"]["unit_of_length"]) == "km" ? " Kms" : " Mi";

        String logline = "State:           " + state
                     + "\nSince:           " + since
                     + "\nOdometer:        " + odometer
                     + "\nBattery level:   " + battery_level
                     + "\nBattery range:   " + battery_range
                     + "\nTemp inside:     " + temp_inside
                     + "\nTemp outside:    " + temp_outside
                     + "\nStatus healthy:  " + status_healthy
                     + "\nStatus locked:   " + status_locked
                     + "\nStatus sentry:   " + status_sentry
                     + "\nStatus windows:  " + status_windows
                     + "\nStatus doors:    " + status_doors
                     + "\nStatus trunk:    " + status_trunk
                     + "\nStatus frunk:    " + status_frunk
                     + "\nStatus presence: " + status_present;
        Serial.println(logline);
    }
}

void set_display() {
    lv_label_set_text(ui_status, state.c_str());
    lv_label_set_text(ui_kmstotal, (String(odometer) + unit_length).c_str());

    lv_label_set_text(ui_tempinsidenumber, String(temp_inside).c_str());
    lv_arc_set_value(ui_tempinsidearc, temp_inside);
    lv_label_set_text(ui_tempoutsidenumber, String(temp_outside).c_str());
    lv_arc_set_value(ui_tempoutsidearc, temp_outside);

    lv_obj_set_style_bg_color(ui_healthpanel, lv_color_hex(status_healthy ? GREEN : RED), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lockedpanel, lv_color_hex(status_locked ? GREEN : RED), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sentrypanel, lv_color_hex(status_sentry ? GREEN : GREY), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_userpanel, lv_color_hex(status_present ? GREEN : GREY), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_windowspanel, lv_color_hex(status_windows ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_doorspanel, lv_color_hex(status_doors ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_frunkpanel, lv_color_hex(status_frunk ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_trunkpanel, lv_color_hex(status_trunk ? RED : GREEN), LV_STATE_DEFAULT);

    lv_color_t battery_color = lv_color_hex(GREEN);
    if (battery_level <= 10)
        battery_color = lv_color_hex(RED);
    else if (battery_level <= 20)
        battery_color = lv_color_hex(ORANGE);
    lv_obj_set_style_bg_color(ui_Panel3, battery_color, LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_label_set_text(ui_pctnumber, String(battery_level).c_str());
    lv_obj_set_style_bg_color(ui_pctbar, battery_color, LV_PART_INDICATOR | LV_STATE_DEFAULT );
    lv_bar_set_value(ui_pctbar, battery_level, LV_ANIM_OFF);

    lv_label_set_text(ui_kmsestimated, (String(battery_range) + unit_length).c_str());

}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
        wifi_connection();
    update();
    set_display();
    lv_timer_handler();
    delay(POLLING_INTERVAL * 1000);
}
