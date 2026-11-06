// Copyright 2021 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/* Shared keymap definition for the kvndrsslr boards (ergodox_ez, zsa/moonlander).
 *
 * Every layer is written once, in the ergodox_pretty ("76 key") order:
 *
 *   l01..l07 | r01..r07    numbers row      (7 keys per hand)
 *   l08..l14 | r08..r14    QWERTY row       (7 keys per hand)
 *   l15..l20 | r15..r20    home row         (6 keys per hand)
 *   l21..l27 | r21..r27    bottom row       (7 keys per hand)
 *   l28..l32 | r28..r32    outer bottom row (5 keys per hand)
 *   l33, le1, re1, r33     thumb keys       (le*, re* exist on the ergodox only)
 *   le2, re2               thumb keys       (ergodox only)
 *   l34..l36 | r34..r36    thumb keys       (3 keys per hand)
 *
 * Only one mapping is maintained: the ergodox takes it as it is
 *
 *     [UBSE] = ERGO_LAYOUT(HRM(LAYER_UBSE))
 *
 * and the moonlander translates it, dropping the keys it does not have
 *
 *     [UBSE] = MOON_LAYOUT(C_72(HRM(LAYER_UBSE)))
 *
 * The ergodox has three thumb keys (le1, le2, l36 on the left, re1, re2, r34 on
 * the right) where the moonlander has only one (l36, r34), so the two extras
 * simply repeat that key's binding: pressing any of the three does the same
 * thing. This keeps the geometry identical without maintaining a second mapping.
 * C_72() ignores le1, re1, le2, re2 entirely.
 *
 * HRM() turns the four middle home row keys of each hand into mod-taps; it is
 * applied per layer, and only the two base layers use it.
 */

#pragma once

// -------------------------------- layers ------------------------------------

enum layers {
    UBSE, // QWERTY base
    UQGM, // QGMLWY alternative base
    USYM, // mouse / media
    UGER, // German umlauts
    UFNK, // F-keys / numpad
    SYMB, // symbols (plus RGB controls on the moonlander)
    GAME, // plain keys for gaming
};

// ------------------------------ keycode notes --------------------------------

/* The umlauts are macro keycodes defined in kvndrsslr.c: macOS option key
 * sequences ("option+u" for the diaeresis, "option+s" for sharp s), so no
 * unicode map and no Unicode Hex Input source is involved. Shift (or caps lock)
 * on those keys gives the capital. */
#define MTEAMS LSFT(LCA(KC_M)) // mute in MS Teams

// --------------------------- board differences -------------------------------

// The RGB matrix controls only do something on the board that has them.
#if defined(RGB_MATRIX_ENABLE)
#    define AUX_RGB(k) k
#else
#    define AUX_RGB(k) _______
#endif

// ----------------------------- home row mods ---------------------------------

#define HRML(k1, k2, k3, k4) LSFT_T(k1), LALT_T(k2), LCTL_T(k3), LGUI_T(k4)
#define HRMR(k1, k2, k3, k4) RGUI_T(k1), RCTL_T(k2), RALT_T(k3), RSFT_T(k4)

// Mod-tap wrapper: mod-tap the four middle keys of each home row.
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP(                                                                        \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07,               \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14,               \
    l15, l16, l17, l18, l19, l20,              r15, r16, r17, r18, r19, r20,               \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27,               \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32,               \
                             l33, le1,    re1, r33,                                        \
                                  le2,    re2,                                                 \
                        l34, l35, l36,    r34, r35, r36                                    \
)                                                                                          \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07,               \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14,               \
    l15, HRML(l16, l17, l18, l19), l20,   r15, HRMR(r16, r17, r18, r19), r20,               \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27,               \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32,               \
                             l33, le1,    re1, r33,                                        \
                                  le2,    re2,                                                 \
                        l34, l35, l36,    r34, r35, r36                                    \

// ----------------------- ergodox_pretty -> moonlander ------------------------

/* Translate the 76 key order above into the moonlander's 72 key order: the four
 * ergodox-only thumb keys are dropped, the inner column keys move to where the
 * moonlander has them, and both thumb rows keep their physical order. */
#define C_72(k) CONV_76_TO_72(k)
#define CONV_76_TO_72(                                                                    \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07,               \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14,               \
    l15, l16, l17, l18, l19, l20,              r15, r16, r17, r18, r19, r20,               \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27,               \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32,               \
                             l33, le1,    re1, r33,                                        \
                                  le2,    re2,                                                 \
                        l34, l35, l36,    r34, r35, r36                                    \
)                                                                                          \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07,               \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14,               \
    l15, l16, l17, l18, l19, l20, l27,    r21, r15, r16, r17, r18, r19, r20,               \
    l21, l22, l23, l24, l25, l26,              r22, r23, r24, r25, r26, r27,               \
    l28, l29, l30, l31, l32, l33,              r33, r28, r29, r30, r31, r32,               \
                        l34, l35, l36,    r34, r35, r36                                    \

// ------------------------------ layer wrappers -------------------------------

