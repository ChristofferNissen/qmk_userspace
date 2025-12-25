#pragma once

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define PLOOPY_DPI_OPTIONS {400}
#define PLOOPY_DPI_DEFAULT 1
#define PLOOPY_DRAGSCROLL_DPI 100

// #define PLOOPY_DRAGSCROLL_MOMENTARY
// #define PLOOPY_DRAGSCROLL_INVERT
#define PLOOPY_DRAGSCROLL_INVERT_Y

// #define PLOOPY_DRAGSCROLL_DIVISOR_H 120.0
// #define PLOOPY_DRAGSCROLL_DIVISOR_V 120.0
#define PLOOPY_DRAGSCROLL_DIVISOR_H 4.0
#define PLOOPY_DRAGSCROLL_DIVISOR_V 4.0
// #define PLOOPY_DRAGSCROLL_DIVISOR_H 8.0
// #define PLOOPY_DRAGSCROLL_DIVISOR_V 8.0

#define POINTING_DEVICE_HIRES_SCROLL_ENABLE
#define POINTING_DEVICE_HIRES_SCROLL_MULTIPLIER 15
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

/* --- Mouse Acceleration (Quadratic) --- */
#define ACCEL_OFFSET 10 // Threshold (counts) to start acceleration
#define ACCEL_SLOPE 1.5 // Aggressiveness of acceleration (Curve Steepness)
#define ACCEL_LIMIT 4.0 // Maximum multiplier cap

/* --- Scroll Configuration (Hysteresis & High-Res) --- */
#define SCROLL_SENSITIVITY 0.9f // Multiplier for fine-grained scroll speed
#define SCROLL_STRAIGHT_FACTOR 1.5
#define SCROLL_UNLOCK_THRESHOLD 30
// #define POINTING_DEVICE_TASK_THROTTLE_MS 1 // High refresh rate for smooth scroll

/* --- Click Configuration --- */
#define TAPPING_TERM 200
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
