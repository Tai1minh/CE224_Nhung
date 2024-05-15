#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "servo_lib.h"

// Define the GPIO pin for the servo
#define SERVO_GPIO_PIN GPIO_NUM_18  // Change this to your servo GPIO pin
#define SERVO_CHANNEL LEDC_CHANNEL_0

void app_main(void) {
    // Create a servo_t instance
    servo_t my_servo;

    // Initialize the servo
    servo_init(&my_servo, SERVO_GPIO_PIN, SERVO_CHANNEL);

    while (1) {
        // Enable and set the servo to 0 degrees
        servo_set_angle(&my_servo, 0, 1);
        printf("Servo set to 0 degrees\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);  // Delay for 2 seconds

        // Set the servo to 90 degrees
        servo_set_angle(&my_servo, 90, 1);
        printf("Servo set to 90 degrees\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);  // Delay for 2 seconds

        // // Set the servo to 180 degrees
        // servo_set_angle(&my_servo, 180, 1);
        // printf("Servo set to 180 degrees\n");
        // vTaskDelay(2000 / portTICK_PERIOD_MS);  // Delay for 2 seconds

        // // Disable the servo
        // servo_set_angle(&my_servo, 0, 0);
        // printf("Servo disabled\n");
        // vTaskDelay(2000 / portTICK_PERIOD_MS);  // Delay for 2 seconds
    }
}
