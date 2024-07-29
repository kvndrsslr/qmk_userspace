/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR

#undef DEBOUNCE
#define DEBOUNCE 20

#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 85

#undef TAPPING_TERM
#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD

// #define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0

#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS, UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE

#define L_HOMEROW 2
#define R_HOMEROW 9

#define SWAP_ROWS_AND_COLS

#ifndef __ASSEMBLER__
#   include "layout.h"
#endif
