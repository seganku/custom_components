import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan, output, uart

DEPENDENCIES = ['uart']

from esphome.const import (
    CONF_DIRECTION_OUTPUT,
    CONF_OUTPUT_ID,
)
CONF_ENABLE_REMOTE= "enable_remote"
ifan_ns = cg.esphome_ns.namespace('ifan')
IFan = ifan_ns.class_("IFan", cg.Component, fan.Fan, uart.UARTDevice)

CONFIG_SCHEMA = fan.FAN_SCHEMA.extend(
    {
        cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(IFan),
        cv.Optional(CONF_DIRECTION_OUTPUT): cv.use_id(output.BinaryOutput),
        cv.Optional(CONF_ENABLE_REMOTE, default=False): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)




async def to_code(config):
    if config[CONF_ENABLE_REMOTE]:
        CONFIG_SCHEMA.extend(uart.UART_DEVICE_SCHEMA)
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    await cg.register_component(var, config)
    await fan.register_fan(var, config)

    if config[CONF_ENABLE_REMOTE]:
        await uart.register_uart_device(var, config)
        cg.add(var.enable_remote(True))
    else: 
        cg.add(var.enable_remote(False))

    if CONF_DIRECTION_OUTPUT in config:
        direction_output = await cg.get_variable(config[CONF_DIRECTION_OUTPUT])
        cg.add(var.set_direction(direction_output))
        
