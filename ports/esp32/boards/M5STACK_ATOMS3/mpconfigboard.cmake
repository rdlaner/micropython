set(IDF_TARGET esp32s3)

set(SDKCONFIG_DEFAULTS
    ${SDKCONFIG_IDF_VERSION_SPECIFIC}
    boards/M5STACK_ATOMS3/sdkconfig.board
    boards/sdkconfig.240mhz
    boards/sdkconfig.base
    boards/sdkconfig.ble
    boards/sdkconfig.usb
    boards/sdkconfig.spiram_sx
)

set(MICROPY_FROZEN_MANIFEST ${MICROPY_BOARD_DIR}/manifest.py)