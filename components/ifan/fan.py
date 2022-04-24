import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan, output, uart

DEPENDENCIES = ['uart']

from esphome.const import (
    CONF_DIRECTION_OUTPUT,
    CONF_OUTPUT_ID,
    CONF_ENABLE_REMOTE,
)

ifan_ns = cg.esphome_ns.namespace('ifan')
if CONF_ENABLE_REMOTE :
    IFan = ifan_ns.class_("IFan", cg.Component, fan.Fan, uart.UARTDevice)
else:
    IFan = ifan_ns.class_("IFan", cg.Component, fan.Fan)
CONFIG_SCHEMA = fan.FAN_SCHEMA.extend(
    {
        cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(IFan),
        cv.Optional(CONF_DIRECTION_OUTPUT): cv.use_id(output.BinaryOutput),
        cv.Required(CONF_ENABLE_REMOTE, default=False): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    await cg.register_component(var, config)
    await fan.register_fan(var, config)

    if CONF_ENABLE_REMOTE in config:
        await uart.register_uart_device(var, config)
        enable_remote = await cg.get_variable(config[CONF_ENABLE_REMOTE])
        cg.add(var.enable_remote(enable_remote))

    if CONF_DIRECTION_OUTPUT in config:
        direction_output = await cg.get_variable(config[CONF_DIRECTION_OUTPUT])
        cg.add(var.set_direction(direction_output))
        
