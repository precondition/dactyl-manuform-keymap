/* Colemak DHm with home row mods and hybrid steno
 * for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// All custom keycodes and aliases can be found in precondtion_keymap.h
#include "precondition_keymap.h"

/*MAKE SURE THAT ADJUST AND QK_BOOT ARE ACCESSIBLE ON BOTH HALVES!*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|   `   |   "   |  F4   |  F5   | |   ¨   |   ^   |   È   |   É   |--------------.
 * | UNDO  | REDO  |-------+-------+-------+-------| |-------+-------+-------+-------|  F10  | F11  |
 * |-------+-------|   W   |   F   |   P   |   B   | |   J   |   L   |   U   |   Y   |-------+------|
 * |   À   |   Q   |-------+-------+-------+-------| |-------+-------+-------+-------|  : ;  | - _  |
 * |-------+-------|  R/⎇  |  S/⇧  |  T/⎈  |   G   | |   M   |  N/⎈  |  E/⇧  |  I/⎇  |-------+------|
 * |  ESC  |  A/◆  |-------+-------+-------+-------| |-------+-------+-------+-------|  O/◆  | ' "  |
 * |-------+-------|   X   |   C   |   D   |   V   | |   K   |   H   |  , <  |  . >  |-------+------|
 * |   Z   |REPEAT |-------+-------+---------------' `---------------+-------+-------|  / ?  |-> => |
 * `---------------|TG_MIC |   Ç   |                                 | AltGr |   `   |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |TAB/NAV|  SPC  | | BSPC  | ⏎/SYM |
 *                                 |-------+-------| |-------+-------|
 *                                 |COMPOSE|1-SHOT⇧| |1-SHOT⇧|  UP   |
 *                                 |-------+-------| |-------+-------|
 *                                 |PLOVER |CAPS/MS| |SWAPHND| DOWN  |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
  [_COLEMAK_DH] = LAYOUT_5x6(
           UNDO, REDO  , KC_GRV,KC_DQUO, KC_F4 , KC_F5 ,    DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,    KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,    KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
           KC_Z, REPEAT, KC_X  , KC_C  , KC_D  , KC_V  ,    KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,
                         TG_MIC,C_CDILA,                                    KC_RALT, KC_GRV,
                                        NAV_TAB, KC_SPC,    KC_BSPC,SYM_ENT,
                                        COMPOSE,OS_LSFT,    OS_RSFT, KC_UP ,
                                        PLOVER ,MS_CAPS,    SH_OS  ,KC_DOWN
  ),

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|  #2   |  #3   |  #4   |  #5   | |  #6   |  #7   |  #8   |  #9   |--------------.
 * |       |  #1   |-------+-------+-------+-------| |-------+-------+-------+-------|  NA   | BSPC |
 * |-------+-------|   Z   |   N   |   X   |  *1   | |  *3   |   e   |   n   |   z   |-------+------|
 * |       |   F   |-------+-------+-------+-------| |-------+-------+-------+-------|   f   |  -D  |
 * |-------+-------|   C   |   P   |   R   |  *2   | |  *4   |   a   |   p   |   c   |-------+------|
 * |       |   S   |-------+-------+-------+-------| |-------+-------+-------+-------|   s   |  -Z  |
 * |-------+-------|1-SHOT⎇|1-SHOT⇧|1-SHOT⎈|       | |       |1-SHOT⎈|1-SHOT⇧|1-SHOT⎇|-------+------|
 * |       |1-SHOT◆|-------+-------+---------------' `---------------+-------+-------|1-SHOT◆|      |
 * `---------------|       |       |                                 |       |       |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |   I   |   U   | |   u   |   i   |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |TAB/NAV| | ⏎/SYM |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |PLOVER |       | |       |       |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
    [_PLOVER] = LAYOUT_5x6(
        _______, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,     STN_N6, STN_N7,  STN_N8,  STN_N9,  STN_NA, KC_BSPC,
        _______, STN_S1, STN_TL, STN_PL, STN_HL,STN_ST1,    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        _______, STN_S2, STN_KL, STN_WL, STN_RL,STN_ST2,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
        _______,OS_LGUI,OS_LALT,OS_LSFT,OS_LCTL,_______,    _______,OS_RCTL, OS_RSFT, OS_LALT, OS_RGUI,_______,
                        _______,_______,                                    _______,_______,
                                          STN_A,  STN_O,      STN_E,  STN_U,
                                        _______,NAV_TAB,    SYM_ENT,_______,
                                        PLOVER ,_______,    _______,_______
    ),

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|  F2   |  F3   |  F4   |  F5   | |  F6   |  F7   |  F8   |  F9   |--------------.
 * |  F12  |  F1   |-------+-------+-------+-------| |-------+-------+-------+-------|  F10  | F11  |
 * |-------+-------|   2   |   3   |   1   |   5   | |   6   |   0   |   8   |   9   |-------+------|
 * |   X   |   4   |-------+-------+-------+-------| |-------+-------+-------+-------|   7   | - _  |
 * |-------+-------|   [   |   ]   |  "]   |   »   | |  {⏎   |   {   |   (   |   )   |-------+------|
 * |   «   |  ["   |-------+-------+-------+-------| |-------+-------+-------+-------|   }   |  }⏎  |
 * |-------+-------|   @   |   #   |   $   |   %   | |   ^   |   &   |   *   |   =   |-------+------|
 * |   ~   |   !   |-------+-------+---------------' `---------------+-------+-------|   +   |  `   |
 * `---------------|       |       |                                 |  , <  |  . >  |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |  NAV  |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |ADJUST |ADJUST |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
  [_SYM] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
           KC_X, KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,    KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        GUILL_L,O_BRQOT,KC_LBRC,KC_RBRC,C_BRQOT,GUILL_R,    O_BRACE,KC_LCBR,KC_LPRN,KC_RPRN,KC_RCBR,C_BRACE,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS, KC_GRV,
                        _______,_______,                                    KC_COMM, KC_DOT,
                                          NAV  ,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    ADJUST, ADJUST
  ),

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|  F2   |  F3   |  F4   |  F5   | |  F6   |  F7   |  F8   |  F9   |--------------.
 * |  F12  |  F1   |-------+-------+-------+-------| |-------+-------+-------+-------|  F10  | F11  |
 * |-------+-------|NumLock|ScrLock|  Ins  |       | |       | PGUP  |  UP   | PGDN  |-------+------|
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       | MUTE |
 * |-------+-------|LALT ⎇ |LSFT ⇧ |LCTL ⎈ | GNAV  | | HOME  | LEFT  | DOWN  | RGHT  |-------+------|
 * |CAPS/MS|LGUI ◆ |-------+-------+-------+-------| |-------+-------+-------+-------|  END  | VOLU |
 * |-------+-------|Ctrl+A |Ctrl+C |Ctrl+V |       | |       |PrintSc|   {   |   }   |-------+------|
 * |       |COUTLN |-------+-------+---------------' `---------------+-------+-------|  Ins  | VOLD |
 * `---------------|       |       |                                 | BRID  | BRIU  |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |ADJUST |ADJUST | |       |       |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
  [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , KC_F11,
        _______,_______,KC_NUM,KC_SCRL,KC_INS ,_______,    _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        MS_CAPS,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______, COUTLN,C(KC_A),C(KC_C),C(KC_V),_______,    _______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,
                        _______,_______,                                    KC_BRID,KC_BRIU,
                                         _______,_______,   _______,_______,
                                         _______,_______,   _______,_______,
                                           ADJUST,ADJUST,   _______,_______
  ),

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|       |       |       |       | |       |       |       |       |--------------.
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       | |       |       | G_UP  |       |-------+------|
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       | |G_HOME |       |G_DOWN |       |-------+------|
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------| G_END |      |
 * |-------+-------|       |       |       |       | |       |       |       |       |-------+------|
 * |       |       |-------+-------+---------------' `---------------+-------+-------|       |      |
 * `---------------|       |       |                                 |       |       |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
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


#ifdef MOUSEKEY_ENABLE
/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|       |       |       |       | |       |       |       |       |--------------.
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       | |       |   ⯬   |MOUSE ↑|   ⯮   |-------+------|
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|LALT ⎇ |LSFT ⇧ |LCTL ⎈ |       | |       |MOUSE ←|MOUSE ↓|MOUSE →|-------+------|
 * |       |LGUI ◆ |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       | |       | BTN3  |WHEEL ↓|WHEEL ↑|-------+------|
 * |       |       |-------+-------+---------------' `---------------+-------+-------|       |      |
 * `---------------|       |       |                                 |       |       |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |       |       | | BTN1  | BTN2  |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | | BTN3  |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_WBAK,KC_MS_U,KC_WFWD,_______,_______,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,    _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_BTN3,KC_WH_D,KC_WH_U,_______,_______,
                       _______,_______,                                    _______,_______,
                                        _______,_______,    KC_BTN1,KC_BTN2,
                                        _______,_______,    KC_BTN3,_______,
                                        _______,_______,    _______,_______
    ),
#endif

/*                 ,-------------------------------. ,-------------------------------.
 * ,---------------|       |       |       |       | |       |       | INT8  | LNG9  |--------------.
 * | UNDO  | AGAIN |-------+-------+-------+-------| |-------+-------+-------+-------| PB_10 |      |
 * |-------+-------|       | FIND  |       |EE_CLR | |       |NKROon |       |       |-------+------|
 * |       |       |-------+-------+-------+-------| |-------+-------+-------+-------|       |      |
 * |-------+-------|   ⏹   |   ⏯   |   ⏭   |QK_RBT | | ⎈ ↔ ◆ |       |  (/⇧  |  )/⇧  |-------+------|
 * |` ~/Esc|   ⏮   |-------+-------+-------+-------| |-------+-------+-------+-------|       |\NUHS||
 * |-------+-------|  CUT  | COPY  | PASTE |QK_BOOT| |QK_BOOT|NKROoff|       |       |-------+------|
 * |\NUBS| |       |-------+-------+---------------' `---------------+-------+-------| KP /  |      |
 * `---------------|       |       |                                 |       |       |--------------'
 *                 `---------------'                                 `---------------'
 *                                 ,---------------. ,---------------.
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 |-------+-------| |-------+-------|
 *                                 |       |       | |       |       |
 *                                 `---------------' `---------------'       generated by [keymapviz] */
    [_ADJUST] = LAYOUT_5x6(
        KC_UNDO,KC_AGIN,_______,_______,_______,_______,    _______,_______,KC_INT8,KC_LNG9, PB_10 ,_______,
        _______,_______,_______,KC_FIND,_______, EE_CLR,    _______, NK_ON ,_______,_______,_______,_______,
        QK_GESC,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT, QK_RBT,    RCG_SWP,_______,SC_LSPO,SC_RSPC,_______,KC_NUHS,
        KC_NUBS,_______, KC_CUT,KC_COPY,KC_PSTE,QK_BOOT,    QK_BOOT, NK_OFF,_______,_______,KC_PSLS,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    )
};

