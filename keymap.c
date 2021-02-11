/* Colemak DHm with home row mods and hybrid steno
 * for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// All custom keycodes and aliases can be found in keymap.h
#include "keymap.h"

/*MAKE SURE THAT ADJUST AND RESET ARE ACCESSIBLE!*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT_5x6(
           REDO, UNDO  ,KC_WH_U,KC_WH_D, KC_F4 , KC_F5 ,    DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,    KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,    KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
        MS_CAPS, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,    KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,
                      KC_BSLASH,C_CDILA,                                    KC_RALT, KC_GRV,
                                        NAV_TAB, KC_SPC,    KC_BSPC,SYM_ENT,
                                        COMPOSE,OS_LSFT,    OS_RSFT, KC_UP ,
                                        KC_BTN3,MS_CAPS,    SH_OS  ,KC_DOWN
  ),

  [_SYM] = LAYOUT_5x6(

        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
        KC_DOT , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,    KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS, KC_GRV,
        _______,_______,_______,_______,DED_CIR,_______,    _______,COMPOSE,_______, KC_DOT, UPDIR ,_______,
                        _______,_______,                                    GUILL_L,GUILL_R,
                                        NAV_UND,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    ADJUST, ADJUST
  ),

  [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , KC_F11,
        _______,_______,KC_NLCK,KC_SLCK,KC_INS ,_______,    _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        MS_CAPS,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______, YICODE,C(KC_A),C(KC_C),C(KC_V),_______,    _______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,
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


// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }

        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    caps_word_enable();
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
            case KC_F24: /* The dummy keycode used in NAV_UND */
            case CAPS_WORD:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed) {
                    caps_word_disable();
                }
                break;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time);
#endif
    process_caps_word(keycode, record);

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {


    case CAPS_WORD:
        // Toggle `caps_word_on`
        if (record->event.pressed) {
            if (caps_word_on) {
                caps_word_disable();
                return false;
            } else {
                caps_word_enable();
                return false;
            }
        }
        break;

    case KC_BSPC:
        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                // In case only one shift is held
                // see https://stackoverflow.com/questions/1596668/logical-xor-operator-in-c
                // This also means that in case of holding both shifts and pressing KC_BSPC,
                // Shift+Delete is sent (useful in Firefox) since the shift modifiers aren't deleted.
                if (!(mod_state & MOD_BIT(KC_LSHIFT)) != !(mod_state & MOD_BIT(KC_RSHIFT))) {
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
          if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            send_string("=>");
            set_mods(mod_state);
          } else {
            SEND_STRING("->");
          }
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

    case GUILL_L:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code16(KC_LT);
            tap_code16(KC_LT);
        }
      break;

    case GUILL_R:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code16(KC_GT);
            tap_code16(KC_GT);
        }
      break;

    case UPDIR:
      if (record->event.pressed) {
          tap_code(KC_DOT);
          tap_code(KC_DOT);
          tap_code(KC_SLSH);
          return false;
      }
      break;

    case YICODE:
      if (record->event.pressed) {
          send_string("$yi{");
          return false;
      }
      break;

    case NAV_UND:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          // send advanced keycode, etc.
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }
        // do not continue with default tap action if the MT was pressed or released, but not held
        return false;
      }
      break;

    }
    return true;
};

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
            return TAPPING_TERM + 20;
        case SYM_ENT:
            // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 65;
        // The One Shot Shift thumb key is used more frequently.
        // To avoid accidental shiftings of T or N or I
        // when rolling over the home row, the tapping term
        // is increased.
        case HOME_S:
        case HOME_E:
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
};
