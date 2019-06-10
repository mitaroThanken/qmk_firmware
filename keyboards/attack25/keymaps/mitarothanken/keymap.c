#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "toggle_gui.h"

bool MAC_mode = true;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NUM] = LAYOUT_ortho_5x5(
    KC_NLCK,     KC_ESC, KC_SLASH, S(KC_8), KC_MINS,
    DF(_WINCTL), KC_7,   KC_8,     KC_9,    S(KC_EQL),
    DF(_VSCTRL), KC_4,   KC_5,     KC_6,    S(KC_TAB),
    KC_HOME,     KC_1,   KC_2,     KC_3,    KC_TAB,
    MO(_FN),     KC_0,   KC_COMMA, KC_DOT,  KC_ENT),

  [_NUMOFF] = LAYOUT_ortho_5x5(
    _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_UP,   KC_PGUP, _______,
    _______, KC_LEFT, XXXXXXX, KC_RGHT, _______,
    _______, KC_END,  KC_DOWN, KC_PGDN, _______,
    _______, KC_INS,  KC_BSPC, KC_DEL,  _______),

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return toggle_gui(keycode, record); }
