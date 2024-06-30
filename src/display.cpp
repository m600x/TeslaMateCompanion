#include "TeslaMateCompanion.h"

void displayFlush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();
    lv_disp_flush_ready( disp );
}

void toggleUpdateSpinner(bool enabled) {
    if (enabled) {
        lv_obj_set_style_opa(ui_main_update_spinner, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
        lv_obj_set_style_opa(ui_main_elapsed, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    }
    else {
        lv_obj_set_style_opa(ui_main_update_spinner, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
        lv_obj_set_style_opa(ui_main_elapsed, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
    }
}

void setMainScreen() {
    lv_label_set_text(ui_main_car_name, data.carname.c_str());
    lv_label_set_text(ui_main_status, data.state.c_str());
    lv_label_set_text(ui_main_odometer, (String(data.odometer) + data.unit_length).c_str());
    lv_label_set_text(ui_main_elapsed, data.elapsed.c_str());

    lv_label_set_text(ui_main_temp_inside_value, String(data.temp_inside).c_str());
    lv_arc_set_range(ui_main_temp_inside_arc, 0, data.unit_temp == "C" ? 100 : 212);
    lv_arc_set_value(ui_main_temp_inside_arc, data.temp_inside);

    lv_label_set_text(ui_main_temp_outside_value, String(data.temp_outside).c_str());
    lv_arc_set_range(ui_main_temp_outside_arc, 0, data.unit_temp == "C" ? 100 : 212);
    lv_arc_set_value(ui_main_temp_outside_arc, data.temp_outside);

    lv_obj_set_style_bg_color(ui_main_healthy_panel, lv_color_hex(data.status_healthy ? GREEN : RED), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_locked_panel, lv_color_hex(data.status_locked ? GREEN : RED), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_sentry_panel, lv_color_hex(data.status_sentry ? GREEN : GREY), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_user_panel, lv_color_hex(data.status_present ? GREEN : GREY), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_windows_panel, lv_color_hex(data.status_windows ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_doors_panel, lv_color_hex(data.status_doors ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_frunk_panel, lv_color_hex(data.status_frunk ? RED : GREEN), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_main_trunk_panel, lv_color_hex(data.status_trunk ? RED : GREEN), LV_STATE_DEFAULT);

    lv_color_t battery_color = lv_color_hex(GREEN);
    if (data.battery_level <= 10)
        battery_color = lv_color_hex(RED);
    else if (data.battery_level <= 20)
        battery_color = lv_color_hex(ORANGE);
    lv_obj_set_style_bg_color(ui_main_battery_panel, battery_color, LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_label_set_text(ui_main_battery_value, String(data.battery_level).c_str());
    lv_obj_set_style_bg_color(ui_main_battery_bar, battery_color, LV_PART_INDICATOR | LV_STATE_DEFAULT );
    lv_bar_set_value(ui_main_battery_bar, data.battery_level, LV_ANIM_OFF);

    lv_label_set_text(ui_main_estimated_value, (String(data.battery_range) + data.unit_length).c_str());
}