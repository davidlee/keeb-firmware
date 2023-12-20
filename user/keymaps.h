#pragma once 
#include "davidlee.h"

//
// Define keymap chunks for sharing between keebs
// 

// clang-format off

#define __BLANKS   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#define __CMK_R0   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS // preonic only
#define __CMK_R1   TAB_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP
#define __CMK_R1B  GRV_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP
#define __CMK_R2   ESC_MEH, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QOT_MEH
#define __CMK_R3   KC_LSFT, Z_CTL,   X_OPT,   C_CMD,   KC_D,    KC_V,    KC_K,    KC_H,    COM_CMD, DOT_OPT, SLS_CTL, ENT_SFT
#define __CMK_R4   FN,      KC_LCTL, KC_LOPT, CMD_TAB, SPC_NUM, E_FUN,   NAV,     BS_SFT,  ENT_MED, _______, PTR_LCK, MO_PTR

#define __HRM_R0 __BLANKS
#define __HRM_R1 __BLANKS
#define __HRM_R2   _______, A_CTL,   R_OPT,   S_CMD,   T_SFT,   _______, _______, N_SFT,   E_CMD,   I_OPT,   O_CTL,   _______
#define __HRM_R3 __BLANKS
#define __HRM_R4 __BLANKS

#define __NAV_R0 __BLANKS
#define __NAV_R1   KC_TAB,  _______, _______, _______, _______, _______, KC_WH_U, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_U
#define __NAV_R2   _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL
#define __NAV_R3   KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   KC_WH_D, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_D
#define __NAV_R4   _______, _______, _______, KC_TAB,  KC_SPC,  MO_PTR,  _______, _______, _______, _______, _______, _______

#define __NUM_R0 __BLANKS
#define __NUM_R1   KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_AMPR 
#define __NUM_R2   SIRI,    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS
#define __NUM_R3   _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_COLN, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT
#define __NUM_R4   _______, _______, _______, EM_DASH, XXXXXXX, _______, KC_0,    _______, KC_DOT,  _______, _______, _______


#define __FUN_R0 __BLANKS
#define __FUN_R1   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______
#define __FUN_R2   FN,      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, KC_LSFT, KC_RGUI, KC_RALT, KC_RCTL, FN
#define __FUN_R3   KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______
#define __FUN_R4   _______, _______, _______, GAM_LCK, _______, _______, MO_PTR,  _______, _______, _______, _______, _______

#define __MED_R0 __BLANKS
#define __MED_R1   _______, _______, _______, KC_MSTP, KC_MPLY, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______
#define __MED_R2   FN,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______, KC_LSFT, KC_RGUI, KC_RALT, KC_RCTL, FN
#define __MED_R3   _______, DM_REC1, DM_REC2, DM_PLY2, DM_PLY1, DM_RSTP, _______, KC_MPLY, _______, _______, _______, _______
#define __MED_R4   _______, _______, _______, _______, MO_PTR,  _______, _______, _______, XXXXXXX, _______, _______, _______

#define __GAM_R0   QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
#define __GAM_R1   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL
#define __GAM_R2   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define __GAM_R3   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT
#define __GAM_R4   EXT_GAM, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_LCTL, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#define __PTR_R0 __BLANKS
#define __PTR_R1   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, EXT_PTR
#define __PTR_R2   _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2
#define __PTR_R3   _______, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______
#define __PTR_R4   _______, _______, _______, _______, KC_SPC,  _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______

// clang-format on
