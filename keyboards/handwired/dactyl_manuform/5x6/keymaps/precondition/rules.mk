CONSOLE_ENABLE = no
COMMAND_ENABLE = no
UNICODEMAP_ENABLE = yes
KEY_LOCK_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
SWAP_HANDS_ENABLE = yes
LTO_ENABLE = yes

SRC += combos.c

# Load the necessary hand_swap_config if and only if
# the config option SWAP_HANDS_ENABLE has been enabled
ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
	SRC += swap_hand.c
endif
