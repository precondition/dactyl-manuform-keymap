#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

/* Magic rules version 4.0 */

/*
 * "Magic key" is AKL jargon (https://layouts.wiki/reference/terminology/magic/).
 * Not to be confused with QMK magic keycodes (https://docs.qmk.fm/keycodes_magic)
 */

/*
 * Percentages are given relative to ngram class in a corpus composed of my
 * keylogs, and shell commands:
 * « 1 » (frequency percentage among all unigrams/monograms)
 * « 12 » (frequency percentage among all bigrams),
 * « 123 » (frequency percentage among all trigrams),
 * « 1_3 » (frequency percentage of « 1 » <something> « 3 » among all skip-1-grams)
 * etc.
 */

#include "get_closest_home_keypos.c"

void summon_same_finger_home_key(const keypos_t keypos) {
    const keypos_t home_keypos = get_closest_home_keypos(keypos);
    const uint16_t home_keycode = keymap_key_to_keycode(layer_switch_get_layer(home_keypos), home_keypos);
    if (QK_MOD_TAP <= home_keycode && home_keycode <= QK_MOD_TAP_MAX) {
        tap_code(GET_TAP_KC(home_keycode));
        last_summoned_keycode = GET_TAP_KC(home_keycode);
    } else {
        tap_code16(home_keycode);
        last_summoned_keycode = home_keycode;
    }
}

