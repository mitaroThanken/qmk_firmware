#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT_ortho_5x5(
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_ESC,
        KC_P7, KC_P8, KC_P9, KC_PPLS, LT(_FN, KC_SLCK),
        KC_P4, KC_P5, KC_P6, S(KC_TAB), LT(_RGB, KC_PSCR),
        KC_P1, KC_P2, KC_P3, KC_TAB, KC_DEL,
        KC_P0, P00, KC_PDOT, KC_PENT, KC_BSPC),

    [_NUMOFF] = LAYOUT_ortho_5x5(
        _______, _______, _______, _______, _______,
        KC_HOME, KC_UP, KC_PGUP, _______, LT(_FN, KC_SLCK),
        KC_LEFT, XXXXXXX, KC_RGHT, _______, LT(_RGB, KC_PSCR),
        KC_END, KC_DOWN, KC_PGDN, _______, _______,
        KC_INS, P00, KC_DEL, _______, _______),

    [_FN] = LAYOUT_ortho_5x5(
        KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_F7, KC_F8, KC_F9, KC_TRNS, XXXXXXX,
        KC_F4, KC_F5, KC_F6, KC_TRNS, _______,
        KC_F1, KC_F2, KC_F3, KC_TRNS, WINMAC,
        XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_RGB] = LAYOUT_ortho_5x5(
        RGB_TOG, RGB_MODF, RGBHINC, RGBSINC, RGBVINC,
        RGBRST, RGB_MODR, RGBHDEC, RGBSDEC, RGBVDEC,
        RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, XXXXXXX, XXXXXXX,
        RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};
