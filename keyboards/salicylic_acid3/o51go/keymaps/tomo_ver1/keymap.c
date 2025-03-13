/* Copyright 2021 ai03
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
#include "keymap_japanese.h"

extern uint8_t is_master;

typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK,
  UNDO
};


#define CTR2TB MT(MOD_LCTL, KC_TAB)
#define SF2SP LSFT_T(KC_SPC)
#define CTR2F11 MT(MOD_LCTL, KC_F11)
#define SF2F12 MT(MOD_LSFT, KC_F12)
#define CMDSP LGUI(KC_SPC)
#define GUI_BS LGUI(KC_BSPC)
#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)
#define SFTSP LSFT(KC_SPC)
#define CTL_V RCTL(KC_V)
#define CTL_C RCTL(KC_C)
#define CTL_X RCTL(KC_X)
#define CTL_Z RCTL(KC_Z)
#define SCP LSFT(LCTL(KC_P))


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make salicylic_acid3/o51go:tomo_ver1
 * $ qmk compile -kb salicylic_acid3/o51go -km tomo_ver1
 *
 * Upload command
 * $ make salicylic_acid3/o51go:tomo_ver1:flash
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R, KC_T, KC_NO, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        CTR2TB,   KC_A,   KC_S,    KC_D,    KC_F, KC_G, KC_NO, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V, KC_B, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP,   MT(MOD_RSFT, KC_SLSH),
        KC_ENT,   KC_DEL, KC_LALT, KC_LGUI, LT(_ADJUST, KC_SPC), SF2SP, MO(_LOWER), MO(_RAISE), KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO, KC_6,    KC_7,  KC_8,  KC_9,  KC_0,  _______,
        KC_LCTL,   KC_SLSH, KC_DOT,  KC_COMM, KC_MINS, KC_EQL,  KC_NO, KC_COLN, KC_NO, KC_NO, KC_NO, KC_NO, _______,
        _______,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
        JIS_TO_US, _______, _______, _______, KC_SPC,     SF2SP,    KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_RAISE] = LAYOUT(
        KC_TILD,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, JP_YEN,
        KC_LCTL,  KC_QUES,  KC_LABK, KC_RABK, KC_MINS, KC_EQL,  KC_NO, KC_COLN, KC_DQT,  KC_NO,   KC_LBRC, KC_RBRC, KC_PIPE,
        _______,  KC_NO,    KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_NO, KC_NO,   KC_QUOT, KC_NO,   KC_LCBR, KC_RCBR, KC_BSLS,
        US_TO_JIS, _______, _______, _______, SFTSP,       SF2SP,  KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    [_ADJUST] = LAYOUT(
        JPZKHK,  KC_NO,  KC_F2,  KC_F3,   KC_F4,   KC_F5,  KC_NO, KC_F6,   KC_F7,   KC_F8,   KC_F9,   SCP,     _______,
        CTR2F11, SF2F12, SGUI_L, GUI_BS,  KC_LGUI, KC_F10, KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, _______,
        _______, CTL_Z,  CTL_X,  CTL_C,   CTL_V,   KC_NO,  KC_NO, KC_UNDS, KC_DEL,  KC_NO,   KC_NO,   KC_PGUP, KC_RSFT,
        KC_NO,   KC_NO,  KC_NO,  QK_BOOT, KC_NO,      KC_NO, CMDSP,       KC_BSPC,  KC_LALT, KC_HOME, KC_PGDN, KC_END
    )
};

// -------- EEPROM functions --------
void load_persistent(void) {
  user_config.raw = eeconfig_read_user();
}

void save_persistent(void) {
  eeconfig_update_user(user_config.raw);
}

void eeconfig_init_user(void) {
  save_persistent();
}

void keyboard_post_init_user(void) {
  load_persistent();
}

// -------- Keyboard functions --------
const uint16_t us2jis[][2] = {
  {KC_LPRN, JP_LPRN},
  {KC_RPRN, JP_RPRN},
  {KC_AT,   JP_AT},
  {KC_LBRC, JP_LBRC},
  {KC_RBRC, JP_RBRC},
  {KC_LCBR, JP_LCBR},
  {KC_RCBR, JP_RCBR},
  {KC_MINS, JP_MINS},
  {KC_EQL,  JP_EQL},
  {KC_BSLS, JP_BSLS},
  {KC_SCLN, JP_SCLN},
  {KC_QUOT, JP_QUOT},
  {KC_GRV,  JP_GRV},
  {KC_PLUS, JP_PLUS},
  {KC_COLN, JP_COLN},
  {KC_UNDS, JP_UNDS},
  {KC_PIPE, JP_PIPE},
  {KC_DQT,  JP_DQUO},
  {KC_ASTR, JP_ASTR},
  {KC_TILD, JP_TILD},
  {KC_AMPR, JP_AMPR},
  {KC_CIRC, JP_CIRC},
};

bool twpair_on_jis(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;

  uint16_t skeycode; // シフトビットを反映したキーコード
  bool lshifted = keyboard_report->mods & MOD_BIT(KC_LSFT); // シフトキーの状態
  bool rshifted = keyboard_report->mods & MOD_BIT(KC_RSFT);
  bool shifted = lshifted | rshifted;

  if (shifted) {
    skeycode = QK_LSFT | keycode;
  } else {
    skeycode = keycode;
  }

  for (int i = 0; i < sizeof(us2jis) / sizeof(us2jis[0]); i++) {
    if (us2jis[i][0] == skeycode) {
      unregister_code(KC_LSFT);
      unregister_code(KC_RSFT);
      if ((us2jis[i][1] & QK_LSFT) == QK_LSFT || (us2jis[i][1] & QK_RSFT) == QK_RSFT) {
        register_code(KC_LSFT);
        tap_code(us2jis[i][1]);
        unregister_code(KC_LSFT);
      } else {
        tap_code(us2jis[i][1]);
      }
      if (lshifted) register_code(KC_LSFT);
      if (rshifted) register_code(KC_RSFT);
      return false;
    }
  }

  return true;
}

void set_keyboard_lang_to_jis(bool set_jis){
    if ( user_config.jis == set_jis){ return; }
    if (set_jis){
        user_config.jis = 1;
    } else {
        user_config.jis = 0;
    }
    save_persistent();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;

  switch (keycode) {
    case US_TO_JIS:
        set_keyboard_lang_to_jis(true);
        return false;
    case JIS_TO_US:
        set_keyboard_lang_to_jis(false);
        return false;
    case JPZKHK:
      //
      if (record->event.pressed) {
        tap_code(KC_GRV);
      }
      return false;
    default:
      if (user_config.jis) {
        return twpair_on_jis(keycode, record);
      } else {
        result = true;
        break;
      }
  }

  return result;
}
