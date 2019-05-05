/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Salicylic_Acid
#define PRODUCT         naked60
#define DESCRIPTION     A custom keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B6, D1, D0, D4, C6 }

// wiring of each half
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, D7, E6, B4, B5, D3 }
// #define MATRIX_COL_PINS { D3, B5, B4, E6, D7, B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

/*
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { D2, D3, D4, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6, D7, E6, B4, B5 }
*/

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* ws2812 RGB LED */
#define RGB_DI_PIN D2

#define RGBLED_NUM 48    // Number of LEDs

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
