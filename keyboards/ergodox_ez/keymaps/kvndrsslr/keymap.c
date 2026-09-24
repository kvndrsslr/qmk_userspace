#include QMK_KEYBOARD_H
#include "kvndrsslr.c"

/* The layer contents live in users/kvndrsslr/layout.h, written in ergodox_pretty
 * key order; ERGO_LAYOUT() expands them into this keyboard's layout. HRM() adds
 * the home row mod-taps to the two base layers; the layers that only hold
 * modifiers or symbols are used as they are. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [UBSE] = ERGO_LAYOUT(HRM(LAYER_UBSE)),
    [UQGM] = ERGO_LAYOUT(HRM(LAYER_UQGM)),
    [USYM] = ERGO_LAYOUT(LAYER_USYM),
    [UGER] = ERGO_LAYOUT(LAYER_UGER),
    [UFNK] = ERGO_LAYOUT(LAYER_UFNK),
    [SYMB] = ERGO_LAYOUT(LAYER_SYMB),
    [GAME] = ERGO_LAYOUT(LAYER_GAME),
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

/* Show the active layer on the three right hand LEDs. */
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (get_highest_layer(state)) {
        case UQGM:
            ergodox_right_led_3_on();
            break;
        case USYM:
            ergodox_right_led_2_on();
            break;
        case UGER:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
        case UFNK:
            ergodox_right_led_1_on();
            break;
        case SYMB:
            ergodox_right_led_3_on();
            ergodox_right_led_1_on();
            break;
        case GAME:
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }
    return state;
};
