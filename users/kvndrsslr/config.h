// SPDX-License-Identifier: GPL-2.0+

/* Configuration shared by all kvndrsslr boards (ergodox_ez, zsa/moonlander).
 * QMK includes this before the per-board keymap config.h, so a board can
 * override anything here with #undef / #define. */

#pragma once

/* ------------------------- timeless home row mods ---------------------------
 * urob's ZMK "timeless" home row mods, assembled from core QMK options only:
 *
 *  - a generous TAPPING_TERM makes the tap/hold decision insensitive to timing;
 *  - Permissive Hold settles an opposite-hand nested chord as hold right away,
 *    Chordal Hold settles same-hand chords as tap, so rolling over the home row
 *    does not fire modifiers by accident;
 *  - Flow Tap settles a tap-hold key as tap when it follows another typing key
 *    quickly, which removes the input lag that a long tapping term would add;
 *  - Speculative Hold applies Shift/Ctrl on keydown (Shift+click stays snappy).
 *
 * See https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/
 * Enabled on both boards, currently without per-key exceptions.
 * ------------------------------------------------------------------------- */
#undef TAPPING_TERM
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define SPECULATIVE_HOLD

/* get_tapping_term() in kvndrsslr.c: shorter term on the Shift home row mods. */
#define TAPPING_TERM_PER_KEY

/* ----------------------------- shared features ---------------------------- */
#define ENABLE_COMPILE_KEYCODE /* QK_MAKE, used on the mouse layer */

/* Space the keycodes that a macro sends out: the umlaut dead keys need the host
 * to see the dead key and the letter as separate events. */
#define TAP_CODE_DELAY 10

#ifndef __ASSEMBLER__
#    include "layout.h"
#endif
