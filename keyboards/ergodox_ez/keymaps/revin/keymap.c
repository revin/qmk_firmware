#include "ergodox_ez.h"
#include "version.h"
/*
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
*/

enum layers {
  BASE = 0,
  SHIFTED,
  ARROWS,
  FN_TENKEY,
  EMOJI,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | TT 3 |           |CtCmSp|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Ctrl/' |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |Shft/ENT|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctrl-C| CS-[ | CS-] | Alt  | Cmd  |                                       |Space |   +  |   *  |   \  | BkSp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        | CS-4 | Cmd-\ |       | Cmd-' | CS-= |
 *                                 ,------|------|-------|       |-------+------+------.
 *                                 |      |      | Cmd-` |       | Cmd-; |      |      |
 *                                 | Meh  | MO 1 |-------|       |-------| MO 2 |Hyper |
 *                                 |      |      |C-Right|       | C-Left|      |      |
 *                                 `---------------------'       `---------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE,         KC_1,                    KC_2,                    KC_3,    KC_4,    KC_5, TT(3),
  KC_TAB,           KC_Q,                    KC_W,                    KC_E,    KC_R,    KC_T, KC_LBRACKET,
  CTL_T(KC_ESCAPE), KC_A,                    KC_S,                    KC_D,    KC_F,    KC_G,
  SFT_T(KC_NO),     KC_Z,                    KC_X,                    KC_C,    KC_V,    KC_B, KC_LPRN,
    LCTL(KC_C),     LGUI(LSFT(KC_LBRACKET)), LGUI(LSFT(KC_RBRACKET)), KC_LALT, KC_LGUI,

                                                                      LGUI(LSFT(KC_4)), LGUI(KC_BSLASH),
                                                                                        LGUI(KC_GRAVE),
                                                                      KC_MEH,  MO(1),   LCTL(KC_RIGHT),

  // right hand
  LCTL(LGUI(KC_SPACE)), KC_6,     KC_7,     KC_8,       KC_9,           KC_0,      KC_MINUS,
  KC_RBRACKET,          KC_Y,     KC_U,     KC_I,       KC_O,           KC_P,      KC_EQUAL,
                        KC_H,     KC_J,     KC_K,       KC_L,           KC_SCOLON, RCTL_T(KC_QUOTE),
  KC_RPRN,              KC_N,     KC_M,     KC_COMMA,   KC_DOT,         KC_SLASH,  RSFT_T(KC_ENTER),
                                  KC_SPACE, KC_KP_PLUS, KC_KP_ASTERISK, KC_BSLASH, KC_BSPACE,

  RGUI(KC_QUOTE),       RGUI(RSFT(KC_EQUAL)),
  RGUI(KC_SCOLON),
  LCTL(KC_LEFT),        MO(2),    KC_HYPR),

/* Keymap 1: Shifted Punctuation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Home |           | PgUp |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * |        |      |      |      |      |   <  |      |           |      |   >  |      |      |      |      | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      | BkSp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      | Alt- | Alt- |
 *                                 |      | /M1/ |------|       |------| Left | Right|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SHIFTED] = LAYOUT_ergodox(
  // left hand
  _______,   _______, _______, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, KC_HOME,
  _______,   KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC,
  _______,   _______, _______, _______, _______, KC_LABK, KC_END,
    _______, _______, _______, _______, _______,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

  // right hand
  _______,   _______, _______, _______, _______, _______, _______,
  KC_PGUP,   _______, _______, _______, _______, _______, _______,
             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_PGDOWN, KC_RABK, _______, _______, _______, _______, KC_ENTER,
                      _______, _______, _______, _______, KC_BSPACE,

  _______,   _______,
  _______,
  _______, LALT(KC_LEFT), LALT(KC_RIGHT)
),

/* Keymap 2: Arrows & Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Home |           | PgUp |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft| MsUp |MsDown|MsRght|------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |S-PgUp|      |      |      | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |S-PgDn|      |      |      | BkSp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Cmd- | Cmd- |      |       |      |      |      |
 *                                 | Left | Right|------|       |------| /M2/ |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARROWS] = LAYOUT_ergodox(
  // left hand
  _______,   _______, _______,    _______,  _______,       _______,        _______,
  _______,   _______, _______,    _______,  _______,       _______,        KC_HOME,
  _______,   _______, KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN,    KC_MS_RIGHT,
  _______,   _______, _______,    _______,  _______,       _______,        KC_END,
    _______, _______, _______,    _______,  _______,

                                                           _______,        _______,
                                                                           _______,
                                            LGUI(KC_LEFT), LGUI(KC_RIGHT), _______,

  // right hand
  _______,   _______, _______,         _______, _______,  _______, _______,
  KC_PGUP,   _______, _______,         _______, _______,  _______, _______,
             KC_LEFT, KC_DOWN,         KC_UP,   KC_RIGHT, _______, _______,
  KC_PGDOWN, _______, RSFT(KC_PGUP),   _______, _______,  _______, KC_ENTER,
                      RSFT(KC_PGDOWN), _______, _______,  _______, KC_BSPACE,

  _______,   _______,
  _______,
  _______,   _______, _______
),

/* Keymap 3: Function keys & 10-key pad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   *  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | To 0   |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  | BkSp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+-----.
 *                                 |      |      |      |       |      |      |     |
 *                                 |      |      |------|       |------|Enter | Spc |
 *                                 |      |      |      |       |      |      |     |
 *                                 `--------------------'       `-------------------'
 */
[FN_TENKEY] = LAYOUT_ergodox(
  // left hand
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______,   _______, _______, _______, _______, _______, _______,
  TO(0),     _______, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

  // right hand
  _______, KC_F6,       KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,
  _______, _______,     KC_7,    KC_8,    KC_9,      KC_ASTR,    KC_F12,
           _______,     KC_4,    KC_5,    KC_6,      KC_KP_PLUS, _______,
  _______, _______,     KC_1,    KC_2,    KC_3,      KC_SLASH,   KC_KP_ENTER,
                        KC_KP_0, KC_KP_0, KC_KP_DOT, KC_EQUAL,   KC_BSPACE,

  _______, _______,
  _______,
  _______, KC_KP_ENTER, KC_SPACE
),

};

bool suspended = false;
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
