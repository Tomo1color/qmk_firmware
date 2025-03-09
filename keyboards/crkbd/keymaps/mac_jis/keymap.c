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

enum custom_layers {
  _QWERTY = 0,      // デフォルトレイヤー
  _LOWER,           // Lower
  _RAISE,           // Raise
  _ADJUST           // Adjust
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WN_SCLN,          // タップでJISの「;」  シフトでJISの「:」 (JIS)
  WN_QUOT,          // タップでJISの「'」  シフトでJISの「"」 (JIS)
  WN_MINS,          // タップでJISの「-」  シフトでJISの「_」 (JIS)
  WN_LPLT,          // ( or < with shift (JIS)
  WN_RPGT,          // ) or > with shift (JIS)
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
  QAA,
  NOTION,
  DISPLAYL,
  DISPLAYR
};

#define RST   RESET
#define LPLT WN_LPLT
#define RPGT WN_RPGT

#define TAB_L LGUI(JP_LCBR)         // GUI + {
#define TAB_R LGUI(JP_RCBR)         // GUI + }
#define CTL_F5 LCTL(KC_F5)          // Ctr + F5
#define CMDSP LGUI(KC_SPC)          // GUI + Space
#define GUI_BS LGUI(KC_BSPC)        // GUI + BS
#define ALTLAN LALT(KC_SPC)
#define SGUI_2 SGUI(KC_2)
#define SGUI_5 SGUI(KC_5)
#define ALT_PS LALT(KC_PSCR)        // Alt + Print Screen
#define ALT_ENT LALT(KC_ENT)        // Alt + Enter
#define SFSP LSFT(KC_SPC)

// #define GUI_A LGUI(KC_A)            // GUI + A
// #define GUI_S LGUI(KC_S)            // GUI + S
// #define GUI_F LGUI(KC_F)            // GUI + F
#define GUI_Z LGUI(KC_Z)            // GUI + Z
#define GUI_X LGUI(KC_X)            // GUI + X
#define GUI_C LGUI(KC_C)            // GUI + C
#define GUI_V LGUI(KC_V)            // GUI + V
#define GUI_N LGUI(KC_N)            // GUI + N

