#include "TeslaMateCompanion.h"

WiFiUDP ntpUDP;
HTTPClient http;
RemoteDebug Debug;
TFT_eSPI tft = TFT_eSPI();
ESP32Time rtc(TZ_OFFSET * 3600);
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);
TeslaMateStruct data;

void loop_display(void *pvParameters) {
    while(true) {
        setMainScreen();
        lv_timer_handler();
        delay(50);
    }
}

void loop_data(void *pvParameters) {
    wifi_connection();
    initOTA();
    Debug.begin(HOSTNAME);
    Debug.setResetCmdEnabled(true);
    Debug.showProfiler(true);
    Debug.showColors(true);
    Debug.showTime(true);
    while(true) {
        toggleUpdateSpinner(true);
        if (WiFi.status() != WL_CONNECTED)
            wifi_connection();
        String response = retrieveData();
        if (response != "") {
            updateValues(response);
        }
        toggleUpdateSpinner(false);
        delay(POLLING_INTERVAL * 1000);
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(PIN_BTN_TOP, INPUT);
    pinMode(PIN_BTN_BOTTOM, INPUT);
    lv_init();
    tft.begin();
    tft.setRotation(1);
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = displayFlush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
    ui_init();
    xTaskCreatePinnedToCore(loop_display, "loop_display", 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(loop_data, "loop_data", 8096, NULL, 1, NULL, 1);
}

void loop()
{
    ArduinoOTA.handle();
    Debug.handle();
    delay(50);
}
