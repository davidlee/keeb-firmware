#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(COLEMAK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif

#define COMBO_COUNT 18

#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY 1
#define TAPPING_FORCE_HOLD 1       // allows mod tap to resolve to a mod after a tap
#define TAP_CODE_DELAY 5
#define PERMISSIVE_HOLD_PER_KEY 1  // we want permissive hold for all tap-hold keys except home row mods
#define QUICK_TAP_TERM_PER_KEY 1
#define QUICK_TAP_TERM 30

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER
#define COMBO_TERM 20               // time to get all combo keys down - keep it short!
#define COMBO_HOLD 30               // time to hold to trigger delayed combo

#define CAPSWORD_USE_SHIFT 1
#define QMK_KEYS_PER_SCAN 4

#define DYNAMIC_MACRO_NO_NESTING 1

// MOUSE KEYS
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
//
#define MK_C_OFFSET_0 5
#define MK_C_OFFSET_1 10
#define MK_C_OFFSET_UNMOD 20
#define MK_C_OFFSET_2 40
//
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_INTERVAL_0 16
#define MK_C_INTERVAL_1 16
#define MK_C_INTERVAL_2 16
//
#define MK_W_OFFSET_UNMOD   1         
#define MK_W_INTERVAL_UNMOD 20           
#define MK_W_INTERVAL_0     60       
#define MK_W_INTERVAL_1     40       
#define MK_W_INTERVAL_2     10       
