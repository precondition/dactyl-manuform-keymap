#include QMK_KEYBOARD_H
#include "keymap.h"

enum combo_events {
    UY_PRN,
    YCLN_PRN,
    JU_JUST,
    HV_HAVE,
    EV_EVERY,
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
    BSPCQ_QUE,
    NHI_KI,
    PT_B,
    TD_V,
    NH_K,
    LN_J,
    RST_G,
    IET_M,
    FS_G,
    UE_M,
    DELT_THIS,
    ZX_GRAVE,
    DOTSLASH_GRAVE,
    IDOTSLASH_IGRAVE,
    AX_GRAVE,
    XC_ACUTE,
    XCE_ACUTE,
    COMMADOT_ACUTE,
    XDOT_CIRCUM,
    COMBO_LENGTH
};

int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM U_Y_COMBO[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM Y_SCLN_COMBO[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM J_U_COMBO[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM H_V_COMBO[] = {HOME_H, KC_V, COMBO_END};
const uint16_t PROGMEM E_V_COMBO[] = {HOME_E, KC_V, COMBO_END};
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
const uint16_t PROGMEM BSPC_Q_COMBO[] = {KC_BSPC, KC_Q, COMBO_END};
const uint16_t PROGMEM BSPC_T_A_COMBO[] = {KC_BSPC, HOME_T, HOME_A, COMBO_END};
const uint16_t PROGMEM P_T_COMBO[] = {KC_P, HOME_T, COMBO_END};
const uint16_t PROGMEM D_T_COMBO[] = {HOME_D, HOME_T, COMBO_END};
const uint16_t PROGMEM N_H_COMBO[] = {HOME_N, HOME_H, COMBO_END};
const uint16_t PROGMEM N_H_I_COMBO[] = {HOME_N, HOME_H, HOME_I, COMBO_END};
const uint16_t PROGMEM L_N_COMBO[] = {KC_L, HOME_N, COMBO_END};
const uint16_t PROGMEM R_S_T_COMBO[] = {HOME_R, HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM I_E_T_COMBO[] = {HOME_I, HOME_E, HOME_N, COMBO_END};
const uint16_t PROGMEM F_S_COMBO[] = {KC_F, HOME_S, COMBO_END};
const uint16_t PROGMEM U_E_COMBO[] = {KC_U, HOME_E, COMBO_END};
const uint16_t PROGMEM Z_X_COMBO[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM T_G_COMBO[] = {HOME_T, KC_G, COMBO_END};
const uint16_t PROGMEM A_X_COMBO[] = {HOME_A, KC_X, COMBO_END};
const uint16_t PROGMEM X_C_COMBO[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM X_C_E_COMBO[] = {KC_X, KC_C, HOME_E, COMBO_END};
const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA, TD_DOT, COMBO_END};
const uint16_t PROGMEM DOT_SLASH_COMBO[] = {TD_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM I_DOT_SLASH_COMBO[] = {HOME_I, TD_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM X_DOT_COMBO[] = {KC_X, TD_DOT, COMBO_END};
const uint16_t PROGMEM DEL_T_COMBO[] = {KC_DEL, HOME_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [UY_PRN] = COMBO_ACTION(U_Y_COMBO),
    [YCLN_PRN] = COMBO_ACTION(Y_SCLN_COMBO),
    [JU_JUST] = COMBO_ACTION(J_U_COMBO),
    [HV_HAVE] = COMBO_ACTION(H_V_COMBO),
    [EV_EVERY] = COMBO_ACTION(E_V_COMBO),
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
    [BSPCQ_QUE] = COMBO_ACTION(BSPC_Q_COMBO),
    [PT_B] = COMBO(P_T_COMBO, KC_B),
    [TD_V] = COMBO(D_T_COMBO, KC_V),
    [NH_K] = COMBO(N_H_COMBO, KC_K),
    [NHI_KI] = COMBO_ACTION(N_H_I_COMBO),
    [LN_J] = COMBO(L_N_COMBO, KC_J),
    [RST_G] = COMBO(R_S_T_COMBO, KC_G),
    [FS_G] = COMBO(F_S_COMBO, KC_G),
    [UE_M] = COMBO(U_E_COMBO, KC_M),
    [ZX_GRAVE] = COMBO_ACTION(Z_X_COMBO),
    [DOTSLASH_GRAVE] = COMBO_ACTION(DOT_SLASH_COMBO),
    [IDOTSLASH_IGRAVE] = COMBO_ACTION(I_DOT_SLASH_COMBO),
    [AX_GRAVE] = COMBO_ACTION(A_X_COMBO),
    [XC_ACUTE] = COMBO_ACTION(X_C_COMBO),
    [XCE_ACUTE] = COMBO_ACTION(X_C_E_COMBO),
    [COMMADOT_ACUTE] = COMBO_ACTION(COMMA_DOT_COMBO),
    [XDOT_CIRCUM] = COMBO_ACTION(X_DOT_COMBO),
    [DELT_THIS] = COMBO_ACTION(DEL_T_COMBO),
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
                    send_string("[");
                    // "resuming" *the* shift so that you can hold shift 
                    // and the square brackets combo still works without
                    // having to re-press shift every time.
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

        case EV_EVERY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Every");
                    set_mods(mod_state);
                }
                else {
                    send_string("every");
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

        case BSPCTA_THAT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("That");
                    set_mods(mod_state);
                }
                else {
                    send_string("that");
                }
        }
        break;

        case BSPCQ_QUE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Que");
                    set_mods(mod_state);
                }
                else {
                    send_string("que");
                }
        }
        break;

        case NHI_KI:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ki");
                    set_mods(mod_state);
                }
                else {
                    send_string("ki");
                }
        }
        break;

        case ZX_GRAVE:
            if (pressed) {
                tap_code16(ALGR(KC_GRV));
            }
        break;

        case DOTSLASH_GRAVE:
            if (pressed) {
                tap_code16(ALGR(KC_GRV));
            }
        break;

        case AX_GRAVE:
            if (pressed) {
                tap_code16(ALGR(KC_GRV));
            }
        break;

        case XC_ACUTE:
            if (pressed) {
                tap_code16(ALGR(KC_QUOT));
            }
        break;

        case XCE_ACUTE:
            if (pressed) {
                tap_code16(ALGR(KC_QUOT));
                register_code(KC_E);
            } else {
                unregister_code(KC_E);
            }
        break;

        case COMMADOT_ACUTE:
            if (pressed) {
                tap_code16(ALGR(KC_QUOT));
            }
        break;

        case IDOTSLASH_IGRAVE:
            if (pressed) {
                tap_code(KC_I);
                tap_code16(ALGR(KC_GRV));
            }
        break;

        case XDOT_CIRCUM:
            if (pressed) {
                tap_code16(ALGR(KC_6));
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
};
