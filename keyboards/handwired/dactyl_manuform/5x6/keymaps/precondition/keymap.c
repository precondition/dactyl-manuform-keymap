/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


void matrix_init_user() {
	set_unicode_input_mode(UC_LNX);
};

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

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)

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
// Initialize boolean variable which
// tells if the last key hit was an accented letter.
static bool has_typed_accent;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {

    case ARROW_R:
      if (record->event.pressed) {
        SEND_STRING("->");
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

    case KC_ESC:
        // Home row alt-tabbing.
        if (mod_state & MOD_MASK_ALT) {
            if (record->event.pressed) {
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        }
        // Else, let QMK process the KC_ESC keycode as usual
        return true;

    case XP(c_CDIL, C_CDIL_U):
        if (record->event.pressed) {
            if (has_typed_accent) {
                register_code(KC_C);
                return false;
            }
            has_typed_accent = true;
        } else {
            if (has_typed_accent) {
                unregister_code(KC_C);
            }
        }
        return true;

    case XP(e_ACUT, E_ACUT_U):
        if (record->event.pressed) {
            if (has_typed_accent) {
                register_code(KC_E);
                return false;
            }
            has_typed_accent = true;
        } else {
            if (has_typed_accent) {
                unregister_code(KC_E);
            }
        }
        return true;

    case HOME_I:
        // This piece of code nullifies the effect of Right Shift when
        // tapping the HOME_I key. This helps rolling over HOME_E and HOME_I
        // to obtain the intended "ei" instead of "I". Consequently, capital I can
        // only be obtained by tapping HOME_I and holding HOME_S (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_E);
                tap_code(KC_I);
                set_mods(mod_state);
                return false;
            }
        }
        // else process HOME_I as usual.
        return true;


    case HOME_N:
         /*This piece of code nullifies the effect of Right Shift when*/
         /*tapping the HOME_N key. This helps rolling over HOME_E and HOME_N */
         /*to obtain the intended "en" instead of "N". Consequently, capital N can */
         /*only be obtained by tapping HOME_N and holding HOME_S (which is the left shift mod tap).*/
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_E);
                tap_code(KC_N);
                set_mods(mod_state);
                return false;
            }
        }
         /*else process HOME_N as usual.*/
        return true;

    case HOME_T:
         /*This piece of code nullifies the effect of Left Shift when*/
         /*tapping the HOME_T key. This helps rolling over HOME_S and HOME_T */
         /*to obtain the intended "st" instead of "T". Consequently, capital T can */
         /*only be obtained by tapping HOME_T and holding HOME_E (which is the right shift mod tap).*/
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_LSHIFT)) {
                unregister_code(KC_LSHIFT);
                tap_code(KC_S);
                tap_code(KC_T);
                set_mods(mod_state);
                return false;
            }
        }
         /*else process HOME_T as usual.*/
        return true;

    case HOME_D:
    // Let HOME_D act as an autorepeatable KC_D when CTRL is held
    {
        static bool d_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_CTRL) {
                register_code(KC_D);
                d_registered = true;
                return false;
            }
        } else {
            if (d_registered) {
                unregister_code(KC_D);
                d_registered = false;
                return false;
            }
        }
    }

    }
    return true;
};

enum {
    DOT_TD = 0,
    XCLM_TD,
    CA_CC_CV,
};

// Tap dance states
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// To do: Look into more advanced tap dance functions
// that have a callback to each tap
void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    /* Detect double tap of TD_DOT */
    if (state->count == 2) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
        /* Check that Shift is inactive */
            SEND_STRING(". ");
            /* Internal code of OSM(MOD_LSFT) */
            set_oneshot_mods(MOD_LSFT | get_oneshot_mods()); // NOTE: Watch out for nullified shift for rolling home row keys
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

void exclamative_sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
            SEND_STRING("! ");
            set_oneshot_mods(MOD_LSFT | get_oneshot_mods()); // NOTE: Watch out for nullified shift for rolling home row keys
    } else {
        for (uint8_t i = state->count; i > 0; i--) {
            tap_code16(KC_EXLM);
        }
    }
}


// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
    } else {
        return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  }
}

