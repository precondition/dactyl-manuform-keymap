#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum combo_events {
    /* Backspace steno-lite combos */
    // These let me type common words and n-grams
    // more quickly, in one single stroke.
    BSPCEV_EVERY,
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
    BSPCIS_IONS,
    BSPCTA_THAT,
    BSPCQ_QUE,
    // I use the word "key" much more frequently than the common folk
    // and if you're reading this, you probably do too
    BSPCK_KEY,
    BSPCTS_THIS,
    BSPCDN_DONT,
    BSPCIT_IN_THE,

    /* Other steno-lite combos */
    // Additional steno-lite combos for common words and n-grams
    // that do not involve the backspace thumb key because these
    // combinations of keys do not generate too many conflicts
    // in normal typing.
    JU_JUST,
    HV_HAVE,
    QK_QMK,
    DELT_THIS,
    KB_KEYBOARD,
    WA_WHAT,

    /* Non-alphanumeric combos */
    // Combos for which the output isn't one or more alphanumeric characters
    UY_PRN,
    YCLN_PRN,
    UYCLN_INDEX,
    OS_SFT_CAPS,

    /* Vertical combos */
    // An attempt to radically remove all lateral movements
    // by substituting the inner index keys by vertical combos
    // of the main index column keys
    PT_B,
    TD_V,
    NH_K,
    LN_J,
    IET_M,
    FS_G,
    UE_EU,
    NHI_KI,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_E_V_COMBO[] = {KC_BSPC,  HOME_E,  KC_V,    COMBO_END};
