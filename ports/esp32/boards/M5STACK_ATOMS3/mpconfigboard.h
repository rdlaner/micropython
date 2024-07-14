#define MICROPY_HW_BOARD_NAME                   "M5Stack AtomS3"
#define MICROPY_HW_MCU_NAME                     "ESP32S3"
#define MICROPY_PY_NETWORK_HOSTNAME_DEFAULT     "m5stack-atom-s3"

#define MICROPY_HW_I2C0_SCL                     (39)
#define MICROPY_HW_I2C0_SDA                     (38)

#define MICROPY_HW_SPI1_MOSI                    (21)
#define MICROPY_HW_SPI1_SCK                     (17)
#define MICROPY_HW_SPI1_MISO                    (18)  // Not used, not sure if 18 even works
