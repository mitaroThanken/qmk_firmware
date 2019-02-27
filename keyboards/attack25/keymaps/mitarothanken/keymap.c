#include QMK_KEYBOARD_H

bool MAC_mode = true;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NUM] = LAYOUT_ortho_5x5(
    KC_NLCK,     KC_ESC, KC_PSLS,  KC_PAST, KC_PMNS,
    DF(_WINCTL), KC_P7,  KC_P8,    KC_P9,   KC_PPLS,
    DF(_VSCTRL), KC_P4,  KC_P5,    KC_P6,   S(KC_TAB),
    KC_HOME,     KC_P1,  KC_P2,    KC_P3,   KC_TAB,
    MO(_FN),     KC_P0,  KC_COMMA, KC_PDOT, KC_PENT),

  [_NUMOFF] = LAYOUT_ortho_5x5(
    _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_UP,   KC_PGUP, _______,
    _______, KC_LEFT, XXXXXXX, KC_RGHT, _______,
    _______, KC_END,  KC_DOWN, KC_PGDN, _______,
    _______, KC_INS,  KC_BSPC, KC_DEL,  _______),

  [_WINCTL] = LAYOUT_ortho_5x5(
    XXXXXXX,     KC_ESC,              LGUI(KC_UP),   XXXXXXX,              LGUI(KC_1),
    DF(_NUM),    LGUI(KC_LEFT),       LGUI(KC_DOWN), LGUI(KC_RIGHT),       LGUI(KC_2),
    DF(_VSCTRL), LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB),  LCTL(LGUI(KC_RIGHT)), LGUI(KC_3),
    LGUI(KC_E),  KC_PGUP,             KC_UP,         KC_PGDN,              LGUI(KC_4),
    _______,     KC_LEFT,             KC_DOWN,       KC_RIGHT,             KC_PENT),

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
    _______,  KC_F4,  KC_F5,   KC_F6,  LGUI(KC_F4),
    _______,  KC_F1,  KC_F2,   KC_F3,  LGUI(KC_D),
    _______,  KC_DEL, KC_BSPC, KC_APP, KC_LWIN)
};
// clang-format on
