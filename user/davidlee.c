#include "davidlee.h"
#include "keycodes.h"
#include "keymaps.h"
#include "combos.h"

#ifdef AUDIO_ENABLE
  float blip_song[][2] = SONG(BLIP);
  float arp_song[][2]  = SONG(ARP);
#endif

#define LAYER_MASK_DEFAULT (1 << _CMK | 1 << _HRM)

const int home_row_mod_keys[] = { A_CTL, R_OPT, S_CMD, T_SFT, N_SFT, E_CMD, I_OPT, O_CTL};

//
// Function Overrides
//

void keyboard_post_init_user(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & ALPHA TAP/HOLD layers
  oneshot_enable(); // FIXME should not be necessary but ... weird bug
#ifdef RGBLIGHT_ENABLE
  rgblight_enable();
  // rgblight_setrgb_noeeprom (0x01,  0x00, 0x00);
  rgblight_sethsv_noeeprom (0x01,  0x00, 0x00);
#endif

#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
#endif
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_SFT:
            return QUICK_TAP_TERM - 20;
        default:
            return QUICK_TAP_TERM;
    }
}
// give precedence to tap rather than hold for home row mods, to avoid accidental mistypes
// NOTE: this gives _hold_ precedence for bottom row mods Z_CTL, X_OPT, C_CMD and COM_CMD, DOT_OPT, SLS_CTL
// as well as all hold/tap keys on the side and lower rows

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case BS_SFT:

    case A_CTL:
    case R_OPT:
    case S_CMD:
    case T_SFT:
  
    case O_CTL:
    case I_OPT:
    case E_CMD:
    case N_SFT:

    // case Z_CTL:
    // case X_OPT:
    // case C_CMD:

    // case SLS_CTL:
    // case DOT_OPT:
    // case COM_CMD:
      return false;
    default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      // home row mods
      case A_CTL:
      case O_CTL:
        return TAPPING_TERM + 40;
      case R_OPT:
      case I_OPT:
        return TAPPING_TERM + 40; // lazy ring fingers are the biggest culprit for misfires
      case S_CMD:
      case E_CMD:
        return TAPPING_TERM + 40;
      case T_SFT:
      case N_SFT:
        return TAPPING_TERM + 30;

      // bottom row mods 
      // case Z_CTL:
      // case X_OPT:
      // case C_CMD:
      // case SLS_CTL:
      // case DOT_OPT:
      // case COM_CMD:
        // return TAPPING_TERM + 20; // doesn't matter as much due to permissive_hold

      default:
        return TAPPING_TERM;
    }
}


#ifdef RGB_MATRIX_ENABLE
// TODO:
//
// 1. extract mapping of layer state => RGB MATRIX mode for use in layer_state_set_user
// 2. consider using rgb_matrix_indicators_advanced_user in 
//    place of caps_word_set_user / the first stanza of layer_state_set_user
// 3. use global variable layer_state along with said mapping 
//    for the "caps disabled" branch, to return to the appropriate layer indication

void caps_word_set_user(bool active) {
  if (active) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);      
  } else {
    // TODO FIXME hax 
    // this should call layer_state_set_user, or 
    // we need to implement layer indications using some other hook
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  }
}

// helper method for caps lock layer indication
// bool _is_caps_lock_on(void) {
//   return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  // CAPS LOCK / CAPS WORD indication
  // without this, activation via a momentary layer (vs say, a combo) 
  // will have its indication cancelled when layer changes back ...
  // still, it feels a bit like a crude hack.
  // if (_is_caps_lock_on() || is_caps_word_on()) {
  //   rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
  //   return state;
  // }

  switch (get_highest_layer(state)) {
    case _NUM:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
      break;
    case _NAV:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
      break;
    case _PTR:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
      break;
    case _FUN:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
      break;
    case _MED:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
      break;
    case _GAM:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
      break;
    case _CMK:
    default:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
      break;
  }
  
  return state;
}
#endif

#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _NUM:
      rgblight_sethsv_noeeprom (0x55,  0x7A, 0xFF);
      break;
    case _NAV:
      rgblight_sethsv_noeeprom (0x77,  0xFF, 0x00);
      break;
    case _PTR:
      rgblight_sethsv_noeeprom (0x33,  0xFF, 0xAA);
      break;
    case _FUN:
      rgblight_sethsv_noeeprom (0x00,  0x00, 0xEE);
      break;
    case _MED:
      rgblight_sethsv_noeeprom (0x00,  0xAA, 0xFF);
      break;
    case _GAM:
      rgblight_sethsv_noeeprom (0x99,  0x44, 0x33);
      break;
    case _CMK:
    default:
      rgblight_sethsv_noeeprom (0x00,  0x02, 0x01);
      break;
  }
  return state;
}
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// static uint16_t fun_ptr_timeout = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAM_LCK:
      layer_on(_GAM);
      #ifdef AUDIO_ENABLE
        PLAY_SONG(arp_song);
      #endif
      return false;

    case PTR_LCK:
      layer_on(_PTR);
      // #ifdef RGB_MATRIX_ENABLE
      //   rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
      // #endif
      #ifdef AUDIO_ENABLE
        PLAY_SONG(arp_song);
      #endif
      return false;

    // EXIT LAYERS

    case EXT_GAM:
      layer_off(_GAM);
      #ifdef AUDIO_ENABLE
        PLAY_SONG(arp_song);
      #endif
      return false;

    case EXT_PTR:
      layer_off(_PTR);
      #ifdef AUDIO_ENABLE
        PLAY_SONG(blip_song);
      #endif
      return false;

    // other functions

    case CAP_WRD:
      if (record->event.pressed) {
        caps_word_on();
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif
      }
      return false;

    case BS_WORD:
      if (record->event.pressed) {
        tap_code16(LOPT(KC_BSPC));
      }
      return false;

    case DEL_WORD:
      if (record->event.pressed) {
        tap_code16(LOPT(KC_DELETE));
      }
      return false;
    default:
      return true; /* Process all other keycodes normally */
  }
}

void _reset(void) {
  default_layer_set(LAYER_MASK_DEFAULT);
  layer_state_set(LAYER_MASK_DEFAULT);
}

// LEADER KEY stanzas
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
bool did_leader_succeed;
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_TWO_KEYS(KC_L, KC_L) { // Layer: default
      _reset();
      did_leader_succeed = true;
    }

    SEQ_TWO_KEYS(KC_H, KC_E) { // home row mods enable
      _reset();
      did_leader_succeed = true;
    }

    SEQ_TWO_KEYS(KC_H, KC_D) { // home row mods disable
      default_layer_set(_CMK);
      layer_state_set(_CMK);
      did_leader_succeed = true;
    }

    leader_end();
  }
}

void leader_start(void) {
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
#endif
  } else {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_PINWHEEL_SAT);
#endif
  }
}
#endif
