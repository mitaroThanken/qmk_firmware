#include "quantum.h"
#include "toggle_gui.h"

bool tg_gui = false;

bool toggle_gui(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_GUI:
            if (record->event.pressed) {
                if (tg_gui == false) {
                    tg_gui = true;
                    register_code(KC_LGUI);
                } else {
                    tg_gui = false;
                    unregister_code(KC_LGUI);
                }
            }
            break;
        case KC_LGUI:
        case KC_RGUI:
            if (record->event.pressed) {
                tg_gui = false;
            }
            break;
        case KC_ESC:
            if (record->event.pressed) {
                if (tg_gui) {
                    tg_gui = false;
                    unregister_code(KC_LGUI);
                }
            }
            break;
        default:
            break;
    }
    return true;
}
