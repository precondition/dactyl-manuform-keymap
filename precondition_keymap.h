#pragma once

#include QMK_KEYBOARD_H

bool caps_word_lock_on;

enum layer_names {
    _XYLOCUP,
    _SYM,
    _NAV,
    _GNAV,
    _BNAV,
    _MOUSE,
    _ADJUST,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV MO(_NAV)
#define GNAV MO(_GNAV)
#define BNAV OSL(_BNAV)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define XYLOCUP TG(_XYLOCUP)

#ifdef MOUSEKEY_ENABLE
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MS_CAPS KC_CAPS
// Keep the _MOUSE layer (it also holds non-mouse keys and MAGIC_L relies on
// it) but make its mouse keycodes fall through to the layer below.
// The QMK keycodes enum is already defined by QMK_KEYBOARD_H at this point, so
// these macros only shadow the enum names in the keymap.
#    define MS_UP   KC_TRNS
#    define MS_DOWN KC_TRNS
#    define MS_LEFT KC_TRNS
#    define MS_RGHT KC_TRNS
#    define MS_WHLU KC_TRNS
#    define MS_WHLD KC_TRNS
#    define MS_BTN1 KC_TRNS
#    define MS_BTN2 KC_TRNS
#    define MS_BTN3 KC_TRNS
#endif


// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COMPOSE KC_APP
#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute
/*
 * Paste key options in QMK:
 *
 * C(KC_V)    - Ctrl+V. Works in most GUI apps on Windows and Linux, but fails
 *              in terminal applications.
 *
 * G(KC_V)    - Cmd+V. Standard for macOS GUI apps.
 *
 * S(KC_INS)  - Shift+Insert. The universal winner on Windows and Linux: works in
 *              terminals, and GUI applications. Unsupported on macOS.
 *
 * KC_PASTE   - Basically unusable. Almost no apps support this obscure HID keycode.
 */
#define PASTE S(KC_INS)

// Left-hand home row mods
#define HOME_R LGUI_T(KC_R)
#define HOME_N LALT_T(KC_N)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_E RSFT_T(KC_E)
#define HOMERET  RCTL_T(KC_ENTER)
#define HOME_A LALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)

// French accents
// The other common grave accented letters are custom keycodes
// And the rest of other accented letters are accessed using dead keys
#define E_ACUTE ALGR(KC_E)
#define C_CDILA ALGR(KC_COMMA)

#define TMUX_PREFIX_KEY C(KC_B)

// The tap keycode will get entirely overridden by process_magic_left.
#define MAGIC_L LT(_MOUSE, KC_COPY)

enum custom_keycodes {
    ARROW_R = QK_USER,
    // g navigation to move through screen lines in Vim
    G_DOWN,
    G_UP,
    G_HOME,
    G_END,
    // « French quotation marks »
    GUILL_R,
    GUILL_L,
    // French grave accented letters
    E_GRAVE,
    A_GRAVE,
    REPEAT,
    // "Opening brace"
    // Macro for
    // {<enter>
    O_BRACE,
    CAPS_WORD_LOCK,
    // "Opening Bracket-Quote"
    // Macro for
    // ["
    O_BRQOT,
    // "Closing Bracket-Quote"
    // Macro for
    // "]
    C_BRQOT,
    // tmux window navigation
    B_CREAT,
    B_PREV,
    B_NEXT,
    // tmux pane navigation
    B_VERT,
    B_HORIZ,
    B_UP,
    B_LEFT,
    B_DOWN,
    B_RIGHT,
    // tmux copy mode and paste buffer
    B_PASTE,
    B_CPY_M,
    // tmux zoom
    B_ZOOM,
    // tmux close pane
    B_CLOSE,
    // Useful dead keys for French
    //  Dead circumflex (e.g. ^ + e = ê)
    //  The same as KC_CIRCUMFLEX on US intl but setting it as a separate
    //  keycode helps to exclude it from `post_process_record_user`.
    DED_CIR,
    //  Dead Umlaut (e.g. ¨ + e = ë)
    //  The same as KC_DOUBLE_QUOTE on US intl but setting it as a separate
    //  keycode helps to exclude it from `post_process_record_user`.
    DED_UML,
    // Toggle `base_dead_keys` dynamically at run time.
    BDED_ON, // base dead keys ON  (corresponds to US Intl.)
    BDED_OF, // base dead keys OFF (corresponds to US Intl. with AltGr dead keys)
    // Right magic key.
    MAGIC_R,
    // Quoted paste.
    // Especially useful to paste Windows-style backslash file paths in a MSYS
    // terminal.
    QOTPAST,
    // Leader key but not quite, hence the intentional typo.
    // Literally just KC_LALT but without all the special handling that OSL &
    // co. do with modifier keys when on Windows as use for the Alt leader key
    // sequences in apps like Word.  Compose key (menu) on Linux.
    // Shift inverts the meaning.
    LAEDER,
    // Like QK_REP but repeats the last two keys (with their mods), e.g.
    // « ↓␣ » or « ⇧⇥⏎ ».
    REP2,
};

bool base_dead_keys;

// summoned by magic.
uint16_t last_summoned_keycode;

// History of the last keys remembered by QMK's repeat key feature, with their
// mods, sorted from most recent to least recent:
// prev_records[0] = last key
// prev_records[1] = penultimate key
// prev_records[2] = antepenultimate key
// Keys that QMK does not remember (mods, layer keys, one-shot keys, …) do not
// enter the history. QK_REP presses enter it with the QK_REP keycode.
#define PREV_KEYS_WINDOW_LENGTH 3
extern keyrecord_t prev_records[PREV_KEYS_WINDOW_LENGTH];
extern uint8_t prev_mods[PREV_KEYS_WINDOW_LENGTH];

// Shorthands for prev_records[i].keycode and prev_records[i].event.key.
uint16_t prev_keycode(uint8_t i);
keypos_t prev_keypos(uint8_t i);

void process_magic_key_left(void);
void process_magic_key_right(void);


// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

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
