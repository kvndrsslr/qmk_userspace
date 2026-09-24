// Tests for the kvndrsslr tap-hold setup: the "timeless" options (Chordal Hold's
// opposite hands rule and Flow Tap) are off by default and one key turns them
// on; layer taps are exempt from both while they are on.
//
// Geometry: the test keyboard's left hand is columns 0-4, the right hand
// columns 5-9 (see chordal_hold_layout in test_keymap.c).

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "test_common.hpp"
#include "action_tapping.h"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"
#include "test_keycodes.h"
#include "eeconfig.h"

using testing::_;
using testing::InSequence;

class KvndrsslrTimeless : public TestFixture {};

// Off by default: with the timeless options off, a mod-tap chorded with the same
// hand simply holds (plain Permissive Hold), and Flow Tap reports no term.
TEST_F(KvndrsslrTimeless, timeless_off_means_no_opposite_hands_rule) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap       = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       same_hand_key = KeymapKey(0, 2, 0, KC_A);

    test_timeless_set(false);
    set_keymap({mod_tap, same_hand_key});

    keyrecord_t record{};
    EXPECT_EQ(get_flow_tap_term(SFT_T(KC_P), &record, KC_A), 0);

    EXPECT_NO_REPORT(driver);
    mod_tap.press();
    run_one_scan_loop();
    same_hand_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Same hand, so Chordal Hold would normally tap it; with the rule off the
    // mod-tap holds as soon as the other key is released, and the shift comes
    // through.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_A));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    same_hand_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

// The toggle key flips the state and keeps it in user EEPROM.
TEST_F(KvndrsslrTimeless, toggle_key_flips_and_persists) {
    TestDriver driver;
    InSequence s;
    auto       toggle = KeymapKey(0, 5, 0, HRM_TIMELESS);

    test_timeless_set(false);
    set_keymap({toggle});

    EXPECT_FALSE(test_timeless_get());
    tap_key(toggle);
    EXPECT_TRUE(test_timeless_get());
    EXPECT_EQ(eeconfig_read_user() & 1, 1);

    tap_key(toggle);
    EXPECT_FALSE(test_timeless_get());
    EXPECT_EQ(eeconfig_read_user() & 1, 0);
}

// On: a mod-tap chorded with the same hand settles as a tap.
TEST_F(KvndrsslrTimeless, enabled_mod_tap_same_hand_chord_taps) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap       = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       same_hand_key = KeymapKey(0, 2, 0, KC_A);

    test_timeless_set(true);
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

// On: an opposite hand chord still holds the mod-tap.
TEST_F(KvndrsslrTimeless, enabled_mod_tap_opposite_hand_chord_holds) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap        = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       other_hand_key = KeymapKey(0, MATRIX_COLS - 1, 0, KC_A);

    test_timeless_set(true);
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

// On: a layer tap chorded with the same hand still holds (the exception).
TEST_F(KvndrsslrTimeless, enabled_layer_tap_same_hand_chord_holds) {
    TestDriver driver;
    InSequence s;
    auto       layer_tap     = KeymapKey(0, 1, 0, LT(1, KC_P));
    auto       same_hand_key = KeymapKey(0, 2, 0, KC_A);
    auto       layer_1_key   = KeymapKey(1, 2, 0, KC_B);

    test_timeless_set(true);
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

// On: Flow Tap must not settle a layer tap as tapped when it follows typing.
TEST_F(KvndrsslrTimeless, enabled_layer_tap_after_typing_still_holds) {
    TestDriver driver;
    InSequence s;
    auto       letter      = KeymapKey(0, 2, 0, KC_A);
    auto       layer_tap   = KeymapKey(0, 3, 0, LT(1, KC_SPACE));
    auto       layer_1_key = KeymapKey(1, 2, 0, KC_B);

    test_timeless_set(true);
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

// On: Flow Tap does apply to the home row mod-taps, it settles them as taps when
// they follow another typing key.
TEST_F(KvndrsslrTimeless, enabled_flow_tap_applies_to_mod_taps) {
    TestDriver driver;
    InSequence s;
    auto       letter  = KeymapKey(0, 2, 0, KC_A);
    auto       mod_tap = KeymapKey(0, 3, 0, SFT_T(KC_P));

    test_timeless_set(true);
    set_keymap({letter, mod_tap});

    EXPECT_REPORT(driver, (KC_A));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(letter);
    VERIFY_AND_CLEAR(driver);

    // Right after typing, the mod-tap is settled as tapped on key down.
    EXPECT_REPORT(driver, (KC_P));
    mod_tap.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}