#define JP_LBRC KC_RBRC       // [
#define JP_RBRC KC_NUHS       // ]
#define JP_COLN KC_QUOT       // :
#define JP_AT   KC_LBRC       // @
#define JP_CIRC KC_EQL        // ^
#define JP_YEN  KC_INT3       // ¥
#define JP_DQUO LSFT(KC_2)    // "
#define JP_DLR  LSFT(KC_4)    // $
#define JP_AMPR LSFT(KC_6)    // &
#define JP_UNDS LSFT(JP_BSLS) // _
#define JP_LCBR LSFT(JP_LBRC) // {
#define JP_RCBR LSFT(JP_RBRC) // }
#define JP_ASTR LSFT(JP_COLN) // *
#define JP_EQL  LSFT(KC_MINS) // =
#define JP_PIPE LSFT(JP_YEN)  // |
#define JP_GRV  LSFT(JP_AT)   // `
#define JP_PLUS LSFT(KC_SCLN) // +
#define JP_TILD LSFT(KC_EQL)  // ~
#define JP_BSLS KC_INT1     // (backslash)
#define MAC_BSLS LALT(JP_YEN)  // '\'

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,------------------------------------------------------.
          KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,\
  //|-----------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
  LCTL_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, WN_SCLN,  WN_QUOT,\
  //|-----------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RO_CT,\
  //|-----------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                    LGUI_T(KC_DEL), KC_L1SPC, KC_AJDSP,    RSFT_T(KC_SPC), KC_L2ET,  KC_RALT \
                                 //`----------------------------------'  `-----------------------------------'
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   TAB_L,\
  //|--------+--------+---------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LANG2,  GUI_BS, KC_LGUI, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, WN_MINS, JP_ASTR,\
  //|--------+--------+---------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   GUI_Z,    GUI_X,   GUI_C,   GUI_V, XXXXXXX,                        GUI_N,  KC_DEL, KC_PGDN, KC_PGUP, _______, JP_UNDS,\
  //|--------+--------+---------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               RST, XXXXXXX, XXXXXXX,      CMDSP, KC_BSPC, _______ \
                                       //`--------------------------'  `---------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,------------------------------------------------------.
       KC_TAB,        KC_EXLM,   JP_AT,  KC_HASH,   JP_DLR, KC_PERC,                      JP_CIRC, JP_AMPR,    LPLT,    RPGT,  JP_ASTR,   TAB_R,\
  //|--------+---------------+--------+---------+---------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_LCTL, LSFT_T(KC_F12), KC_ZKHK,  KC_ZKHK,  KC_LGUI,  JP_YEN,                      JP_ASTR,  JP_EQL, JP_LBRC, JP_RBRC,  JP_PIPE,  JP_GRV,\
  //|--------+---------------+--------+---------+---------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_LSFT,        KC_LCTL, XXXXXXX, DISPLAYL, DISPLAYR, XXXXXXX,                        KC_RO, JP_PLUS, JP_LCBR, JP_RCBR, MAC_BSLS, JP_TILD,\
  //|--------+---------------+--------+---------+---------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                                   KC_LALT,  ALTLAN, _______,    XXXXXXX, XXXXXXX, XXXXXXX \
                                               //`--------------------------'  `---------------------------'
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  SGUI_5,\
  //|-----------+---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_F11), LSFT_T(KC_F12), XXXXXXX,  GUI_BS, KC_LGUI,  SGUI_2,                     KC_HOME,  XXXXXXX, XXXXXXX,  KC_END, XXXXXXX,  ALT_PS,\
  //|-----------+---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LSFT,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      NOTION,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,\
  //|-----------+---------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    XXXXXXX,     QAA, XXXXXXX,    XXXXXXX, ALT_ENT, KC_RALT \
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // set_keylog(keycode, record);
  }

  static bool lshift = false;
  static bool rshift = false;

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case WN_MINS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code (KC_RSFT);
            register_code(JP_BSLS);
            unregister_code(JP_BSLS);
            unregister_code (KC_RSFT);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_MINS);
          unregister_code(KC_MINS);
        }
      }
      return false;
      break;
    case WN_SCLN:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code(JP_COLN);
            unregister_code(JP_COLN);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      return false;
      break;
    case WN_QUOT:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code (KC_RSFT);
            register_code(KC_2);
            unregister_code(KC_2);
            unregister_code (KC_RSFT);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          register_code (KC_RSFT);
          register_code(KC_7);
          unregister_code(KC_7);
          unregister_code (KC_RSFT);
        }
      }
      return false;
      break;
    case WN_LPLT:
      if (record->event.pressed) {
        if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
          // <
          tap_code(KC_COMM); // shift is already registered
        } else {
          // (
          register_mods(MOD_BIT(KC_LSFT));
          tap_code(KC_8);
          unregister_mods(MOD_BIT(KC_LSFT));
        }
      }
      return false;
      break;
    case WN_RPGT:
      if (record->event.pressed) {
        if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
          // <
          tap_code(KC_DOT); // shift is already registered
        } else {
          // )
          register_mods(MOD_BIT(KC_LSFT));
          tap_code(KC_9);
          unregister_mods(MOD_BIT(KC_LSFT));
        }
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case QAA:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_APPLICATION) SS_TAP(X_Q) SS_UP(X_APPLICATION));
      } else {
        //released
      }
      return false;
      break;
    case NOTION:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_APPLICATION) SS_TAP(X_N) SS_UP(X_APPLICATION));
      } else {
        //released
      }
      return false;
      break;
    case DISPLAYL:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LCTRL) SS_UP(X_LALT) SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
      } else {
        //released
      }
      return false;
      break;
    case DISPLAYR:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LCTRL) SS_UP(X_LALT) SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
      } else {
        //released
      }
      return false;
      break;
    default:
      break;
  }
  return true;
}
#endif // OLED_ENABLE