// handle the possible states for each tapdance keycode you define:

void CA_CC_CV_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(C(KC_C));
      break;
    case SINGLE_HOLD:
      tap_code16(C(KC_A));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(C(KC_V));
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN (sentence_end),
    [XCLM_TD] = ACTION_TAP_DANCE_FN (exclamative_sentence_end),
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
};

#define TD_XCLM TD(XCLM_TD)
#define TD_DOT TD(DOT_TD)
#define CACCCV TD(CA_CC_CV)

enum combo_events {
    UY_PRN,
    YCLN_PRN,
    JU_JUST,
    HV_HAVE,
    BSPCU_YOU,
    BSPCA_AND,
    BSPCN_NOT,
    BSPCW_WITH,
    BSPCF_FOR,
    BSPCH_HERE,
    BSPCT_THE,
    BSPCM_MENT,
    BSPCG_ING,
    BSPCO_OUGH,
    BSPCI_ION,
    BSPCTA_THAT,
    NHI_KI,
    PT_B,
    TD_V,
    NH_K,
    LN_J,
    RST_G,
    IET_M,
    DELT_THIS,
    COMBO_LENGTH
};
int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM U_Y_COMBO[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM Y_SCLN_COMBO[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM J_U_COMBO[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM H_V_COMBO[] = {HOME_H, KC_V, COMBO_END};
const uint16_t PROGMEM BSPC_U_COMBO[] = {KC_BSPC, KC_U, COMBO_END};
const uint16_t PROGMEM BSPC_A_COMBO[] = {KC_BSPC, HOME_A, COMBO_END};
const uint16_t PROGMEM BSPC_N_COMBO[] = {KC_BSPC, HOME_N, COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[] = {KC_BSPC, KC_W, COMBO_END};
const uint16_t PROGMEM BSPC_F_COMBO[] = {KC_BSPC, KC_F, COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[] = {KC_BSPC, HOME_H, COMBO_END};
const uint16_t PROGMEM BSPC_T_COMBO[] = {KC_BSPC, HOME_T, COMBO_END};
const uint16_t PROGMEM BSPC_M_COMBO[] = {KC_BSPC, KC_M, COMBO_END};
const uint16_t PROGMEM BSPC_G_COMBO[] = {KC_BSPC, KC_G, COMBO_END};
const uint16_t PROGMEM BSPC_O_COMBO[] = {KC_BSPC, HOME_O, COMBO_END};
const uint16_t PROGMEM BSPC_I_COMBO[] = {KC_BSPC, HOME_I, COMBO_END};
const uint16_t PROGMEM BSPC_T_A_COMBO[] = {KC_BSPC, HOME_T, HOME_A, COMBO_END};
const uint16_t PROGMEM P_T_COMBO[] = {KC_P, HOME_T, COMBO_END};
const uint16_t PROGMEM D_T_COMBO[] = {HOME_D, HOME_T, COMBO_END};
const uint16_t PROGMEM N_H_COMBO[] = {HOME_N, HOME_H, COMBO_END};
const uint16_t PROGMEM N_H_I_COMBO[] = {HOME_N, HOME_H, HOME_I, COMBO_END};
const uint16_t PROGMEM L_N_COMBO[] = {KC_L, HOME_N, COMBO_END};
const uint16_t PROGMEM R_S_T_COMBO[] = {HOME_R, HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM I_E_T_COMBO[] = {HOME_I, HOME_E, HOME_N, COMBO_END};
const uint16_t PROGMEM DEL_T_COMBO[] = {KC_DEL, HOME_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [UY_PRN] = COMBO_ACTION(U_Y_COMBO),
    [YCLN_PRN] = COMBO_ACTION(Y_SCLN_COMBO),
    [JU_JUST] = COMBO_ACTION(J_U_COMBO),
    [HV_HAVE] = COMBO_ACTION(H_V_COMBO),
    [BSPCU_YOU] = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCA_AND] = COMBO_ACTION(BSPC_A_COMBO),
    [BSPCN_NOT] = COMBO_ACTION(BSPC_N_COMBO),
    [BSPCW_WITH] = COMBO_ACTION(BSPC_W_COMBO),
    [BSPCF_FOR] = COMBO_ACTION(BSPC_F_COMBO),
    [BSPCH_HERE] = COMBO_ACTION(BSPC_H_COMBO),
    [BSPCT_THE] = COMBO_ACTION(BSPC_T_COMBO),
    [BSPCM_MENT] = COMBO_ACTION(BSPC_M_COMBO),
    [BSPCG_ING] = COMBO_ACTION(BSPC_G_COMBO),
    [BSPCO_OUGH] = COMBO_ACTION(BSPC_O_COMBO),
    [BSPCI_ION] = COMBO_ACTION(BSPC_I_COMBO),
    [BSPCTA_THAT] = COMBO_ACTION(BSPC_T_A_COMBO),
    [PT_B] = COMBO(P_T_COMBO, KC_B),
    [TD_V] = COMBO(D_T_COMBO, KC_V),
    [NH_K] = COMBO(N_H_COMBO, KC_K),
    [NHI_KI] = COMBO_ACTION(N_H_I_COMBO),
    [LN_J] = COMBO(L_N_COMBO, KC_J),
    [RST_G] = COMBO(R_S_T_COMBO, KC_G),
    [IET_M] = COMBO(I_E_T_COMBO, KC_M),
    [DELT_THIS] = COMBO_ACTION(DEL_T_COMBO),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    mod_state = get_mods();
    switch(combo_index) {
        case UY_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("[");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("{");
                    set_mods(mod_state);
                }
                else {
                    send_string("(");
                }
            }
            break;

        case YCLN_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("]");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("}");
                    set_mods(mod_state);
                }
                else {
                    send_string(")");
                }
        }
        break;

        case JU_JUST:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Just");
                    set_mods(mod_state);
                }
                else {
                    send_string("just");
                }
        }
        break;

        case HV_HAVE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Have");
                    set_mods(mod_state);
                }
                else {
                    send_string("have");
                }
        }
        break;

        case BSPCU_YOU:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("You");
                    set_mods(mod_state);
                }
                else {
                    send_string("you");
                }
        }
        break;

        case BSPCA_AND:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("And");
                    set_mods(mod_state);
                }
                else {
                    send_string("and");
                }
        }
        break;

        case BSPCN_NOT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Not");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("n't");
                    set_mods(mod_state);
                }
                else {
                    send_string("not");
                }
        }
        break;

        case BSPCW_WITH:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("With");
                    set_mods(mod_state);
                }
                else {
                    send_string("with");
                }
        }
        break;

        case BSPCF_FOR:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("For");
                    set_mods(mod_state);
                }
                else {
                    send_string("for");
                }
        }
        break;

        case BSPCH_HERE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Here");
                    set_mods(mod_state);
                }
                else {
                    send_string("here");
                }
        }
        break;

        case BSPCT_THE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("The");
                    set_mods(mod_state);
                }
                else {
                    send_string("the");
                }
        }
        break;

        case BSPCM_MENT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ment");
                    set_mods(mod_state);
                }
                else {
                    send_string("ment");
                }
        }
        break;

        case BSPCG_ING:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ing");
                    set_mods(mod_state);
                }
                else {
                    send_string("ing");
                }
        }
        break;

        case BSPCO_OUGH:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ough");
                    set_mods(mod_state);
                }
                else {
                    send_string("ough");
                }
        }
        break;

        case BSPCI_ION:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ion");
                    set_mods(mod_state);
                }
                else {
                    send_string("ion");
                }
        }
        break;

        case PT_B:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("B");
                    set_mods(mod_state);
                }
                else {
                    send_string("b");
                }
        }
        break;

        case TD_V:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("V");
                    set_mods(mod_state);
                }
                else {
                    send_string("v");
                }
        }
        break;

        case NH_K:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("K");
                    set_mods(mod_state);
                }
                else {
                    send_string("k");
                }
        }
        break;

        case LN_J:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("J");
                    set_mods(mod_state);
                }
                else {
                    send_string("j");
                }
        }
        break;

        case DELT_THIS:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("This");
                    set_mods(mod_state);
                }
                else {
                    send_string("this");
                }
        }
        break;

    }
}


