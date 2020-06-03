/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 
/* The last/lowest row of keys on the keyboard seems to be mixed up within each split. */

#include QMK_KEYBOARD_H


void matrix_init_user() {
	set_unicode_input_mode(UC_LNX);
};

// Layer names
#define _COLEMAK_DHM 0
#define _SYM 1
#define _NAV 2
#define _GNAV 3
#define _ACCENTS 4
#define _MOUSE 5
#define _UPPER 6
#define _LOWER 7
#define _ADJUST 8

// Layer keys
#define NAV MO(_NAV)
#define GNAV MO(_GNAV)
#define SYM MO(_SYM)
#define ACCENTS OSL(_ACCENTS)
#define MOUSE MO(_MOUSE)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define LW_SPC LT(_LOWER, KC_SPC)
#define UP_BSPC LT(_UPPER, KC_BSPC)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)
#define D_EOF LCTL(KC_D)

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

enum unicode_names {
        e_ACUT,
        E_ACUT_U,
        u_ACUT,
        U_ACUT_U,
        a_GRAV,
        A_GRAV_U,
        e_GRAV,
        E_GRAV_U,
        u_GRAV,
        U_GRAV_U,
        a_CIRC,
        A_CIRC_U,
        e_CIRC,
        E_CIRC_U,
        i_CIRC,
        I_CIRC_U,
        o_CIRC,
        O_CIRC_U,
        u_CIRC,
        U_CIRC_U,
        i_UML,
        I_UML_U,
        o_UML,
        O_UML_U,
        c_CDIL,
        C_CDIL_U
};

const uint32_t PROGMEM unicode_map[] = {
    [e_ACUT] = 0x00E9,
    [E_ACUT_U] = 0x00C9,
    [u_ACUT] = 0x00F9,
    [U_ACUT_U] = 0x00D9,
    [a_GRAV] = 0x00E0,
    [A_GRAV_U] = 0x00C0,
    [e_GRAV] = 0x00E8,
    [E_GRAV_U] = 0x00C8,
    [u_GRAV] = 0x00F9,
    [U_GRAV_U] = 0x00D9,
    [a_CIRC] = 0x00E2,
    [A_CIRC_U] = 0x00C2,
    [e_CIRC] = 0x00EA,
    [E_CIRC_U] = 0x00CA,
    [i_CIRC] = 0x00EE,
    [I_CIRC_U] = 0x00CE,
    [o_CIRC] = 0x00F4,
    [O_CIRC_U] = 0x00D4,
    [u_CIRC] = 0x00FB,
    [U_CIRC_U] = 0x00DB,
    [i_UML]  = 0x00EF,
    [I_UML_U]  = 0x00CF,
    [o_UML]  = 0x00F6,
    [O_UML_U]  = 0x00DC,
    [c_CDIL] = 0x00E7,
    [C_CDIL_U] = 0x00C7
};

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    G_DOWN,
    G_UP,
    G_HOME,
    G_END
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {

    case HOME_N:
        if (record->event.pressed) {
            // when RCTL is activated
        } else {
            // when "n" is tapped
        }
        break;

    case ARROW_R:
      if (record->event.pressed) {
        // when keycode ARROW_R is pressed
        SEND_STRING("->");
      } else {
        // when keycode ARROW_R is released
      }
      break;

    case G_DOWN:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_DOWN);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_DOWN);
        }
	  break;

    case G_UP:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_UP);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_UP);
        }
	  break;

    case G_HOME:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_HOME);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_HOME);
        }
	  break;

    case G_END:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_END);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_END);
        }
		break;

    }
    return true;
};

enum {
    TD_DOT = 0
};

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    /* Detect double tap of TD_DOT */
    if (state->count == 2) {
        /* Check that Shift is inactive */
        if (!(get_mods() & MOD_MASK_SHIFT)) {
            SEND_STRING(". ");
            /* Internal code of OSM(MOD_LSFT) */
            set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
        } else { // shift is active, so send '>>'
            tap_code(KC_DOT);
            tap_code(KC_DOT);
        }
    }
    else {
        /* send KC_DOT as many times as I have tapped the TD_DOT key */
        for (uint8_t i = state->count; i > 0; i--) {
            tap_code(KC_DOT);
        }
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_DOT] = ACTION_TAP_DANCE_FN (sentence_end)
};

enum combo_events {
  UY_PRN,
  YCLN_PRN,
  ZX_BCKSLSH,
  SPCU_YOU,
};

