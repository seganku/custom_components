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
  this->publish_state();

  this->write_state_();
}
void IFan::write_state_() {
  if (this->direction_ != nullptr)
    this->direction_->set_state(this->direction == fan::FanDirection::REVERSE);
  int local_speed = static_cast<int>(this->speed);
  ESP_LOGD("IFAN", "Setting Fan Speed %i", local_speed);
  ESP_LOGD("IFAN", "State is %i", this->state);

  target_fan_speed = local_speed;
  if (state == 0){
    set_off();
    this->speed = 0;
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
    
  //this->output_->set_level(speed);

 
}  // write_state_
void IFan::set_off(){
    ESP_LOGD("IFAN", "Setting Fan OFF");
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
    long_beep();
    this->turn_off();
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
void IFan::enable_remote(bool enabled){

}

void IFan::loop() {
  while (this->available()) {
    uint8_t c;
    this->read_byte(&c);
    this->handle_char_(c);
  }
}
void IFan::toggle_light(){
  digitalWrite(9, !digitalRead(9));
}

void IFan::handle_char_(uint8_t c) {
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
void IFan::handle_command_(uint8_t type, uint8_t param) {
  if (type == 4) {
    if (param == 4)
      toggle_light();
      //this->light_trigger_->trigger();
      return;
    else
      write_state_();
      //this->fan_trigger_->trigger(param);
      return;
    return;
  }
  if (type == 6) {
    //this->buzzer_trigger_->trigger();
    beep();
    return;
  }
  ESP_LOGD(TAG, "unknown command type %d param %d", type, param);
}
}  // namespace ifan

}  // namespace esphome
