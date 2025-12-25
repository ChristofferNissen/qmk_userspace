#include QMK_KEYBOARD_H
#include <math.h>

enum custom_keycodes {
    // CUSTOM_DRAG_SCROLL = SAFE_RANGE,
    ZOOM_BTN3
};

// --- TAP DANCE ENUMERATION ---
enum {
    TD_MEDIA_CTRL,
    TD_BRIGHT_CTRL,
};

// --- LAYER DEFINITIONS ---
// _VIA layers reserved for future configuration
enum layers {
    _BASE,
    _MEDIA,
    _BRIGHTNESS,
    _PLAYBACK,
    _VIA2,
    _VIA3
};

// --- STATE VARIABLES ---
static bool is_zoom_mode = false;
static uint16_t zoom_timer = 0;
int16_t media_acum_x = 0;
int16_t media_acum_y = 0;
int16_t bright_acum_x = 0;
int16_t bright_acum_y = 0;

// --- CONFIGURATION ---
#define MEDIA_THRESHOLD 150   // Sensitivity threshold for media controls

// --- MEDIA TAP DANCE ---
void media_click_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            tap_code(MS_BTN5);
        } else {
            // Hold: Media Layer (Momentary)
            layer_on(_MEDIA);
            media_acum_x = 0;
            media_acum_y = 0;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
             // Double Tap: Switch to Playback Layer (Toggle/One-shot logic if needed, user requested change layer)
             layer_on(_PLAYBACK);
        }
    }
}

void media_click_reset(tap_dance_state_t *state, void *user_data) {
    // Always turn off temporary media layer on release
    if (IS_LAYER_ON(_MEDIA)) {
        layer_off(_MEDIA);
    }
}

// --- BRIGHTNESS TAP DANCE ---
void bright_click_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            tap_code(MS_BTN4);
        } else {
            // Hold: Media Layer (Momentary)
            layer_on(_BRIGHTNESS);
            media_acum_x = 0;
            media_acum_y = 0;
        }
    }
    else if (state->count == 2) {
        if (!state->pressed) {
             // Double Tap: Switch to Playback Layer (Toggle/One-shot logic if needed, user requested change layer)
             layer_on(_BRIGHTNESS);
        }
    }
}

void bright_click_reset(tap_dance_state_t *state, void *user_data) {
    if (IS_LAYER_ON(_BRIGHTNESS)) {
        layer_off(_BRIGHTNESS);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, media_click_finished, media_click_reset),
    [TD_BRIGHT_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bright_click_finished, bright_click_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(TD(TD_BRIGHT_CTRL), TD(TD_MEDIA_CTRL), DRAG_SCROLL, MS_BTN2, MS_BTN1, ZOOM_BTN3),

    // Media Layer - Transparent (handled via C code logic)
    [_MEDIA] = LAYOUT(_______, _______, _______, _______, _______, _______),
    [_BRIGHTNESS] = LAYOUT(_______, _______, _______, _______, _______, QK_BOOT),

    // Playback Layer - Media Controls
    [_PLAYBACK] = LAYOUT(KC_MPRV,  TO(_BASE), KC_MPLY,  KC_MNXT, KC_MFFD,  KC_MRWD ),
    [_VIA2] = LAYOUT(_______, _______, _______, _______, _______, _______),
    [_VIA3] = LAYOUT(_______, _______, _______, _______, _______, _______)
};

// --- KEYCODE LOGIC ---
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ZOOM_BTN3:
            if (record->event.pressed) {
                is_zoom_mode = true;
                zoom_timer = timer_read();
                register_code(KC_LCTL);
                // register_code(KC_LSFT); // Add Shift for broader browser support (Pinch Zoom emulation)
            } else {
                is_zoom_mode = false;
                // unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                if (timer_elapsed(zoom_timer) < TAPPING_TERM) {
                    tap_code(MS_BTN3); // Tap Middle Click if short press
                }
            }
            return false;
        default:
            return true;
    }
}

// --- POINTING DEVICE LOGIC ---
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // --- MOUSE ACCELERATION ALGORITHM (QUADRATIC) ---
    // Calculate 2D velocity magnitude (speed)
    float speed = sqrt(pow(mouse_report.x, 2) + pow(mouse_report.y, 2));

    if (speed > ACCEL_OFFSET) {
        // Quadratic acceleration formula
        // Use a smaller divisor (0.001) since we are squaring the speed difference
        float factor = 1.0f + pow(speed - ACCEL_OFFSET, 2) * 0.001f * ACCEL_SLOPE;

        // Cap the acceleration factor
        if (factor > ACCEL_LIMIT) {
            factor = ACCEL_LIMIT;
        }

        // Apply scaling
        mouse_report.x = (int16_t)(mouse_report.x * factor);
        mouse_report.y = (int16_t)(mouse_report.y * factor);
    }

    else if (IS_LAYER_ON(_MEDIA) || IS_LAYER_ON(_PLAYBACK)) {
        media_acum_x += mouse_report.x;
        media_acum_y += mouse_report.y;

        // Volume (Y-axis)
        if (media_acum_y > MEDIA_THRESHOLD) {
            tap_code(KC_VOLU);
            media_acum_y = 0;
        } else if (media_acum_y < -MEDIA_THRESHOLD) {
            tap_code(KC_VOLD);
            media_acum_y = 0;
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.v = 0;
        mouse_report.h = 0;
    }

    else if (IS_LAYER_ON(_BRIGHTNESS)) {
        bright_acum_x += mouse_report.x;
        bright_acum_y += mouse_report.y;

        // Brightness (Y-axis)
        if (bright_acum_y > MEDIA_THRESHOLD) {
            tap_code(KC_BRIU);
            // tap_code(KC_SCRL); // mac
            bright_acum_y = 0;
        } else if (bright_acum_y < -MEDIA_THRESHOLD) {
            tap_code(KC_BRID);
            // tap_code(KC_PAUS); // mac
            bright_acum_y = 0;
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.v = 0;
        mouse_report.h = 0;
    }

    else if (is_zoom_mode) {
        // Map Y-axis to Vertical Scroll (v)
        // With Control held, this is interpreted as Zoom by the OS
        mouse_report.v = -mouse_report.y;

        // Lock cursor and other axes
        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.h = 0;
    }

    return mouse_report;
}

