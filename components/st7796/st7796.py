
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display, spi
from esphome.const import CONF_ID, CONF_LAMBDA

DEPENDENCIES = ['spi']

st7796 = cg.esphome_ns.namespace('st7796')
ST7796 = ht16k33_alpha_ns.class_('ST7796', cg.PollingComponent, spi.spiDevice)


cg.register_component(st7796)
display.register_display(ST7796)


