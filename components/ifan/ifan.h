#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "esphome/components/output/float_output.h"
#include "esphome/components/fan/fan.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace ifan {

class IFan : public Component, public fan::Fan , public uart::UARTDevice {
 public:
  IFan() {}
  void setup() override;
  void dump_config() override;
  fan::FanTraits get_traits() override;
  void set_buzzer_enable(bool buzzer_enable) { this->buzzer_enable_ = buzzer_enable; }
  void set_remote_enable(bool remote_enable) { this->remote_enable_ = remote_enable;};

 protected:
  void control(const fan::FanCall &call) override;
  void write_state_();
  void set_off();
  void set_low();
  void set_med();
  void set_high();
  void do_speed(int lspeed);
  void beep(int num=1);
  void long_beep(int num=1);
  int speed_count_{};
  int current_speed=0;
  bool buzzer_enable_;
  bool remote_enable_;

  // For Remote
public:
  void loop() override;
  void output(const float speed);
 protected:
  void handle_char_(uint8_t c);
  void handle_command_(uint8_t type, uint8_t param);

};

}  // namespace speed
}  // namespace esphome
