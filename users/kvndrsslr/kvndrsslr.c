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

#ifdef COMBO_ENABLE
#    include "combos.h"
#endif

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    VRSN = SAFE_RANGE, // type out firmware version, on the symbol layer
    UM_AE,             // ä, Ä with shift
    UM_OE,             // ö, Ö with shift
    UM_UE,             // ü, Ü with shift
    UM_SZ,             // ß
};

/* Send the umlauts as macOS option key sequences instead of through the unicode
 * map: "option+u" is the diaeresis dead key and "option+s" is sharp s, so no
 * Unicode Hex Input source is needed and the option layer keeps working.
 * The case is chosen the way the previous UP(unshifted, shifted) unicode pairs
 * did: shift or caps lock gives the capital. The dead key is always sent
 * without shift, otherwise a held shift would turn option+u into another
 * character. ß has no shift variant on macOS layouts, so it always sends ß. */
static bool umlaut_upper(void) {
    uint8_t mods = get_mods() | get_weak_mods();
#ifndef NO_ACTION_ONESHOT
    mods |= get_oneshot_mods();
#endif
    return (mods & MOD_MASK_SHIFT) ^ host_keyboard_led_state().caps_lock;
}

static void send_diaeresis(uint16_t base) {
    const bool    upper = umlaut_upper();
    const uint8_t mods  = get_mods();
    del_mods(MOD_MASK_SHIFT);
    tap_code16(A(KC_U));
    set_mods(mods);
    if (upper) {
        tap_code16(S(base));
    } else {
        tap_code(base);
    }
}

static void send_sharp_s(void) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    tap_code16(A(KC_S));
    set_mods(mods);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case VRSN:
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case UM_AE:
            send_diaeresis(KC_A);
            return false;
        case UM_OE:
            send_diaeresis(KC_O);
            return false;
        case UM_UE:
            send_diaeresis(KC_U);
            return false;
        case UM_SZ:
            send_sharp_s();
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
