#include QMK_KEYBOARD_H
#include "version.h"

enum unicode_names {
    AU,
    AAU,
    OU,
    OOU,
    UU,
    UUU,
    SZ,
    SSZ
};

const uint32_t PROGMEM unicode_map[] = {
    [AU]  = 0x00e4,
    [AAU] = 0x00c4,
    [OU]  = 0x00f6,
    [OOU] = 0x00d6,
    [UU]  = 0x00fc,
    [UUU] = 0x00dc,
    [SZ]  = 0x00df,
    [SSZ] = 0x1e9e
};

#define MUC_SZ   UP(SZ, SSZ)
#define MUC_AUML UP(AU, AAU)
#define MUC_OUML UP(OU, OOU)
#define MUC_UUML UP(UU, UUU)

enum layers {
    UBSE,
    USYM,
    UGER,
    UFNK,
    GAME,
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [UBSE] = LAYOUT_moonlander(
      KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           MO(SYMB) ,                                          _______       , KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           MO(UFNK),                                          MO(UFNK),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_ESCAPE,
    KC_BACKSPACE,      LSFT_T(KC_A),           LALT_T(KC_S),   LCTL_T(KC_D),   LGUI_T(KC_F),   LT(UGER,KC_G), MO(USYM),                                          MO(USYM),   LT(UGER,KC_H),     RGUI_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RSFT_T(KC_SEMICOLON),      KC_DELETE,
    KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                             KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSFT,
    OSM(MOD_HYPR),  OSM(MOD_MEH),   KC_BACKSLASH,      KC_GRAVE,       SH_T(KC_QUOTE),                LGUI(KC_SPACE),                                       LGUI(KC_SPACE),         KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,    _______       , OSM(MOD_MEH),   OSM(MOD_HYPR),
                                                                                    LT(USYM,KC_SPACE),       KC_TAB,         _______       ,          QK_BOOT,          KC_TAB,         KC_ENTER
    ),
    [USYM] = LAYOUT_moonlander(
       VRSN,       _______       ,           _______       ,           _______       ,           _______       ,           _______       ,           _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       ,           _______       ,           _______       ,           _______       ,           _______       ,           _______       ,                                 _______       , KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, _______       , _______       ,
    _______       ,      _______       ,      _______       ,   _______       ,  _______       ,   _______       ,      _______       ,                                                      _______       ,            KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MS_BTN3,     _______       ,
    _______       , _______       , _______       , _______       ,   _______       ,      _______       ,                                         KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    _______       , _______       ,
    _______       , _______       , _______       , _______       ,    _______       ,    _______       ,                                                                                      _______       ,   KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_MEDIA_NEXT_TRACK,_______       ,
                                                                                    _______       , _______       , _______       , QK_MAKE,          KC_MS_BTN2,     KC_MS_BTN1
    ),
    [UGER] = LAYOUT_moonlander(
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , MUC_UUML,       _______       , MUC_OUML,       _______       , _______       ,
    _______       , MUC_AUML,       MUC_SZ,         _______       , _______       , _______       ,     _______       ,                                                 _______       ,         _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       ,                              _______       , _______       , _______       , _______       , _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       ,  _______      ,                                _______       ,      _______       , _______       , _______       , _______       , _______       ,
                                                                                    _______       , _______       , _______       , _______       , _______       , _______
    ),
    [UFNK] = LAYOUT_moonlander(
    _______       , KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______       ,                                 _______       , KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , KC_7,           KC_8,           KC_9,           _______       , KC_F12,
    _______       , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , KC_4,           KC_5,           KC_6,           _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , _______       ,                                                                 _______       , KC_1,           KC_2,           KC_3,           _______       , _______       ,
    _______       , _______       , _______       , _______       , _______       , LED_LEVEL     ,                                                                 _______       ,   _______       , KC_0,           _______       , _______       , _______       ,
                                                                                    _______       , _______       , _______       , _______       , _______       , _______
    ),
    [GAME] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [BASE] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, _______, _______,          RGB_MOD,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR,_______, RGB_HUD, RGB_HUI
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   uint8_t layer = biton32(state);
//   ergodox_board_led_off();
//   ergodox_right_led_1_off();
//   ergodox_right_led_2_off();
//   ergodox_right_led_3_off();
//   switch (layer % 8) {
//     case 1:
//       ergodox_right_led_3_on();
//       break;
//     case 2:
//       ergodox_right_led_2_on();
//       break;
//     case 3:
//       ergodox_right_led_3_on();
//       ergodox_right_led_2_on();
//       break;
//     case 4:
//       ergodox_right_led_1_on();
//       break;
//     case 5:
//       ergodox_right_led_3_on();
//       ergodox_right_led_1_on();
//       break;
//     case 6:
//       ergodox_right_led_2_on();
//       ergodox_right_led_1_on();
//       break;
//     case 7:
//       ergodox_right_led_3_on();
//       ergodox_right_led_2_on();
//       ergodox_right_led_1_on();
//       break;
//     default:
//       break;
//   }
//   return state;
// };
