// Tests for the kvndrsslr tap-hold setup: layer taps are exempt from Chordal
// Hold and from Flow Tap, home row mod-taps are not.
//
// Geometry: the test keyboard's left hand is columns 0-4, the right hand
// columns 5-9 (see chordal_hold_layout in test_keymap.c).

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "test_common.hpp"
#include "action_tapping.h"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"

using testing::_;
using testing::InSequence;

class KvndrsslrLayerTap : public TestFixture {};

// Layer tap chorded with a key on the same hand: the hook lets it hold, so the
// key resolves on layer 1 (KC_B) instead of layer 0 (KC_A).
TEST_F(KvndrsslrLayerTap, layer_tap_same_hand_chord_holds) {
    TestDriver driver;
    InSequence s;
    auto       layer_tap     = KeymapKey(0, 1, 0, LT(1, KC_P));
    auto       same_hand_key = KeymapKey(0, 2, 0, KC_A);
    auto       layer_1_key   = KeymapKey(1, 2, 0, KC_B);

    set_keymap({layer_tap, same_hand_key, layer_1_key});

    EXPECT_NO_REPORT(driver);
    layer_tap.press();
    run_one_scan_loop();
    same_hand_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    same_hand_key.release();
    run_one_scan_loop();
    EXPECT_EQ(layer_state, 2);
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    layer_tap.release();
    run_one_scan_loop();
    EXPECT_EQ(layer_state, 0);
    VERIFY_AND_CLEAR(driver);
}

// Control for the same geometry: a mod-tap is still constrained, it settles as a
// tap (KC_P and KC_A, no shift).
TEST_F(KvndrsslrLayerTap, mod_tap_same_hand_chord_taps) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap       = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       same_hand_key = KeymapKey(0, 2, 0, KC_A);

    set_keymap({mod_tap, same_hand_key});

    EXPECT_NO_REPORT(driver);
    mod_tap.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_P));
    EXPECT_REPORT(driver, (KC_P, KC_A));
    same_hand_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_P));
    same_hand_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

// Control: an opposite hand chord still holds the mod-tap.
TEST_F(KvndrsslrLayerTap, mod_tap_opposite_hand_chord_holds) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap       = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       other_hand_key = KeymapKey(0, MATRIX_COLS - 1, 0, KC_A);

    set_keymap({mod_tap, other_hand_key});

    EXPECT_NO_REPORT(driver);
    mod_tap.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_A));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    tap_key(other_hand_key);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

// Flow Tap must not settle a layer tap as tapped when it follows typing: hold
// space right after a letter and the layer still engages.
TEST_F(KvndrsslrLayerTap, layer_tap_after_typing_still_holds) {
    TestDriver driver;
    InSequence s;
    auto       letter        = KeymapKey(0, 2, 0, KC_A);
    auto       layer_tap     = KeymapKey(0, 3, 0, LT(1, KC_SPACE));
    auto       layer_1_key   = KeymapKey(1, 2, 0, KC_B);

    set_keymap({letter, layer_tap, layer_1_key});

    // Type a letter, then hold the layer tap within FLOW_TAP_TERM of it.
    EXPECT_REPORT(driver, (KC_A));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(letter);
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    layer_tap.press();
    run_one_scan_loop();
    letter.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    letter.release();
    run_one_scan_loop();
    EXPECT_EQ(layer_state, 2);
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    layer_tap.release();
    run_one_scan_loop();
    EXPECT_EQ(layer_state, 0);
    VERIFY_AND_CLEAR(driver);
}
