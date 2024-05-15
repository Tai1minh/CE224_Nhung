#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_lib.h"

// Define the GPIO pin for the LED
//#define LED_GPIO_PIN 13  // Change this to your LED GPIO pin

void app_main(void) {
    // Create an led_t instance
    led_t my_led;

    // Initialize the LED
    led_init(&my_led, 13);

    while (1) {
        // Turn the LED on by setting the state to 1
        led_set(&my_led, 1);
        printf("LED is ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second

        // Turn the LED off by setting the state to 0
        led_set(&my_led, 0);
        printf("LED is OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
    }
}
