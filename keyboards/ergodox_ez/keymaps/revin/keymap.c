#include "ergodox_ez.h"
#include "version.h"
#include "action_layer.h"
#include "process_unicodemap.h"

enum layers {
  BASE = 0,
  SHIFTED,
  ARROWS,
  FN_TENKEY,
  EMOJI,
};

enum combos {
  DOUBLE_BRACKETS,
};

const uint16_t PROGMEM double_brackets_combo[] = {KC_LBRACKET, KC_RBRACKET, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DOUBLE_BRACKETS] = COMBO_ACTION(double_brackets_combo),
};

enum unicode_names {
  ANGRY,
  ARLFT,
  ARRGT,
  CONFU,
  ELLIP,
  FIRE,
  FLUSH,
  GRIMC,
  HEART,
  HORSE,
  HUH,
  HUND,
  NDASH,
  MDASH,
  PARTY,
  RLEYE,
  ROBOT,
  SOB,
  SHRUG,
  SPARK,
  TEAR,
  THINK,
  UDFAC,
};

const uint32_t PROGMEM unicode_map[] = {
  [ANGRY] = 0x1F620,
  [ARLFT] = 0x2B05,
  [ARRGT] = 0x27A1,
  [CONFU] = 0x1F615,
  [ELLIP] = 0x2026,
  [FIRE]  = 0x1F525,
  [FLUSH] = 0x1F633,
  [GRIMC] = 0x1F62C,
  [HEART] = 0x1F49C,
  [HORSE] = 0x1F434,
  [HUH]   = 0x2049,
  [HUND]  = 0x1F4AF,
  [NDASH] = 0x2013,
  [MDASH] = 0x2014,
  [PARTY] = 0x1F389,
  [RLEYE] = 0x1F644,
  [ROBOT] = 0x1F916,
  [SOB]   = 0x1F62D,
  [SHRUG] = 0x1F937,
  [SPARK] = 0x2728,
  [TEAR]  = 0x1F622,
  [THINK] = 0x1F914,
  [UDFAC] = 0x1F643,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  U_BICEP,
  U_DANCE,
  U_FIST,
  U_FNGR2,
  U_HIFIV,
  U_THMBU,
  U_THMBD,
  U_WAVE,
  U_WLIFT,
  JSARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |TTFN10|           |CtCmSp|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Ctrl/' |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CS-[ | CS-] |Ctrl-C| Alt  |MOShft|                                       |MO Arr|   +  |   *  |   \  | BkSp |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.     ,--------------.
 *                                        | CS-4 | Cmd-\ |     | Cmd-' | CS-= |
 *                                 ,------|------|-------|     |-------+------+------.
 *                                 |      | Meh/ | Cmd-` |     | Cmd-; |Hyper/| Cmd/ |
 *                                 | Cmd  |Enter |-------|     |-------|Enter |Space |
 *                                 |      |      |C-Left |     |C-Right|      |      |
 *                                 `---------------------'     `---------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE,                  KC_1,                    KC_2,       KC_3,    KC_4,        KC_5, TT(FN_TENKEY),
  KC_TAB,                    KC_Q,                    KC_W,       KC_E,    KC_R,        KC_T, KC_LBRACKET,
  CTL_T(KC_ESCAPE),          KC_A,                    KC_S,       KC_D,    KC_F,        KC_G,
  SFT_T(KC_NO),              KC_Z,                    KC_X,       KC_C,    KC_V,        KC_B, KC_LPRN,
    LGUI(LSFT(KC_LBRACKET)), LGUI(LSFT(KC_RBRACKET)), LCTL(KC_C), KC_LALT, MO(SHIFTED),

                                                                      LGUI(LSFT(KC_4)), LGUI(KC_BSLASH),
                                                                                         LGUI(KC_GRAVE),
                                                             KC_LCMD,  MEH_T(KC_ENTER),   LCTL(KC_LEFT),

  // right hand
  LCTL(LGUI(KC_SPACE)), KC_6,     KC_7,       KC_8,       KC_9,           KC_0,      KC_MINUS,
  KC_RBRACKET,          KC_Y,     KC_U,       KC_I,       KC_O,           KC_P,      KC_EQUAL,
                        KC_H,     KC_J,       KC_K,       KC_L,           KC_SCOLON, RCTL_T(KC_QUOTE),
  KC_RPRN,              KC_N,     KC_M,       KC_COMMA,   KC_DOT,         KC_SLASH,  KC_RSHIFT,
                                  MO(ARROWS), KC_KP_PLUS, KC_KP_ASTERISK, KC_BSLASH, KC_BSPACE,

  RGUI(KC_QUOTE),  RGUI(RSFT(KC_EQUAL)),
  RGUI(KC_SCOLON),
  LCTL(KC_RIGHT),  HYPR_T(KC_ENTER), CMD_T(KC_SPACE)),

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
 *   |      |      |      |      | /M/  |                                       |MOEmoj|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  |      |      |      |     |      | Alt- | Alt- |
 *                                  |      |      |------|     |------| Left | Right|
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[SHIFTED] = LAYOUT_ergodox(
  // left hand
  _______,   _______, _______, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, KC_HOME,
  _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
  _______,   _______, _______, _______, _______, KC_LABK, KC_END,
    _______, _______, _______, _______, _______,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

  // right hand
  _______,   _______, _______,   _______, _______, _______, _______,
  KC_PGUP,   _______, _______,   _______, _______, _______, _______,
             KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_PGDOWN, KC_RABK, _______,   _______, _______, _______, KC_ENTER,
                      MO(EMOJI), _______, _______, _______, _______,

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
 * |        |      |      |S-PgDn|S-PgUp|      |      |           |      |      |      |      |      |      | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |MOEmoj|                                       | /M/  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  | Cmd- | Cmd- |      |     |      |      |      |
 *                                  | Left | Right|------|     |------|      |      |
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[ARROWS] = LAYOUT_ergodox(
  // left hand
  _______,   _______, _______,    _______,       _______,       _______,     _______,
  _______,   _______, _______,    _______,       _______,       _______,     KC_HOME,
  _______,   _______, KC_MS_LEFT, KC_MS_UP,      KC_MS_DOWN,    KC_MS_RIGHT,
  _______,   _______, _______,    RSFT(KC_PGDN), RSFT(KC_PGUP), _______,     KC_END,
    _______, _______, _______,    _______,       MO(EMOJI),

                                                           _______,        _______,
                                                                           _______,
                                            LGUI(KC_LEFT), LGUI(KC_RIGHT), _______,

  // right hand
  _______,   _______, _______, _______, _______,  _______, _______,
  KC_PGUP,   _______, _______, _______, _______,  _______, _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  KC_PGDOWN, _______, _______, _______, _______,  _______, KC_ENTER,
                      _______, _______, _______,  _______, _______,

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
 * |To BASE |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+-----.
 *                                  |      |      |      |     |      |      |     |
 *                                  |      |      |------|     |------|Enter | Spc |
 *                                  |      |      |      |     |      |      |     |
 *                                  `--------------------'     `-------------------'
 */
[FN_TENKEY] = LAYOUT_ergodox(
  // left hand
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______,   _______, _______, _______, _______, _______, _______,
  TO(BASE),  _______, _______, _______, _______, _______,
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
                        KC_KP_0, KC_KP_0, KC_KP_DOT, KC_EQUAL,   _______,

  _______, _______,
  _______,
  _______, KC_KP_ENTER, KC_SPACE
),

/* Keymap 4: Unicode / Emoji
 *
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  💯  |  ✌️   |      |      |  🙌  |      |           |      |      |      |      |      |  👊  |   —    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  👋  |  🙄  |  🤖  |  🤔  |  🙃  |           |  👍  |  🤷  |  🏋  |      |  😳  |  🎉  |   –    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |To BASE |  😠  |  ✨  |  💃  |  🔥  |  😬  |------|           |------|  🐴  |      |      |  💜  |      |  =>    |
 * |--------+------+------+------+------+------|      |           |  👎  |------+------+------+------+------+--------|
 * |        |      |  😭  |  😢  |      |  💪  |      |           |      |      |      |      |  …   |  😕  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | /M/  |                                       | /M/  |   ⬅  |  ➡   |      |  ⁉   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  |      |      |      |     |      |      |      |
 *                                  |      |------|      |     |------|      |      |
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[EMOJI] = LAYOUT_ergodox(
  // left hand
  _______,   X(HUND),  U_FNGR2,  _______,  _______,  U_HIFIV,  _______,
  _______,   _______,  U_WAVE,   X(RLEYE), X(ROBOT), X(THINK), X(UDFAC),
  TO(BASE),  X(ANGRY), X(SPARK), U_DANCE,  X(FIRE),  X(GRIMC),
  _______,   _______,  X(SOB),   X(TEAR),  _______,  U_BICEP,  _______,
    _______, _______,  _______,  _______,  _______,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

  // right hand
  _______, _______,  _______,  _______,  _______,   U_FIST,   X(MDASH),
  U_THMBU, X(SHRUG), U_WLIFT,  _______,  X(FLUSH),  X(PARTY), X(NDASH),
           X(HORSE), _______,  _______,  X(HEART),  _______,  JSARROW,
  U_THMBD, _______,  _______,  _______,  X(ELLIP),  X(CONFU), _______,
                     _______,  X(ARLFT), X(ARRGT),  _______,  X(HUH),

  _______, _______,
  _______,
  _______, _______, _______
),

};

bool send_unicode(keyrecord_t *record, char *hex_str) {
  if (record->event.pressed) {
    send_unicode_hex_string(hex_str);
  }
  return true;
}

#define SKIN(emoji_hex_str) (emoji_hex_str " D83C DFFC")

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case U_BICEP: return send_unicode(record, SKIN("D83D DCAA"));
    case U_DANCE: return send_unicode(record, SKIN("D83D DC83"));
    case U_FIST:  return send_unicode(record, SKIN("D83D DC4A"));
    case U_FNGR2: return send_unicode(record, SKIN("270C"));
    case U_HIFIV: return send_unicode(record, SKIN("D83D DE4C"));
    case U_THMBU: return send_unicode(record, SKIN("D83D DC4D"));
    case U_THMBD: return send_unicode(record, SKIN("D83D DC4E"));
    case U_WAVE:  return send_unicode(record, SKIN("D83D DC4B"));
    case U_WLIFT: return send_unicode(record, SKIN("D83C DFCB"));
    case JSARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
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
    if (layer <= 7) {
      if (layer & 0x01) ergodox_right_led_1_on();
      if (layer & 0x02) ergodox_right_led_2_on();
      if (layer & 0x04) ergodox_right_led_3_on();
    }
    return state;

}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case DOUBLE_BRACKETS:
      if (pressed) {
        layer_move(EMOJI);
      }
      break;
  };
}
