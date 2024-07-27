/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef DEBOUNCE
#define DEBOUNCE 19

#undef TAPPING_TERM
#define TAPPING_TERM 210

// #define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0

#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS, UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
