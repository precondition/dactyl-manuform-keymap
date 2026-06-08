#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

enum combo_events {
    PT_MOUSE,

    BV_Z,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM P_T_COMBO[]        = {KC_P,     HOME_T,  COMBO_END};
const uint16_t PROGMEM B_V_COMBO[]        = {KC_B,     KC_V,    COMBO_END};

combo_t key_combos[] = {
    [PT_MOUSE]        = COMBO(P_T_COMBO, MOUSE),
    [BV_Z]            = COMBO(B_V_COMBO, KC_Z),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef CONSOLE_ENABLE
    combo_t *combo = &key_combos[combo_index];
    uint8_t idx = 0;
    uint16_t combo_keycode;
    while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t0\t%s\n",
            combo_keycode,
            254,
            254,
            layer_state|default_layer_state,
            pressed,
            get_mods(),
            get_oneshot_mods(),
            /* tap_count==0 */
            get_keycode_string(combo_keycode)
        );
        idx++;
    }
#endif
};
