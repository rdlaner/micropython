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

from micropython import const
from machine import Pin

# Button
PIN_BUTTON = const(41)

# IR
PIN_IR = const(4)

# I2C
PIN_I2C0_SCL = const(39)
PIN_I2C0_SDA = const(38)

# LCD SPI
PIN_SPI_CS = const(15)
PIN_SPI_SCK = const(17)
PIN_SPI_MOSI = const(21)

# LCD
PIN_LCD_BL = const(16)
PIN_LCD_RS = const(33)
PIN_LCD_RST = const(34)

# Grove port
PIN_GROVE_PORT = (const(2), const(1))


class ATOMS3:
    def __init__(self):
        self._btn = Pin(PIN_BUTTON, Pin.IN, Pin.PULL_UP)

    def get_button_status(self):
        return self._btn.value()

    def set_button_callback(self, cb):
        self._btn.irq(trigger=Pin.IRQ_FALLING, handler=cb)
