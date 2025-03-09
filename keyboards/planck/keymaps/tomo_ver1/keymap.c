/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK,
  QAA,
  DISPLAYL,
  DISPLAYR
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define GUI_BS LGUI(KC_BSPC)     // GUI + BS
#define GUI_LC LGUI(JP_LCBR)     // GUI + {
#define GUI_RC LGUI(JP_RCBR)     // GUI + }
#define CTL_F5 LCTL(KC_F5)       // Ctr + F5
#define CMDSP LGUI(KC_SPC)       // GUI + Space
#define ALT_ENT LALT(KC_ENT)     // Alt + Enter
#define ALT_PS LALT(KC_PSCR)     // Alt + Print Screen
#define SGUI_2 SGUI(KC_2)        // Screen Shot
#define SGUI_5 SGUI(KC_5)        // Screen Shot
#define SGUI_7 SGUI(KC_7)        // Screen Shot
#define SFTSPC LSFT(KC_SPC)
#define SF2SP LSFT_T(KC_SPC)

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make git-submodule
 * $ make planck/rev6:tomo_ver1
 *
 * Upload command
 * $ make planck/rev6:tomo_ver1:dfu-util
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,               KC_Q,    KC_W,    KC_E,    KC_R,                KC_T,   KC_Y,               KC_U,               KC_I,     KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,                KC_G,   KC_H,               KC_J,               KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,                KC_B,   KC_N,               KC_M,               KC_COMM,  KC_DOT,  KC_SLSH, KC_DEL,
    KC_LCTL,              KC_DEL,  KC_LALT, KC_LGUI, LT(_ADJUST, KC_SPC), SF2SP,  LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LCTL,   KC_LABK, KC_RABK, KC_QUES, KC_MINS, KC_PLUS, KC_ASTR, KC_COLN, KC_LBRC, KC_RBRC, JP_YEN,  _______,
    _______,   KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS,  KC_EQL, KC_NO,   KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE, _______,
    JIS_TO_US, _______, _______, _______, KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSLS, _______,
    KC_LCTL,   KC_TILD, KC_NO,   KC_NO,   KC_DQT,  KC_NO,   KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______,   KC_NO,   KC_NO,   KC_NO,   KC_QUOT, KC_NO,   KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
    US_TO_JIS, _______, _______, _______, KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    JPZKHK,         KC_NO,          KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ALT_PS,
    LCTL_T(KC_F11), LSFT_T(KC_F12), SGUI_L,  GUI_BS, KC_LGUI, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, _______,
    _______,        KC_NO,          KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_UNDS, KC_DEL,  _______, _______, _______, _______,
    KC_NO,          KC_NO,          QK_BOOT, KC_NO,  KC_NO,   KC_LSFT, KC_SPC,  KC_BSPC, KC_LALT, _______, _______, _______
)

};

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

// -------- Keyboard functions --------
void set_keyboard_lang_to_jis(bool set_jis){
    if ( user_config.jis == set_jis){ return; }
    if (set_jis){
        user_config.jis = 1;
    } else {
        user_config.jis = 0;
    }
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
      // return twpair_on_jis(keycode, record);
      if (user_config.jis) {
        return twpair_on_jis(keycode, record);
      } else {
        result = true;
        break;
      }
  }
  return result;
}
