#include QMK_KEYBOARD_H
#include "kvndrsslr.c"

/* The layer contents live in users/kvndrsslr/layout.h, written in ergodox_pretty
 * key order; C_72() translates them to this keyboard's 72 key layout and
 * MOON_LAYOUT() expands them into it. HRM() adds the home row mod-taps to the
 * two base layers. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [UBSE] = MOON_LAYOUT(C_72(HRM(LAYER_UBSE))),
    [UQGM] = MOON_LAYOUT(C_72(HRM(LAYER_UQGM))),
    [USYM] = MOON_LAYOUT(C_72(LAYER_USYM)),
    [UGER] = MOON_LAYOUT(C_72(LAYER_UGER)),
    [UFNK] = MOON_LAYOUT(C_72(LAYER_UFNK)),
    [SYMB] = MOON_LAYOUT(C_72(LAYER_SYMB)),
    [GAME] = MOON_LAYOUT(C_72(LAYER_GAME)),
};
