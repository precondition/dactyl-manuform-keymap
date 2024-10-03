#pragma once

#include QMK_KEYBOARD_H

uint16_t last_keycode;
bool caps_word_lock_on;

enum layer_names {
    _COLEMAK_DH,
    _PLOVER,
    _SYM,
    _NAV,
    _GNAV,
#ifdef MOUSEKEY_ENABLE
    _MOUSE,
#endif
    _ADJUST,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV MO(_NAV)
#define GNAV MO(_GNAV)
#define SYM MO(_SYM)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define PLOVER TG(_PLOVER)

#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif


// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COMPOSE KC_APP
#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_O RGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N RCTL_T(KC_N)

// One Shot Modifiers
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)

// French accents
// The other common grave accented letters are custom keycodes
// And the rest of other accented letters are accessed using dead keys
#define E_ACUTE ALGR(KC_E)
#define C_CDILA ALGR(KC_COMMA)
// Useful dead keys for French
#define DED_CIR ALGR(KC_6)
#define DED_UML S(ALGR(KC_QUOT))

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    // g navigation to move through screen lines in Vim
    G_DOWN,
    G_UP,
    G_HOME,
    G_END,
    // « French quotation marks »
    GUILL_R,
    GUILL_L,
    // Macro to refer to the parent directory in Linux ../
    UPDIR,
    // French grave accented letters
    E_GRAVE,
    A_GRAVE,
    // Macro for 
    // std::cout << | << "\n";
    // (with | representing the cursor position)
    COUTLN,
    REPEAT,
    // "Opening brace"
    // Macro for
    // {<enter>
    O_BRACE,
    // "Closing brace"
    // Macro for
    // }<enter>
    C_BRACE,
    CAPS_WORD_LOCK,
    // "Opening Bracket-Quote"
    // Macro for
    // ["
    O_BRQOT,
    // "Closing Bracket-Quote"
    // Macro for
    // "]
    C_BRQOT,
    // "QMK Version"
    // Prints the keyboard name, QMK version and build date
    QK_VERS,
};

#ifdef TAP_DANCE_ENABLE
enum {
    DOT_TD,
};

#define TD_DOT TD(DOT_TD)
#else
#define TD_DOT KC_DOT
#endif


// The lowest row of thumb keys is wired a little differently from the layout macro on my specific build
#undef LAYOUT_5x6
#define LAYOUT_5x6(\
  L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
            L42, L43,                                              R42, R43,           \
                      L44, L45,                          R40, R41,                     \
                                L54, L55,      R50, R51,                               \
                                L53, L52,      R53, R52                                \
  ) \
  { \
    { L00,   L01,   L02, L03, L04, L05 }, \
    { L10,   L11,   L12, L13, L14, L15 }, \
    { L20,   L21,   L22, L23, L24, L25 }, \
    { L30,   L31,   L32, L33, L34, L35 }, \
    { KC_NO, KC_NO, L42, L43, L44, L45 }, \
    { KC_NO, KC_NO, L52, L53, L54, L55 }, \
                                          \
    { R00, R01, R02, R03, R04,   R05   }, \
    { R10, R11, R12, R13, R14,   R15   }, \
    { R20, R21, R22, R23, R24,   R25   }, \
    { R30, R31, R32, R33, R34,   R35   }, \
    { R40, R41, R42, R43, KC_NO, KC_NO }, \
    { R50, R51, R52, R53, KC_NO, KC_NO }  \
}
