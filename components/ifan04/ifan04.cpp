#include "ifan04.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ifan04 {

static const char *TAG = "ifan04";

void IFan04::dump_config() {
  ESP_LOGCONFIG(TAG, "");
}

void IFan04::loop() {
  while (this->available()) {
    uint8_t c;
    this->read_byte(&c);
    this->handle_char_(c);
  }
}

void IFan04::handle_char_(uint8_t c) {
  static int state = 0;
  static uint8_t type = 0;
  static uint8_t param = 0;
  uint8_t csum;

  if (c == 0xaa) {
    state = 1;
    return;
  }
  switch (state) {
   case 1:
    if (c != 0x55)
      state = -1;
    break;
   case 2:
   case 5:
    if (c != 1)
      state = -1;
    break;
   case 3:
    type = c;
    break;
   case 4:
    if (c != 0)
      state = -1;
    break;
   case 6:
    param = c;
    break;
   case 7:
    csum = 2 + type + param;
    if (csum != c)
      ESP_LOGE(TAG, "checksum error: %02x != %02x", csum, c);
    else
      this->handle_command_(type, param);
    state = -1;
    break;
   default:
    state = -1;
  }
  state++;
}

void IFan04::handle_command_(uint8_t type, uint8_t param) {
  if (type == 4) {
    if (param == 4)
      this->light_trigger_->trigger();
    else
      this->fan_trigger_->trigger(param);
    return;
  }
  if (type == 6) {
    this->buzzer_trigger_->trigger();
    return;
  }
  ESP_LOGD(TAG, "unknown command type %d param %d", type, param);
}
void IFan04::output(const float state){
  if (state) {
            int speed = int(state / 0.33);
            if (!id(target_fan_speed) && (speed < 3)) {
              ESP_LOGD("IFAN04", "Fan currently off, boosting speed");
              id(target_fan_speed) = speed;
              state = 1.0;
              id(start_time_offset) = millis() + 5000; // 5 second delay
            } else {
              id(start_time_offset) = 0;
              id(target_fan_speed) = speed;
            }
          }
          if (state < 0.3) {
            // OFF
            id(target_fan_speed) = 0;
            id(start_time_offset) = 0;
            id(fan_relay1).turn_off();
            id(fan_relay2).turn_off();
            id(fan_relay3).turn_off();
          } else if (state < 0.6) {
            // low speed
            id(fan_relay1).turn_on();
            id(fan_relay2).turn_off();
            id(fan_relay3).turn_off();
          } else if (state < 0.9) {
            // medium speed
            id(fan_relay1).turn_off();
            id(fan_relay2).turn_on();
            id(fan_relay3).turn_off();
          } else {
            // high speed
            id(fan_relay1).turn_off();
            id(fan_relay2).turn_off();
            id(fan_relay3).turn_on();
          }
}
}  // namespace ifan04
}  // namespace esphome
