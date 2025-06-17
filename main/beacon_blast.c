#include "esp_log_level.h"
#include <esp_log.h>

#define TAG "LOG"

void app_main(void) {
  esp_log_level_set(TAG, ESP_LOG_INFO);
  ESP_LOGI(TAG, "This is working");
}
