#pragma once

#define USE_SERIAL

#define MASTER_LEFT
// #define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up

// Default tapping term is 200
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

#define TAPDANCE_TERM 80
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
 
// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD_PER_KEY
// The reason this above setting is per key is because of TT()
// The setting below defines how many times you need to tap a TT() to toggle the layer.
#define TAPPING_TOGGLE 3
 
// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

#define COMBO_VARIABLE_LEN
#define COMBO_COUNT COMBO_VARIABLE_LEN
#define COMBO_TERM 40


//Shamelessly stolen mouse key settings from @pierrechevalier83:

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Htz or higher
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
