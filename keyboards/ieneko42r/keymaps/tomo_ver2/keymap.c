/* SPDX-License-Identifier: GPL-2.0-or-later */

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
  RGB_RST = SAFE_RANGE,
  US_TO_JIS,
  JIS_TO_US,
  JPZKHK,
  QAA,
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
#define SFTSPC LSFT(KC_SPC)

#define JP_YEN  KC_INT3       // ¥
#define SGUI_L SGUI(KC_LEFT)
#define SFTSP LSFT(KC_SPC)

/**
 * Keycodes Overview
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * Build command
 * qmk compile -kb ieneko42r -km tomo_ver2
 *
 * make ieneko42r:tomo_ver2
 *
 * Flashing example for this keyboard:
 *
 * make ieneko42r:tomo_ver2:flash
 *
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
    KC_ESC,               KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P, KC_BSPC,
		MT(MOD_LCTL, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_ENT,
		KC_LSFT,              KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),
		KC_LCTL, MT(MOD_LALT, KC_DEL), KC_LGUI, LT(3,KC_SPC), LT(1, KC_SPC), MO(2), KC_RALT, MT(MOD_RCTL, KC_APP)
	),

	[1] = LAYOUT(
	  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
		KC_LCTL, KC_LABK, KC_RABK, KC_QUES, KC_MINS, KC_PLUS, KC_ASTR, KC_COLN, KC_LBRC, KC_RBRC, JP_YEN,
	  _______, KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS, KC_EQL,  KC_NO,   KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE,
    JIS_TO_US, _______, _______, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO
	),

	[2] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSLS,  _______,
    KC_LCTL, KC_NO, KC_NO,   KC_NO,   KC_DQT,  KC_EQL,  KC_ASTR, KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_NO,   KC_NO, KC_NO,   KC_QUOT, KC_PLUS, KC_NO,   KC_COLN,   KC_NO,   KC_NO,   KC_NO,
    US_TO_JIS, _______, _______, SFTSP, KC_NO, KC_NO, KC_NO, KC_NO
	),

	[3] = LAYOUT(
    JPZKHK,         KC_NO,          KC_F2,   KC_F3,  KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, ALT_PS,
    LCTL_T(KC_F11), LSFT_T(KC_F12), SGUI_L,  GUI_BS, KC_LGUI, KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
    _______,        KC_NO,          KC_NO,   KC_NO,  KC_NO,   KC_NO, KC_UNDS, KC_DEL,  _______, _______, _______,
    KC_NO, QK_BOOT, KC_NO, KC_NO, KC_BSPC, KC_RGUI, KC_RALT, KC_RCTL
	)
};

led_config_t g_led_config = { {
	// Key Matrix to LED Index
	{ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, },
	{12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, },
	{23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, },
	{34, 35, 36, 37, 38, 39, 40, 41 },
}, {
  // LED Index to Physical Position
	{0,0}, {20.36,0}, {40.73,0}, {61.09,0}, {81.45,0}, {101.82,0}, {122.18,0}, {142.55,0}, {162.91,0}, {183.27,0}, {203.64,0}, {224,0},
	{5.09,21.33}, {25.45,21.33}, {45.82,21.33}, {66.18,21.33}, {86.54,21.33}, {106.91,21.33}, {127.27,21.33}, {147.64,21.33}, {168,21.33}, {188.36,21.33}, {224,21.33},
	{15.27,42.67}, {35.63,42.67}, {56,42.67}, {76.36,42.67}, {96.72,42.67}, {117.09,42.67}, {137.45,42.67}, {157.82,42.67}, {178.18,42.67}, {198.54,42.67}, {224,42.67},
	{0,64}, {25.45,64}, {45.82,64}, {101.82,64}, {147.63,64}, {168,64}, {193.45,64}, {224,64}
}, {
  	// LED Index to Flag
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	2, 2, 2, 2, 2, 2, 2, 2
  }
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  int is_layer = get_highest_layer(layer_state|default_layer_state);
  HSV hsv = {0, 255, rgblight_get_val()};
  if (is_layer == 1) {
	hsv.h = 128; //CYAN
  } else if (is_layer == 2)  {
    hsv.h = 85; //GREEN
  } else if (is_layer == 3)  {
    hsv.h = 43; //YELLOW
  } else if (is_layer == 4)  {
    hsv.h = 21; //ORANGE
  } else {
    hsv.h = 191; //PURPLE
  }
  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i <= led_max; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
  return false;
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

//
void set_keyboard_lang_color(void) {
  // rgb_matrix_disable_noeeprom(); // disables Rgb, without saving settings
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  HSV hsv = {0, 255, rgblight_get_val()};

  if (user_config.jis) {
    hsv.h = 191;
  } else {
    hsv.h = 0;
    hsv.s = 0;
  }
  rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
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
