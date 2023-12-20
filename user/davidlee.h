#pragma once
#include QMK_KEYBOARD_H

#ifndef USERSPACE
#define USERSPACE

enum userspace_layers {
  _CMK,   // Colemak-DH
  _HRM,   // Home Row Mods / alpha hold-taps
  _GAM,   // Gaming / QWERTY
  _GRT,   // Gaming right hand transposed left mirrored w. fn keys
  _NUM,   // Numbers
  _PTR,   // Pointer
  _NAV,   // Navigation
  _FUN,   // Function keys
  _MED,   // Media & right hand mods
};

#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)
  #define ARP   ED_NOTE(_C1), ED_NOTE(_DS1), ED_NOTE(_G1),  ED_NOTE(_C2), ED_NOTE(_DS2), ED_NOTE(_G2),  ED_NOTE(_C3), ED_NOTE(_G3), ED_NOTE(_C3), ED_NOTE(_G2), ED_NOTE(_DS2), ED_NOTE(_C2)
#endif

void _reset(void);
bool _is_caps_lock_on(void);