void process_magic_key_left(const uint16_t prev_keycodes[], const keypos_t prev_keypos[]) {
    const uint16_t penultimate_keycode = prev_keycodes[1] == MAGIC_L || prev_keycodes[1] == MAGIC_R ? last_summoned_keycode : prev_keycodes[1];
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_SPACE:
                case KC_L:
                case KC_M:
                case KC_F:
                case KC_H:
                case KC_QUOTE:
                case KC_K:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_B:
            switch (penultimate_keycode) {
                case KC_SEMICOLON:
                case KC_COLON:
                case KC_M:
                case KC_K:
                    // rationale: avoid SFB.
                    // ngram: « bd » (0.01193%)
                    // examples: « :bd » (buffer delete), « lambda », « kbd »
                    tap_code(KC_D);
                    last_summoned_keycode = KC_D;
                    break;

                default:
                    // examples: « about », « obtention »
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_E:
        case HOME2_E:
            switch (penultimate_keycode) {
                case KC_B:
                    // « between␣ »
                    tap_code(KC_T);
                    tap_code(KC_W);
                    tap_code(KC_E);
                    tap_code(KC_E);
                    tap_code(KC_N);
                    tap_code(KC_SPACE);
                    last_summoned_keycode = KC_SPACE;
                    break;

                case KC_R:
                case HOME2_R:
                    /*
                     * « rex » (0.00018%) < « req » (0.01271%)
                     */
                    tap_code(KC_Q);
                    last_summoned_keycode = KC_Q;
                    break;

                case KC_V:
                    // rationale: avoid SFS.
                    // ngram: « ved␣ » (TODO%)
                    // examples: « moved »,  « removed »,  « served »,  « solved »
                    tap_code(KC_D);
                    tap_code(KC_SPACE);
                    last_summoned_keycode = KC_SPACE;
                    break;

                default:
                    // rationale: avoid SFS.
                    // ngram: « e<sym> » (0.10403%)
                    // examples: TODO
                    //set_oneshot_layer(_SYM, ONESHOT_START);
                    //last_summoned_keycode = OSL(_SYM);
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_G:
            // rationale: reduce typing.
            // ngram: « git␣ » (0.30964%)
            // examples: « git st », « git add », « git commit »
            tap_code(KC_I);
            tap_code(KC_T);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_I:
        case HOME2_I:
            switch (penultimate_keycode) {
                case KC_SPACE:
                    // rationale: avoid SFS.
                    // ngram: « ␣⇧I␣w »
                    // examples: « I was »,  « I would »,  « I want »,  « I wonder », « I wish »
                    tap_code(KC_SPACE);
                    tap_code(KC_W);
                    last_summoned_keycode = KC_W;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_L:
            // examples: « alors »
            summon_same_finger_home_key(prev_keypos[1]);
            break;

        case KC_N:
        case HOME2_N:
            // rationale: avoid SFS.
            // ngram: « nal » (0.02550%)
            // examples: "final",  "terminal",  "personally",  "original", "national"
            /*
             * Especially important to avoid the double SFS in « onal ».
             */
            tap_code(KC_A);
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_O:
            switch (penultimate_keycode) {
                case KC_T:
                case HOME2_T:
                    /*
                     * « top » (0.015466%) > « toa » (0.000580%)
                     */
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[0]);
                    break;
            }
            break;

        case KC_Q:
            // rationale: TODO
            // ngram: « q! » (TODO%)
            // examples: « :q!⏎ »
            tap_code16(KC_EXLM);
            last_summoned_keycode = KC_EXLM;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFB and SKB.
            // ngram: « rr » (0.09392%)
            // examples: « bizarre », « correct », « erreur », « array »
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_T:
        case HOME2_T:
            // rationale: avoid SFS.
            // ngram: « ted » (0.04675%)
            // examples: « expected », « dedicated », « accented »
            tap_code(KC_E);
            tap_code(KC_D);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_U:
            switch (penultimate_keycode) {
                case KC_K:
                    // rationale: avoid SFS
                    // ngram: « kub » (TODO%)
                    // examples: « kubectl », « kubernetes », « kubelet »
                    tap_code(KC_B);
                    last_summoned_keycode = KC_B;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_V:
            // rationale: avoid SKS.
            // ngram: Ctrl+(Shift+)V⏎
            // examples: TODO
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case KC_W:
            // rationale: avoid row skip scissor.
            // ngram: « wo » (0.07773%)
            // examples: « work »,  « two »,  « won't »,  « word »
            tap_code(KC_O);
            last_summoned_keycode = KC_O;
            break;

        case KC_X:
            // rationale: avoid SKB and SFB.
            // ngram: « xx » (0.02115%)
            // examples: « xx » (delete 2 chars in Vim), « xxd »,  « `xxx_ENABLE »
            /*
             * « xr » (0.00070%) < « xx » (0.02115%)
             */
            tap_code(KC_X);
            last_summoned_keycode = KC_X;
            break;

        case KC_Z:
            // rationale: avoid SFB.
            // ngram: « zt » (0.00007%)
            // examples: « zt » (reposition current line at top of the window, see :help scroll-cursor)
            /*
             * The frequency of the bigram might look abysmally small but
             * that's because I never used vim folds before my job. Obviously,
             * I cannot run a key logger on my work computer without raising
             * alarms in the IT department so I cannot gather more
             * representative figures.
             */
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_RPRN:
            // rationale: reduce typing.
            // ngram: « ); » (TODO%)
            // examples: TODO
            tap_code(KC_SEMICOLON);
            last_summoned_keycode = KC_SEMICOLON;
            break;

        case KC_LCBR:
            // rationale: avoid SKB.
            // ngram: « {⏎ » (TODO%)
            // examples: TODO
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case KC_COLN:
            // rationale: avoid LSB and SFS.
            // ngram: « :find␣ » (TODO%)
            // examples: TODO
            SEND_STRING("find ");
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_PERCENT:
            // rationale: reduce typing.
            // ngram: « %s/\v//gc »
            SEND_STRING("s/\\v//gc");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
            last_summoned_keycode = KC_LEFT;
            break;

        case KC_TILDE:
            // rationale: typing reduction.
            // ngram: « ~/. » (0.00291%)
            // examples: « ~/.vimrc », « ~/.config »
            tap_code(KC_SLASH);
            tap_code(KC_DOT);
            last_summoned_keycode = KC_DOT;
            break;

        case KC_ESC:
            // rationale: avoid SFS and reduce typing.
            // ngram: « ⎋:x⏎ »
            tap_code16(KC_COLON);
            tap_code(KC_X);
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case MAGIC_R:
            // rationale: avoid SFB.
            // ngram: « <MAGIC_R>e »
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        default:
            summon_same_finger_home_key(prev_keypos[0]);
            break;

    }
}


void process_magic_key_right(const uint16_t prev_keycodes[], const keypos_t prev_keypos[]) {
    const uint16_t penultimate_keycode = prev_keycodes[1] == MAGIC_L || prev_keycodes[1] == MAGIC_R ? last_summoned_keycode : prev_keycodes[1];
    const bool is_preceded_by_the = prev_keycodes[1] == MAGIC_R && prev_keycodes[2] == KC_SPACE;
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_SPACE:
                case KC_L:
                case KC_M:
                case KC_F:
                case KC_H:
                case KC_QUOTE:
                case KC_K:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_C:
            // rationale: avoid SFS.
            // ngram: « ces » (0.03377%)
            // examples: « ␣ces␣ »,  « access »,  « exercices »,  « process »
            tap_code(KC_E);
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_D:
            // rationale: avoid SFS.
            // ngram: « dev » (TODO%)
            // examples: « devoir »,  « devrait »,  « develop »,  « devant », « device »
            tap_code(KC_E);
            tap_code(KC_V);
            last_summoned_keycode = KC_V;
            break;

        case KC_F:
            switch (penultimate_keycode) {
                case KC_I:
                case HOME2_I:
                    // rationale: avoid SFS.
                    // ngram: « ify » (0.00332%)
                    // examples: « specify »,  « modify »,  « simplify »
                    tap_code(KC_Y);
                    last_summoned_keycode = KC_Y;
                    break;

                default:
                    // rationale: avoid SFB.
                    // ngram: « f" » (TODO%)
                    // examples: « f"python interpolated f-string" »
                    tap_code16(KC_DOUBLE_QUOTE);
                    if (base_dead_keys) {
                        tap_code(KC_SPACE);
                    }
                    last_summoned_keycode = KC_DOUBLE_QUOTE;
                    break;
            }
            break;

        case KC_G:
            // rationale: avoid SFB.
            // ngram: « gs » (0.01907%)
            // examples: « settings », « things », « strings », « mappings »
            if (prev_keycodes[1] == KC_SLASH) {
                // « :%s/re/p/gc »
                tap_code(KC_C);
                last_summoned_keycode = KC_C;
            } else {
                tap_code(KC_S);
                last_summoned_keycode = KC_S;
            }
            break;

        case KC_H:
            // rationale: typing & typo reduction (too many accidental h⏎ and oh⏎)
            // ngram: « how » (0.02984%)
            // examples: « how »,  « show », « somehow », « however »
            tap_code(KC_O);
            tap_code(KC_W);
            last_summoned_keycode = KC_W;
            break;

        case KC_I:
        case HOME2_I:
            switch (penultimate_keycode) {
                case KC_H:
                    // rationale: avoid SFS.
                    // ngram: « hif »
                    // examples: « shift », « Ctrl+Shift », « chiffre »
                    tap_code(KC_F);
                    last_summoned_keycode = KC_F;
                    break;

                case KC_G:
                    // rationale: avoid SFS.
                    // ngram: « gic »
                    // examples: « logic »,  « magic »,  « logical »,  « logiciel »
                    tap_code(KC_C);
                    last_summoned_keycode = KC_C;
                    break;

                default:
                    // rationale: avoid SFS.
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_J:
            // rationale: avoid SFS-2.
            // ngram: « jour » (TODO%)
            // examples: « jour », « bonjour », « aujourd'hui », « journey »
            tap_code(KC_O);
            tap_code(KC_U);
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_N:
        case HOME2_N:
            switch (penultimate_keycode) {
                case KC_A:
                case HOME2_A:
                    if (prev_keycodes[2] != KC_E && prev_keycodes[2] != HOME2_E) {
                        // rationale: avoid SFS.
                        // ngram: « ano » (TODO%)
                        // examples: « another »,  « piano »,  « anonyme »,  « nano »
                        tap_code(KC_O);
                        last_summoned_keycode = KC_O;
                    } else {
                        // rationale: avoid SFS.
                        // ngram: « eanl » (TODO%)
                        // examples: « cleanly »,  « cleanliest »,
                        tap_code(KC_L);
                        last_summoned_keycode = KC_L;
                    }
                    break;

                default:
                    // rationale: avoid SFB:
                    // ngram: « nl » (TODO%)
                    // examples: « only »,  « unless »,  « online »,  « enlever »,  « unlikely »
                    summon_same_finger_home_key(prev_keypos[0]);
                    break;
            }
            break;

        case KC_M:
            // rationale: avoid SFS.
            // ngram: « m␣" » (TODO%)
            // examples: « git commit -m "msg" »
            tap_code(KC_SPACE);
            tap_code16(KC_DOUBLE_QUOTE);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
            last_summoned_keycode = KC_DOUBLE_QUOTE;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: « ow » (0.10844%)
            // examples: « how »,  « know »,  « down »,  « now »,  « Windows »
            tap_code(KC_W);
            last_summoned_keycode = KC_W;
            break;

        case KC_P:
            // rationale: avoid SFB.
            // ngram: « pd » (0.01643%)
            // examples: « update »,  « pdf »,  « pdt »,  « dropdown »,  « pd.DataFrame »
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            if (penultimate_keycode == KC_U) {
                // Make typing « update » and « updating » more comfortable.
                tap_code(KC_A);
                tap_code(KC_T);
                tap_code(KC_E);
                last_summoned_keycode = KC_E;
            }
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFS.
            // ngram: « ree » (0.02534%)
            // examples: « free »,  « screen »,  « three »,  « freeze »
            /*
             * The most frequent letter preceding « ee » is R but various
             * constraints and design choices led R to occupy the same finger
             * as ↻. This magic rules fixes the deficiency.
             */
            // to make it easier to type « there » without SFS.
            tap_code(KC_E);
            if (!is_preceded_by_the) {
                tap_code(KC_E);
            }
            last_summoned_keycode = KC_E;
            break;

        case KC_S:
        case HOME2_S:
            // rationale: avoid SFB.
            // ngram: « sg » (0.00539%)
            // examples: « msg », « disgusted »,  « disguised »
            if (is_preceded_by_the) {
                // to make it easier to type « these » without SFS.
                tap_code(KC_E);
                last_summoned_keycode = KC_E;
            } else {
                tap_code(KC_G);
                last_summoned_keycode = KC_G;
            }
            break;

        case KC_T:
        case HOME2_T:
            switch (penultimate_keycode) {
                default:
                    summon_same_finger_home_key(prev_keypos[0]);
                    break;
            }
            break;

        case KC_W:
            // rationale: avoid ring-pinky outer row skip and SFS.
            // ngram: « would » (0.07580%)
            // examples: « would »,  « wouldn't »
            tap_code(KC_O);
            tap_code(KC_U);
            tap_code(KC_L);
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_Q:
            // rationale: avoid SKB and SFB.
            // ngram: « qq » (0.01282%)
            // examples: « gqq » (format current line), « qqun »,  « qqch »,  « qqs »
            tap_code(KC_Q);
            last_summoned_keycode = KC_Q;
            break;

        case KC_U:
            switch (prev_keycodes[1]) {
                case KC_H:
                    // examples: « thumb »,  « human »,  « humain », « thumbnails »
                    /*
                     * The default rule would have produced « hu⏎ » which is not very helpful.
                     */
                    tap_code(KC_M);
                    last_summoned_keycode = KC_M;
                    break;

                default:
                    // rationale: avoid SFS.
                    // examples: « but »,  « put »,  « custom »,  « input »,  « such »,  « dessus »
                    summon_same_finger_home_key(prev_keypos[1]);
                    break;
            }
            break;

        case KC_V:
            // rationale: avoid SFB.
            // ngram: « vb » (TODO%)
            // examples: « vb » (enter visual mode, go back once), « file.vb », « VB.NET », « VBA »
            tap_code(KC_B);
            last_summoned_keycode = KC_B;
            break;

        case KC_X:
            // rationale: avoid SKB and SFB.
            // ngram: « xx » (0.02115%)
            // examples: « xx » (delete 2 chars in Vim), « xxd »,  « xxx_ENABLE »
            /*
             * « xr » (0.00070%) < « xx » (0.02115%)
             */
            tap_code(KC_X);
            last_summoned_keycode = KC_X;
            break;

        case KC_Y:
            // rationale: avoid SFB.
            // ngram: « ying » (0.00561%)
            // examples: « annoying »,  « saying »,  « buying »
            /*
             * « yi » is almost always followed by « ng » (« ying » makes up 0.68375%
             * of all tetragrams starting with « yi »). Exceptions include
             * « yikes » (0.04580%), « yield » (0.02181%) and « yank inner » Vim
             * commands (0.24863%) like « yiw ».
             */
            tap_code(KC_I);
            tap_code(KC_N);
            tap_code(KC_G);
            last_summoned_keycode = KC_G;
            break;

        case KC_Z:
            // rationale: avoid SFB.
            // ngram: « zb » (0.00012%)
            // examples: « zb » (reposition current line at bottom of the window, see :help scroll-cursor)
            /*
             * The frequency of the bigram might look abysmally small but
             * that's because I never used vim folds before my job. Obviously,
             * I cannot run a key logger on my work computer without raising
             * alarms in the IT department so I cannot gather more
             * representative figures.
             */
            tap_code(KC_B);
            last_summoned_keycode = KC_B;
            break;

        case KC_DOT:
            // rationale: avoid ring-pinky LSB.
            // ngram: « ./ » (0.04388%)
            // examples: « ./program »,  « ./hid_listen »,  « require('./config.json'); »
            tap_code(KC_SLASH);
            last_summoned_keycode = KC_SLASH;
            break;

        case KC_QUOTE:
            // rationale: avoid SFB.
            // ngram: « 'h » (0.00944%)
            // examples: « aujourd'hui »,  « l'histoire »,  « l'heure »,  « l'hypothèse »
            tap_code(KC_H);
            last_summoned_keycode = KC_H;
            break;

        case KC_ESC:
            // rationale: avoid SFS and reduce typing.
            // ngram: « ⎋:q⏎ »
            tap_code16(KC_COLON);
            tap_code(KC_Q);
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case KC_SPACE:
            // rationale: typing reduction.
            // ngram: « ␣the » (0.27805%)
            // examples: « in the », « of the », « with the »,  « and then »
            tap_code(KC_T);
            tap_code(KC_H);
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case QK_REP:
            switch (penultimate_keycode) {
                case KC_O:
                    // rationale: avoid LSB.
                    // ngram: « o↻k » (0.01618%)
                    // examples: « look »,  « looks »,  « took »,  « notebook »,  « hook »
                    /*
                     * « o↻er » (0.00000%) < « o↻k » (0.01618%)
                     */
                    tap_code(KC_K);
                    last_summoned_keycode = KC_K;
                    break;

                case KC_DOT:
                    // rationale: avoid ring-pinky LSS.
                    // ngram: « ../ » (TODO%)
                    // examples: « cd ../ », « ../my_script.sh », « cp ../out.xml ../before.xml »
                    tap_code(KC_SLASH);
                    last_summoned_keycode = KC_SLASH;
                    break;

                default:
                    // rationale: avoid SFS.
                    // ngram: « ↻er » (TODO%)
                    // examples: « different »,  « better »,  « passer »,  « aller »,  « letter »
                    tap_code(KC_E);
                    tap_code(KC_R);
                    last_summoned_keycode = KC_R;
                    break;
            }
            break;

        case MAGIC_R:
            // rationale: typing reduction and consistency.
            // ngram: « ␣the » (TODO%)
            // examples: « git commit the », « :find the »,
            switch (last_summoned_keycode) {
                case KC_SPACE:
                    SEND_STRING("the");
                    last_summoned_keycode = KC_SPACE;
                    break;

                default:
                    tap_code(KC_E);
                    last_summoned_keycode = KC_E;
                    break;
            }
            break;

        case MAGIC_L:
            // rationale: avoid SFB.
            // ngram: « _<MAGIC_L>␣ », « __<MAGIC_L>␣ »
            /*
             * the main reason why there may seem to be more magic rules on the
             * right hand is that MAGIC_R does not cause SFBs with KC_SPACE
             * whereas MAGIC_L has a nasty tendency to trade a non-thumb SFB or
             * SFS by a left thumb SFB or SFS if the sequence ends with a space
             * (almost) directly after. This magic rule helps to at least
             * alleviate the « <MAGIC_L>␣ » SFB. The « <MAGIC_L>_␣ » SFS cannot be
             * bypassed though.
             */
            switch (last_summoned_keycode) {
                case KC_SPACE:
                    if (prev_keycodes[1] == KC_G) {
                        // Avoid the KC_G MAGIC_L KC_C SFS.
                        SEND_STRING("commit ");
                        last_summoned_keycode = KC_SPACE;
                    } else {
                        // e.g., KC_T MAGIC_L MAGIC_R for "I creaTED THE ".
                        SEND_STRING("the");
                        last_summoned_keycode = KC_E;
                    }
                    break;
                default:
                    tap_code(KC_SPACE);
                    last_summoned_keycode = KC_SPACE;
                    break;
            }
            break;

        default:
            summon_same_finger_home_key(prev_keypos[0]);
            break;

    }
}
