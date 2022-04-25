#include "ifan.h"
#include "esphome/components/fan/fan_helpers.h"
#include "esphome/core/log.h"
#include "esphome.h"

namespace esphome {
namespace ifan {
#define buzzer 10
#define relay_1 14
#define relay_2 12
#define relay_3 15
static const char *const TAG = "ifan.fan";
int target_fan_speed;
int start_time_offset;
void IFan::setup() {
  pinMode(buzzer, 0x01);
  pinMode(relay_1, 0x01);
  pinMode(relay_2, 0x01);
  pinMode(relay_3, 0x01);

  auto restore = this->restore_state_();
  if (restore.has_value()) {
    restore->apply(*this);
    this->current_speed = this->speed;
    this->write_state_();
  }
}
void IFan::dump_config() { LOG_FAN("", "IFan", this); }
fan::FanTraits IFan::get_traits() { return fan::FanTraits(false, true, false, 3); }
void IFan::control(const fan::FanCall &call) {
  if (call.get_state().has_value())
    this->state = *call.get_state();
  if (call.get_speed().has_value())
    this->speed = *call.get_speed();

  this->write_state_();
  this->publish_state();
}
void IFan::write_state_() {
  int local_speed = static_cast<int>(this->speed);
  ESP_LOGD("IFAN", "Setting Fan Speed %i", local_speed);
  ESP_LOGD("IFAN", "State is %s", this->state ? "ON" : "OFF");
  if (this->speed != this->current_speed) {
    if (this->speed)
      this->state = 1;
  }
  target_fan_speed = local_speed;
  if (this->state == 0) {
    set_off();
    return;
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
  this->current_speed = this->speed;
  // this->output_->set_level(speed);

}  // write_state_
void IFan::set_off() {
  ESP_LOGD("IFAN", "Setting Fan OFF");
  this->speed = 0;
  this->state = 0;
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  long_beep();
}
void IFan::set_low() {
  this->speed = 1;
  this->state = 1;
  ESP_LOGD("IFAN", "Setting Fan Low");
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  beep();
}
void IFan::set_med() {
  this->speed = 2;
  this->state = 1;
  ESP_LOGD("IFAN", "Setting Fan Med");
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, LOW);
  beep(2);
}
void IFan::set_high() {
  this->speed = 3;
  this->state = 1;
  ESP_LOGD("IFAN", "Setting Fan HIGH");
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, HIGH);

  beep(3);
}
void IFan::set_buzzer_enable(bool buzzer_enable) { this->buzzer_enable_ = buzzer_enable; }
void IFan::beep(int num) {
  if (!this->buzzer_enable_)
    return;
  for (int i = 0; i < num; i++) {
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(50);
  }
}
void IFan::long_beep(int num) {
  if (!this->buzzer_enable_)
    return;
  for (int i = 0; i < num; i++) {
    ESP_LOGD("IFAN", "Long Beep");
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
}

}  // namespace ifan

}  // namespace esphome
