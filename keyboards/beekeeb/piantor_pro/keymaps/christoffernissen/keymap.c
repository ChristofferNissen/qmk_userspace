// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum layers {
    _COLEMAKDH = 0,
    _LOWER = 1,
    _RAISE = 2,
    _ADJUST = 3,
    _ARROW,
    _MOUSEL,
    _MOUSER
};

#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_RAISE_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

enum custom_keycodes {
// Layer overlay keycodes
    LOWER = MO(_LOWER),
    RAISE = MO(_RAISE),
    ARROW = MO(_ARROW),
    MOUSEL = TT(_MOUSEL),
    MOUSER = TT(_MOUSER),
// Thumb keys
    T0 = LT(MOUSEL, KC_ESC),
    T1 = LT(ARROW, KC_SPC),
    T2 = LT(LOWER, KC_TAB),
    T3 = LT(RAISE, KC_ENT),
    T4 = KC_BSPC,
    T5 = LT(MOUSER, KC_QUOT),
// _BASE Mod taps homerow
    HR_A = MT(MOD_LGUI, KC_A),
    HR_S = MT(MOD_LALT, KC_S),
    HR_D = MT(MOD_LSFT, KC_D),
    HR_F = MT(MOD_LCTL, KC_F),
    HR_J = MT(MOD_RCTL, KC_J),
    HR_K = MT(MOD_RSFT, KC_K),
    HR_L = MT(MOD_LALT, KC_L),
    HR_SCLN = MT(MOD_RGUI, KC_SCLN),
    HR_1 = MT(MOD_LGUI, KC_1),
    HR_2 = MT(MOD_LALT, KC_2),
    HR_3 = MT(MOD_LSFT, KC_3),
    HR_4 = MT(MOD_LCTL, KC_4),
    HR_7 = MT(MOD_RCTL, KC_7),
    HR_8 = MT(MOD_RSFT, KC_8),
    HR_9 = MT(MOD_RALT, KC_9),
    HR_0 = MT(MOD_RGUI, KC_0),
// _COLEMAKDH mod taps homerow
    // HR_A = MT(MOD_LGUI, KC_A), same as qwerty
    HR_R = MT(MOD_LALT, KC_R),
    HR_S_C = MT(MOD_LSFT, KC_S),
    HR_T = MT(MOD_LCTL, KC_T),
    HR_N = MT(MOD_RCTL, KC_N),
    HR_E = MT(MOD_RSFT, KC_E),
    HR_I = MT(MOD_RALT, KC_I),
    HR_O = MT(MOD_RGUI, KC_O),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HR_A,    HR_R,  HR_S_C,    HR_T,    KC_G,                         KC_M,    HR_N,    HR_E,    HR_I,    HR_O, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               T0,      T1,      T2,         T3,      T4,      T5
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HR_1,    HR_2,    HR_3,    HR_4,    KC_5,                         KC_6,    HR_7,    HR_8,    HR_9,    HR_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PLUS, XXXXXXX, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,KC_TILDE, KC_SLSH, KC_BSLS, KC_PIPE,  KC_GRV,                       KC_EQL, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_DEL, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX,   DF(4),   DF(0),                      KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ARROW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSEL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX,                      MS_WHLU, MS_WHLL, MS_UP, MS_WHLR, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_BTN1, XXXXXXX, MS_BTN2, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, MS_BTN2, MS_BTN1,    MS_BTN1, MS_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, MS_WHLL,   MS_UP, MS_WHLR, MS_WHLU,                      XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, MS_BTN1, XXXXXXX, MS_BTN2, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, MS_BTN2, MS_BTN1,    MS_BTN1, MS_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

//   [_TEMPLATE] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           _______, _______, _______,     _______, _______, _______
//                                       //`--------------------------'  `--------------------------'
//   ),

};

