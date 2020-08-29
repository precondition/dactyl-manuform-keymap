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

enum combo_events {
    UY_PRN,
    YCLN_PRN,
    JU_JUST,
    HV_HAVE,
    EV_EVERY,
    BSPCU_YOU,
    BSPCA_AND,
    BSPCN_NOT,
    BSPCW_WITH,
    BSPCF_FOR,
    BSPCH_HERE,
    BSPCT_THE,
    BSPCM_MENT,
    BSPCG_ING,
    BSPCO_OUGH,
    BSPCI_ION,
    BSPCTA_THAT,
    BSPCQ_QUE,
    NHI_KI,
    PT_B,
    TD_V,
    NH_K,
    LN_J,
    RST_G,
    IET_M,
    FS_G,
    UE_M,
    DELT_THIS,
    ZX_GRAVE,
    DOTSLASH_GRAVE,
    IDOTSLASH_IGRAVE,
    AX_GRAVE,
    XC_ACUTE,
    XCE_ACUTE,
    COMMADOT_ACUTE,
    XDOT_CIRCUM,
    COMBO_LENGTH
};