/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_I:
            // My ring finger tends to linger on the key
            // This tapping term allows me to type "ion" effortlessly.
            return TAPPING_TERM + 200;
        case HOME_O:
            return TAPPING_TERM + 10;
        case SYM_ENT:
            // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 65;
        // These next mod taps are used very frequently during typing.
        // As such, the lower the tapping term, the faster the typing.
        case HOME_S:
            return TAPPING_TERM - 28;
        case HOME_E:
            return TAPPING_TERM - 26;
        case HOME_D:
            return TAPPING_TERM - 20;
        case HOME_H:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

/*
 * Per key force hold settings
 */
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV:
            return false;
        default:
            return true;
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
           REDO, UNDO  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
         CACCCV, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,    KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,    KC_M  , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
      KC_BSLASH, KC_Z  , KC_X  , KC_C  , HOME_D, KC_V  ,    KC_K  , HOME_H,KC_COMM, TD_DOT,KC_SLSH, KC_GRV,
                      KC_BSLASH,ARROW_R,                                   KC_RALT, KC_GRV,
                                        NAV_TAB,KC_SPC,    KC_BSPC, SYM_ENT,
                                         CACCCV, MOUSE,    KC_DEL , KC_APP ,
                                        PLOVER,KC_CAPS,    SH_OS  , OSM(MOD_LSFT)
  ),

  [_SYM] = LAYOUT_5x6(

        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_BSPC,
        KC_DOT , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,    KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TILD,TD(TD_EXCLM), KC_AT ,KC_HASH,KC_DLR ,KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,KC_MINS,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______, KC_DOT,_______,_______,
                        _______,_______,                                    _______,_______, 
                                        KC_UNDS,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    ADJUST, ADJUST
  ),

  [_NAV] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,KC_NLCK,KC_INS ,KC_SLCK,_______,    KC_PGUP,KC_PGDN, KC_UP ,KC_WH_D,KC_WH_U,KC_MUTE,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______,_______,_______,_______,_______,_______,    _______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,
                        _______,_______,                                    KC_BRID,KC_BRIU,
                                         _______,_______,   _______,_______,
                                         _______,_______,   _______,_______,
                                           ADJUST,ADJUST,   _______,_______
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
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,XP(a_CIRC,A_CIRC_U),_______,_______,_______,_______,    _______,_______,XP(u_CIRC,U_CIRC_U),XP(i_UML,I_UML_U),XP(o_UML,O_UML_U),_______,
        _______,XP(a_GRAV,A_GRAV_U),_______,_______,_______,KC_B,    KC_J,XP(e_GRAV,E_GRAV_U),XP(e_ACUT,E_ACUT_U),XP(i_CIRC,I_CIRC_U),XP(o_CIRC,O_CIRC_U),_______,
        _______,_______,_______,XP(c_CDIL,C_CDIL_U),_______,_______,      _______,_______,XP(e_CIRC,E_CIRC_U),_______,_______,_______,
        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
  ),

    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______, KC_9  , KC_8  , KC_7  ,_______,    _______,KC_WBAK,KC_MS_U,KC_WFWD,_______,_______,
_______,KC_LGUI,LALT_T(KC_6),LSFT_T(KC_5),LCTL_T(KC_4),_______,    _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______, KC_3  , KC_2  , KC_1  ,_______,    _______,KC_BTN3,KC_WH_D,KC_WH_U,_______,_______,
                        _______, KC_0  ,                                    _______,_______,
                                        _______,_______,    KC_BTN1,KC_BTN2,
                                        _______,_______,    KC_BTN3,_______,
                                        _______,_______,    _______,_______
    ),

    [_PLOVER] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,    KC_6   ,KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,    KC_Y   ,KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,    KC_H   ,KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,    KC_N   ,KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                         KC_LBRC,KC_RBRC,                                  KC_PLUS, KC_EQL,
                                         KC_C,   KC_V,      KC_N   , KC_M,
                                         KC_TAB,  KC_B ,    KC_BSPC, KC_DEL,
                                         PLOVER, KC_SPC,    KC_LGUI, KC_LALT
    ),

    [_ADJUST] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______, RESET ,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    )
};
