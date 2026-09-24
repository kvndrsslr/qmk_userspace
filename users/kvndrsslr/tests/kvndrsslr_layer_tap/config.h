/* Configuration of the kvndrsslr setup under test: same tap-hold options as
 * users/kvndrsslr/config.h in the userspace. */

#pragma once

#include "test_common.h"

#undef TAPPING_TERM
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
