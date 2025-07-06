#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hal/gpio_types.h"
#include "portmacro.h"
#include "soc/gpio_num.h"
#include <esp_log.h>
#include <stdint.h>

#define TAG "LOG"

#define LED_PIN GPIO_NUM_8
#define BLASTER_SELECT_BUTTON GPIO_NUM_3

gpio_config_t io_conf = {.pin_bit_mask = 1ULL << BLASTER_SELECT_BUTTON,
                         .mode = GPIO_MODE_INPUT,
                         .pull_down_en = GPIO_PULLDOWN_DISABLE,
                         .pull_up_en = GPIO_PULLUP_ENABLE,
                         .intr_type = GPIO_INTR_DISABLE};

void app_main(void) {
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
  gpio_config(&io_conf);
  while (true) {
    int blaster_select_state = gpio_get_level(BLASTER_SELECT_BUTTON);
    ESP_LOGI("LOG", "Button state %d", blaster_select_state);
    gpio_set_level(LED_PIN, blaster_select_state);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