// CAPS_WORD_LOCK: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_lock_enable(void) {
    caps_word_lock_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_lock_disable(void) {
    caps_word_lock_on = false;
    unregister_mods(MOD_MASK_SHIFT);
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

inline uint8_t get_tap_kc(uint16_t dual_role_key) {
    // Used to extract the basic tapping keycode from a dual-role key.
    // Example: get_tap_kc(MT(MOD_RSFT, KC_E)) == KC_E
    return dual_role_key & 0xFF;
}

static void process_caps_word_lock(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_lock_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = get_tap_kc(keycode);
                break;
            default:
                break;
        }

        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
            case A_GRAVE:
            case E_ACUTE:
            case E_GRAVE:
            case C_CDILA:
                if (record->event.pressed) {
                    if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                        caps_word_lock_disable();
                        add_oneshot_mods(MOD_MASK_SHIFT);
                    }
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
            case KC_PIPE:
            case REPEAT:
            case CAPS_WORD_LOCK:
            case OS_LSFT:
            case OS_RSFT:
            case KC_LPRN:
            case KC_RPRN:
            case DED_CIR:
            case DED_UML:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_lock_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed && !(get_oneshot_mods() & MOD_MASK_SHIFT)) {
                    caps_word_lock_disable();
                }
                break;
        }
    }
}

