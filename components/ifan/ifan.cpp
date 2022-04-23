#include "ifan.h"
#include "esphome/components/fan/fan_helpers.h"
#include "esphome/core/log.h"
#define LOW 0
#define HIGH 1
namespace esphome {
namespace ifan {

static const char *const TAG = "ifan.fan";

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

      if (speed < 0.3) {
        // OFF
        digitalWrite(14, LOW);
        digitalWrite(12, LOW);
        digitalWrite(15, LOW);
      } else if (state < 0.6) {
        // low speed
        digitalWrite(14, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(15, LOW);
      } else if (state < 0.9) {
        // medium speed
        digitalWrite(14, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(15, LOW);
      } else {
        // high speed
        digitalWrite(14, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(15, HIGH);
      }
    }
  this->output_->set_level(speed);

  if (this->direction_ != nullptr)
    this->direction_->set_state(this->direction == fan::FanDirection::REVERSE);
}

}  // namespace speed
}  // namespace esphome
