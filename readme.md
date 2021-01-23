## Precondition's keymap for the Dactyl Manuform 5x6
To be inserted in ~/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition

This keymap uses Colemak-DH for its alpha base with the addition of common French accented keys in direct access and dead keys for the less common ones. For use in English, French, and programming.

Notably, [home row mods](https://precondition.github.io/home-row-mods) are used, as well as tap dance and combos.

Aside from the usual combos that expand to a single special character or command like <kbd>]</kbd> or <kbd>Caps Lock</kbd>, you can find, what I've dubbed, “steno-lite” combos in `combos.c`. Taking inspiration from machine stenography, common n-grams, word parts and words that are too short to abbreviate (in a text expansion program such as AutoKey) are assigned a key chord/combo, most frequently involving the <kbd>Backspace</kbd> key. Using <kbd>Backspace</kbd>+<kbd>Letter(s)</kbd> has the benefit of greatly reducing potential combo misfires as you're unlikely to type a letter and simultaneously delete it.

Don't expect a fancy KLE visualisation of the keymap in this README or a graphic of the layout of the keymap in the comments of `keymap.c`. If you look at the code of the people who do that, you'll notice that the visualisation is nearly always outdated and misleads the reader, so why bother? Besides, `LAYOUT_5x6` is pretty enough as is.

For much more details, read the comments in the source files.

### OS Setup

* OS: Xubuntu Linux
* Regional keyboard layout: Modified English US intl. with AltGr dead keys
    * Swapped the shift pairs of the semicolon key

### Required features
New features take a very long time to get merged into `qmk:master` so, meanwhile, I merge pending pull requests into my own fork to use them. Below is the list of PRs that are required for this particular instance of my keymap to work properly — It varies from branch to branch.

1. [Combo improvements](https://github.com/qmk/qmk_firmware/pull/8591) by @sevanteri: Used in `combos.c` for all the combos involving non-basic keycodes
