#ifndef TeslaMateCompanion_h
# define TeslaMateCompanion_h

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32Time.h>
#include <NTPClient.h>
#include <TFT_eSPI.h>
#include <WiFiUdp.h>
#include <lvgl.h>
#include <ui.h>
#include "WiFi.h"
#include "RTClib.h"
#include "RemoteDebug.h"

#define WIFI_SSID        "REPLACE_ME"
#define WIFI_PASS        "REPLACE_ME"
#define WIFI_TIMEOUT     5
#define API_URL          "REPLACE_ME"
#define API_TIMEOUT      2
#define API_AUTH         true
#define API_USER         "REPLACE_ME"
#define API_PASS         "REPLACE_ME"
#define TZ_OFFSET        1
#define POLLING_INTERVAL 30
#define HOSTNAME         "TeslaMateCompanion"
#define BRIGHTNESS       120

#define GREEN            0x00B200
#define RED              0xFF0000
#define GREY             0x303030
#define ORANGE           0xE08700
#define PIN_LCD_BL       38
#define PIN_BTN_TOP      14
#define PIN_BTN_BOTTOM   0

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 170;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

extern WiFiUDP ntpUDP;
extern HTTPClient http;
extern TFT_eSPI tft;
extern NTPClient timeClient;
extern RemoteDebug Debug;
extern ESP32Time rtc;

struct TeslaMateStruct {
    int wifi_elapsed_time = 0;
    String carname = "";
    String state = "";
    String since = "";
    String elapsed = "";
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
    String unit_temp = "";
    bool lastAttemptSucceeded = false;
    bool waitingConnection = false;
};

extern TeslaMateStruct data;

void wifi_connection();
void updateRTC();
void initOTA();
String retrieveData();

void displayFlush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void toggleUpdateSpinner(bool enabled);
void setMainScreen();

void updateValues(String response);

void logger(String msg);

#endif