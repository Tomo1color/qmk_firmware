/* Copyright 2019 yynmt
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

#define _DEFAULT 0
#define _LOWER 1

/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make dozen0:default:avrdude
 *
 * $ make dozen0:tomo
 * $ make dozen0:tomo:avrdude
 *
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    LCTL(KC_C), LCTL(KC_V), M(0), LCTL(KC_1), M(1), KC_DEL, \
    LT(_LOWER, KC_ESC), KC_LCTRL, KC_LSFT, KC_PGUP, KC_PGDN, LALT(KC_PSCR) \
  ),
  [_LOWER] = LAYOUT(
    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_UP, M(0), KC_BSPC, \
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case 0:
        return MACRO( D(LALT), T(H), U(LALT), T(O), T(R), END );
      case 1:
        return MACRO( D(LALT), T(H), U(LALT), T(F), T(D), T(O), END );
      case 2:
        return MACRO( T(LBRC), T(RBRC), T(LEFT), END);
      case 3:
        return MACRO( D(LSFT), T(COMMA), U(LSFT), D(LSFT), T(DOT), U(LSFT), END );
    }
  }
  return MACRO_NONE;
};
