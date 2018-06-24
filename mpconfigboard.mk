MCU_SERIES = f4
CMSIS_MCU = STM32F407xx
AF_FILE = boards/stm32f405_af.csv
LD_FILES = boards/CLICKER2/stm32f407.ld boards/common_ifs.ld
TEXT0_ADDR = 0x08000000
TEXT1_ADDR = 0x08020000

# Select if default frozen modules needs to included
FROZEN_MPY_DIR ?=
