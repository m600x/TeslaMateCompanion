SET(SOURCES ui_wifi.c
    ui_main.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_img_health_png.c
    ui_img_lock_png.c
    ui_img_sentry_png.c
    ui_img_present_png.c
    ui_img_window_png.c
    ui_img_doors_png.c
    ui_img_frunk_png.c
    ui_img_trunk_png.c)

add_library(ui ${SOURCES})
