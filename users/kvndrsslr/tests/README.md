# Host tests for the tap-hold setup

QMK's test runner only looks inside `qmk_firmware/tests`, so copy this directory
into the firmware checkout and run it there:

    cp -r ~/.config/qmk_userspace/users/kvndrsslr/tests/kvndrsslr_layer_tap \
          ~/.config/qmk/tests/tap_hold_configurations/chordal_hold/
    make -C ~/.config/qmk test:tap_hold_configurations/chordal_hold/kvndrsslr_layer_tap

`test_keymap.c` holds copies of `get_chordal_hold()` and `get_flow_tap_term()`
from `users/kvndrsslr/kvndrsslr.c`, because the test environment cannot include
that file (it pulls in `version.h` and `QMK_KEYBOARD_H`). Keep them in sync when
the hooks change.

What the four tests cover:

| Test | Expectation |
| --- | --- |
| `layer_tap_same_hand_chord_holds` | a layer tap chorded with the same hand still holds (the exception) |
| `layer_tap_after_typing_still_holds` | a layer tap right after typing still holds (no Flow Tap on layer taps) |
| `mod_tap_same_hand_chord_taps` | a home row mod-tap in the same hand still settles as a tap |
| `mod_tap_opposite_hand_chord_holds` | an opposite hand mod-tap chord still holds |

The last two are controls: they pass with and without the exceptions, and they
are what fails if Chordal Hold is ever dropped from the shared config.
