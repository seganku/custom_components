import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import (
    CONF_OUTPUT_ID,
)

marlin_ns = cg.esphome_ns.namespace("marlin")

Marlin = marlin_ns.class_("MarlinButton", cg.Component, button)

CONFIG_SCHEMA = button.BUTTON_SCHEMA.extend(
    {
        cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(Marlin),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    await button.register_button(var, config)
