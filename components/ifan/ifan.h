#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "esphome/components/output/float_output.h"
#include "esphome/components/fan/fan.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace ifan {

class IFan : public Component, public fan::Fan, public uart::UARTDevice {
 public:
  IFan() {}
  void setup() override;
  void dump_config() override;
  void set_direction(output::BinaryOutput *direction) { this->direction_ = direction; }
  fan::FanTraits get_traits() override;
  void enable_remote(bool enabled);
 protected:
  void control(const fan::FanCall &call) override;
  void write_state_();

  void set_off();
  void set_low();
  void set_med();
  void set_high();
  void beep(int num=1);
  void long_beep(int num=1);
  
  output::BinaryOutput *direction_{nullptr};
  int speed_count_{};
};

}  // namespace speed
}  // namespace esphome