uint16_t last_keycode = KC_NO;
static void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    static uint8_t last_modifier = 0;
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        if (record->event.pressed) {
            last_modifier = get_oneshot_mods() | get_mods();
        }
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = get_tap_kc(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t%u\n",
         keycode,
         is_combo ? 254 : record->event.key.row,
         is_combo ? 254 : record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
    process_caps_word_lock(keycode, record);
    process_repeat_key(keycode, record);

    const uint8_t mod_state = get_mods();
    const uint8_t oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {


    case CAPS_WORD_LOCK:
        // Toggle `caps_word_lock_on`
        if (record->event.pressed) {
            if (caps_word_lock_on) {
                caps_word_lock_disable();
                return false;
            } else {
                caps_word_lock_enable();
                return false;
            }
        }
        return false;


    case KC_SPC:
        if (oneshot_mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
            }
            return false;
        }
        return true;

    case KC_BSPC:
        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                // In case only one shift is held
                // see https://stackoverflow.com/questions/1596668/logical-xor-operator-in-c
                // This also means that in case of holding both shifts and pressing KC_BSPC,
                // Shift+Delete is sent (useful in Firefox) since the shift modifiers aren't deleted.
                if (!(mod_state & MOD_BIT(KC_LEFT_SHIFT)) != !(mod_state & MOD_BIT(KC_RIGHT_SHIFT))) {
                    del_mods(MOD_MASK_SHIFT);
                }
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }

     case A_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             tap_code16(ALGR(KC_GRV));
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_A);
         }
         return false;

     case E_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             tap_code16(ALGR(KC_GRV));
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_E);
         }
         return false;

    case ARROW_R:
      if (record->event.pressed) {
          if ((mod_state|oneshot_mod_state) & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            send_string("=>");
            set_mods(mod_state);
          } else {
            SEND_STRING("->");
          }
      }
      return false;

    case G_DOWN:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_DOWN);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_DOWN);
        }
        return false;

    case G_UP:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_UP);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_UP);
        }
        return false;

    case G_HOME:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_HOME);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_HOME);
        }
	    return false;

    case G_END:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_END);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_END);
        }
		return false;

    case GUILL_L:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code16(KC_LT);
            tap_code16(KC_LT);
            tap_code(COMPOSE);
            tap_code(KC_SPACE);
            tap_code(KC_SPACE);
        }
        return false;

    case GUILL_R:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code(KC_SPACE);
            tap_code(KC_SPACE);
            tap_code(COMPOSE);
            tap_code16(KC_GT);
            tap_code16(KC_GT);
        }
        return false;

    case UPDIR:
        if (record->event.pressed) {
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code(KC_SLSH);
        }
        return false;

    case COUTLN:
        if (record->event.pressed) {
            // ; and : keysyms are swapped on my OS layout
            send_string("std;;cout <<  << \"\\n\":");
            for (int i = 0; i < 9; ++i)  {
                tap_code(KC_LEFT);
            }
        }
        return false;

    case O_BRACE:
        if (record->event.pressed) {
            tap_code16(KC_LEFT_CURLY_BRACE);
            tap_code(KC_ENTER);
        }
        return false;

    case C_BRACE:
        if (record->event.pressed) {
            tap_code16(KC_RIGHT_CURLY_BRACE);
            tap_code(KC_ENTER);
        }
        return false;

    case O_BRQOT:
        if (record->event.pressed) {
            tap_code(KC_LEFT_BRACKET);
            tap_code16(KC_DOUBLE_QUOTE);
        }
        return false;

    case C_BRQOT:
        if (record->event.pressed) {
            tap_code16(KC_DOUBLE_QUOTE);
            tap_code(KC_RIGHT_BRACKET);
        }
        return false;

    }
    return true;
};

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_TAB:
        case HOME_R: // I like to hold Ctrl+R to redo many changes in Vim
            return 64;
        default:
            return 64;
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
            return TAPPING_TERM + 30;
        case SYM_ENT:
            // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 85;
        default:
            return TAPPING_TERM;
    }
};
#endif
