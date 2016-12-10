/*
  mpconfigboard.h

  for the CLICKER2 board

*/
#define MICROPY_HW_BOARD_NAME       "CLICKER2"
#define MICROPY_HW_MCU_NAME         "STM32F407VGT6"

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (0)
#define MICROPY_HW_HAS_MMA7660      (0)
#define MICROPY_HW_HAS_LIS3DSH      (0)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_CAN       (1)

//#define HSE_VALUE    				((uint32_t)25000000)
// HSE is 25MHz
#define MICROPY_HW_CLK_PLLM 		(25)
#define MICROPY_HW_CLK_PLLN 		(336)
#define MICROPY_HW_CLK_PLLP 		(RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ 		(7)
//#define MICROPY_HW_CLK_LAST_FREQ (1)				// -> what does it mean?

// The pyboard has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// CAN busses
#define MICROPY_HW_CAN1_NAME "CAN1" // CAN1 on RX,TX = Y3,Y4 = PB8,PB9
#define MICROPY_HW_CAN2_NAME "CAN2" // CAN2 on RX,TX = Y5,Y6 = PB12,PB13

// some very low level init code goes in separate file
#define MICROPY_BOARD_EARLY_INIT    CLICKER2_board_early_init
void CLICKER2_board_early_init(void);

// REPL on second port
//#define MICROPY_HW_UART_REPL 		(1)				// port accessible through tag connect port
//#define MICROPY_HW_UART_REPL_BAUD	(115200)		// fast enough

// not used now
//#define MICROPY_HW_UART1_TX     (pin_B6)
//#define MICROPY_HW_UART1_RX     (pin_B7)

// on MB1, no handshake used
#define MICROPY_HW_UART2_TX     (pin_D5)
#define MICROPY_HW_UART2_RX     (pin_D6)
//#define MICROPY_HW_UART2_RTS    (pin_A1)
//#define MICROPY_HW_UART2_CTS    (pin_A0)

// on MB2, no handshake support
#define MICROPY_HW_UART3_TX     (pin_D8)
#define MICROPY_HW_UART3_RX     (pin_D9)
//#define MICROPY_HW_UART3_RTS    (pin_B14)
//#define MICROPY_HW_UART3_CTS    (pin_B13)

// on HDR2
#define MICROPY_HW_UART4_TX     (pin_A0)
#define MICROPY_HW_UART4_RX     (pin_A1)

#define MICROPY_HW_UART6_TX     (pin_C6)
#define MICROPY_HW_UART6_RX     (pin_C7)

// I2C busses
//#define MICROPY_HW_I2C1_SCL (pin_B6)
//#define MICROPY_HW_I2C1_SDA (pin_B7)

#define MICROPY_HW_I2C2_SCL (pin_B10)	// on MB2
#define MICROPY_HW_I2C2_SDA (pin_B11)

#define MICROPY_HW_I2C3_SCL (pin_A8)	// on MB1
#define MICROPY_HW_I2C3_SDA (pin_C9)

// SPI busses
//#define MICROPY_HW_SPI1_NSS  (pin_A4)
//#define MICROPY_HW_SPI1_SCK  (pin_A5)
//#define MICROPY_HW_SPI1_MISO (pin_A6)
//#define MICROPY_HW_SPI1_MOSI (pin_A7)

#define MICROPY_HW_SPI2_SCK  (pin_B13)	// on MB 2
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)
#define MICROPY_HW_SPI2_NSS  (pin_E11)

#define MICROPY_HW_SPI3_SCK  (pin_C10)	// on MB 1
#define MICROPY_HW_SPI3_MISO (pin_C11)
#define MICROPY_HW_SPI3_MOSI (pin_C12)
#define MICROPY_HW_SPI3_NSS  (pin_E8)


// T2-PE0 - USRSW is pulled high. Pressing the button makes the input go low.
//
#define MICROPY_HW_USRSW_PIN        (pin_E0)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// T3-PA10 - Second Switch, normally pulled high, Pressing button makes the input low.
// -- not implemented yet
#define MICROPY_HW_USRSW2_PIN        (pin_A10)

// LEDs
//
#define MICROPY_HW_LED1             (pin_E12) // LED 1 (red)
#define MICROPY_HW_LED2             (pin_E15) // LED 2
//#define MICROPY_HW_LED3             (pin_E15)
//#define MICROPY_HW_LED4             (pin_E15)

// CHECK IF THESE PINS CAN BE USED FOR PWM
#define MICROPY_HW_LED1_PWM         { TIM2, 2, TIM_CHANNEL_1, GPIO_AF1_TIM2 }
#define MICROPY_HW_LED2_PWM         { TIM3, 3, TIM_CHANNEL_1, GPIO_AF2_TIM3 }

#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// SD card detect switch
//
#if MICROPY_HW_HAS_SDCARD
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_A8)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (1)
#endif

// USE EXTRA 64K IN FLASH
#define MICROPY_HW_FLASH_EXTRA	(1)	// use the extra 64K in stmhal/storage.c when defined
// SET LABEL OF DRIVE TO BOARD NAME
#define MICROPY_HW_FLASH_LABEL	(1)	// set the label of the drive in stmhal/main.c when defined

// USB config
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
//#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

// NOT USED
//
// networking
#define MICROPY_PY_NETWORK			(0)		// added NETWORK ENABLING
#define MICROPY_PY_USOCKET			(0)		// added SOCKET NEEDS NETWORK OTHERWISE LINK ERROR

// MMA accelerometer config
//#define MICROPY_HW_MMA_AVDD_PIN     (pin_B5)
