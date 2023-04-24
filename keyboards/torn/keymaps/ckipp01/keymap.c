/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

enum torn_layers { _QWERTY, _SECONDARY };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define S_SPC LT(_SECONDARY, KC_SPC)

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | `    |   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | SHIFT|   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | LT   |  Cmd | Ent  | Ctrl |    |Bksp  |Space | Ctrl | Cmd |
 *               `---------------------------'    `---------------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_4(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LEFT_SHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC ,
            TG(_SECONDARY), KC_LEFT_GUI, KC_ENTER,  KC_LCTL,    KC_BSPC,  S_SPC,  KC_RIGHT_GUI, KC_MEDIA_PLAY_PAUSE
),

/* SECONDARY
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | =    |   1  |   2  |   3  |   4  |   5  |    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | _    |      |      |      | Up   | Down |    | Left |Right |   ,  |   .  |   /  |  +   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_SECONDARY] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PMNS,
    KC_UNDS, _______, _______, _______, KC_UP, KC_DOWN,   KC_LEFT, KC_RIGHT, KC_COMM, KC_DOT,  KC_SLSH, KC_PPLS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
// clang-format on

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY] =  { {_______, _______}, { KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN } }
};
