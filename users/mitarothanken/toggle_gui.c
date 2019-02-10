#include "toggle_gui.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool tg_gui = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TG_LGUI:
      if (record->event.pressed) {
        if (tg_gui == false) {
          tg_gui = true;
          SEND_STRING(SS_DOWN(X_LGUI));
        } else {
          tg_gui = false;
          SEND_STRING(SS_UP(X_LGUI));
        }
      }
      break;
    case KC_ESC:
      if (record->event.pressed) {
        if (tg_gui) {
          tg_gui = false;
          SEND_STRING(SS_UP(X_LGUI));
        }
      }
      break;
    default:
      break;
  }
  return process_record_keymap(keycode, record);
}
