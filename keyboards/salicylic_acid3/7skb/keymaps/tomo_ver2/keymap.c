
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

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
  QAA,
  DISPLAYL,
  DISPLAYR,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK
};

#define KC_RO KC_INT1

#define CTRTB LCTL_T(KC_TAB)
#define GUIDEL LGUI_T(KC_DEL)
#define GUISP LGUI_T(KC_SPC)
#define ALTSP LALT_T(KC_SPC)
#define ALTDEL LALT_T(KC_DEL)
#define ALTBS LALT_T(KC_BSPC)
#define SFTBS RSFT_T(KC_BSPC)
#define AJESC LT(_ADJUST,KC_ESC)
#define AJSP LT(_ADJUST,KC_SPC)
#define SFTET RSFT_T(KC_ENT)
#define SFTRO RSFT_T(KC_RO)
#define SF2SP LSFT_T(KC_SPC)

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

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)
#define SFTSP LSFT(KC_SPC)


/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make salicylic_acid3/7skb/rev1:tomo_ver2
 *
 * Upload command
 * $ make salicylic_acid3/7skb/rev1:tomo_ver2:avrdude
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
        CTRTB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, LT(_ADJUST, KC_DEL),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
             KC_LALT, KC_LGUI, LT(_ADJUST, KC_SPC),  SF2SP,    LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_RGUI, KC_RALT
          //`---------------------------------------------|   |----------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-------------------------------------------------------|   |--------------------------------------------------------------------------------.
       JPZKHK,   KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_NO,   KC_NO,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO,   KC_NO, _______,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LABK,  KC_RABK,  KC_QUES, KC_MINS, KC_PLUS,     KC_ASTR, KC_COLN, KC_LBRC, KC_RBRC,  JP_YEN,   KC_NO, _______,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_COMM,   KC_DOT,  KC_SLSH,  KC_UNDS, KC_EQL,       KC_NO, KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE, _______,  KC_DEL,
  //|--------+--------+---------+---------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                       JIS_TO_US,  _______,  KC_SPC, KC_LSFT,       KC_NO,   KC_NO,   KC_NO,   KC_NO
          //`-----------------------------------------------|   |--------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,------------------------------------------------------|   |--------------------------------------------------------------------------------.
       JPZKHK,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_NO,   KC_NO,
  //|--------+---------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TILD,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSLS,   KC_NO,   KC_NO, _______,
  //|--------+---------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_NO,   KC_NO,   KC_NO,  KC_DQT,  KC_EQL,     KC_ASTR, KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE,   KC_NO, _______,
  //|--------+---------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_NO,   KC_NO,   KC_NO, KC_QUOT, KC_PLUS,       KC_NO, KC_COLN,   KC_NO,   KC_NO,   KC_NO, _______,  KC_DEL,
  //|--------+---------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                       US_TO_JIS, _______,   SFTSP, KC_LSFT,       KC_NO,   KC_NO,   KC_NO,   KC_NO
          //`----------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,---------------------------------------------------------------|   |--------------------------------------------------------------------------------.
        JPZKHK,          KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  ALT_PS,
  //|---------+---------------+----------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       _______,          KC_NO,     KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,   KC_NO, _______,
  //|---------+---------------+----------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
LCTL_T(KC_F11), LSFT_T(KC_F12),    SGUI_L,  GUI_BS, KC_LGUI,   KC_NO,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_MINS,   KC_NO, ALT_ENT,
  //|---------+---------------+----------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
       _______,          KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_UNDS,  KC_DEL, KC_LABK, KC_RABK, KC_QUES, _______, KC_CAPS,
  //|---------+---------------+----------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                    KC_NO, QK_BOOT,   KC_NO,   KC_NO,       CMDSP, KC_BSPC, _______, _______
                  //`-----------------------------------------------|   |--------------------------------------------'
  )
};


void set_keyboard_lang_color(void) {
#ifdef RGBLIGHT_ENABLE
  if (user_config.jis) {
    rgblight_sethsv_at(HSV_CYAN, 0);
  } else {
    rgblight_sethsv_at(HSV_PURPLE, 0);
  }
#endif
}

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  //state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _LOWER:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _RAISE:
      rgblight_sethsv_at(HSV_GREEN, 0);
      break;
    case _ADJUST:
      rgblight_sethsv_at(HSV_ORANGE, 0);
      break;
    default: //  for any other layers, or the default layer
      //rgblight_sethsv_at( 0, 0, 0, 0);
      set_keyboard_lang_color();
      break;
    }
    rgblight_set_effect_range( 1, 5);
#endif
return state;
}

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

void keyboard_post_init_user(void) {
 // load_persistent();
  set_keyboard_lang_color();
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

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;

  switch (keycode) {
    case US_TO_JIS:
        set_keyboard_lang_to_jis(true);
        set_keyboard_lang_color();
        return false;
    case JIS_TO_US:
        set_keyboard_lang_to_jis(false);
        set_keyboard_lang_color();
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
      if (user_config.jis) {
        return twpair_on_jis(keycode, record);
      } else {
        result = true;
        break;
      }
  }

  return result;
}
