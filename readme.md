## Precondition's keymap for the Dactyl Manuform 5x6
To be inserted in ~/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition

This keymap uses Colemak-DH for its alpha base with the addition of common French accented keys in direct access and dead keys for the less common ones. For use in English, French, and programming.

Notably, [home row mods](https://precondition.github.io/home-row-mods) are used, as well as tap dance and combos.

Aside from the usual combos that expand to a single special character or command like <kbd>]</kbd> or <kbd>Caps Lock</kbd>, you can find, what I've dubbed, “steno-lite” combos in `combos.c`. Taking inspiration from machine stenography, common n-grams, word parts and words that are too short to abbreviate (in a text expansion program such as AutoKey) are assigned a key chord/combo, most frequently involving the <kbd>Backspace</kbd> key. Using <kbd>Backspace</kbd>+<kbd>Letter(s)</kbd> has the benefit of greatly reducing potential combo misfires as you're unlikely to type a letter and simultaneously delete it.

Keymap visualisation diagrams are automatically generated with the help of [keymapviz] every time I compile.

[keymapviz]: https://github.com/yskoht/keymapviz

For much more details, read the comments in the source files.

### Keymap Tricks
This keymap contains many nifty QMK tricks that can inspire you for your own keymap. Here's a non-exhaustive list.

1. Home row mods: All the modifiers on the home row.
2. Shift+Backspace: Delete.
3. `NAV_UND`: Using a non-basic keycode (`S(KC_MINS)`) in a layer-tap.
4. Modifier-aware combos: Combos whose output changes based on the active modifier.
5. `TD_DOT`: Double tap the dot key to produce <kbd>.</kbd><kbd>space</kbd><kbd>One-Shot Shift</kbd> to quickly flow from one sentence to another.
6. One-Shot Swap Hand: For one-handed typing.
7. `CAPS_WORD`: Capitalizes the next word you type and then automatically toggle off Caps Lock. Perfect for typing all-caps IDENTIFIERS in code.

### OS Setup

* OS: Xubuntu Linux
* Regional keyboard layout: Modified English US intl. with AltGr dead keys
    * Swapped the shift pairs of the semicolon key

### Required features
New features take a very long time to get merged into `qmk:master` so, meanwhile, I merge pending pull requests into my own fork to use them. Below is the list of PRs that are required for this particular instance of my keymap to work properly — It varies from branch to branch.

1. [Combo improvements](https://github.com/qmk/qmk_firmware/pull/8591) by @sevanteri: Used in `combos.c` for all the combos involving non-basic keycodes.
2. [keymapviz] by @yskoht (not a QMK PR): Used in `rules.mk` to generate the fancy keymap visualisations of each layer. Remove the `.PHONY` code block from `rules.mk` to disable it.
