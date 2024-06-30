#include "TeslaMateCompanion.h"

String millisToTime() {
    unsigned long seconds = millis() / 1000;
    unsigned long minutes = seconds / 60;
    unsigned long hours = minutes / 60;

    return (hours / 60 < 10 ? "0" : "") + String(hours % 24, DEC) + ":" +
           (minutes % 60 < 10 ? "0" : "") + String(minutes % 60, DEC) + ":" +
           (seconds % 60 < 10 ? "0" : "") + String(seconds % 60, DEC);
}

void logger(String msg) {
    String payload = "T " + rtc.getTime("%F %T") + " | U " + millisToTime() + " | C" + String(xPortGetCoreID()) + " | " + msg;
    Serial.println(payload);
    Debug.println(payload);
}
