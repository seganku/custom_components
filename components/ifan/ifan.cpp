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
    
  int local_speed = static_cast<int>(this->speed);
  ESP_LOGD("IFAN", "Setting Fan Speed %i", local_speed);
  target_fan_speed = local_speed;
  if (!this->state){
    set_off();
    target_fan_speed = 0;
  }
  switch (local_speed) {
    case 0:
      // OFF
      set_off();
      break;
    case 1:
      // low speed
      set_low();
      break;
    case 2:
      // medium speed
      set_med();
      break;
    case 3:
      // high speed
      set_high();
      break;
    default:
      set_off();
      break;
  }
    
  //this->output_->set_level(speed);

  if (this->direction_ != nullptr)
    this->direction_->set_state(this->direction == fan::FanDirection::REVERSE);
}  // write_state_
void IFan::set_off(){
    ESP_LOGD("IFAN", "Setting Fan OFF");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
    long_beep();
}
void IFan::set_low(){
    ESP_LOGD("IFAN", "Setting Fan Low");
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
    beep();
}
void IFan::set_med(){
    ESP_LOGD("IFAN", "Setting Fan Med");
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(15, LOW);
    beep(2);
}
void IFan::set_high(){
    ESP_LOGD("IFAN", "Setting Fan HIGH");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, HIGH);

    beep(3);
}
void IFan::beep(int num){
  for (int i=0; i<num; i++){
    digitalWrite(10, LOW);
    delay(50);
    digitalWrite(10, HIGH);
    delay(50);
  }
}
void IFan::long_beep(int num){
    for (int i=0; i<num; i++){
    ESP_LOGD("IFAN", "Long Beep");
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(10, HIGH);
    delay(500);
  }
}

}  // namespace ifan

}  // namespace esphome
