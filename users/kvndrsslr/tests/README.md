# Host tests for the tap-hold setup

QMK's test runner only looks inside `qmk_firmware/tests`, so copy this directory
into the firmware checkout and run it there:

    cp -r ~/.config/qmk_userspace/users/kvndrsslr/tests/kvndrsslr_layer_tap \
          ~/.config/qmk/tests/tap_hold_configurations/chordal_hold/
    make -C ~/.config/qmk test:tap_hold_configurations/chordal_hold/kvndrsslr_layer_tap

`test_keymap.c` holds copies of `get_chordal_hold()`, `get_flow_tap_term()`,
`keyboard_post_init_user()` and the toggle from `users/kvndrsslr/kvndrsslr.c`,
because the test environment cannot include that file (it pulls in `version.h`
and `QMK_KEYBOARD_H`). Keep them in sync when the hooks change. The accessors in
`test_keycodes.h` exist only so each test can pick its own starting state.

## What the tests cover

The timeless options (Chordal Hold's opposite hands rule and Flow Tap) are off
until the `HRM_TIMELESS` key on the symbols layer switches them on.

| Test | Expectation |
| --- | --- |
| `timeless_off_means_no_opposite_hands_rule` | off: a same hand mod-tap chord holds anyway (plain Permissive Hold) and Flow Tap reports no term |
| `toggle_key_flips_and_persists` | the key flips the state and leaves the bit in user EEPROM |
| `enabled_mod_tap_same_hand_chord_taps` | on: a same hand mod-tap chord settles as a tap |
| `enabled_mod_tap_opposite_hand_chord_holds` | on: an opposite hand mod-tap chord holds |
| `enabled_layer_tap_same_hand_chord_holds` | on: a layer tap chorded with the same hand still holds (the exception) |
| `enabled_layer_tap_after_typing_still_holds` | on: a layer tap right after typing still holds (no Flow Tap on layer taps) |
| `enabled_flow_tap_applies_to_mod_taps` | on: a mod-tap right after typing settles as a tap |

The last five are the behaviour the toggle turns on; `timeless_off_means_no_opposite_hands_rule`
is what protects the default: it fails if the timeless options ever leak into
the off state.
