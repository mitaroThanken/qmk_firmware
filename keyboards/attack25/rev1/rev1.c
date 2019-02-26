#include QMK_KEYBOARD_H
#include <drivers/avr/pro_micro.h>

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

bool RGB_momentary_on = false;
extern bool MAC_mode;
bool NumLock_Mode = true;

void matrix_init_kb(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_init();
  RGB_current_config = rgblight_config;
#endif
  TX_RX_LED_INIT; // Turn LEDs off by default
  RXLED0;
  TXLED0;
  matrix_init_user();
}

void matrix_scan_kb(void) {
  // NOP
  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case WINMAC:
    if (record->event.pressed) {
      MAC_mode = !MAC_mode;
    }
    return false;
  case KC_NLCK:
    if (record->event.pressed) {
      if (MAC_mode) {
        NumLock_Mode = !NumLock_Mode;
        if (NumLock_Mode) {
          layer_off(_NUMOFF);
        } else {
          layer_on(_NUMOFF);
        }
        return false;
      }
    } else {
      if (MAC_mode) {
        return false;
      }
    }
    break;
  case RGB_MODF:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_mode_noeeprom(RGB_current_config.mode);
      rgblight_step();
      RGB_current_config.mode = rgblight_config.mode;
    }
#endif
    return false;
  case RGB_MODR:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_mode_noeeprom(RGB_current_config.mode);
      rgblight_step_reverse();
      RGB_current_config.mode = rgblight_config.mode;
    }
#endif
    return false;
  case RGBRST:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      eeconfig_update_rgblight_default();
      rgblight_enable();
      RGB_current_config = rgblight_config;
    }
#endif
    return false;
  case RGBHINC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_increase_hue();
      RGB_current_config.hue = rgblight_config.hue;
    }
#endif
    return false;
  case RGBHDEC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_decrease_hue();
      RGB_current_config.hue = rgblight_config.hue;
    }
#endif
    return false;
  case RGBSINC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_increase_sat();
      RGB_current_config.sat = rgblight_config.sat;
    }
#endif
    return false;
  case RGBSDEC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_decrease_sat();
      RGB_current_config.sat = rgblight_config.sat;
    }
#endif
    return false;
  case RGBVINC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_increase_val();
      RGB_current_config.val = rgblight_config.val;
    }
#endif
    return false;
  case RGBVDEC:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgblight_decrease_val();
      RGB_current_config.val = rgblight_config.val;
    }
#endif
    return false;
  case RGB_MODE_PLAIN:
  case RGB_MODE_BREATHE:
  case RGB_MODE_RAINBOW:
  case RGB_MODE_SWIRL:
  case RGB_MODE_SNAKE:
  case RGB_MODE_KNIGHT:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
    } else {
      RGB_current_config.mode = rgblight_config.mode;
    }
#endif
    break;
  case P00:
    if (record->event.pressed) {
      SEND_STRING("00");
    }
    return false;
  default:
    break;
  }
  return process_record_user(keycode, record);
}

uint32_t layer_state_set_kb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  switch (biton32(state)) {
  case _FN:
    rgblight_sethsv_noeeprom_orange();
    rgblight_mode_noeeprom(1);
    RGB_momentary_on = true;
    break;
  case _NUMOFF:
    rgblight_sethsv_noeeprom_azure();
    rgblight_mode_noeeprom(1);
    break;
  case _RGB:
    break;
  default:
    rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat,
                             RGB_current_config.val);
    rgblight_mode_noeeprom(RGB_current_config.mode);
    RGB_momentary_on = false;
    break;
  }
#endif
  return layer_state_set_user(state);
}

void led_set_kb(uint8_t usb_led) {
#ifdef RGBLIGHT_ENABLE
  if (!RGB_momentary_on && !MAC_mode) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
      rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat,
                               RGB_current_config.val);
      rgblight_mode_noeeprom(RGB_current_config.mode);
    } else {
      rgblight_sethsv_noeeprom_azure();
      rgblight_mode_noeeprom(1);
    }
  }
#endif

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
  } else {
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
  } else {
  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {
  } else {
  }

  if (usb_led & (1 << USB_LED_KANA)) {
  } else {
  }

  led_set_user(usb_led);
}
