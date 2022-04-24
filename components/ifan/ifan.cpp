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
    
  int state = this->state ? static_cast<int>(this->speed); // state = 0-1 float
  ESP_LOGD("IFAN", "Setting Fan Speed %f", state);

  switch (state) {
    case 0:
      // OFF
      set_off();
      break;
    case 1 ... 33:
      // low speed
      set_low();
      break;
    case 34 ... 65:
      // medium speed
      set_med();
      break;
    case 66 ... 100:
      // high speed
      set_high();
      break;
  }
    
  //this->output_->set_level(speed);

  //if (this->direction_ != nullptr)
  //  this->direction_->set_state(this->direction == fan::FanDirection::REVERSE);
}  // write_state_
void IFan::set_low(){
    ESP_LOGD("IFAN", "Setting Fan OFF");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
}
void IFan::set_low(){
    ESP_LOGD("IFAN", "Setting Fan Low");
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
}
void IFan::set_med(){
    ESP_LOGD("IFAN", "Setting Fan Med");
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(15, LOW);
}
void IFan::set_high(){
    ESP_LOGD("IFAN", "Setting Fan HIGH");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, HIGH);
}
}  // namespace ifan

}  // namespace esphome
