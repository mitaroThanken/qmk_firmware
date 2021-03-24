/* Copyright 2020 takashiski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _FN2,
};

enum custom_keycodes {
    ESC_FN24 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT(
  KC_GRAVE,      KC_1,     KC_2,     KC_3,          KC_4,    KC_5,    KC_MINS,   KC_EQL,    KC_6,     KC_7,             KC_8,    KC_9,     KC_0, KC_DEL, KC_INS,
  KC_TAB,         KC_Q,     KC_W,     KC_E,          KC_R,    KC_T,    KC_LBRC,   KC_RBRC,   KC_Y,     KC_U,             KC_I,    KC_O,     KC_P,    
  LCTL_T(KC_F24),  KC_A,     KC_S,     KC_D,          KC_F,    KC_G,    KC_SCLN,   KC_QUOT,   KC_H,     KC_J,             KC_K,    KC_L,     KC_BSLS,    KC_ENT,
  KC_LSPO,          KC_Z,     KC_X,     KC_C,          KC_V,    KC_B,    KC_COMM,   KC_DOT,    KC_N,     KC_M,             KC_SLSH,   KC_RSPC,          KC_BSPC,          
  KC_LCTL, KC_LGUI, KC_LALT,  KC_CALC,  LT(_FN,KC_F23), LT(_FN,KC_F24),   KC_ESC,  KC_SPC, LT(_FN,KC_SPC), LT(_FN,KC_SPC),  KC_RALT,   KC_APP,          KC_RCTL
 ),
  [_FN] = LAYOUT(
  KC_TRNS,        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,   KC_TRNS,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_TRNS,  KC_TRNS,
  KC_TRNS,         KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15 ,  KC_TRNS,   KC_TRNS,   KC_F16,   KC_F17,   KC_F18,   KC_F19,     KC_F20,
  LT(_FN2,KC_TRNS), KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,   KC_TRNS,       KC_TRNS,
  KC_RSPC,           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                 KC_DEL,
  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,             ESC_FN24,  KC_TRNS,    KC_NO,    KC_NO,     KC_TRNS,        KC_TRNS,          KC_TRNS
),
 [_FN2] = LAYOUT(
  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
  KC_NO,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_HOME,  KC_PGDN,  KC_PGUP,    KC_END,   KC_TRNS,       KC_TRNS,
  KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  EEP_RST,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                 KC_TRNS,
  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,             KC_TRNS,   KC_TRNS,    KC_NO,  KC_NO,       KC_TRNS,        KC_TRNS,          KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_FN24:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC));
            } else {
                SEND_STRING(SS_TAP(X_F24));
            }
            break;

    }
    return true;
}
