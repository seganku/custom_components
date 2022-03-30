import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.components import display, spi
from esphome.const import (
    CONF_DC_PIN,
    CONF_ID,
    CONF_LAMBDA,
    CONF_MODEL,
    CONF_PAGES,
    CONF_RESET_PIN,
)

DEPENDENCIES = ["spi"]

CONF_LED_PIN = "led_pin"

st7796_ns = cg.esphome_ns.namespace("st7796")
st7796 = st7796_ns.class_(
    "ST7796Display", cg.PollingComponent, spi.SPIDevice, display.DisplayBuffer
)
ST7796M5Stack = st7796_ns.class_("ST7796M5Stack", st7796)
ST7796TFT24 = st7796_ns.class_("ST7796TFT24", st7796)
ST7796WT32 = st7796_ns.class_("ST7796WT32", st7796)

ST7796Model = st7796_ns.enum("ST7796Model")

MODELS = {
    "M5STACK": ST7796Model.M5STACK,
    "TFT_2.4": ST7796Model.TFT_24,
    "WT_32": ST7796Model.WT_32,
}

ST7796_MODEL = cv.enum(MODELS, upper=True, space="_")

CONFIG_SCHEMA = cv.All(
    display.FULL_DISPLAY_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(st7796),
            cv.Required(CONF_MODEL): ST7796_MODEL,
            cv.Required(CONF_DC_PIN): pins.gpio_output_pin_schema,
            cv.Optional(CONF_RESET_PIN): pins.gpio_output_pin_schema,
            cv.Optional(CONF_LED_PIN): pins.gpio_output_pin_schema,
        }
    )
    .extend(cv.polling_component_schema("1s"))
    .extend(spi.spi_device_schema(False)),
    cv.has_at_most_one_key(CONF_PAGES, CONF_LAMBDA),
)


async def to_code(config):
    if config[CONF_MODEL] == "M5STACK":
        lcd_type = ST7796M5Stack
    if config[CONF_MODEL] == "TFT_2.4":
        lcd_type = ST7796TFT24
        if config[CONF_MODEL] == "WT_32":
        lcd_type = ST7796WT32
    rhs = lcd_type.new()
    var = cg.Pvariable(config[CONF_ID], rhs)

    await cg.register_component(var, config)
    await display.register_display(var, config)
    await spi.register_spi_device(var, config)
    cg.add(var.set_model(config[CONF_MODEL]))
    dc = await cg.gpio_pin_expression(config[CONF_DC_PIN])
    cg.add(var.set_dc_pin(dc))

    if CONF_LAMBDA in config:
        lambda_ = await cg.process_lambda(
            config[CONF_LAMBDA], [(display.DisplayBufferRef, "it")], return_type=cg.void
        )
        cg.add(var.set_writer(lambda_))
    if CONF_RESET_PIN in config:
        reset = await cg.gpio_pin_expression(config[CONF_RESET_PIN])
        cg.add(var.set_reset_pin(reset))
    if CONF_LED_PIN in config:
        led_pin = await cg.gpio_pin_expression(config[CONF_LED_PIN])
        cg.add(var.set_led_pin(led_pin))