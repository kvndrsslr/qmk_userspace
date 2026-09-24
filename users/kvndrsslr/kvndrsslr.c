// Copyright @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/* Shared code for the kvndrsslr keymaps, included by each board's keymap.c.
 *
 * Only what the core tap-hold options do not already provide is kept here: the
 * hand rolled "opposite hands" rule (get_permissive_hold /
 * get_hold_on_other_key_press and the unilateral/bilateral macros behind them)
 * is replaced by CHORDAL_HOLD + PERMISSIVE_HOLD, the next-key cache it needed
 * (pre_process_record_user) is gone with it, and the dead helpers that nothing
 * called (combo input timer, caps unlock, clipboard tap-holds, autocorrect
 * hooks, magic fallbacks) were dropped.
 */

#include "layout.c"

#ifdef COMBO_ENABLE
#    include "combos.h"
#endif

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    VRSN = SAFE_RANGE, // type out firmware version, on the symbol layer
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode == VRSN) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
    return true;
}

/* Per-key tapping term: the Shift home row mods get a shorter term so that
 * deliberately holding one for Shift engages faster. Rolls that must not fire a
 * modifier are handled by Chordal Hold, not by the timeout. */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):    // QWERTY, left
        case LSFT_T(KC_D):    // QGMLWY, left
        case RSFT_T(KC_SCLN): // QWERTY, right
        case RSFT_T(KC_O):    // QGMLWY, right
            return TAPPING_TERM - 75;
        default:
            return TAPPING_TERM;
    }
}

/* The fork replaces the stock 30us matrix settling delay with a few nops. Kept
 * for the ergodox only: the moonlander's matrix.c calls matrix_io_delay() as
 * well, and shortening the delay there has never been tested. */
#if defined(KEYBOARD_ergodox_ez) && !defined(DIRECT_PINS)
void matrix_io_delay(void) {
    __asm__ volatile("nop\nnop\nnop\n");
}
#endif
