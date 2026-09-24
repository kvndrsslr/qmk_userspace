/* Keymap for the kvndrsslr tap-hold tests. The hooks and the toggle are copies
 * of the ones in users/kvndrsslr/kvndrsslr.c (the test environment cannot
 * include that file), plus accessors so every test can pick its own starting
 * state instead of relying on what a previous test left behind. */

#include "quantum.h"
#include "eeconfig.h"
#include "test_keycodes.h"

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
    {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'},
};

static bool timeless_hrm;

void keyboard_post_init_user(void) {
    timeless_hrm = eeconfig_read_user() & 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode == HRM_TIMELESS) {
        timeless_hrm       = !timeless_hrm;
        uint32_t user_conf = eeconfig_read_user();
        user_conf          = timeless_hrm ? (user_conf | 1u) : (user_conf & ~1u);
        eeconfig_update_user(user_conf);
        return false;
    }
    return true;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    if (!timeless_hrm) {
        return true; // opposite hands rule off: plain Permissive Hold
    }
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return true; // layer taps may be held, whichever hand the other key is on
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    if (!timeless_hrm) {
        return 0; // Flow Tap off with the rest of the timeless options
    }
    if (IS_QK_LAYER_TAP(keycode)) {
        return 0; // no Flow Tap on layer taps
    }
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

/* Test only: pick the starting state directly. */
void test_timeless_set(bool on) {
    timeless_hrm = on;
}

bool test_timeless_get(void) {
    return timeless_hrm;
}
