#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "toggle_gui.h"
#include <drivers/avr/pro_micro.h>

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t        RGB_current_config;
#endif

// clang-format off
enum layer_number {
    _NUM = 0,
    _NUMOFF,
    _WINCTL,
    _VSCTRL,
    _RGB,
    _FN
};

enum custom_keycodes {
    NUM = CUSTOM_KEYCODES_PLACEHOLDER,
    NUMOFF,
    FN,
    RGB_MODF,
    RGB_MODR,
    RGBHINC,
    RGBHDEC,
    RGBSINC,
    RGBSDEC,
    RGBVINC,
    RGBVDEC,
    RGBRST,
    P00,
    WINMAC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT_ortho_5x5(
        KC_NLCK,     KC_ESC, JP_SLSH, JP_ASTR, JP_MINS,
        DF(_WINCTL), KC_7,   KC_8,     KC_9,    JP_PLUS,
        DF(_VSCTRL), KC_4,   KC_5,     KC_6,    S(KC_TAB),
        KC_HOME,     KC_1,   KC_2,     KC_3,    KC_TAB,
        MO(_FN),     KC_0,   JP_COMM,  JP_DOT,  KC_ENT),

    [_NUMOFF] = LAYOUT_ortho_5x5(
        _______, _______, _______, _______, _______,
        _______, KC_HOME, KC_UP,   KC_PGUP, _______,
        _______, KC_LEFT, XXXXXXX, KC_RGHT, _______,
        _______, KC_END, KC_DOWN,  KC_PGDN, _______,
        _______, KC_INS, KC_BSPC, KC_DEL, _______),

    [_WINCTL] = LAYOUT_ortho_5x5(
        XXXXXXX,     KC_ESC,           LGUI(KC_COMMA), LGUI(KC_D),     LGUI(KC_1),
        DF(_NUM),    LGUI(LALT(KC_D)), LGUI(KC_S),     LGUI(KC_E),     LGUI(KC_2),
        DF(_VSCTRL), KC_PGUP,          KC_UP,          KC_PGDN,        LGUI(KC_3),
        TG_GUI,      KC_LEFT,          KC_DOWN,        KC_RIGHT,       LGUI(KC_4),
        _______,     LCTL(KC_LEFT),    KC_TAB,         LCTL(KC_RIGHT), KC_PENT),

    [_VSCTRL] = LAYOUT_ortho_5x5(
        XXXXXXX,     _______, _______, _______, _______,
        DF(_WINCTL), _______, _______, _______, _______,
        DF(_NUM),    _______, _______, _______, _______,
        _______,     _______, _______, _______, _______,
        _______,     _______, _______, _______, _______),

    [_RGB] = LAYOUT_ortho_5x5(
        XXXXXXX, RGB_MODE_SWIRL, RGB_MODE_SNAKE,   RGB_MODE_KNIGHT,  XXXXXXX,
        RGBRST,  RGB_MODR,       RGBHDEC,          RGBSDEC,          RGBVDEC,
        RGB_TOG, RGB_MODF,       RGBHINC,          RGBSINC,          RGBVINC,
        XXXXXXX, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, XXXXXXX,
        MO(_FN), XXXXXXX,        XXXXXXX,          XXXXXXX,          XXXXXXX),

    [_FN] = LAYOUT_ortho_5x5(
        TG(_RGB), KC_F10, KC_F11,  KC_F12, LCTL(KC_F4),
        _______,  KC_F7,  KC_F8,   KC_F9,  LALT(KC_F4),
        _______,  KC_F4,  KC_F5,   KC_F6,  LGUI(LCTL(KC_F4)),
        _______,  KC_F1,  KC_F2,   KC_F3,  LGUI(LCTL(KC_D)),
        _______,  KC_DEL, KC_BSPC, KC_APP, KC_LWIN)
};
// clang-format on

bool RGB_momentary_on = false;
bool MAC_mode         = true;
bool NumLock_Mode     = true;

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_init();
    RGB_current_config = rgblight_config;
#endif
    TX_RX_LED_INIT;  // Turn LEDs off by default
    RXLED0;
    TXLED0;
}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

    if ((record->event.pressed) && layer_state_is(_NUM)) {
        SEND_STRING(SS_TAP(X_INT5));
    }

    return toggle_gui(keycode, record);
}

uint32_t layer_state_set_user(uint32_t state) {
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
            rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
            rgblight_mode_noeeprom(RGB_current_config.mode);
            RGB_momentary_on = false;
            break;
    }
#endif
    return state;
}

void led_set_user(uint8_t usb_led) {
#ifdef RGBLIGHT_ENABLE
    if (!RGB_momentary_on && !MAC_mode) {
        if (usb_led & (1 << USB_LED_NUM_LOCK)) {
            rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
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
}
