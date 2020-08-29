#pragma once

#include QMK_KEYBOARD_H
#include "tapdance.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

enum layer_names {
    _COLEMAK_DHM = 0,
    _SYM,
    _NAV,
    _GNAV,
    _ACCENTS,
    _MOUSE,
    _PLOVER,
    _ADJUST,
};

// Layer keys
#define NAV TT(_NAV)
#define NAV_TAB LT(_NAV, KC_TAB)
#define GNAV MO(_GNAV)
#define SYM MO(_SYM)
#define ACCENTS OSL(_ACCENTS)
#define MOUSE MO(_MOUSE)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define PLOVER TG(_PLOVER)
#define NAV_UND LT(_NAV, KC_F24)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define DED_CIR ALGR(KC_6)
#define COMPOSE KC_APP

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_D LT(_ACCENTS, KC_D)

// Right-hand home row mods
#define HOME_O LGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N LCTL_T(KC_N)
#define HOME_H LT(_ACCENTS, KC_H)

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    G_DOWN,
    G_UP,
    G_HOME,
    G_END
};

