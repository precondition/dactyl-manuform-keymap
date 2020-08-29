#pragma once

#include QMK_KEYBOARD_H

enum {
    DOT_TD = 0,
    XCLM_TD,
    CA_CC_CV,
};

#define TD_XCLM TD(XCLM_TD)
#define TD_DOT TD(DOT_TD)
#define CACCCV TD(CA_CC_CV)

