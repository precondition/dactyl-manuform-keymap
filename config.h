#pragma once

// Home row mods settings //

// Default tapping term is 200
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define QUICK_TAP_TERM_PER_KEY

// Disable PERMISSIVE_HOLD
// (It's enabled dy default for all Dactyl Manuform boards, 
// so it requires explicit undef to disable)
#undef PERMISSIVE_HOLD

#define COMBO_TERM 70

// Limits the max. amount of layers to 16 to save firmware memory.
#define LAYER_STATE_16BIT

// Save firmware space
// Strip away all prints except `uprintf`
#define USER_PRINT
// Disable hardware lock switches support to free up space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RIGHT_CTRL

// Custom config settings that are not part of QMK core. //

// Define the delay to wait for before pressing the next key in a sequence of
// keys defined as a part of a macro/custom keycode.
#define KEY_SEQ_DELAY 10

// The second key must be pressed within ADAPTIVE_KEY_TERM milliseconds of the
// last input activity for the adaptive key functionality to take effect.
// Applies to adaptive swaps as well.
#define ADAPTIVE_KEY_TERM 809

// Shamelessly stolen mouse key settings from @pierrechevalier83 //

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100
