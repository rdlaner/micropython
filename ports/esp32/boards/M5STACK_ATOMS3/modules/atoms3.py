"""
M5STACK ATOM S3 Hardware Pin Assignments

          Back
|3V3|
| G5|             |G39|
| G6|             |G38|
| G7|             | 5V|
| G8|             |GND|
      GND 5V G2 G1
       Grove Port
"""
import st7789py as st7789
from micropython import const
from machine import Pin, SPI

# Button
PIN_BUTTON = const(41)

# IR
PIN_IR = const(4)

# I2C
PIN_I2C0_SCL = const(39)
PIN_I2C0_SDA = const(38)
PINT_I2C1_SCL = const(1)
PIN_I2C1_SDA = const(2)

# LCD SPI
PIN_SPI_CS = const(15)
PIN_SPI_SCK = const(17)
PIN_SPI_MOSI = const(21)

# LCD
PIN_LCD_BL = const(16)
PIN_LCD_DC = const(33)
PIN_LCD_RST = const(34)

# Grove port
PIN_GROVE_PORT = (const(2), const(1))


class ATOMS3:
    def __init__(self, rotation=0):
        self._btn = Pin(PIN_BUTTON, Pin.IN, Pin.PULL_UP)
        self._spi = SPI(
            2, baudrate=40000000, sck=Pin(PIN_SPI_SCK), mosi=Pin(PIN_SPI_MOSI), miso=None
        )
        self._lcd = st7789.ST7789(
            self._spi,
            128,
            128,
            reset=Pin(PIN_LCD_RST, Pin.OUT),
            dc=Pin(PIN_LCD_DC, Pin.OUT),
            cs=Pin(PIN_SPI_CS, Pin.OUT),
            backlight=Pin(PIN_LCD_BL, Pin.OUT),
            rotation=rotation,
            color_order=st7789.BGR,
        )

    def get_button_status(self):
        return self._btn.value()

    def set_button_callback(self, cb):
        self._btn.irq(trigger=Pin.IRQ_FALLING, handler=cb)
