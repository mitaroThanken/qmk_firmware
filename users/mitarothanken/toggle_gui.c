#include "quantum.h"
#include "keycodes.h"
#include "toggle_gui.h"

bool tg_gui = false;

bool toggle_gui(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TG_GUI:
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
  return true;
}
