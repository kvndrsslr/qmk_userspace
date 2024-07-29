#define HM_A    LSFT_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LGUI_T(KC_F)
#define HM_J    RGUI_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_QUOT RSFT_T(KC_QUOT)

#define HRML(k1,k2,k3,k4) LSFT_T(k1),LALT_T(k2),LCTL_T(k3),LGUI_T(k4)
#define HRMR(k1,k2,k3,k4) RGUI_T(k1),RCTL_T(k2),RALT_T(k3),RSFT_T(k4)

enum layers {
    UBSE,
    UQGM,
    USYM,
    UGER,
    UFNK,
    GAME,
};

// Unicode
enum unicode_names {
    AU,
    AAU,
    OU,
    OOU,
    UU,
    UUU,
    SZ,
    SSZ
};

#define MUC_SZ   UP(SZ, SSZ)
#define MUC_AUML UP(AU, AAU)
#define MUC_OUML UP(OU, OOU)
#define MUC_UUML UP(UU, UUU)


// Mod-tap wrapper
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07, \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14, \
    l15, l16, l17, l18, l19, l20,              r15, r16, r17, r18, r19, r20, \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27, \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32, \
                             l33, le1,    re1, r33,                          \
                                  le2,    re2,                               \
                        l34, l35, l36,    r34, r35, r36                      \
) \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07, \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14, \
    l15, HRML(l16, l17, l18, l19), l20,  r15, HRMR(r16, r17, r18, r19), r20, \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27, \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32, \
                             l33, le1,    re1, r33,                          \
                                  le2,    re2,                               \
                        l34, l35, l36,    r34, r35, r36                      \



#define C_72(k) CONV_76_TO_72(k)
#define CONV_76_TO_72( \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07, \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14, \
    l15, l16, l17, l18, l19, l20,              r15, r16, r17, r18, r19, r20, \
    l21, l22, l23, l24, l25, l26, l27,    r21, r22, r23, r24, r25, r26, r27, \
    l28, l29, l30, l31, l32,                        r28, r29, r30, r31, r32, \
                             l33, le1,    re1, r33,                          \
                                  le2,    re2,                               \
                        l34, l35, l36,    r34, r35, r36                      \
) \
    l01, l02, l03, l04, l05, l06, l07,    r01, r02, r03, r04, r05, r06, r07, \
    l08, l09, l10, l11, l12, l13, l14,    r08, r09, r10, r11, r12, r13, r14, \
    l15, l16, l17, l18, l19, l20, l27,    r21, r15, r16, r17, r18, r19, r20, \
    l21, l22, l23, l24, l25, l26,              r22, r23, r24, r25, r26, r27, \
    l28, l29, l30, l31, l32, l33,              r33, r28, r29, r30, r31, r32, \
                        l34, l35, l36,    r36, r35, r34

#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _____________CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWY_L3_____________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define _____________CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _____________CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H,
#define _____________CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10


#define __BASE__ \
    KC_EQL , ________________NUMBER_LEFT________________, XXXXXXX, XXXXXXX, ________________NUMBER_RIGHT_______________, KC_MINS, \
    KC_ESC , _________________QWERTY_L1_________________, XXXXXXX, XXXXXXX, _________________QWERTY_R1_________________, KC_ESC , \
    KC_BSPC, _________________QWERTY_L2_________________,                   _________________QWERTY_R2_________________, KC_DEL , \
    KC_LSFT, _________________QWERTY_L3_________________, XXXXXXX, XXXXXXX, _________________QWERTY_R3_________________, KC_RSFT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                              \
                                                          XXXXXXX, XXXXXXX,                                                       \
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __QGML__ \
    KC_EQL , ________________NUMBER_LEFT________________, XXXXXXX, XXXXXXX, ________________NUMBER_RIGHT_______________, KC_MINS, \
    KC_ESC , _____________CARPLAX_QGMLWY_L1_____________, XXXXXXX, XXXXXXX, _____________CARPLAX_QGMLWY_R1_____________, KC_ESC , \
    KC_BSPC, _____________CARPLAX_QGMLWY_L2_____________,                   _____________CARPLAX_QGMLWY_R2_____________, KC_DEL , \
    KC_LSFT, _____________CARPLAX_QGMLWY_L3_____________, XXXXXXX, XXXXXXX, _____________CARPLAX_QGMLWY_R3_____________, KC_RSFT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                              \
                                                          XXXXXXX, XXXXXXX,                                                       \
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX



#define _BASE \
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(GAME),                                          _______       , KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS, \
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           MO(UFNK),                                          MO(UFNK),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_ESCAPE, \
    KC_BACKSPACE,   HM_A,           LALT_T(KC_S),   LCTL_T(KC_D),   LGUI_T(KC_F),   LT(UGER,KC_G),                                                                     LT(UGER,KC_H),     RGUI_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RSFT_T(KC_SEMICOLON),      KC_DELETE, \
    KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           MO(USYM),                                          MO(USYM),          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSFT, \
    OSM(MOD_HYPR),  OSM(MOD_MEH),   KC_BACKSLASH,      KC_GRAVE,       SH_T(KC_QUOTE),                                                                                                       KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,    _______       , OSM(MOD_MEH),   OSM(MOD_HYPR), \
                                                                                                    _______, _______       , _______       , _______       , \
                                                                                                                    _______       , _______       , \
                                                                                    LT(USYM,KC_SPACE),       KC_TAB,      LGUI(KC_SPACE)       ,          QK_BOOT,          KC_TAB,         KC_ENTER


