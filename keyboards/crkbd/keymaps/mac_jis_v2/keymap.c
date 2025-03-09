/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_japanese.h"


typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_layers {
  _QWERTY = 0,      // デフォルトレイヤー
  _LOWER,           // Lower
  _RAISE,           // Raise
  _ADJUST           // Adjust
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  QAA,
  DISPLAYL,
  DISPLAYR,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK
};


#define CMDSP LGUI(KC_SPC)          // GUI + Space
#define GUI_BS LGUI(KC_BSPC)        // GUI + BS
#define SGUI_2 SGUI(KC_2)
#define SGUI_5 SGUI(KC_5)
#define ALT_PS LALT(KC_PSCR)        // Alt + Print Screen
#define ALT_ENT LALT(KC_ENT)        // Alt + Enter
#define SFSP LSFT(KC_SPC)

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)

// Base layer mod tap
#define KC_A_SF LSFT_T(KC_A)
#define KC_Z_CT LCTL_T(KC_Z)
#define KC_D_AL LALT_T(KC_D)
#define KC_V_AL LALT_T(KC_V)
#define KC_F_GU LGUI_T(KC_F)
#define KC_J_GU RGUI_T(KC_J)
#define KC_RO_CT RCTL_T(KC_RO)

#define KC_L1SPC LT(_LOWER,KC_SPC)
#define KC_AJDSP LT(_ADJUST,KC_SPC)
#define KC_AJDBS LT(_ADJUST,KC_BSPC)
#define KC_ADJUST MO(_ADJUST)
#define KC_ALTESC LALT_T(KC_ESC)
#define KC_L2ET LT(_RAISE,KC_ENT)


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make crkbd/rev1:mac_jis_v2
 *
 * Upload command
 * $ make crkbd/rev1:mac_jis_v2:avrdude
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                     ,------------------------------------------------------.
          KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,\
  //|-----------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
  LCTL_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|-----------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|-----------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+---------|
                                             KC_LALT, KC_LGUI, KC_L1SPC,    RSFT_T(KC_SPC), KC_L2ET,  KC_ADJUST \
                                 //`-----------------------------------'  `-------------------------------------'
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       JPZKHK,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,\
  //|--------+--------+---------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT,   SGUI_L,  GUI_BS, KC_LGUI, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_MINS, ALT_ENT,\
  //|--------+--------+---------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS,  KC_DEL, _______, _______, _______, KC_TILD,\
  //|--------+--------+---------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           QK_BOOT, XXXXXXX,  KC_DEL,      CMDSP, KC_BSPC, _______ \
                                       //`--------------------------'  `---------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,------------------------------------------------------.
       KC_GRV,        KC_EXLM,   KC_AT,  KC_HASH,   KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN,  KC_ASTR, _______,\
  //|--------+---------------+--------+---------+---------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_LCTL, LSFT_T(KC_F12), XXXXXXX,  XXXXXXX,  KC_LGUI,  JP_YEN,                      KC_ASTR,  KC_EQL, KC_LBRC, KC_RBRC,  KC_PIPE, _______,\
  //|--------+---------------+--------+---------+---------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_LSFT,        XXXXXXX, XXXXXXX, DISPLAYL, DISPLAYR, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_BSLS, _______,\
  //|--------+---------------+--------+---------+---------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                                 JIS_TO_US, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                               //`--------------------------'  `---------------------------'
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  SGUI_5,\
  //|-----------+---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_F11), LSFT_T(KC_F12), XXXXXXX, XXXXXXX, KC_LGUI,  SGUI_2,                      KC_HOME, XXXXXXX, XXXXXXX,  KC_END, XXXXXXX,  ALT_PS,\
  //|-----------+---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LSFT,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,\
  //|-----------+---------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  US_TO_JIS,     QAA, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                                //`--------------------------'  `---------------------------'
   )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE


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
    // save_persistent();
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
    case QAA:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_APPLICATION) SS_TAP(X_Q) SS_UP(X_APPLICATION));
      } else {
        //released
      }
      return false;
    case DISPLAYL:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LCTL) SS_UP(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
      } else {
        //released
      }
      return false;
    case DISPLAYR:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LCTL) SS_UP(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
      } else {
        //released
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
