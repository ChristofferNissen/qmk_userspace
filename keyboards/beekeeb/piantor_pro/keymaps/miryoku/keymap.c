// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include <stdlib.h>  // for rand()

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum layers {
    _COLEMAKDH = 0,
    // _GRAPHITE = 0,
    _GAME=1,
    // Miryoku
    _MEDIA=2,
    _NAV=3,
    _MOUSE=4,
    _SYM=5,
    _NUM=6,
    _FUNC=7,
};

enum custom_keycodes {
// Miryoku
    MEDIA = MO(_MEDIA),
    NAV = MO(_NAV),
    MOUSE = MO(_MOUSE),
    NUM = MO(_NUM),
    SYM = MO(_SYM),
    FUNC = MO(_FUNC),
// Thumb keys
    T0 = LT(MEDIA, KC_ESC),
    T1 = LT(NAV, KC_SPC),
    T2 = LT(MOUSE, KC_TAB),
    T3 = LT(SYM, KC_ENT),
    T4 = LT(NUM, KC_BSPC),
    T5 = LT(FUNC, KC_QUOT),
    //  Mod taps homerow
    HR_A = MT(MOD_LGUI, KC_A),
    HR_R = MT(MOD_LALT, KC_R),
    HR_S = MT(MOD_LSFT, KC_S),
    HR_T = MT(MOD_LCTL, KC_T),
    HR_N = MT(MOD_RCTL, KC_N),
    HR_E = MT(MOD_RSFT, KC_E),
    HR_I = MT(MOD_RALT, KC_I),
    HR_O = MT(MOD_RGUI, KC_O),

