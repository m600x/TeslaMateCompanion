// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: TeslaMateCompanion_Project

#include "ui.h"

void ui_wifi_screen_init(void)
{
ui_wifi = lv_obj_create(NULL);
lv_obj_clear_flag( ui_wifi, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Spinner1 = lv_spinner_create(ui_wifi,1000,90);
lv_obj_set_width( ui_Spinner1, 80);
lv_obj_set_height( ui_Spinner1, 80);
lv_obj_set_align( ui_Spinner1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Spinner1, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_obj_set_style_arc_width(ui_Spinner1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_wifi);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label3, 0 );
lv_obj_set_y( ui_Label3, -63 );
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"Connecting to wifi...");
lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssidtext = lv_label_create(ui_wifi);
lv_obj_set_width( ui_ssidtext, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssidtext, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssidtext, 0 );
lv_obj_set_y( ui_ssidtext, 62 );
lv_obj_set_align( ui_ssidtext, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssidtext,"My SSID");
lv_obj_set_style_text_font(ui_ssidtext, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_elapsedtime = lv_label_create(ui_wifi);
lv_obj_set_width( ui_elapsedtime, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_elapsedtime, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_elapsedtime, LV_ALIGN_CENTER );
lv_label_set_text(ui_elapsedtime,"0");

}
