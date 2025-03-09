/* Copyright 2018 Carlos Filoteo
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

extern keymap_config_t keymap_config;


typedef union {
  uint32_t raw;
  struct {
    bool jis :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK,
  QAA,
  DISPLAYL,
  DISPLAYR
};

#define SF2SP LSFT_T(KC_SPC)

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

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)

/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * $ make keyhive/ut472:tomo_ver3
 *
 * Upload command
 * $ make keyhive/ut472:tomo_ver3:dfu
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		       KC_ESC,           KC_Q,    KC_W,      KC_E,        KC_R,    KC_T,    KC_Y,          KC_U,             KC_I,    KC_O,    KC_P,  KC_BSPC,
		MT(MOD_LCTL, KC_TAB),    KC_A,    KC_S,      KC_D,        KC_F,    KC_G,    KC_H,          KC_J,             KC_K,    KC_L, KC_SCLN,  KC_QUOT,
		      KC_LSFT,           KC_Z,    KC_X,      KC_C,        KC_V,    KC_B,    KC_N,          KC_M,          KC_COMM,  KC_DOT, KC_SLSH,   KC_DEL,
		        KC_NO,     KC_LCTL, KC_LALT, KC_LGUI,  LT(1, KC_SPC),        SF2SP,     LT(2, KC_ENT),   MO(3), KC_DOWN,   KC_UP,    KC_NO
	),

	[1] = LAYOUT(
	   JPZKHK,    KC_1,    KC_2,     KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
		KC_LCTL, KC_LSFT,  SGUI_L,  GUI_BS,  KC_LGUI,    KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_MINS, ALT_ENT,
	  _______,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_UNDS,  KC_DEL, _______, _______, KC_TILD, _______,
	  KC_NO,   KC_NO,  QK_BOOT,   KC_NO,     KC_NO,         CMDSP,     KC_BSPC,   KC_RGUI, KC_RALT, KC_LCTL,   KC_NO
	),

	[2] = LAYOUT(
		KC_GRV,             KC_EXLM,   KC_AT,  KC_HASH,   KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, _______,
	 KC_LCTL, MT(MOD_LSFT,KC_F12),   KC_NO,  KC_QUOT,   KC_DQT,  JP_YEN, KC_ASTR,  KC_EQL, KC_LBRC, KC_RBRC, KC_PIPE, _______,
	 _______,               KC_NO,   KC_NO, DISPLAYL, DISPLAYR,   KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS, _______,
 US_TO_JIS,             KC_LALT, KC_LGUI,   JPZKHK,         KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
	),

	[3] = LAYOUT(
		         KC_NO,          KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  ALT_PS,
		LCTL_T(KC_F11), LSFT_T(KC_F12),   KC_NO,   KC_NO, KC_LGUI,     KC_NO,     KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,
		         KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		     JIS_TO_US,        KC_LALT,     QAA,   KC_NO,   KC_NO,           KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_CAPS
	),

	[4] = LAYOUT(
		TO(0), US_TO_JIS, JIS_TO_US,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   RGB_VAI,   RGB_SAI, RGB_HUI, RGB_SPI,  RGB_MOD, RGB_TOG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   RGB_VAD,   RGB_SAD, RGB_HUD, RGB_SPD, RGB_RMOD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  EE_CLR,   KC_NO,
		KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,         KC_NO,       KC_NO,   KC_NO,   KC_NO, QK_BOOT,   KC_NO
	)
};


void set_keyboard_lang_color(void) {
  // rgb_matrix_disable_noeeprom(); // disables Rgb, without saving settings
  // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  HSV hsv = {0, 255, rgblight_get_val()};

  if (user_config.jis) {
    hsv.h = 191;
  } else {
    hsv.h = 0;
    hsv.s = 0;
  }
  // rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
  rgblight_sethsv_at(hsv.h, hsv.s, hsv.v, 0);
}

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  //state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case 1:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case 2:
      rgblight_sethsv_at(HSV_GREEN, 0);
      break;
    case 3:
      rgblight_sethsv_at(HSV_ORANGE, 0);
      break;
    case 4:
      rgblight_sethsv_at(HSV_YELLOW, 0);
      break;
   default: //  for any other layers, or the default layer
      //rgblight_sethsv_at( 0, 0, 0, 0);
      set_keyboard_lang_color();
      break;
    }
    rgblight_set_effect_range(1, 7);
    // rgblight_sethsv_range(HSV_OFF, 0, 4);
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
    save_persistent();
}

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
    default:
      //return twpair_on_jis(keycode, record);
      if (user_config.jis) {
        return twpair_on_jis(keycode, record);
      } else {
        result = true;
        break;
      }
  }
  return result;
}
