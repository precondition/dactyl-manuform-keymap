/* Colemak DHm with home row mods and hybrid steno
 * for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#include "keymap.h"
#include "accented_letters.h"

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
    return true;
    }

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
};

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

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
};

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects 
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
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
};

/*MAKE SURE THAT ADJUST AND RESET ARE ACCESSIBLE !!*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DHM] = LAYOUT_5x6(
           REDO, UNDO  ,KC_WH_U,KC_WH_D, KC_F4 , KC_F5 ,    KC_F6  ,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,    KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,    KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
      KC_BSLASH, KC_Z  , KC_X  , KC_C  , HOME_D, KC_V  ,    KC_K   , HOME_H,KC_COMM, TD_DOT,KC_SLSH,E_ACUTE,
                      KC_BSLASH,C_CDILA,                                    KC_RALT, KC_GRV,
                                        NAV_TAB, KC_SPC,    KC_BSPC,SYM_ENT,
                                         CACCCV,MS_CAPS,    KC_DEL , KC_UP ,
                                         PLOVER,KC_CAPS,    SH_OS  ,KC_DOWN
  ),

  [_SYM] = LAYOUT_5x6(

        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_BSPC,
        KC_DOT , KC_7  , KC_5  , KC_3  , KC_1  , KC_9  ,    KC_8   , KC_0  , KC_2  , KC_4  , KC_6  ,KC_MINS,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,KC_MINS,
        _______,_______,_______,_______,DED_CIR,_______,    _______,COMPOSE,_______, KC_DOT,_______,_______,
                        _______,_______,                                    GUILL_L,GUILL_R,
                                        NAV_UND,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    ADJUST, ADJUST
  ),

  [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_BSPC,
        _______,_______,KC_NLCK,KC_INS ,KC_SLCK,_______,    _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______,_______,_______,_______, CACCCV,_______,    _______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,
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


    [_ACCENTS] =LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,A_CIRCU,_______,_______,_______,_______,    _______,_______,U_CIRCU,I_UMLAU,O_UMLAU,_______,
        _______,A_GRAVE,_______,_______,_______,_______,    _______,E_GRAVE,E_ACUTE,I_CIRCU,O_CIRCU,_______,
        _______,_______,_______,C_CDILA,_______,_______,    _______,_______,E_GRAVE,E_CIRCU,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
  ),

    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______, KC_9  , KC_8  , KC_7  ,_______,    _______,KC_WBAK,KC_MS_U,KC_WFWD,_______,_______,
_______,KC_LGUI,LALT_T(KC_6),LSFT_T(KC_5),LCTL_T(KC_4),_______,    _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______, KC_3  ,KC_WH_U,KC_WH_D,_______,    _______,KC_BTN3,KC_WH_D,KC_WH_U,_______,_______,
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
        _______,_______,UC_M_WC,_______,_______,_______,    _______,UC_M_LN,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______, RESET ,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    )
};
