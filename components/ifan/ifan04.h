#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/core/automation.h"

namespace esphome {
namespace ifan {

class IFan04 : public Component, public uart::UARTDevice {
 public:
  void dump_config() override;
  void loop() override;
  void output(const float speed);
 protected:
  void handle_char_(uint8_t c);
  void handle_command_(uint8_t type, uint8_t param);

};

}  // namespace ifan04
}  // namespace esphome

