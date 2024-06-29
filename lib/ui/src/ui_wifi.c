// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: TeslaMateCompanion_Project

#include "ui.h"

void ui_wifi_screen_init(void)
{
ui_wifi = lv_obj_create(NULL);
lv_obj_clear_flag( ui_wifi, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_wifi_label = lv_label_create(ui_wifi);
lv_obj_set_width( ui_wifi_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifi_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wifi_label, 0 );
lv_obj_set_y( ui_wifi_label, -63 );
lv_obj_set_align( ui_wifi_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_wifi_label,"Connecting to wifi...");
lv_obj_set_style_text_font(ui_wifi_label, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifi_spinner = lv_spinner_create(ui_wifi,1000,90);
lv_obj_set_width( ui_wifi_spinner, 80);
lv_obj_set_height( ui_wifi_spinner, 80);
lv_obj_set_align( ui_wifi_spinner, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_wifi_spinner, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_obj_set_style_arc_width(ui_wifi_spinner, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifi_ssid_text = lv_label_create(ui_wifi);
lv_obj_set_width( ui_wifi_ssid_text, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifi_ssid_text, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wifi_ssid_text, 0 );
lv_obj_set_y( ui_wifi_ssid_text, 62 );
lv_obj_set_align( ui_wifi_ssid_text, LV_ALIGN_CENTER );
lv_label_set_text(ui_wifi_ssid_text,"_");
lv_obj_set_style_text_font(ui_wifi_ssid_text, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifi_elapsed_time = lv_label_create(ui_wifi);
lv_obj_set_width( ui_wifi_elapsed_time, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifi_elapsed_time, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_wifi_elapsed_time, LV_ALIGN_CENTER );
lv_label_set_text(ui_wifi_elapsed_time,"0");

}