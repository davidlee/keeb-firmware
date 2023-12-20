#pragma once

//
// Combos
//

// R + S = left CMD
const uint16_t PROGMEM combo_lcmd[]      = {R_OPT, S_CMD, COMBO_END};
const uint16_t PROGMEM combo_lcmd2[]     = {KC_R,  KC_S,  COMBO_END};
// E + I = right CMD
const uint16_t PROGMEM combo_rcmd[]      = {E_CMD, I_OPT, COMBO_END};
const uint16_t PROGMEM combo_rcmd2[]     = {KC_E,  KC_I,  COMBO_END};

// W + F = (
const uint16_t PROGMEM combo_lprn[]      = {KC_W, KC_F, COMBO_END};
// F + P = )
const uint16_t PROGMEM combo_rprn[]      = {KC_F, KC_P, COMBO_END};

// X + C = [
const uint16_t PROGMEM combo_lbrc[]      = {X_OPT, C_CMD, COMBO_END};
// C + D = ]
const uint16_t PROGMEM combo_rbrc[]      = {C_CMD, KC_D, COMBO_END};

// N + S = backspace word
const uint16_t PROGMEM combo_bs_word[]   = {N_SFT, E_CMD, COMBO_END};
const uint16_t PROGMEM combo_bs_word2[]  = {KC_N,  KC_E,  COMBO_END};

// I + O = delete word
const uint16_t PROGMEM combo_del_word[]  = {I_OPT, O_CTL, COMBO_END};
const uint16_t PROGMEM combo_del_word2[] = {KC_I,  KC_O,  COMBO_END};

// A + R = caps word
const uint16_t PROGMEM combo_caps_word[] = {A_CTL, R_OPT, COMBO_END};
const uint16_t PROGMEM combo_caps_word2[]= {KC_A, KC_R,   COMBO_END};

// N + U = turn on PTR layer
const uint16_t PROGMEM combo_ptr[]       = {N_SFT, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ptr2[]      = {KC_N,  KC_U, COMBO_END};

// BOOT MODE
const uint16_t PROGMEM combo_boot_left[]  = {KC_1, KC_5, COMBO_END};
const uint16_t PROGMEM combo_boot_right[] = {KC_6, KC_0, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_lcmd,       KC_LGUI),
  COMBO(combo_lcmd2,      KC_LGUI),
  COMBO(combo_rcmd,       KC_RGUI),
  COMBO(combo_rcmd2,      KC_RGUI),

  COMBO(combo_lbrc,       KC_LBRC),
  COMBO(combo_rbrc,       KC_RBRC),
  COMBO(combo_lprn,       KC_LPRN),
  COMBO(combo_rprn,       KC_RPRN),

  COMBO(combo_bs_word,    BS_WORD),
  COMBO(combo_bs_word2,   BS_WORD),
  COMBO(combo_del_word,   DEL_WORD),
  COMBO(combo_del_word2,  DEL_WORD),

  COMBO(combo_caps_word,  CAP_WRD),
  COMBO(combo_caps_word2, CAP_WRD),

  COMBO(combo_ptr,        PTR_LCK),
  COMBO(combo_ptr2,       PTR_LCK),

  COMBO(combo_boot_left,  QK_BOOT),
  COMBO(combo_boot_right, QK_BOOT),
};
