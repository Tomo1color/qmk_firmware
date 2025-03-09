
#include QMK_KEYBOARD_H
//#include "keymap_jp.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  WN_SCLN,          // タップでJISの「;」  シフトでJISの「:」 (JIS)
  WN_QUOT,          // タップでJISの「'」  シフトでJISの「"」 (JIS)
  WN_MINS,          // タップでJISの「-」  シフトでJISの「_」 (JIS)
  WN_EQL,           // タップでJISの「=」  シフトでJISの「+」 (JIS)
  WN_BSLS,          // タップで USの「\」  シフトでJISの「|」 (JIS)
  WN_GRV,           // タップでJISの「`」  シフトでJISの「~」 (JIS)
  WN_LPLT,          // ( or < with shift (JIS)
  WN_RPGT,           // ) or > with shift (JIS)
  QAA,
  NOTION,
  DISPLAYL,
  DISPLAYR
};


#define CTRTB LCTL_T(KC_TAB)
#define GUIDEL LGUI_T(KC_DEL)
#define GUISP LGUI_T(KC_SPC)
#define ALTSP LALT_T(KC_SPC)
#define ALTDEL LALT_T(KC_DEL)
#define ALTBS LALT_T(KC_BSPC)
#define SFTSP RSFT_T(KC_SPC)
#define SFTBS RSFT_T(KC_BSPC)
#define AJESC LT(_ADJUST,KC_ESC)
#define SFTET RSFT_T(KC_ENT)
#define SFTRO RSFT_T(KC_RO)

#define ALTLAN LALT(KC_SPC)
#define GUI_A LGUI(KC_A)            // GUI + A
#define GUI_S LGUI(KC_S)            // GUI + S
#define GUI_Z LGUI(KC_Z)            // GUI + Z
#define GUI_X LGUI(KC_X)            // GUI + X
#define GUI_C LGUI(KC_C)            // GUI + C
#define GUI_V LGUI(KC_V)            // GUI + V
#define GUI_N LGUI(KC_N)            // GUI + N
#define GUI_BS LGUI(KC_BSPC)        // GUI + BS
#define GUI_LC LGUI(JP_LCBR)        // GUI + {
#define GUI_RC LGUI(JP_RCBR)        // GUI + }
#define CTL_F5 LCTL(KC_F5)          // Ctr + F5
#define CMDSP LGUI(KC_SPC)          // GUI + Space
#define ALT_ENT LALT(KC_ENT)        // Alt + Enter
#define ALT_PS LALT(KC_PSCR)        // Alt + Print Screen
#define SGUI_2 SGUI(KC_2)
#define SGUI_5 SGUI(KC_5)        // Screen Shot

#define JPBSLS LALT(JP_YEN)
#define JPUNDS LSFT(JP_BSLS)

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


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make 7skb:mac_jis
 *
 * Upload command
 * $ make 7skb:mac_jis:avrdude
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,------------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, WN_MINS,  WN_EQL, WN_BSLS,  WN_GRV,
  //|--------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC, KC_BSPC,
  //|--------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------+--------|
        CTRTB,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,        KC_H,    KC_J,    KC_K,    KC_L, WN_SCLN, WN_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   SFTRO, LT(_ADJUST,KC_DEL),
  //|--------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------|
                KC_APP,  GUIDEL, LT(_LOWER, KC_SPC),  ALTSP,       SFTSP, LT(_RAISE, KC_ENT), KC_RGUI, KC_RALT
          //`----------------------------------------------|   |----------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-------------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_ZKHK,   KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  GUI_LC,  GUI_RC, _______,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL, KC_LSFT, KC_LANG2,   KC_F10, KC_MINS, XXXXXXX,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, JP_COLN, JP_DQUO, ALT_ENT,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,   GUI_Z,    GUI_X,    GUI_C,   GUI_V, XXXXXXX,       GUI_N,  KC_DEL, KC_PGDN, KC_PGUP, XXXXXXX,  JPUNDS, _______,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______,    RESET,  XXXXXXX, _______,                CMDSP, KC_BSPC,          _______, _______
          //`-----------------------------------------------|   |--------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   JP_AT, KC_HASH,  JP_DLR, KC_PERC,     JP_CIRC, JP_AMPR, WN_LPLT, WN_RPGT, JP_ASTR,  JP_YEN, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,  KC_F12, KC_ZKHK, KC_ZKHK, XXXXXXX,  JP_YEN,     JP_ASTR,  JP_EQL, JP_LBRC, JP_RBRC, JP_PIPE,  JP_GRV, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,DISPLAYL,DISPLAYR, XXXXXXX,       KC_RO, JP_PLUS, JP_LCBR, JP_RCBR,  JPBSLS, JP_TILD, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,  ALTLAN, _______,              _______, XXXXXXX,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  SGUI_5,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,  ALT_PS,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______,  GUI_BS, _______,  SGUI_2,     KC_HOME, _______, _______,  KC_END, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,      NOTION, _______, _______, _______, _______, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,     QAA, _______,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  //state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _LOWER:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _RAISE:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _ADJUST:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 5);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;

  static bool lshift = false;
  static bool rshift = false;


  switch (keycode) {
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
    case WN_EQL:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
            register_code (KC_RSFT);
            register_code(KC_SCLN);
            unregister_code(KC_SCLN);
            unregister_code (KC_RSFT);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        } else {
          register_code (KC_RSFT);
          register_code(KC_MINS);
          unregister_code(KC_MINS);
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
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}
