// SPDX-License-Identifier: GPL-2.0+

/* Board specific configuration for the moonlander. The shared tap-hold setup
 * (TAPPING_TERM, PERMISSIVE_HOLD, CHORDAL_HOLD, FLOW_TAP_TERM,
 * SPECULATIVE_HOLD, TAPPING_TERM_PER_KEY, unicode modes) lives in
 * users/kvndrsslr/config.h, which QMK includes before this file. */

#pragma once

#define ORYX_CONFIGURATOR

#undef DEBOUNCE
#define DEBOUNCE 19

#define USB_SUSPEND_WAKEUP_DELAY 0

#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE
#define RGB_MATRIX_DEFAULT_HUE 95
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 255
#define RGB_MATRIX_DEFAULT_SPD 20
