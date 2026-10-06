static keypos_t get_closest_home_keypos(const keypos_t keypos) {
    /*  Matrix for Dactyl Manuform 5x6:
     * ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐                    ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
     * │00││01││02││03││04││05│                    │60││61││62││63││64││65│
     * └──┘└──┘└──┘└──┘└──┘└──┘                    └──┘└──┘└──┘└──┘└──┘└──┘
     * ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐                    ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
     * │10││11││12││13││14││15│                    │70││71││72││73││74││75│
     * └──┘└──┘└──┘└──┘└──┘└──┘                    └──┘└──┘└──┘└──┘└──┘└──┘
     * ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐                    ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
     * │20││21││22││23││24││25│                    │80││81││82││83││84││85│
     * └──┘└──┘└──┘└──┘└──┘└──┘                    └──┘└──┘└──┘└──┘└──┘└──┘
     * ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐                    ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
     * │30││31││32││33││34││35│                    │90││91││92││93││94││95│
     * └──┘└──┘└──┘└──┘└──┘└──┘                    └──┘└──┘└──┘└──┘└──┘└──┘
     *         ┌──┐┌──┐                                    ┌──┐┌──┐
     *         │42││43│                                    │A2││A3│
     *         └──┘└──┘                                    └──┘└──┘
     *                 ┌──┐┌──┐                    ┌──┐┌──┐
     *                 │44││45│                    │A0││A1│
     *                 └──┘└──┘                    └──┘└──┘
     *                         ┌──┐┌──┐    ┌──┐┌──┐
     *                         │54││55│    │B0││B1│
     *                         └──┘└──┘    └──┘└──┘
     *                         ┌──┐┌──┐    ┌──┐┌──┐
     *                         │52││53│    │B2││B3│
     *                         └──┘└──┘    └──┘└──┘
     *
     * ⚠️ The layout produced by the `qmk info -kb handwired/dactyl_manuform/5x6 --matrix` command and
     * the reality do not match!
     */
    const int home_row = keypos.row  < 6 ? 2 : 8;

    const bool is_left_thumb_keypos = (5 == keypos.row) || (4 == keypos.row && 4 <= keypos.row && keypos.row <= 5);
    if (is_left_thumb_keypos) {
        return (keypos_t){.row = 4, .col = 5};
    }

    const bool is_right_thumb_keypos = (11 == keypos.col) || (10 == keypos.row && 0 <= keypos.row && keypos.col <= 1);
    if (is_right_thumb_keypos) {
        return (keypos_t){.row = 10, .col = 0};
    }

    const bool is_left_outer_col = 0 == keypos.col;
    if (is_left_outer_col) {
        return (keypos_t){.row = home_row, .col = keypos.col + 1};
    }

    const bool is_right_outer_col = 5 == keypos.col;
    if (is_right_outer_col) {
        return (keypos_t){.row = home_row, .col = keypos.col - 1};
    }

    // Deviate a bit from the reported function name.
    // This must go after the outer col logic to avoid catching the non-resting
    // key positions on home row.
    const bool is_home_row = home_row == keypos.row;
    if (is_home_row) {
        return (keypos_t){.row = keypos.row - 1, .col = keypos.col};
    }

    return (keypos_t){.row = home_row, .col = keypos.col};
}
