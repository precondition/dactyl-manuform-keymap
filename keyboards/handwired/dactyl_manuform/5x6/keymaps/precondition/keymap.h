#pragma once

#include QMK_KEYBOARD_H
#include "tapdance.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

enum layer_names {
    _COLEMAK_DH,
    _SYM,
    _NAV,
    _GNAV,
    _MOUSE,
    _PLOVER,
    _ADJUST,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define GNAV MO(_GNAV)
#define SYM MO(_SYM)
#define MOUSE MO(_MOUSE)
#define MS_CAPS LT(_MOUSE, KC_CAPS)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define PLOVER TG(_PLOVER)
#define NAV_UND LT(_NAV, KC_F24)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COMPOSE KC_APP

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_O LGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N LCTL_T(KC_N)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

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
};

