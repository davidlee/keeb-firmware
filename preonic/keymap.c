#include QMK_KEYBOARD_H
#include "davidlee.c"

#define LAYOUT_preonic_wrapper(...)   LAYOUT_preonic_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_CMK] = LAYOUT_preonic_wrapper(
    __CMK_R0,
    __CMK_R1,
    __CMK_R2,
    __CMK_R3,
    __CMK_R4
  ), 

  [_HRM] = LAYOUT_preonic_wrapper(
    __HRM_R0,
    __HRM_R1,
    __HRM_R2,
    __HRM_R3,
    __HRM_R4
  ), 

  [_NAV] = LAYOUT_preonic_wrapper(
    __NAV_R0,
    __NAV_R1,
    __NAV_R2,
    __NAV_R3,
    __NAV_R4
  ), 

  [_NUM] = LAYOUT_preonic_wrapper(
    __NUM_R0,
    __NUM_R1,
    __NUM_R2,
    __NUM_R3,
    __NUM_R4
  ), 

  [_FUN] = LAYOUT_preonic_wrapper(
    __FUN_R0,
    __FUN_R1,
    __FUN_R2,
    __FUN_R3,
    __FUN_R4
  ), 

  [_MED] = LAYOUT_preonic_wrapper(
    __MED_R0,
    __MED_R1,
    __MED_R2,
    __MED_R3,
    __MED_R4
  ), 

  [_GAM] = LAYOUT_preonic_wrapper(
    __GAM_R0,
    __GAM_R1,
    __GAM_R2,
    __GAM_R3,
    __GAM_R4
  ), 

  [_PTR] = LAYOUT_preonic_wrapper(
    __PTR_R0,
    __PTR_R1,
    __PTR_R2,
    __PTR_R3,
    __PTR_R4
  ), 

};
