#include "Fan.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

void app_main(void)
{   
    // Cấu hình các chân GPIO để điều khiển động cơ qua driver L298N
    esp_rom_gpio_pad_select_gpio(IN1_GPIO_NUM);
    gpio_set_direction(IN1_GPIO_NUM, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(IN2_GPIO_NUM);
    gpio_set_direction(IN2_GPIO_NUM, GPIO_MODE_OUTPUT);

    // Cấu hình PWM
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = PWM_RESOLUTION,
        .freq_hz = PWM_FREQ,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .channel = LEDC_CHANNEL_0,
        .duty = 0,
        .gpio_num = IN1_GPIO_NUM,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);
    printf("Quạt sẽ quay trong vòng 1 phút\n");
    run_fan_for_minutes(1);
    set_motor_speed(0);
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    while (1) {
        set_motor_speed(DUTY_LIGHT);
        printf("Speed: Light\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS); 

        set_motor_speed(DUTY_MEDIUM);
        printf("Speed: Medium\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS); 

        set_motor_speed(DUTY_HIGH);
        printf("Speed: High\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
