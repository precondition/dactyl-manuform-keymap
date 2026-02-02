# Automatically update the keymap visualization when compiling
# The '-' in front of keymapviz is used to ignore errors spewed by keymapviz.
KEYMAP_FOLDER = keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition
.PHONY: %
%:
	-keymapviz -k dactyl_manuform5x6 -t fancy -r $(KEYMAP_FOLDER)/keymap.c -c $(KEYMAP_FOLDER)/visualisation/keymapviz/keymapviz.ini > /dev/null

CONSOLE_ENABLE = no    # USER_PRINT is currently bugged, see issue #24987 on qmk/qmk_firmware
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = no
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
SWAP_HANDS_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# Space savings
LTO_ENABLE = yes
COMMAND_ENABLE = no
KEY_LOCK_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += combos.c
endif
ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
	SRC += swap_hand.c
endif