    // mod taps graphite
    // HR_N = MT(MOD_LGUI, KC_N),
    // HR_R = MT(MOD_LALT, KC_R),
    // HR_T = MT(MOD_LSFT, KC_T),
    // HR_S = MT(MOD_LCTL, KC_S),
    // HR_H = MT(MOD_RCTL, KC_H),
    // HR_A = MT(MOD_RSFT, KC_A),
    // HR_E = MT(MOD_RALT, KC_E),
    // HR_I = MT(MOD_RGUI, KC_I),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HR_A,    HR_R,    HR_S,    HR_T,    KC_G,                         KC_M,    HR_N,    HR_E,    HR_I,    HR_O, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               T0,      T1,      T2,         T3,      T4,      T5
                                      //`--------------------------'  `--------------------------'
  ),

  // [_GRAPHITE] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     _______,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                      KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______,    HR_N,    HR_R,    HR_T,    HR_S,    KC_G,                         KC_Y,    HR_H,    HR_A,    HR_E,    HR_I, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P,  KC_DOT, KC_MINS, KC_SLSH, _______,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                              T0,      T1,      T2,         T3,      T4,      T5
  //                                     //`--------------------------'  `--------------------------'
  // ),

  [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    HR_N,    HR_E,    HR_I,    HR_O, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               T0,  KC_SPC,  KC_TAB,         T3,      T4,      T5
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, QK_BOOT, XXXXXXX,XXXXXXX,TG(_GAME), KC_SLEP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_ENT, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_DEL,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_MINS,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_PLUS,    KC_0, KC_MINS,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                      XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MENU, _______, _______,     _______, _______, _______
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

#if defined(OS_DETECTION_ENABLE)
bool process_detected_host_os_user(os_variant_t detected_os) {
  const bool is_mac = (detected_os == OS_MACOS || detected_os == OS_IOS);
  // Swap Alt and GUI keys if a Mac or iOS machine is detected.
  keymap_config.swap_lalt_lgui = is_mac;
  keymap_config.swap_ralt_rgui = is_mac;
  // keymap_config.swap_lctl_lgui = is_mac;
  // keymap_config.swap_rctl_rgui = is_mac;
  return true;
}
#endif

// World of Warcraft

#define LAYER_GAMING _GAME

typedef struct {
    uint16_t keycode;
    uint16_t interval_ms;        // Base interval
    uint16_t jitter_ms;          // Max jitter
    uint16_t current_interval_ms;// Actual interval for this repeat
    bool repeat_active;
    bool first_press_sent;
    uint16_t timer;
    bool hold;                   // true = hold for repeat, false = toggle repeat
} repeat_key_t;

// D is toggle-to-repeat, interval 2500ms; F is hold-to-repeat (example)
repeat_key_t repeat_keys[] = {
    {KC_D, 2500, 100, 2500, false, false, 0, false},   // D toggles repeat, 2.5s interval
    {KC_SPC, 60000, 100, 60000, false, false, 0, false},   // D toggles repeat, 2.5s interval
    {KC_X, 5000, 100, 5000, false, false, 0, true}      // X hold-to-repeat, 200ms interval
    // {KC_F, 3500, 100, 3500, false, false, 0, true}      // F hold-to-repeat, 200ms interval
};
#define NUM_REPEAT_KEYS (sizeof(repeat_keys)/sizeof(repeat_keys[0]))

// for auto-run feature
static bool autorun_enabled = true;
static uint16_t s_timer = 0;
static bool s_held = false;
static bool s_replaced = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(LAYER_GAMING)) {

        if (autorun_enabled) {
            switch (keycode) {
                case KC_S:
                    if (record->event.pressed) {
                        s_held = true;
                        s_timer = timer_read();
                        s_replaced = false;
                    } else {
                        s_held = false;
                        s_replaced = false;
                    }
                    break;
            }

            // If S is being replaced, suppress KC_S
            if (keycode == KC_S && s_replaced) {
                return false;
            }
        }

        // Check for hold-repeat cancellation by other key presses
        if (record->event.pressed) {
            if (keycode != KC_TAB) {
                // don't cancel on tab for target selection
                for (int i = 0; i < NUM_REPEAT_KEYS; i++) {
                    if (repeat_keys[i].repeat_active
                        && keycode != repeat_keys[i].keycode) {
                        repeat_keys[i].repeat_active = false;
                        repeat_keys[i].first_press_sent = false;
                    }
                }
            }
        }

        // Handle repeat logic
        for (int i = 0; i < NUM_REPEAT_KEYS; i++) {
            if (keycode == repeat_keys[i].keycode) {
                if (repeat_keys[i].hold) {
                    // Hold-to-repeat logic
                    if (record->event.pressed) {
                        register_code(repeat_keys[i].keycode);
                        unregister_code(repeat_keys[i].keycode);
                        repeat_keys[i].repeat_active = true;
                        repeat_keys[i].first_press_sent = true;
                        repeat_keys[i].timer = timer_read();
                        repeat_keys[i].current_interval_ms = repeat_keys[i].interval_ms;
                        if (repeat_keys[i].jitter_ms > 0) {
                            repeat_keys[i].current_interval_ms += rand() % (repeat_keys[i].jitter_ms + 1);
                        }
                    } else {
                        repeat_keys[i].repeat_active = false;
                        repeat_keys[i].first_press_sent = false;
                    }
                } else {
                    // Toggle-to-repeat logic
                    if (record->event.pressed) {
                        if (repeat_keys[i].repeat_active) {
                            // Turn off
                            repeat_keys[i].repeat_active = false;
                            repeat_keys[i].first_press_sent = false;
                        } else {
                            repeat_keys[i].repeat_active = true;
                            repeat_keys[i].first_press_sent = true;
                            repeat_keys[i].timer = timer_read();
                            repeat_keys[i].current_interval_ms = repeat_keys[i].interval_ms;
                            if (repeat_keys[i].jitter_ms > 0) {
                                repeat_keys[i].current_interval_ms += rand() % (repeat_keys[i].jitter_ms + 1);
                            }
                        }
                        // Turn on and send initial press
                        register_code(repeat_keys[i].keycode);
                        // Generate random delay between 60 and 70 ms
                        uint8_t delay = 30 + (rand() % 31); // rand() % 11 gives 0-10
                        wait_ms(delay);
                        unregister_code(repeat_keys[i].keycode);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (layer_state_is(LAYER_GAMING)) {

        if (autorun_enabled) {
            if (s_held && !s_replaced) {
                if (timer_elapsed(s_timer) > 2000) { // 2 seconds
                    // Stop sending S, send middle mouse button click instead
                    register_code(MS_BTN3);   // Press middle mouse button
                    unregister_code(MS_BTN3); // Release middle mouse button
                    s_replaced = true;
                }
            }
        }

        for (int i = 0; i < NUM_REPEAT_KEYS; i++) {
            if (repeat_keys[i].repeat_active && repeat_keys[i].first_press_sent) {
                if (timer_elapsed(repeat_keys[i].timer) > repeat_keys[i].current_interval_ms) {
                    register_code(repeat_keys[i].keycode);
                    // Generate random delay between 60 and 70 ms
                    uint8_t delay = 30 + (rand() % 31); // rand() % 11 gives 0-10
                    wait_ms(delay);
                    unregister_code(repeat_keys[i].keycode);
                    repeat_keys[i].timer = timer_read();
                    // Set next interval with jitter
                    repeat_keys[i].current_interval_ms = repeat_keys[i].interval_ms;
                    if (repeat_keys[i].jitter_ms > 0) {
                        repeat_keys[i].current_interval_ms += rand() % (repeat_keys[i].jitter_ms + 1);
                    }
                }
            }
        }
    }
}

