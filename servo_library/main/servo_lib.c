#include "servo_lib.h"

// Frequency of PWM signal
#define SERVO_PWM_FREQ 50

// Function to initialize the servo
void servo_init(servo_t *servo, gpio_num_t gpio_num, ledc_channel_t channel) {
    servo->channel = channel;
    servo->gpio_num = gpio_num;
    servo->min_pulsewidth_us = 500;
    servo->max_pulsewidth_us = 2500;
    servo->max_angle = 180;

    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_16_BIT,
        .freq_hz = SERVO_PWM_FREQ,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);

    // Configure the LEDC channel
    ledc_channel_config_t ledc_channel = {
        .channel = servo->channel,
        .duty = 0,
        .gpio_num = servo->gpio_num,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .hpoint = 0,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);
}

// Function to set the servo angle and enable/disable it
void servo_set_angle(servo_t *servo, uint32_t angle, uint8_t enable) {
    if (enable) {
        if (angle > servo->max_angle) {
            angle = servo->max_angle;
        }

        // Calculate the duty cycle based on the angle
        uint32_t duty = ((angle * (servo->max_pulsewidth_us - servo->min_pulsewidth_us)) / servo->max_angle) + servo->min_pulsewidth_us;

        // Convert microseconds to duty cycle
        uint32_t duty_cycle = (duty * (1 << 16)) / (1000000 / SERVO_PWM_FREQ);

        // Set the duty cycle
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, servo->channel, duty_cycle);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, servo->channel);
    } else {
        // Disable the servo by setting duty cycle to 0
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, servo->channel, 0);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, servo->channel);
    }
}
