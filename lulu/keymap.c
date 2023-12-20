#include QMK_KEYBOARD_H
#include "davidlee.c"
#include "encoder.h"
#include "custom_oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CMK] = LAYOUT(
// COLEMAK
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LEAD,
TAB_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP,
ESC_MEH, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QOT_MEH,
OSL_FUN, Z_CTL,   X_OPT,   C_CMD,   KC_D,    KC_V,    ENC_B1,  ENC_B2,  KC_K,    KC_H,    COM_CMD, DOT_OPT, SLS_CTL, ENT_SFT,
                           FN,      CMD_TAB, SPC_NUM, MO_PTR,  NAV,     BS_SFT,  ENT_MED, _______
  ),

  [_HRM] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, A_CTL,   R_OPT,   S_CMD,   T_SFT,   _______,                   _______, N_SFT,   E_CMD,   I_OPT,   O_CTL,   _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAM] = LAYOUT(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LGUI,
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                           OSL_GRT, KC_LALT, KC_SPC,  KC_LCTL, NAV,     KC_BSPC, KC_ENT,  EXT_GAM
  ),

  [_GRT] = LAYOUT(
_______, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
KC_DEL,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                      KC_LBRC, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                      KC_RBRC, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
KC_ENT,  KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                           KC_LGUI, KC_MINS, KC_EQL,  _______, _______, _______, _______, EXT_GAM
  ),

  [_NUM] = LAYOUT(
KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PIPE,
KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_LPRN,                   KC_RPRN, KC_7,    KC_8,    KC_9,    KC_COLN, KC_AMPR,
SIRI,    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LBRC,                   KC_RBRC, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS,
CAP_WRD, KC_BSLS, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  _______, _______, KC_COLN, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT,
                           _______, EM_DASH, _______, _______, KC_0,    _______, KC_DOT,  _______
  ),

  [_PTR] = LAYOUT(
_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, _______,
KC_TAB,  XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, KC_ACL2,                   KC_WH_U, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_WH_U,
KC_ESC,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_BTN1,                   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, // f11 = center cursor w/ karabiner
KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, XXXXXXX, KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, KC_F11,  KC_WH_D, // f11 = center cursor w/ karabiner
                           GAM_LCK, PTR_LCK, KC_SPC,  _______, KC_ACL2, KC_ACL0, KC_ACL1, EXT_PTR
  ),

  [_NAV] = LAYOUT(
_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, _______,
KC_TAB,  _______, _______, _______, _______, _______,                   KC_WH_U, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_U,
KC_ESC,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______,                   KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _______, _______, KC_WH_D, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_D,
                           PTR_LCK, KC_TAB,  KC_SPC,  MO_PTR,  _______, _______, _______, _______
  ),

// not in use 
  [_FUN] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MED] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
KC_TAB,  _______, _______, KC_MSTP, KC_MPLY, _______,                   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
FN,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,                   _______, KC_LSFT, KC_RGUI, KC_RALT, KC_RCTL, FN,
_______, DM_REC1, DM_REC2, DM_PLY2, DM_PLY1, DM_RSTP, _______, _______, _______, KC_MPLY, _______, _______, _______, _______,
                           _______, _______, KC_MPLY, _______, _______, _______, _______, _______
  ),

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
void display_layer_state(void) {
  switch (get_highest_layer(layer_state)) {
    case _CMK:
    case _GAM:
      _render_logo();
      break;
    case _NUM:
      _render_layer1_logo();
      break;
    case _PTR:
      _render_layer2_logo();
      break;
    case _NAV:
      _render_layer3_logo();
      break;
    case _FUN:
    case _MED:
      _render_layer4_logo();
      break;
  }
}

bool oled_task_user(void) {
    display_layer_state();
    return false;
}
#endif