/* The board LAYOUT macros take a fixed number of arguments, and a macro
 * invocation does not count as one argument per expanded key: the layer macro
 * has to be expanded through a variadic wrapper before it is handed over. */
#define ERGO_LAYOUT(...) LAYOUT_ergodox_pretty(__VA_ARGS__)
#define MOON_LAYOUT(...) LAYOUT_moonlander(__VA_ARGS__)

// ------------------------------ letter runs ----------------------------------

// QWERTY: the fifth home row key carries the umlaut layer tap.
#define QWERTY_L1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_L2 KC_A, KC_S, KC_D, KC_F, LT(UGER, KC_G)
#define QWERTY_L3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define QWERTY_R1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWERTY_R2 LT(UGER, KC_H), KC_J, KC_K, KC_L, KC_SCLN
#define QWERTY_R3 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

// QGMLWY (carplax). The umlaut layer is QWERTY positional, so no layer tap here.
#define QGML_L1 KC_Q, KC_G, KC_M, KC_L, KC_W
#define QGML_L2 KC_D, KC_S, KC_T, KC_N, KC_R
#define QGML_L3 KC_Z, KC_X, KC_C, KC_V, KC_J

#define QGML_R1 KC_Y, KC_F, KC_U, KC_B, KC_SCLN
#define QGML_R2 KC_I, KC_A, KC_E, KC_O, KC_H
#define QGML_R3 KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH

// -------------------------------- layers -------------------------------------

// Skeleton shared by both base layers.
#define BASE_LAYER(L1, L2, L3, R1, R2, R3)                                                \
    /* l01-l07 | r01-r07 */                                                               \
    KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, TG(GAME),                                       \
    MTEAMS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,                                        \
    /* l08-l14 | r08-r14 */                                                               \
    KC_ESC, L1, MO(UFNK),                                                                 \
    MO(UFNK), R1, KC_ESC,                                                                 \
    /* l15-l20 | r15-r20 */                                                               \
    KC_BSPC, L2,                                                                          \
    R2, KC_DEL,                                                                           \
    /* l21-l27 | r21-r27 */                                                               \
    KC_LSFT, L3, MO(USYM),                                                                \
    MO(USYM), R3, KC_RSFT,                                                                \
    /* l28-l32 | r28-r32 */                                                               \
    OSM(MOD_HYPR), OSM(MOD_MEH), KC_BACKSLASH, KC_GRAVE, SH_T(KC_QUOTE),                  \
    KC_LEFT_BRACKET, KC_RIGHT_BRACKET, _______, OSM(MOD_MEH), OSM(MOD_HYPR),              \
    /* l33, le1, re1, r33 */                                                              \
    LGUI(KC_SPACE), MO(SYMB), QK_BOOT, LGUI(KC_SPACE),                                    \
    /* le2, re2 */                                                                        \
    MO(SYMB), QK_BOOT,                                                                    \
    /* l34-l36 | r34-r36 */                                                               \
    LT(USYM, KC_SPACE), KC_TAB, MO(SYMB), QK_BOOT, KC_TAB, KC_ENTER

#define LAYER_UBSE BASE_LAYER(QWERTY_L1, QWERTY_L2, QWERTY_L3, QWERTY_R1, QWERTY_R2, QWERTY_R3)
#define LAYER_UQGM BASE_LAYER(QGML_L1, QGML_L2, QGML_L3, QGML_R1, QGML_R2, QGML_R3)

// Mouse / media. The mouse and the transport keys are on the right hand and the right
// thumb keys; brightness is the inner pair of the left hand's outer bottom row.
//
// Those two are F13/F14 rather than KC_BRIGHTNESS_* on purpose: macOS only takes
// display brightness from its own keyboard driver, so a consumer-page brightness
// usage from this board is ignored, and an event tap never even sees it (no CGEvent
// is created). kxdesk binds the plain keys and steps the panel instead - that is what
// its `display brightness up|down` is for. kanata used to hide this by re-emitting
// every key through the Karabiner virtual HID keyboard, which macOS does honour.
#define LAYER_USYM                                                                        \
    /* l01-l07 | r01-r07 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, _______, _______, _______, _______, _______,                         \
    /* l08-l14 | r08-r14 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, _______,                         \
    /* l15-l20 | r15-r20 */                                                               \
    _______, _______, _______, _______, _______, _______,                                 \
    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, MS_BTN3, _______,                                   \
    /* l21-l27 | r21-r27 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, _______, _______,                           \
    /* l28-l32 | r28-r32 */                                                               \
    _______, _______, _______, KC_SCRL, KC_PAUS,                                             \
    KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP, KC_MEDIA_NEXT_TRACK, _______, \
    /* l33, le1, re1, r33 */                                                              \
    _______, _______, QK_MAKE, _______,                                                  \
    /* le2, re2 */                                                                        \
    _______, QK_MAKE,                                                                     \
    /* l34-l36 | r34-r36 */                                                               \
    _______, _______, _______, QK_MAKE, MS_BTN2, MS_BTN1