const uint16_t PROGMEM BSPC_U_COMBO[]   = {KC_BSPC,  KC_U,    COMBO_END};
const uint16_t PROGMEM BSPC_A_COMBO[]   = {KC_BSPC,  HOME_A,  COMBO_END};
const uint16_t PROGMEM BSPC_N_COMBO[]   = {KC_BSPC,  HOME_N,  COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[]   = {KC_BSPC,  KC_W,    COMBO_END};
const uint16_t PROGMEM BSPC_F_COMBO[]   = {KC_BSPC,  KC_F,    COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[]   = {KC_BSPC,  KC_H,    COMBO_END};
const uint16_t PROGMEM BSPC_T_COMBO[]   = {KC_BSPC,  HOME_T,  COMBO_END};
const uint16_t PROGMEM BSPC_M_COMBO[]   = {KC_BSPC,  KC_M,    COMBO_END};
const uint16_t PROGMEM BSPC_G_COMBO[]   = {KC_BSPC,  KC_G,    COMBO_END};
const uint16_t PROGMEM BSPC_O_COMBO[]   = {KC_BSPC,  HOME_O,  COMBO_END};
const uint16_t PROGMEM BSPC_I_COMBO[]   = {KC_BSPC,  HOME_I,  COMBO_END};
const uint16_t PROGMEM BSPC_I_S_COMBO[] = {KC_BSPC,  HOME_I,  HOME_S,  COMBO_END};
const uint16_t PROGMEM BSPC_Q_COMBO[]   = {KC_BSPC,  KC_Q,    COMBO_END};
const uint16_t PROGMEM BSPC_K_COMBO[]   = {KC_BSPC,  KC_K,    COMBO_END};
const uint16_t PROGMEM BSPC_T_S_COMBO[] = {KC_BSPC,  HOME_T,  HOME_S,  COMBO_END};
const uint16_t PROGMEM K_B_COMBO[]      = {KC_K,     KC_B,    COMBO_END};
const uint16_t PROGMEM BSPC_T_A_COMBO[] = {KC_BSPC,  HOME_T,  HOME_A,  COMBO_END};
const uint16_t PROGMEM BSPC_D_N_COMBO[] = {KC_BSPC,  KC_D,    HOME_N,  COMBO_END};
const uint16_t PROGMEM BSPC_I_T_COMBO[] = {KC_BSPC,  HOME_I,  HOME_T,  COMBO_END};
const uint16_t PROGMEM DEL_T_COMBO[]    = {KC_DEL,   HOME_T,  COMBO_END};
const uint16_t PROGMEM J_U_COMBO[]      = {KC_J,     KC_U,    COMBO_END};
const uint16_t PROGMEM H_V_COMBO[]      = {KC_H,     KC_V,    COMBO_END};
const uint16_t PROGMEM Q_K_COMBO[]      = {KC_Q,     KC_K,    COMBO_END};
const uint16_t PROGMEM W_A_COMBO[]      = {KC_W,     HOME_A,  COMBO_END};
const uint16_t PROGMEM U_Y_COMBO[]      = {KC_U,     KC_Y,    COMBO_END};
const uint16_t PROGMEM Y_SCLN_COMBO[]   = {KC_Y,     KC_SCLN, COMBO_END};
const uint16_t PROGMEM U_Y_SCLN_COMBO[] = {KC_U,     KC_Y,    KC_SCLN, COMBO_END};
const uint16_t PROGMEM OS_SFT_COMBO[]   = {OS_LSFT,  OS_RSFT, COMBO_END};
const uint16_t PROGMEM P_T_COMBO[]      = {KC_P,     HOME_T,  COMBO_END};
const uint16_t PROGMEM D_T_COMBO[]      = {KC_D,     HOME_T,  COMBO_END};
const uint16_t PROGMEM N_H_COMBO[]      = {HOME_N,   KC_H,    COMBO_END};
const uint16_t PROGMEM N_H_I_COMBO[]    = {HOME_N,   KC_H,    HOME_I,  COMBO_END};
const uint16_t PROGMEM L_N_COMBO[]      = {KC_L,     HOME_N,  COMBO_END};
const uint16_t PROGMEM F_S_COMBO[]      = {KC_F,     HOME_S,  COMBO_END};
const uint16_t PROGMEM U_E_COMBO[]      = {KC_U,     HOME_E,  COMBO_END};

combo_t key_combos[] = {
    [BSPCEV_EVERY] = COMBO_ACTION(BSPC_E_V_COMBO),
    [BSPCU_YOU]    = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCA_AND]    = COMBO_ACTION(BSPC_A_COMBO),
    [BSPCN_NOT]    = COMBO_ACTION(BSPC_N_COMBO),
    [BSPCW_WITH]   = COMBO_ACTION(BSPC_W_COMBO),
    [BSPCF_FOR]    = COMBO_ACTION(BSPC_F_COMBO),
    [BSPCH_HERE]   = COMBO_ACTION(BSPC_H_COMBO),
    [BSPCT_THE]    = COMBO_ACTION(BSPC_T_COMBO),
    [BSPCM_MENT]   = COMBO_ACTION(BSPC_M_COMBO),
    [BSPCG_ING]    = COMBO_ACTION(BSPC_G_COMBO),
    [BSPCO_OUGH]   = COMBO_ACTION(BSPC_O_COMBO),
    [BSPCI_ION]    = COMBO_ACTION(BSPC_I_COMBO),
    [BSPCIS_IONS]  = COMBO_ACTION(BSPC_I_S_COMBO),
    [BSPCTA_THAT]  = COMBO_ACTION(BSPC_T_A_COMBO),
    [BSPCQ_QUE]    = COMBO_ACTION(BSPC_Q_COMBO),
    [BSPCK_KEY]    = COMBO_ACTION(BSPC_K_COMBO),
    [BSPCTS_THIS]  = COMBO_ACTION(BSPC_T_S_COMBO),
    [BSPCDN_DONT]  = COMBO_ACTION(BSPC_D_N_COMBO),
    [BSPCIT_IN_THE]= COMBO_ACTION(BSPC_I_T_COMBO),
    [DELT_THIS]    = COMBO_ACTION(DEL_T_COMBO),
    [JU_JUST]      = COMBO_ACTION(J_U_COMBO),
    [HV_HAVE]      = COMBO_ACTION(H_V_COMBO),
    [QK_QMK]       = COMBO_ACTION(Q_K_COMBO),
    [KB_KEYBOARD]  = COMBO_ACTION(K_B_COMBO),
    [WA_WHAT]      = COMBO_ACTION(W_A_COMBO),
    [OS_SFT_CAPS]  = COMBO(OS_SFT_COMBO, CAPS_WORD),
    [UY_PRN]       = COMBO_ACTION(U_Y_COMBO),
    [YCLN_PRN]     = COMBO_ACTION(Y_SCLN_COMBO),
    [UYCLN_INDEX]  = COMBO_ACTION(U_Y_SCLN_COMBO),
    [PT_B]         = COMBO(P_T_COMBO, MOUSE),
    [TD_V]         = COMBO(D_T_COMBO, KC_V),
    [NH_K]         = COMBO(N_H_COMBO, KC_K),
    [NHI_KI]       = COMBO_ACTION(N_H_I_COMBO),
    [LN_J]         = COMBO(L_N_COMBO, KC_J),
    [FS_G]         = COMBO(F_S_COMBO, KC_G),
    [UE_EU]        = COMBO_ACTION(U_E_COMBO),
};

// 5074 bytes free without using steno_combo
void steno_combo(const char *lowercase, const char *uppercase, const char *ctrlcase, bool pressed, uint8_t mod_state) {
    if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            unregister_mods(MOD_MASK_SHIFT);
            send_string(uppercase);
            set_mods(mod_state);
        } else if (ctrlcase && mod_state & MOD_MASK_CTRL) {
            unregister_mods(MOD_MASK_CTRL);
            send_string(ctrlcase);
            set_mods(mod_state);
        } else {
            send_string(lowercase);
        }
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos,
    // like UY_PRN or BSPCN_NOT, more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
    mod_state = get_mods();
#ifdef CONSOLE_ENABLE
    combo_t *combo = &key_combos[combo_index];
    uint8_t idx = 0;
    uint16_t combo_keycode;
    while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        uprintf("kcombo: 0x%04X, pressed: %b\n", combo_keycode, pressed);
        idx++;
    }
