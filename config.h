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

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define COMBO_TERM 70

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT

// Save firmware space
// Strip away all prints except `uprintf`
#define USER_PRINT
// Disable hardware lock switches support to free up space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Custom (i.e. not part of QMK core) config to define the delay to wait for
// before pressing the next key in a sequence of keys defined as a part of a
// macro/custom keycode.
#define KEY_SEQ_DELAY 10

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