const uint16_t PROGMEM U_Y_COMBO[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM Y_SCLN_COMBO[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM Z_X_COMBO[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM SPC_U_COMBO[] = {KC_SPC, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UY_PRN] = COMBO_ACTION(U_Y_COMBO),
  [YCLN_PRN] = COMBO_ACTION(Y_SCLN_COMBO),
  [ZX_BCKSLSH] = COMBO_ACTION(Z_X_COMBO),
  [SPCU_YOU] = COMBO_ACTION(SPC_U_COMBO),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    mod_state = get_mods();
    switch(combo_index) {
        case UY_PRN:
          if (pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                // First canceling both shifts so that shift isn't applied
                // to the KC_LBRC keycode since that would result in
                // a "{" instead of a "[".
                unregister_code(KC_LSHIFT);
                unregister_code(KC_RSHIFT);
                tap_code16(KC_LBRC);
                // "resuming" *the* shift so that you can hold shift 
                // and the square brackets combo still works without
                // having to re-press shift every time.
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_CTRL) {
                unregister_code(KC_LCTL);
                tap_code16(KC_LCBR);
                set_mods(mod_state);
            } else {
                tap_code16(KC_LPRN);
            }
          }
          break;
        case YCLN_PRN:
          if (pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                unregister_code(KC_LSHIFT);
                unregister_code(KC_RSHIFT);
                tap_code16(KC_RBRC);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_CTRL) {
                unregister_code(KC_LCTL);
                tap_code16(KC_RCBR);
                set_mods(mod_state);
            } else {
                tap_code16(KC_RPRN);
            }
          }
          break;
        case ZX_BCKSLSH:
          if (pressed) {
            register_code(KC_BSLASH);  
          } else {
            unregister_code(KC_BSLASH);
          }
          break;
        case SPCU_YOU:
          if (pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                unregister_code(KC_LSHIFT);
                unregister_code(KC_RSHIFT);
                send_string("You");
                set_mods(mod_state);
            } else {
              send_string("you");
              }
          } else {
          }
          break;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_I:
            return TAPPING_TERM + 220;
        case HOME_S:
            return TAPPING_TERM - 30;
        case HOME_E:
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{5,10}, {4,10}, {3,10}, {2,10}, {1,10}, {0,10}},
    {{5,11}, {4,11}, {3,11}, {2,11}, {1,11}, {0,11}},

    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};

/*MAKE SURE THAT ADJUST AND RESET ARE ACCESSIBLE !!*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DHM] = LAYOUT_5x6(
        REDO, UNDO  , CUT   , COPY  , D_EOF , PASTE ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
      KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,                         KC_M  , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
   KC_BSLASH, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                         KC_K  , KC_H  ,KC_COMM,TD(TD_DOT),KC_SLSH, KC_GRV,
                     KC_CAPS,ARROW_R,                                                       KC_RALT, KC_APP,
                                      NAV  ,  KC_SPC,                         KC_BSPC, SYM_ENT,
                                      ACCENTS, MOUSE  ,                       KC_DEL ,OSM(MOD_RSFT),
                                      KC_LALT, KC_LGUI,                       KC_LCTL,SH_OS
  ),

  [_SYM] = LAYOUT_5x6(

        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                      KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        KC_DOT , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_COMM,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                      KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,KC_MINS,
        _______,_______,KC_LBRC,KC_LCBR,KC_LPRN,_______,                      _______,KC_RPRN,KC_RCBR,KC_RBRC,_______,_______,
                        _______,_______,                                                      KC_PLUS, KC_EQL, 
                                        _______,KC_UNDS,                      _______,_______,
                                        _______,_______,                      _______,_______,
                                        _______,_______,                      ADJUST, ADJUST
  ),

  [_NAV] = LAYOUT_5x6(
       _______,_______,_______,_______,_______,_______,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,KC_NLCK,KC_INS ,KC_SLCK,_______,                        KC_PGUP,KC_PGDN, KC_UP ,KC_WH_D,KC_WH_U,KC_MUTE,
       _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,                        KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
       _______,_______,_______,_______,_______,KC_SLCK,                        _______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,
                       _______,_______,                                                        KC_BRID,KC_BRIU,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                                 ADJUST,ADJUST,            _______,_______
  ),

    [_GNAV] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______, G_UP  ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    G_HOME ,_______, G_DOWN,_______, G_END ,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),


    [_ACCENTS] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,     _______,_______,XP(u_CIRC,U_CIRC_U),_______,_______,_______,
        _______,XP(a_CIRC,A_CIRC_U),_______,_______,_______,_______,    _______,_______,XP(u_GRAV,U_GRAV_U),XP(i_UML,I_UML_U),XP(o_UML,O_UML_U),_______,
        _______,XP(a_GRAV,A_GRAV_U),_______,_______,_______,_______,    _______,XP(e_GRAV,E_GRAV_U),XP(e_ACUT,E_ACUT_U),XP(i_CIRC,I_CIRC_U),XP(o_CIRC,O_CIRC_U),_______,
        _______,_______,_______,XP(c_CDIL,C_CDIL_U),_______,_______,      _______,_______,XP(e_CIRC,E_CIRC_U),_______,_______,_______,
        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
  ),

    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,    _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_BTN3,KC_WH_D,KC_WH_U,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    KC_BTN1,KC_BTN2,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),

    [_UPPER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,     KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    KC_BSPC,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),

    [_LOWER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
      KC_BSLASH, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,     KC_K  , KC_H  ,KC_COMM,TD(TD_DOT),KC_SLSH, KC_GRV,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),

    [_ADJUST] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,RESET,      _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    )
};
