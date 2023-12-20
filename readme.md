# Vökvi - a Planck / Preonic layout for power without exertion.

[This layout](layout.txt) takes inspiration from many sources (miryoku,
callum, seniply, etc). It has evolved over months of daily use, and fits my
needs like a glove. If your preferences hew close to mine, it might just be
perfect for you too – or a good starting point for your own customisations.

---
Optimised for:

- Mac OS
- Colemak-DH
- Writing and programming in English (ANSI)
- My own preferences (e.g. left thumb spacebar; right thumb backspace & shift)
- Sharing the same layout across different keyboards without fuss (Lily58 soon)
- From highest to lowest priority:
  - Power (pragmatic efficiency in the hands of an expert user)
  - Comfort
  - Learnability
  - Implementation simplicity
  - Minimalism

---
Design principles:

- Eschew complex customisation. Embrace constraints & strong opinions.
- Nothing is further than one key from home position. Avoid moving from home at
  all where possible.
- Use both thumbs to their full potential. Having space, a numpad & symbol
  layer, Shift and Backspace all accessible from thumb home positions is
  a huge advantage, and better than any credible alternative. Fight me.
- Home row mods are great, and carefully tuned, but can be disabled without
  making life difficult.
- Every non-default layer includes conventional modifiers for one hand, in a
  consistent home row position
- Follow conventions which live in muscle memory, where possible:
  - left thumb for space, because mouse & keyboard games
  - right hand for numpad, from every number pad ever
  - ZXCV positions for undo/cut/copy/paste
  - vim style movement keys (left, down, up, right)
- Sometimes adding flexibility is worth duplication in a layout.
- Using subtle RGBlight / sound to indicate layer state doesn't hurt.
- Combos are awesome. Keep adding them until there's no room for more.
- Easily adapted to any board with 3x6 + 3 thumb keys, e.g. Corne.

---
Recommended with:

- Raycast, for two-keypress application switching with Meh shortcuts
- Karabiner, for Fn key support, and mapping functionality like dictation &
  mission control.

---
```
qmk flash --keyboard planck/rev6_drop
qmk compile --keyboard boardsource/lulu/rp2040
```
