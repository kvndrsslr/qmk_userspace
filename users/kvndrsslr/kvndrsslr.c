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
    HRM_TIMELESS,      // toggle Chordal Hold + Flow Tap for the home row mods
};

/* Chordal Hold's opposite hands rule and Flow Tap change how the home row
 * mod-taps feel, so they are opt-in: off after a fresh flash, flipped with one
 * key, and the choice is remembered in user EEPROM. The layer taps are exempt
 * from both either way. */
static bool timeless_hrm;

void keyboard_post_init_user(void) {
    timeless_hrm = eeconfig_read_user() & 1;
}

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
        case HRM_TIMELESS: {
            timeless_hrm       = !timeless_hrm;
            uint32_t user_conf = eeconfig_read_user();
            user_conf          = timeless_hrm ? (user_conf | 1u) : (user_conf & ~1u);
            eeconfig_update_user(user_conf);
            return false;
        }
    }
    return true;
}

/* Layer taps (space for the mouse layer, G and H for the umlauts) keep their old
 * behaviour: they may be held in a chord with either hand. Chordal Hold exists
 * to keep home row rolls from firing modifiers, and a layer tap is always
 * deliberate, so the layer-tap keys are exempt from the opposite hands rule.
 * Rolling through G or H as letters is unaffected: a tap is still settled when
 * the key is released within the tapping term. */
#if defined(CHORDAL_HOLD)
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    if (!timeless_hrm) {
        return true; // opposite hands rule off: plain Permissive Hold
    }
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return true; // may be held, whichever hand the other key is on
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif

/* Flow Tap must not swallow a layer tap that follows another key while typing:
 * holding space or G right after a letter has to keep working. The home row
 * mod-taps keep Flow Tap, which is what removes their input lag. */
#if defined(FLOW_TAP_TERM)
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
#endif

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