// German umlauts, reached by holding G (left hand) or H (right hand).
#define LAYER_UGER                                                                        \
    /* l01-l07 | r01-r07 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, _______, _______, _______, _______, _______,                         \
    /* l08-l14 | r08-r14 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, UM_UE, _______, UM_OE, _______, _______,                             \
    /* l15-l20 | r15-r20 */                                                               \
    _______, UM_AE, UM_SZ, _______, _______, _______,                                     \
    _______, _______, _______, _______, _______, _______,                                 \
    /* l21-l27 | r21-r27 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, _______, _______, _______, _______, _______,                         \
    /* l28-l32 | r28-r32 */                                                               \
    _______, _______, _______, _______, _______,                                           \
    _______, _______, _______, _______, _______,                                           \
    /* l33, le1, re1, r33 */                                                              \
    _______, _______, _______, _______,                                                    \
    /* le2, re2 */                                                                        \
    _______, _______,                                                                     \
    /* l34-l36 | r34-r36 */                                                               \
    _______, _______, _______, _______, _______, _______

// F-keys on the top row, numpad under the right hand, aligned with the number row.
#define LAYER_UFNK                                                                        \
    /* l01-l07 | r01-r07 */                                                               \
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                                   \
    _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,                                   \
    /* l08-l14 | r08-r14 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, KC_7, KC_8, KC_9, _______, KC_F12,                                   \
    /* l15-l20 | r15-r20 */                                                               \
    _______, _______, _______, _______, _______, _______,                                 \
    _______, KC_4, KC_5, KC_6, _______, _______,                                           \
    /* l21-l27 | r21-r27 */                                                               \
    _______, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, KC_1, KC_2, KC_3, _______, _______,                                  \
    /* l28-l32 | r28-r32 */                                                               \
    _______, _______, _______, _______, _______,                                           \
    _______, KC_0, _______, _______, _______,                                              \
    /* l33, le1, re1, r33 */                                                              \
    LED_LEVEL, _______, _______, _______,                                                  \
    /* le2, re2 */                                                                        \
    _______, _______,                                                                     \
    /* l34-l36 | r34-r36 */                                                               \
    _______, _______, _______, _______, _______, _______

// Symbols, F-keys and (on the moonlander) the RGB controls.
#define LAYER_SYMB                                                                        \
    /* l01-l07 | r01-r07 */                                                               \
    VRSN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                                      \
    _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,                                   \
    /* l08-l14 | r08-r14 */                                                               \
    _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______,                           \
    _______, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,                                     \
    /* l15-l20 | r15-r20 */                                                               \
    _______, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,                                    \
    KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, _______,                                           \
    /* l21-l27 | r21-r27 */                                                               \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,                         \
    _______, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, _______,                                  \
    /* l28-l32 | r28-r32 */                                                               \
    EE_CLR, HRM_TIMELESS, _______, AUX_RGB(RM_SPDD), AUX_RGB(RM_SPDU),                       \
    _______, KC_DOT, KC_0, KC_EQL, _______,                                                \
    /* l33, le1, re1, r33 */                                                              \
    AUX_RGB(RM_NEXT), TOGGLE_LAYER_COLOR, _______, AUX_RGB(RM_TOGG),                       \
    /* le2, re2 */                                                                        \
    TOGGLE_LAYER_COLOR, _______,                                                          \
    /* l34-l36 | r34-r36 */                                                               \
    AUX_RGB(RM_VALD), AUX_RGB(RM_VALU), TOGGLE_LAYER_COLOR, _______,                       \
    AUX_RGB(RM_HUED), AUX_RGB(RM_HUEU)

// Plain keys with the modifiers on the outer columns, for gaming. No mod-taps
// anywhere, so this layer is used without HRM().
#define LAYER_GAME                                                                        \
    /* l01-l07 | r01-r07 */                                                               \
    _______, _______, _______, _______, _______, _______, TG(GAME),                        \
    _______, _______, _______, _______, _______, _______, _______,                         \
    /* l08-l14 | r08-r14 */                                                               \
    KC_LALT, _______, _______, _______, _______, _______, _______,                         \
    _______, _______, _______, _______, _______, _______, KC_RALT,                         \
    /* l15-l20 | r15-r20 */                                                               \
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                                 \
    KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_RCTL,                                              \
    /* l21-l27 | r21-r27 */                                                               \
    KC_LSFT, _______, _______, _______, _______, _______, KC_M,                            \
    _______, _______, _______, _______, _______, _______, KC_RSFT,                         \
    /* l28-l32 | r28-r32 */                                                               \
    KC_LGUI, _______, _______, _______, _______,                                           \
    _______, _______, _______, _______, KC_RGUI,                                           \
    /* l33, le1, re1, r33 */                                                              \
    _______, KC_ESC, KC_ESC, _______,                                                      \
    /* le2, re2 */                                                                        \
    KC_ESC, KC_ESC,                                                                       \
    /* l34-l36 | r34-r36 */                                                               \
    KC_SPACE, _______, KC_ESC, KC_ESC, _______, _______
