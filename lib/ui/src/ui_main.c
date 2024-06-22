// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: TeslaMateCompanion_Project

#include "ui.h"

void ui_main_screen_init(void)
{
ui_main = lv_obj_create(NULL);
lv_obj_clear_flag( ui_main, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_status = lv_label_create(ui_main);
lv_obj_set_width( ui_status, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_status, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_status, 6 );
lv_obj_set_y( ui_status, 0 );
lv_label_set_text(ui_status,"Unknown");
lv_obj_set_style_text_font(ui_status, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel3 = lv_obj_create(ui_main);
lv_obj_set_width( ui_Panel3, 118);
lv_obj_set_height( ui_Panel3, 47);
lv_obj_set_x( ui_Panel3, 97 );
lv_obj_set_y( ui_Panel3, 39 );
lv_obj_set_align( ui_Panel3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_pctbar = lv_bar_create(ui_main);
lv_bar_set_value(ui_pctbar,50,LV_ANIM_OFF);
lv_bar_set_start_value(ui_pctbar, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_pctbar, 312);
lv_obj_set_height( ui_pctbar, 15);
lv_obj_set_x( ui_pctbar, 1 );
lv_obj_set_y( ui_pctbar, 150 );
lv_obj_set_align( ui_pctbar, LV_ALIGN_TOP_MID );
lv_obj_set_style_bg_color(ui_pctbar, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_pctbar, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_pctbar, lv_color_hex(0x00B200), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_pctbar, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_pctnumber = lv_label_create(ui_main);
lv_obj_set_width( ui_pctnumber, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_pctnumber, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_pctnumber, -36 );
lv_obj_set_y( ui_pctnumber, 99 );
lv_obj_set_align( ui_pctnumber, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_pctnumber,"__");
lv_obj_set_style_text_font(ui_pctnumber, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_kmstotal = lv_label_create(ui_main);
lv_obj_set_width( ui_kmstotal, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_kmstotal, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_kmstotal, -3 );
lv_obj_set_y( ui_kmstotal, 0 );
lv_obj_set_align( ui_kmstotal, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_kmstotal,"_____ Kms");
lv_obj_set_style_text_font(ui_kmstotal, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_kmsestimated = lv_label_create(ui_main);
lv_obj_set_width( ui_kmsestimated, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_kmsestimated, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_kmsestimated, -128 );
lv_obj_set_y( ui_kmsestimated, 122 );
lv_obj_set_align( ui_kmsestimated, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_kmsestimated,"___ Kms");
lv_obj_set_style_text_font(ui_kmsestimated, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label9 = lv_label_create(ui_main);
lv_obj_set_width( ui_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label9, 4 );
lv_obj_set_y( ui_Label9, 122 );
lv_label_set_text(ui_Label9,"Estimation:");
lv_obj_set_style_text_color(ui_Label9, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label10 = lv_label_create(ui_main);
lv_obj_set_width( ui_Label10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label10, 4 );
lv_obj_set_y( ui_Label10, 102 );
lv_label_set_text(ui_Label10,"Niveau de la batterie");
lv_obj_set_style_text_color(ui_Label10, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label10, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel1 = lv_obj_create(ui_main);
lv_obj_set_width( ui_Panel1, 155);
lv_obj_set_height( ui_Panel1, 76);
lv_obj_set_x( ui_Panel1, -77 );
lv_obj_set_y( ui_Panel1, -24 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_tempinsidearc = lv_arc_create(ui_main);
lv_obj_set_width( ui_tempinsidearc, 65);
lv_obj_set_height( ui_tempinsidearc, 65);
lv_obj_set_x( ui_tempinsidearc, -118 );
lv_obj_set_y( ui_tempinsidearc, -13 );
lv_obj_set_align( ui_tempinsidearc, LV_ALIGN_CENTER );
lv_arc_set_value(ui_tempinsidearc, 0);
lv_obj_set_style_arc_color(ui_tempinsidearc, lv_color_hex(0x7E7E7E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_tempinsidearc, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_tempinsidearc, 8, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_tempinsidearc, lv_color_hex(0x00B200), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_tempinsidearc, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_tempinsidearc, 8, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_tempinsidearc, lv_color_hex(0x00BC00), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_tempinsidearc, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_tempinsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_tempinsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_tempinsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_tempinsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_tempoutsidearc = lv_arc_create(ui_main);
lv_obj_set_width( ui_tempoutsidearc, 65);
lv_obj_set_height( ui_tempoutsidearc, 65);
lv_obj_set_x( ui_tempoutsidearc, -40 );
lv_obj_set_y( ui_tempoutsidearc, -13 );
lv_obj_set_align( ui_tempoutsidearc, LV_ALIGN_CENTER );
lv_arc_set_value(ui_tempoutsidearc, 0);
lv_obj_set_style_arc_color(ui_tempoutsidearc, lv_color_hex(0x7E7E7E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_tempoutsidearc, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_tempoutsidearc, 8, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_tempoutsidearc, lv_color_hex(0x00B200), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_tempoutsidearc, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_tempoutsidearc, 8, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_tempoutsidearc, lv_color_hex(0x00BC00), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_tempoutsidearc, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_tempoutsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_tempoutsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_tempoutsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_tempoutsidearc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Label11 = lv_label_create(ui_main);
lv_obj_set_width( ui_Label11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label11, -119 );
lv_obj_set_y( ui_Label11, -54 );
lv_obj_set_align( ui_Label11, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label11,"Interieur");
lv_obj_set_style_text_color(ui_Label11, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label11, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_main);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -41 );
lv_obj_set_y( ui_Label1, -54 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"Exterieur");
lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tempinsidenumber = lv_label_create(ui_main);
lv_obj_set_width( ui_tempinsidenumber, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tempinsidenumber, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tempinsidenumber, -119 );
lv_obj_set_y( ui_tempinsidenumber, -13 );
lv_obj_set_align( ui_tempinsidenumber, LV_ALIGN_CENTER );
lv_label_set_text(ui_tempinsidenumber,"__");
lv_obj_set_style_text_font(ui_tempinsidenumber, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tempoutsidenumber = lv_label_create(ui_main);
lv_obj_set_width( ui_tempoutsidenumber, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tempoutsidenumber, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tempoutsidenumber, -39 );
lv_obj_set_y( ui_tempoutsidenumber, -14 );
lv_obj_set_align( ui_tempoutsidenumber, LV_ALIGN_CENTER );
lv_label_set_text(ui_tempoutsidenumber,"__");
lv_obj_set_style_text_font(ui_tempoutsidenumber, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_healthpanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_healthpanel, 37);
lv_obj_set_height( ui_healthpanel, 37);
lv_obj_set_x( ui_healthpanel, 21 );
lv_obj_set_y( ui_healthpanel, -44 );
lv_obj_set_align( ui_healthpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_healthpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imghealth = lv_img_create(ui_main);
lv_img_set_src(ui_imghealth, &ui_img_health_png);
lv_obj_set_width( ui_imghealth, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imghealth, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imghealth, 21 );
lv_obj_set_y( ui_imghealth, -44 );
lv_obj_set_align( ui_imghealth, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imghealth, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imghealth, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imghealth,150);
lv_obj_set_style_opa(ui_imghealth, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lockedpanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_lockedpanel, 37);
lv_obj_set_height( ui_lockedpanel, 37);
lv_obj_set_x( ui_lockedpanel, 60 );
lv_obj_set_y( ui_lockedpanel, -44 );
lv_obj_set_align( ui_lockedpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_lockedpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imglock = lv_img_create(ui_main);
lv_img_set_src(ui_imglock, &ui_img_lock_png);
lv_obj_set_width( ui_imglock, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imglock, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imglock, 60 );
lv_obj_set_y( ui_imglock, -44 );
lv_obj_set_align( ui_imglock, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imglock, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imglock, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imglock,150);
lv_obj_set_style_opa(ui_imglock, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sentrypanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_sentrypanel, 37);
lv_obj_set_height( ui_sentrypanel, 37);
lv_obj_set_x( ui_sentrypanel, 99 );
lv_obj_set_y( ui_sentrypanel, -44 );
lv_obj_set_align( ui_sentrypanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_sentrypanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgsentry = lv_img_create(ui_main);
lv_img_set_src(ui_imgsentry, &ui_img_sentry_png);
lv_obj_set_width( ui_imgsentry, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imgsentry, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imgsentry, 99 );
lv_obj_set_y( ui_imgsentry, -44 );
lv_obj_set_align( ui_imgsentry, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgsentry, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgsentry, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imgsentry,150);
lv_obj_set_style_opa(ui_imgsentry, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_userpanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_userpanel, 37);
lv_obj_set_height( ui_userpanel, 37);
lv_obj_set_x( ui_userpanel, 138 );
lv_obj_set_y( ui_userpanel, -44 );
lv_obj_set_align( ui_userpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_userpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imguser = lv_img_create(ui_main);
lv_img_set_src(ui_imguser, &ui_img_present_png);
lv_obj_set_width( ui_imguser, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imguser, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imguser, 138 );
lv_obj_set_y( ui_imguser, -44 );
lv_obj_set_align( ui_imguser, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imguser, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imguser, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imguser,150);
lv_obj_set_style_opa(ui_imguser, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_windowspanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_windowspanel, 37);
lv_obj_set_height( ui_windowspanel, 37);
lv_obj_set_x( ui_windowspanel, 21 );
lv_obj_set_y( ui_windowspanel, -5 );
lv_obj_set_align( ui_windowspanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_windowspanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgwindows = lv_img_create(ui_main);
lv_img_set_src(ui_imgwindows, &ui_img_window_png);
lv_obj_set_width( ui_imgwindows, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imgwindows, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imgwindows, 20 );
lv_obj_set_y( ui_imgwindows, -6 );
lv_obj_set_align( ui_imgwindows, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgwindows, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgwindows, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imgwindows,150);
lv_obj_set_style_opa(ui_imgwindows, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_doorspanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_doorspanel, 37);
lv_obj_set_height( ui_doorspanel, 37);
lv_obj_set_x( ui_doorspanel, 60 );
lv_obj_set_y( ui_doorspanel, -5 );
lv_obj_set_align( ui_doorspanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_doorspanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgdoors = lv_img_create(ui_main);
lv_img_set_src(ui_imgdoors, &ui_img_doors_png);
lv_obj_set_width( ui_imgdoors, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imgdoors, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imgdoors, 60 );
lv_obj_set_y( ui_imgdoors, -5 );
lv_obj_set_align( ui_imgdoors, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgdoors, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgdoors, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imgdoors,150);
lv_obj_set_style_opa(ui_imgdoors, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_frunkpanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_frunkpanel, 37);
lv_obj_set_height( ui_frunkpanel, 37);
lv_obj_set_x( ui_frunkpanel, 99 );
lv_obj_set_y( ui_frunkpanel, -5 );
lv_obj_set_align( ui_frunkpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_frunkpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgfrunk = lv_img_create(ui_main);
lv_img_set_src(ui_imgfrunk, &ui_img_frunk_png);
lv_obj_set_width( ui_imgfrunk, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imgfrunk, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imgfrunk, 99 );
lv_obj_set_y( ui_imgfrunk, -6 );
lv_obj_set_align( ui_imgfrunk, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgfrunk, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgfrunk, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imgfrunk,170);
lv_obj_set_style_opa(ui_imgfrunk, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_trunkpanel = lv_obj_create(ui_main);
lv_obj_set_width( ui_trunkpanel, 37);
lv_obj_set_height( ui_trunkpanel, 37);
lv_obj_set_x( ui_trunkpanel, 138 );
lv_obj_set_y( ui_trunkpanel, -5 );
lv_obj_set_align( ui_trunkpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_trunkpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgtrunk = lv_img_create(ui_main);
lv_img_set_src(ui_imgtrunk, &ui_img_trunk_png);
lv_obj_set_width( ui_imgtrunk, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_imgtrunk, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_imgtrunk, 138 );
lv_obj_set_y( ui_imgtrunk, -5 );
lv_obj_set_align( ui_imgtrunk, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgtrunk, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgtrunk, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_imgtrunk,170);
lv_obj_set_style_opa(ui_imgtrunk, 180, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label17 = lv_label_create(ui_main);
lv_obj_set_width( ui_Label17, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label17, 138 );
lv_obj_set_y( ui_Label17, 46 );
lv_obj_set_align( ui_Label17, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label17,"%");
lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

}