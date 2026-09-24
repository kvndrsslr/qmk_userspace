/* Keymap for the kvndrsslr exception tests. The hooks below are copies of the
 * ones in users/kvndrsslr/kvndrsslr.c: layer taps must not be constrained by
 * Chordal Hold, home row mod-taps must be. */

#include "quantum.h"

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return true; // layer taps may be held, whichever hand the other key is on
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    if (IS_QK_LAYER_TAP(keycode)) {
        return 0; // no Flow Tap on layer taps
    }
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}
