Program your board using the `esptool.py` program, found
[here](https://github.com/espressif/esptool).

To place the board in _bootloader mode_ - so `esptool`` can be used - press and
hold the reset button for two seconds. A green LED will flash behind the reset
button when the bootloader mode has been activated.

If you are putting MicroPython on your board for the first time then you should
first erase the entire flash using:

```bash
make BOARD=M5Stack_AtomS3 PORT=/dev/cu.usbmodem2101 erase
```

From then on program the firmware starting at address 0:

```bash
make BOARD=M5Stack_AtomS3 PORT=/dev/cu.usbmodem2101 deploy
```

After the firmware has been deployed, press the reset button to reset the device
and start the new firmware.