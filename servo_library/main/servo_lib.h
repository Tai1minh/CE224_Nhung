#ifndef SERVO_LIB_H
#define SERVO_LIB_H

#include "driver/ledc.h"

// Define a struct to hold the servo configuration
typedef struct {
    ledc_channel_t channel;  // LEDC channel
    gpio_num_t gpio_num;     // GPIO pin number
    uint32_t min_pulsewidth_us; // Minimum pulse width in microseconds
    uint32_t max_pulsewidth_us; // Maximum pulse width in microseconds
    uint32_t max_angle;      // Maximum angle in degrees
} servo_t;

// Function prototypes
void servo_init(servo_t *servo, gpio_num_t gpio_num, ledc_channel_t channel);
void servo_set_angle(servo_t *servo, uint32_t angle, uint8_t enable);

#endif // SERVO_LIB_H
    