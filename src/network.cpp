#include "TeslaMateCompanion.h"

void initOTA() {
    ArduinoOTA.setHostname(HOSTNAME);
    ArduinoOTA
        .onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
            else
                type = "filesystem";
            logger("Start updating " + type);
        })
        .onEnd([]() {
            logger("\nEnd");
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            Debug.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error) {
            Debug.printf("Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) logger("Auth Failed");
            else if (error == OTA_BEGIN_ERROR) logger("Begin Failed");
            else if (error == OTA_CONNECT_ERROR) logger("Connect Failed");
            else if (error == OTA_RECEIVE_ERROR) logger("Receive Failed");
            else if (error == OTA_END_ERROR) logger("End Failed");
        });
    ArduinoOTA.begin();
}

void wifi_connection() {
    logger("WIFI | Start wifi connection");
    lv_disp_load_scr(ui_wifi);
    lv_label_set_text(ui_wifi_ssid_text, WIFI_SSID);
    WiFi.mode(WIFI_STA);
    WiFi.setHostname(HOSTNAME);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    for (int i = 0; i < WIFI_TIMEOUT * 100 ; i++) {
        if (WiFi.status() == WL_CONNECTED)
            break ;
        if (i % 100 == 0) {
            data.wifi_elapsed_time += 1;
            lv_label_set_text(ui_wifi_elapsed_time, (String(data.wifi_elapsed_time) + "s").c_str());
            logger("WIFI | Waiting wifi connection for " + String(data.wifi_elapsed_time) + "s");
        }
        lv_timer_handler();
        delay(10);
    }
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.disconnect();
        wifi_connection();
    }
    logger("WIFI | Attributed IP: " + WiFi.localIP().toString());
    data.wifi_elapsed_time = 0;
    updateRTC();
    lv_disp_load_scr(ui_main);
    lv_timer_handler();
}

void updateRTC() {
    logger("RTC  | Start update");
    timeClient.update();
    time_t rawtime = timeClient.getEpochTime();
    logger("RTC  | Received: " + timeClient.getFormattedTime() + " " + timeClient.getDay());
    rtc.setTime(timeClient.getEpochTime());
    rtc.getTime("%F %T");
    logger("RTC  | End update");
}

String retrieveData() {
    logger("HTTP | Querying data");
    http.begin(API_URL);
    http.setTimeout(API_TIMEOUT * 1000);
    if (API_AUTH)
        http.setAuthorization(API_USER, API_PASS);
    int httpCode = http.GET();
    String payload = http.getString();
    http.end();
    logger("HTTP | Response code: " + String(httpCode) + ", size: " + payload.length() + ", received:\n" + payload);
    if (httpCode != 200) {
        logger("HTTP | Request did not succeded, bailing out");
        data.elapsed = "Update error";
        return "";
    }
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
        logger("HTTP | deserializeJson() failed: " + String(error.c_str()));
        data.elapsed = "JSON error";
        return "";
    }
    logger("HTTP | End");
    return payload;
}
