# Automatically update the keymap visualization when compiling
.PHONY: %
%:
	keymapviz -k dactyl_manuform5x6 -t fancy -r keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition/keymap.c -c keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition/keymapviz.toml > /dev/null

CONSOLE_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = no
STENO_ENABLE = yes
SWAP_HANDS_ENABLE = yes

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
	SRC += combos.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif
ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
	SRC += swap_hand.c
endif
