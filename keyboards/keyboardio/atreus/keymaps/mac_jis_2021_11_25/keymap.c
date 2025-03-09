// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

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
  WN_BSLS,          // タップで USの「\」  シフトでJISの「|」 (JIS)
  WN_GRV,           // タップでJISの「`」  シフトでJISの「~」 (JIS)
  WN_LPLT,          // ( or < with shift (JIS)
  WN_RPGT,          // ) or > with shift (JIS)
  LOWER,
  RAISE,
  ADJUST,
  ESCF,
  ESCM,
  QAA,
  NOTION,
  DISPLAYL,
  DISPLAYR
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define XXXXX KC_NO
#define RST   RESET
#define WNSCLN WN_SCLN
#define WNQUOT WN_QUOT
#define WNMINS WN_MINS
#define LPLT WN_LPLT
#define RPGT WN_RPGT

#define TAB_L LGUI(JP_LCBR)         // GUI + {
#define TAB_R LGUI(JP_RCBR)         // GUI + }
#define CTL_F5 LCTL(KC_F5)          // Ctr + F5
#define CTL_SS LCTL(KC_SLSH)        // Ctr + /
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
#define KC_GUI_F LGUI_T(KC_F)
#define KC_ALT_S LALT_T(KC_S)
#define KC_SFT_A LSFT_T(KC_A)
#define KC_GUI_J RGUI_T(KC_J)
#define KC_ALT_L RALT_T(KC_L)

#define KC_A_SF LSFT_T(KC_A)
#define KC_Z_CT LCTL_T(KC_Z)
#define KC_F_GU LGUI_T(KC_F)
#define KC_SCLN_SF RSFT_T(KC_SCLN)
#define KC_SSCT RCTL_T(KC_SLSH)
#define KC_J_GU RGUI_T(KC_J)

#define KC_L1SPC LT(_LOWER,KC_SPC)
#define KC_AJDSP LT(_ADJUST,KC_SPC)
#define KC_AJDESC LT(_ADJUST,KC_ESC)
#define KC_L2ET LT(_RAISE,KC_ENT)


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make keyboardio/atreus:mac_jis
 *
 * Upload command
 * $ make keyboardio/atreus:mac_jis:flash
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,        KC_W,           KC_E,     KC_R,      KC_T,                              KC_Y,       KC_U,       KC_I,     KC_O,     KC_P,
    KC_A_SF, KC_ALT_S,           KC_D,  KC_F_GU,      KC_G,                              KC_H,    KC_J_GU,       KC_K, KC_ALT_L,  WN_SCLN,
    KC_Z_CT,     KC_X,           KC_C,     KC_V,      KC_B,   CTL_SS,  WN_GRV,           KC_N,       KC_M,    KC_COMM,   KC_DOT,  KC_SSCT,
    KC_ESC,    KC_APP, LGUI_T(KC_DEL), KC_L1SPC, KC_AJDESC,  KC_LCTL, KC_RALT, RSFT_T(KC_SPC),    KC_L2ET,    KC_RGUI,   WNQUOT,    KC_RO
  ),

  [_LOWER] = LAYOUT(
              KC_1,             KC_2,     KC_3,    KC_4,    KC_5,                        KC_6,      KC_7,     KC_8,     KC_9,      KC_0,
    LSFT_T(KC_TAB), LALT_T(KC_LANG2), KC_LANG1, KC_MINS,  KC_F10,                     KC_LEFT,   KC_DOWN,    KC_UP,  KC_RGHT,    WNQUOT,
           KC_LCTL,            GUI_X,    GUI_C,   GUI_V,   XXXXX,   XXXXX, WN_BSLS,     GUI_N,    KC_DEL,  _______,  _______,   _______,
             XXXXX,            XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX, KC_RALT,   _______,   KC_BSPC,    CMDSP,  JP_DQUO,   JP_UNDS
  ),

  [_RAISE] = LAYOUT(
           KC_EXLM,          JP_AT,  KC_HASH,   JP_DLR, KC_PERC,                  JP_CIRC, JP_AMPR,    LPLT,      RPGT,  JP_ASTR,
    LSFT_T(KC_TAB), LALT_T(KC_F12),  KC_ZKHK,  KC_LGUI,  JP_YEN,                  JP_ASTR,  JP_EQL, JP_LBRC,   JP_RBRC,  JP_PIPE,
           KC_LCTL,          XXXXX, DISPLAYL, DISPLAYR,   XXXXX, JP_TILD,   XXXXX,  KC_RO, JP_PLUS, JP_LCBR,   JP_RCBR, MAC_BSLS,
            KC_ESC,         KC_TAB,  KC_LGUI,   ALTLAN, KC_LALT, KC_LCTL,   XXXXX,  XXXXX,   XXXXX,   XXXXX,     XXXXX,    XXXXX
  ),

  [_ADJUST] = LAYOUT(
             KC_F1,          KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10,
    LSFT_T(KC_F11), LALT_T(KC_F12),  GUI_BS,   XXXXX,  SGUI_2,                   KC_HOME, KC_PGDOWN, KC_PGUP,  KC_END, JP_DQUO,
             GUI_Z,          GUI_X,   GUI_C,   GUI_V,   XXXXX,   XXXXX,   XXXXX,  NOTION,      ESCM,   KC_LT,   KC_GT, KC_QUES,
             XXXXX,          XXXXX,   XXXXX,     QAA,   XXXXX, KC_LCTL, KC_RALT, _______,   _______,  SGUI_5,  ALT_PS, KC_CAPS
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_L1SPC:
      return TAPPING_LAYER_TERM;
    case KC_AJDESC:
      return TAPPING_LAYER_TERM;
    case KC_L2ET:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool     lshift = false;
  static bool     rshift = false;

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case WN_BSLS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code (KC_RSFT);
            register_code(KC_INT3);
            unregister_code(KC_INT3);
            unregister_code (KC_RSFT);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          register_code (KC_RALT);
          register_code(KC_INT3);
          unregister_code(KC_INT3);
          unregister_code (KC_RALT);
        }
      }
      return false;
      break;
    case WN_GRV:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code (KC_RSFT);
            register_code(KC_EQL);
            unregister_code(KC_EQL);
            unregister_code (KC_RSFT);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          // SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_LBRC) SS_UP(X_LBRC) SS_UP(X_LSHIFT));
          register_code (KC_RSFT);
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
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
    case ESCF:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_ESCAPE) SS_TAP(X_F) SS_UP(X_ESCAPE));
      } else {
        //released
      }
      return false;
      break;
    case ESCM:
      if (record->event.pressed) {
        //released
        SEND_STRING(SS_DOWN(X_ESCAPE) SS_TAP(X_M) SS_UP(X_ESCAPE));
      } else {
        //released
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
