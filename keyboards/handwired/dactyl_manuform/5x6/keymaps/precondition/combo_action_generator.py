#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# First awfully written draft of a script which deserializes combos.json
# into correct C code for keymap.c. For now, it only prints the generated/deserialized code.
# Later, it should also automatically write that code where appropriate (either in keymap.c or
# in a totally new combos.c file if I figure out how to properly split my keymap) and update COMBO_COUNT
# or maybe use that new sevanteri's addition which allows you to keep COMBO_COUNT automatically updated.

import json

def read_combos_json_file():
    try:
        with open("combos.json", "r") as file:
            return file.read()
    except OSError:
        raise OSError("An error occured while loading the combos.json file. Make sure that this script is in the same directory as that of the keymap.c and the combos.json files.")

user_combos = json.loads(read_combos_json_file())

enum_combo_events = "enum combo_events {\n"
for combo_name in user_combos.keys():
    enum_combo_events += "    " + combo_name + ",\n"
enum_combo_events += "};\n"

keys_sequence = ""
keys_sequences_names = []
for combo_def in user_combos.values():
    no_prefix_keys = [key[key.find("_")+1:] for key in combo_def["keys"]]
    key_sequence_name = "_".join(no_prefix_keys) + "_COMBO"
    keys_sequences_names.append(key_sequence_name)
    keys_sequence += f"const uint16_t PROGMEM {key_sequence_name}[] = {{{', '.join(combo_def['keys'])}, COMBO_END}};\n"

combo_t_key_combos = "combo_t key_combos[COMBO_COUNT] = {\n"
for combo_name in user_combos.keys():
    combo_t_key_combos += f"    [{combo_name}] = COMBO_ACTION({keys_sequences_names.pop(0)}),\n"
combo_t_key_combos += "};\n"

def combo_case(combo_name, combo_shift, combo_control, combo_no_mods):

    shift_condition = \
    f"""\t\tif (mod_state & MOD_MASK_SHIFT) {{
    \t\t\tunregister_code(KC_LSHIFT);
    \t\t\tunregister_code(KC_RSHIFT);
    \t\t\tsend_string("{combo_shift}");
    \t\t\tset_mods(mod_state);
    \t\t}}
    """.expandtabs(4)

    control_condition = \
    f"""\t\telse if (mod_state & MOD_MASK_CTRL) {{
    \t\t\tunregister_code(KC_LCTL);
    \t\t\tunregister_code(KC_RCTL);
    \t\t\tsend_string("{combo_control}");
    \t\t\tset_mods(mod_state);
    \t\t}}
    """.expandtabs(4)

    no_mods_condition = \
    f"""\t\telse {{
    \t\t\tsend_string("{combo_no_mods}");
    \t\t}}
    """.expandtabs(4)

    case_code_block = \
    f"""\t\tcase {combo_name}:
    """.expandtabs(4)

    case_code_block += shift_condition
    if len(combo_control) > 0:
        case_code_block += control_condition
    case_code_block += no_mods_condition
    case_code_block += "\t\tbreak;\n\n".expandtabs(4)
    return case_code_block

process_combo_event = "void process_combo_event(uint8_t combo_index, bool pressed) {\n    mod_state = get_mods();\n    switch(combo_index) {\n"
for combo_name in user_combos.keys():
    process_combo_event += combo_case(combo_name, user_combos[combo_name]["shift"], user_combos[combo_name]["control"], user_combos[combo_name]["noMods"])

process_combo_event += "    }\n}\n"

full_combo_code = enum_combo_events + "\n" + keys_sequence + "\n" + combo_t_key_combos + "\n" + process_combo_event
print(full_combo_code)
