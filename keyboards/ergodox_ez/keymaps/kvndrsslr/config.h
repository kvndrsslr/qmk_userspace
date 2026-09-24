// SPDX-License-Identifier: GPL-2.0+

/* Board specific configuration for the ergodox. The shared tap-hold setup
 * (TAPPING_TERM, PERMISSIVE_HOLD, CHORDAL_HOLD, FLOW_TAP_TERM,
 * SPECULATIVE_HOLD, TAPPING_TERM_PER_KEY, unicode modes) lives in
 * users/kvndrsslr/config.h, which QMK includes before this file. */

#pragma once

#define ORYX_CONFIGURATOR

#undef DEBOUNCE
#define DEBOUNCE 20

#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 85

#define USB_SUSPEND_WAKEUP_DELAY 0
