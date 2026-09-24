/* Custom keycodes and helpers of the test keymap, shared between test_keymap.c
 * and the test cases (which bind the keycode with KeymapKey). The test keymap is
 * C, so the helpers need C linkage for the C++ tests. */

#pragma once

#include "quantum.h"

enum custom_keycodes {
    HRM_TIMELESS = SAFE_RANGE,
};

#ifdef __cplusplus
extern "C" {
#endif

/* Test only: pick or read the starting state of the timeless options. */
void test_timeless_set(bool on);
bool test_timeless_get(void);

#ifdef __cplusplus
}
#endif
