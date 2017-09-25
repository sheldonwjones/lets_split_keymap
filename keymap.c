#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _ARW 1
#define _SYM 2
#define _NUM 3
#define _FUN 4
#define _GUI 5
#define _LT 6
#define _GT 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum custom_macros {
  LALT_LT,
  RALT_GT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define CTL_Z       CTL_T(KC_Z)                 // Tap for Z, hold for Ctrl
#define CTL_SLS     RCTL_T(KC_SLSH)             // Tap for /, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)

#define I3_0        LALT(KC_0)                  // i3wm desktop 0
#define I3_1        LALT(KC_1)                  // i3wm desktop 1
#define I3_2        LALT(KC_2)                  // i3wm desktop 2
#define I3_3        LALT(KC_3)                  // i3wm desktop 3
#define I3_4        LALT(KC_4)                  // i3wm desktop 4
#define I3_5        LALT(KC_5)                  // i3wm desktop 5
#define I3_6        LALT(KC_6)                  // i3wm desktop 6
#define I3_7        LALT(KC_7)                  // i3wm desktop 7
#define I3_8        LALT(KC_8)                  // i3wm desktop 8
#define I3_9        LALT(KC_9)                  // i3wm desktop 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   [  |   {  | Alt< | GUI  |Space | Tab  | | Enter| Bksp | GUI  | Alt> |   }  |  ]   |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  MEH_GRV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  CTL_ESC, F(_ARW), F(_SYM), F(_NUM), KC_F,    F(_GUI), KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSPC, \
  KC_LBRC, KC_LCBR, F(_LT),  KC_LGUI, KC_SPC,  KC_TAB,  KC_ENT,  KC_BSPC, KC_RGUI, F(_GT),  KC_RCBR, KC_RBRC
),

/* Arrow
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | ARW  |      |      |      |      | | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |AGnorm|AGswap|      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ARW] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, AG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Symbols
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |   =  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | SYM  |      |      |      | |   ~  |   $  |   %  |   ^  |   |  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   +  |   !  |   @  |   #  |   /  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_SYM] = KEYMAP( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
  _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, S(KC_4), S(KC_5), S(KC_6), KC_PIPE, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, S(KC_1), S(KC_2), S(KC_3), _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numbers
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |   =  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      | NUM  |      |      | |   *  |   4  |   5  |   6  |   .  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   +  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUM] = KEYMAP( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* GUI
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |alt(7)|alt(8)|alt(9)|alt(0)|      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      | GUI  | |      |alt(4)|alt(5)|alt(6)|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |alt(1)|alt(2)|alt(3)|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_GUI] = KEYMAP( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, I3_7,    I3_8,    I3_9,    I3_0,    _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, I3_4,    I3_5,    I3_6,    XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, I3_1,    I3_2,    I3_3,    XXXXXXX, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const uint16_t PROGMEM fn_actions[] = {
    [_ARW] = ACTION_LAYER_TAP_KEY(_ARW, KC_A),
    [_SYM] = ACTION_LAYER_TAP_KEY(_SYM, KC_S),
    [_NUM] = ACTION_LAYER_TAP_KEY(_NUM, KC_D),
    [_GUI] = ACTION_LAYER_TAP_KEY(_GUI, KC_G),
    [_LT] = ACTION_MACRO_TAP(LALT_LT),
    [_GT] = ACTION_MACRO_TAP(RALT_GT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case LALT_LT:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui) {
          register_mods(MOD_LGUI);
        } else {
          register_mods(MOD_LALT);
        }
        record->tap.interrupted = 0;
      } else {
        if (keymap_config.swap_lalt_lgui) {
          unregister_mods(MOD_LGUI);
        } else {
          unregister_mods(MOD_LALT);
        }

        if (record->tap.count && !record->tap.interrupted) {
          add_weak_mods(MOD_LSFT);
          register_code(KC_COMM);
          unregister_code(KC_COMM);
          del_weak_mods(MOD_LSFT);
        }

        record->tap.count = 0;
      }
      break;

    case RALT_GT:
      if (record->event.pressed) {
        if (keymap_config.swap_ralt_rgui) {
          register_mods(MOD_RGUI);
        } else {
          register_mods(MOD_RALT);
        }
        record->tap.interrupted = 0;
      } else {
        if (keymap_config.swap_ralt_rgui) {
          unregister_mods(MOD_RGUI);
        } else {
          unregister_mods(MOD_RALT);
        }

        if (record->tap.count && !record->tap.interrupted) {
          add_weak_mods(MOD_RSFT);
          register_code(KC_DOT);
          unregister_code(KC_DOT);
          del_weak_mods(MOD_RSFT);
        }

        record->tap.count = 0;
      }
      break;
  }
  return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
