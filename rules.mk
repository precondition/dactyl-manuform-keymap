CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
UNICODEMAP_ENABLE = no
KEY_LOCK_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = no
SWAP_HANDS_ENABLE = yes
LTO_ENABLE = yes

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
