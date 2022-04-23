#include "ifan.h"
#include "esphome/components/fan/fan_helpers.h"
#include "esphome/core/log.h"
#include "esphome.h"

namespace esphome {
namespace ifan {

static const char *const TAG = "ifan.fan";
int target_fan_speed;
int start_time_offset;
void IFan::setup() {
  auto restore = this->restore_state_();
  if (restore.has_value()) {
    restore->apply(*this);
    this->write_state_();
  }
}
void IFan::dump_config() { LOG_FAN("", "IFan", this); }
fan::FanTraits IFan::get_traits() {
  return fan::FanTraits(false, true, this->direction_ != nullptr, 3);
}
void IFan::control(const fan::FanCall &call) {
  if (call.get_state().has_value())
    this->state = *call.get_state();
  if (call.get_speed().has_value())
    this->speed = *call.get_speed();
  if (call.get_direction().has_value())
    this->direction = *call.get_direction();

  this->write_state_();
  this->publish_state();
}
void IFan::write_state_() {
    
  float speed = this->state ? static_cast<float>(this->speed) / static_cast<float>(3) : 0.0f;
  ESP_LOGD("IFAN", "Setting Fan Speed %f", speed);

  if (speed < 0.3) {
    // OFF
    
    digitalWrite(14, LOW); // relay 1
    digitalWrite(12, LOW); // relay 2
    digitalWrite(15, LOW); // relay 3
    ESP_LOGD("IFAN", "Setting Fan OFF");
  } else if (state < 0.6) {
    // low speed
    ESP_LOGD("IFAN", "Setting Fan Low");
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
  } else if (state < 0.9) {
    // medium speed
    ESP_LOGD("IFAN", "Setting Fan Medium");
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(15, LOW);
  } else {
    // high speed
    ESP_LOGD("IFAN", "Setting Fan High");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, HIGH);
  }
    
  //this->output_->set_level(speed);

  //if (this->direction_ != nullptr)
  //  this->direction_->set_state(this->direction == fan::FanDirection::REVERSE);
}  // write_state_

}  // namespace ifan

}  // namespace esphome
