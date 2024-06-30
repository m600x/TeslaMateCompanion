#include "TeslaMateCompanion.h"

void updateSingleValue(String name, String &var, const char *value) {
    if (value == NULL) {
        logger("UP1V | Update of [" + name + "] has failed, null pointer found");
        var = "_";
    }
    else {
        logger("UP1V | Update of [" + name + "] to: " + value);
        var = value;
    }
}

void updateSingleValue(String name, int &var, int value) {
    if (value == NULL) {
        logger("UP1V | Update of [" + name + "] has failed, null pointer found");
        var = -1;
    }
    else {
        logger("UP1V | Update of [" + name + "] to: " + value);
        var = value;
    }
}

void updateSingleValue(String name, bool &var, bool value) {
    logger("UP1V | Update of [" + name + "] to: " + value);
    var = value;
}

void updateValues(String response) {
    logger("UPDT | Querying data");
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, response);
    if (error) {
        logger("UPDT | deserializeJson() failed: " + String(error.c_str()));
        data.elapsed = "JSON error";
    }
    else {
        updateSingleValue("state",          data.state,  (const char *)doc["data"]["status"]["state"]);
        updateSingleValue("since",          data.since,  (const char *)doc["data"]["status"]["state_since"]);
        updateSingleValue("odometer",       data.odometer,        (int)doc["data"]["status"]["odometer"]);
        updateSingleValue("battery_level",  data.battery_level,   (int)doc["data"]["status"]["battery_details"]["battery_level"]);
        updateSingleValue("battery_range",  data.battery_range,   (int)doc["data"]["status"]["battery_details"]["est_battery_range"]);
        updateSingleValue("temp_inside",    data.temp_inside,     (int)doc["data"]["status"]["climate_details"]["inside_temp"]);
        updateSingleValue("temp_outside",   data.temp_outside,    (int)doc["data"]["status"]["climate_details"]["outside_temp"]);

        if (!doc["data"]["status"]["car_status"]["healthy"].isNull())
            updateSingleValue("status_healthy", data.status_healthy, (bool)doc["data"]["status"]["car_status"]["healthy"]);
        if (!doc["data"]["status"]["car_status"]["locked"].isNull())
            updateSingleValue("status_locked",  data.status_locked,  (bool)doc["data"]["status"]["car_status"]["locked"]);
        if (!doc["data"]["status"]["car_status"]["sentry_mode"].isNull())
            updateSingleValue("status_sentry",  data.status_sentry,  (bool)doc["data"]["status"]["car_status"]["sentry_mode"]);
        if (!doc["data"]["status"]["car_status"]["windows_open"].isNull())
            updateSingleValue("status_windows", data.status_windows, (bool)doc["data"]["status"]["car_status"]["windows_open"]);
        if (!doc["data"]["status"]["car_status"]["doors_open"].isNull())
            updateSingleValue("status_doors",   data.status_doors,   (bool)doc["data"]["status"]["car_status"]["doors_open"]);
        if (!doc["data"]["status"]["car_status"]["trunk_open"].isNull())
            updateSingleValue("status_trunk",   data.status_trunk,   (bool)doc["data"]["status"]["car_status"]["trunk_open"]);
        if (!doc["data"]["status"]["car_status"]["frunk_open"].isNull())
            updateSingleValue("status_frunk",   data.status_frunk,   (bool)doc["data"]["status"]["car_status"]["frunk_open"]);
        if (!doc["data"]["status"]["car_status"]["is_user_present"].isNull())
            updateSingleValue("status_present", data.status_present, (bool)doc["data"]["status"]["car_status"]["is_user_present"]);

        if (data.carname == "" && doc["data"]["car"]["car_name"] != NULL)
            data.carname = (const char *)doc["data"]["car"]["car_name"];
        if (data.unit_length == "" && doc["data"]["units"]["unit_of_length"] != NULL)
            data.unit_length = String((const char *)doc["data"]["units"]["unit_of_length"]) == "km" ? " Kms" : " Mi";
        if (data.unit_temp == "" && doc["data"]["units"]["unit_of_temperature"] != NULL)
            data.unit_temp =   String((const char *)doc["data"]["units"]["unit_of_temperature"]) == "C" ? " C" : " F";

        if (data.since != "" && data.since != "_") {
            DateTime pastTime = DateTime((data.since).substring(0, 19).c_str());
            DateTime now = DateTime(rtc.getTime("%FT%T").c_str());
            TimeSpan diff = now - pastTime;
            data.elapsed = (diff.days() > 0 ? (String(diff.days()) + "d ") : "")
                    + (diff.hours() > 0 ? (String(diff.hours()) + "h ") : "" )
                    + (diff.minutes() > 0 ? (String(diff.minutes()) + "m ") : "" )
                    + (diff.seconds() > 0 ? (String(diff.seconds()) + "s ") : "" ) + "ago";
        }
    }
    logger("UPDT | End");
}