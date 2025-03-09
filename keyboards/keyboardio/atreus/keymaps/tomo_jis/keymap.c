// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
  JPZKHK = SAFE_RANGE,
  US_TO_JIS,
  JIS_TO_US,
  DISPLAYL,
  DISPLAYR
};

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

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)

/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make keyboardio/atreus:tomo_jis
 *
 * Upload command
 * $ make keyboardio/atreus:tomo_jis:flash
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,   KC_W,   KC_E,        KC_R,                KC_T,                                                           KC_Y,  KC_U,  KC_I,        KC_O,   KC_P,
    KC_A,   KC_S,   LT(3, KC_D), KC_F,                KC_G,                                                           KC_H,  KC_J,  LT(3, KC_K), KC_L,   KC_ENT,
    KC_Z,   KC_X,   KC_C,        KC_V,                KC_B,                JPZKHK,                KC_NO,               KC_N,  KC_M,  KC_COMM,     KC_DOT, KC_BSPC,
    KC_ESC, KC_DEL, KC_LALT,     MT(MOD_LGUI,KC_SPC), MT(MOD_LCTL,KC_TAB), MT(MOD_LSFT,KC_BSPC), MT(MOD_RSFT,KC_SPC), MO(1), MO(2), KC_RALT,     KC_NO,  KC_SLSH
  ),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_NO,   KC_SLSH, KC_MINS, KC_UNDS,                  KC_SCLN, KC_QUOT, KC_LBRC, KC_RBRC, JP_YEN,
    KC_LABK, KC_LABK, KC_QUES, KC_EQL,  KC_UNDS, JPZKHK,  KC_NO,  KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_ESC,  KC_DEL,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  [2] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSLS,
    KC_TILD, KC_NO,   KC_DQT,  KC_QUOT, KC_NO,                     KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JPZKHK,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_ESC,  KC_DEL,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  [3] = LAYOUT(
    KC_F1,   KC_F2,               KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,
    KC_F11,  MT(MOD_LSFT,KC_F12), SGUI_L,  GUI_BS,  KC_NO,                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
    KC_LEFT, KC_NO,               KC_NO,   KC_NO,   KC_NO,   US_TO_JIS, JIS_TO_US, KC_UNDS, KC_DEL,  KC_NO, KC_NO,   KC_BSPC,
    KC_ESC,  KC_DEL,              KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT,   KC_RSFT,   KC_BSPC, KC_NO,   KC_NO, KC_NO,   KC_NO
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
