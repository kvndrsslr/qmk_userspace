#include QMK_KEYBOARD_H
#include "kvndrsslr.c"

#define LAYOUT_ergodox_pretty_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [UBSE] = LAYOUT_ergodox_pretty_wrapper(HRM(__BASE__)),
  [UQGM] = LAYOUT_ergodox_pretty_wrapper(HRM(__QGML__)),
  [USYM] = LAYOUT_ergodox_pretty(
    _______,       _______       ,           _______       ,           _______       ,           _______       ,           _______       ,           _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       ,           _______       ,           _______       ,           _______       ,           _______       ,           _______       ,                                 _______       , KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, _______       , _______       ,
    _______       ,      _______       ,      _______       ,   _______       ,  _______       ,   _______       ,                                                                     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MS_BTN3,     _______       ,
    _______       , _______       , _______       , _______       ,   _______       ,      _______       ,           _______       ,                                 _______       , KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    _______       , _______       ,
    _______       , _______       , _______       , _______       ,    _______       ,                                                                                                    KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_MEDIA_NEXT_TRACK,_______       ,
                                                                                                    _______       , _______       , _______       , _______       ,
                                                                                                                    _______       , _______       ,
                                                                                    _______       , _______       , _______       , QK_MAKE,          KC_MS_BTN2,     KC_MS_BTN1
  ),
  [UGER] = LAYOUT_ergodox_pretty(
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , MUC_UUML,       _______       , MUC_OUML,       _______       , _______       ,
    _______       , MUC_AUML,       MUC_SZ,         _______       , _______       , _______       ,                                                                 _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       ,                                                                                                 _______       , _______       , _______       , _______       , _______       ,
                                                                                                    _______       , _______       , _______       , _______       ,
                                                                                                                    _______       , _______       ,
                                                                                    _______       , _______       , _______       , _______       , _______       , _______
  ),
  // disable QGML.. layers for now
  // [4] = LAYOUT_ergodox_pretty(
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 TO(0),          _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , KC_Q,           KC_G,           KC_M,           KC_L,           KC_W,           _______       ,                                 _______       , KC_Y,           KC_F,           KC_U,           KC_B,           KC_SCOLON,      _______       ,
  //   _______       , LT(6,KC_D),     LALT_T(KC_S),   LCTL_T(KC_T),   LGUI_T(KC_N),   LT(6,KC_R),                                                                     LT(6,KC_I),     RGUI_T(KC_A),   RCTL_T(KC_E),   RALT_T(KC_O),   LT(6,KC_H),     _______       ,
  //   _______       , KC_Z,           KC_X,           KC_C,           KC_V,           KC_J,           MO(5),                                          MO(5),          KC_K,           KC_P,           KC_COMMA,       KC_DOT,         KC_SLASH,       _______       ,
  //   _______       , _______       , _______       , _______       , _______       ,                                                                                                 _______       , _______       , _______       , _______       , _______       ,
  //                                                                                                   _______       , _______       , _______       , _______       ,
  //                                                                                                                   _______       , _______       ,
  //                                                                                   _______       , _______       , _______       , _______       , _______       , _______
  // ),
  // [5] = LAYOUT_ergodox_pretty(
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , KC_SCOLON,      KC_B,           KC_U,           KC_F,           KC_Y,           _______       ,                                 _______       , KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, _______       , _______       ,
  //   _______       , LT(7,KC_H),     LALT_T(KC_O),   LCTL_T(KC_E),   LGUI_T(KC_A),   KC_I,                                                                           KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MS_BTN3,     _______       ,
  //   _______       , KC_SLASH,       KC_DOT,         KC_COMMA,       KC_P,           KC_K,           _______       ,                                 _______       , KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       ,                                                                                                 KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_MEDIA_NEXT_TRACK,_______       ,
  //                                                                                                   _______       , _______       , _______       , _______       ,
  //                                                                                                                   _______       , _______       ,
  //                                                                                   _______       , _______       , _______       , RESET,          KC_MS_BTN2,     KC_MS_BTN1
  // ),
  // [6] = LAYOUT_ergodox_pretty(
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , ST_MACRO_7,     _______       , _______       , _______       ,
  //   _______       , _______       , ST_MACRO_6,     _______       , _______       , _______       ,                                                                 _______       , ST_MACRO_8,     _______       , ,     _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       ,                                                                                                 _______       , _______       , _______       , _______       , _______       ,
  //                                                                                                   _______       , _______       , _______       , _______       ,
  //                                                                                                                   _______       , _______       ,
  //                                                                                   _______       , _______       , _______       , _______       , _______       , _______
  // ),
  // [7] = LAYOUT_ergodox_pretty(
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , _______       , ST_MACRO_10,    _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , ST_MACRO_11,    _______       , ST_MACRO_12,    _______       ,                                                                 _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
  //   _______       , _______       , _______       , _______       , _______       ,                                                                                                 _______       , _______       , _______       , _______       , _______       ,
  //                                                                                                   _______       , _______       , _______       , _______       ,
  //                                                                                                                   _______       , _______       ,
  //                                                                                   _______       , _______       , _______       , _______       , _______       , _______
  // ),
  [UFNK] = LAYOUT_ergodox_pretty(
    _______       , KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______       ,                                 _______       , KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , KC_7,           KC_8,           KC_9,           _______       , KC_F12,
    _______       , _______       , _______       , _______       , _______       , _______       ,                                                                 _______       , KC_4,           KC_5,           KC_6,           _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , KC_1,           KC_2,           KC_3,           _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       ,                                                                                                 _______       , KC_0,           _______       , _______       , _______       ,
                                                                                                    LED_LEVEL,      _______       , _______       , _______       ,
                                                                                                                    _______       , _______       ,
                                                                                    _______       , _______       , _______       , _______       , _______       , _______
  ),
  [GAME] = LAYOUT_ergodox_pretty(
    _______       , _______       , _______       , _______       , _______       , _______       , TG(GAME),                                          _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    KC_LALT,        _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , KC_RALT,
    KC_LCTL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SEMICOLON,      KC_RCTL,
    KC_LSFT,      _______       , _______       , _______       , _______       , _______       , KC_M       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , KC_RSFT,
    KC_LGUI,        _______       , _______       , _______       , _______       ,                                                                                                 _______       , _______       , _______       , _______       , KC_RGUI,
                                                                                                    _______       , _______       , _______       , _______       ,
                                                                                                                    _______       , _______       ,
                                                                                    KC_SPACE       , _______       , KC_ESCAPE,      KC_ESCAPE,      _______       , _______
  )
};

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 13}, {1, 13}, {2, 13}, {3, 13}, {4, 13}, {5, 13}},
    {{0, 12}, {1, 12}, {2, 12}, {3, 12}, {4, 12}, {5, 12}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
    /* Right hand, matrix positions */
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
};

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer % 8) {
    case 1:
      ergodox_right_led_3_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      ergodox_right_led_2_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      break;
    case 5:
      ergodox_right_led_3_on();
      ergodox_right_led_1_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_1_on();
      break;
    case 7:
      ergodox_right_led_3_on();
      ergodox_right_led_2_on();
      ergodox_right_led_1_on();
      break;
    default:
      break;
  }
  return state;
};