#endif
    switch(combo_index) {
        case UY_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    // First canceling both shifts so that shift isn't applied
                    // to the KC_LBRC keycode since that would result in
                    // a "{" instead of a "[".
                    del_mods(MOD_MASK_SHIFT);
                    send_string("[");
                    // "resuming" *the* shift so that you can hold shift
                    // and the square brackets combo still works without
                    // having to re-press shift every time.
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
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
                    del_mods(MOD_MASK_SHIFT);
                    send_string("]");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("}");
                    set_mods(mod_state);
                }
                else {
                    send_string(")");
                }
        }
        break;

        case UYCLN_INDEX:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("[1]");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("[0]");
                    set_mods(mod_state);
                }
                else {
                    send_string("[i]");
                }
        }
        break;

        case JU_JUST:
        steno_combo("just", "Just", NULL, pressed, mod_state);
        break;

        case HV_HAVE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Have");
                    set_mods(mod_state);
                }
                else {
                    send_string("have");
                }
        }
        break;

        case QK_QMK:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    send_string("QMK");
                    set_mods(mod_state);
                }
                else {
                    send_string("qmk");
                }
        }
        break;

        case BSPCEV_EVERY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Not");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
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
                if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("ould");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ion");
                    set_mods(mod_state);
                }
                else {
                    send_string("ion");
                }
        }
        break;

        case BSPCIS_IONS:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ions");
                    set_mods(mod_state);
                }
                else {
                    send_string("ions");
                }
        }
        break;

        case BSPCTA_THAT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
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
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Que");
                    set_mods(mod_state);
                }
                else {
                    send_string("que");
                }
        }
        break;

        case BSPCK_KEY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Key");
                    set_mods(mod_state);
                }
                else {
                    send_string("key");
                }
        }
        break;

        case KB_KEYBOARD:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Keyboard");
                    set_mods(mod_state);
                }
                else {
                    send_string("keyboard");
                }
        }
        break;

        case NHI_KI:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ki");
                    set_mods(mod_state);
                }
                else {
                    send_string("ki");
                }
        }
        break;

        case UE_EU:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Eu");
                    set_mods(mod_state);
                }
                else {
                    send_string("eu");
                }
        }
        break;

        case DELT_THIS:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("This");
                    set_mods(mod_state);
                }
                else {
                    send_string("this");
                }
        }
        break;

        case WA_WHAT:
            steno_combo("what", "What", NULL, pressed, mod_state);
        break;

        case BSPCTS_THIS:
            steno_combo("this", "This", NULL, pressed, mod_state);
        break;

        case BSPCDN_DONT:
            steno_combo("don't", "Don't", NULL, pressed, mod_state);
        break;

        case BSPCIT_IN_THE:
            steno_combo("in the", "In the", NULL, pressed, mod_state);
        break;
    }
};
