#include "DEV_Config.h"
#include <hardware/gpio.h>

/**
 * GPIO
 **/
int EPD_RST_PIN = 7;
int EPD_DC_PIN = 9;
int EPD_CS_PIN = 13;
int EPD_CLK_PIN = 10;
int EPD_MOSI_PIN = 11;
uint slice_num;
/**
 * GPIO read and write
 **/
void DEV_Digital_Write(UWORD Pin, UBYTE Value) { gpio_put(Pin, Value); }

UBYTE DEV_Digital_Read(UWORD Pin) { return gpio_get(Pin); }

/**
 * SPI
 **/
void DEV_SPI_WriteByte(uint8_t Value) {
  spi_write_blocking(SPI_PORT, &Value, 1);
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len) {
  spi_write_blocking(SPI_PORT, pData, Len);
}

/**
 * GPIO Mode
 **/
void DEV_GPIO_Mode(UWORD Pin, UWORD Mode) {
  gpio_init(Pin);
  if (Mode == 0 || Mode == GPIO_IN) {
    gpio_set_dir(Pin, GPIO_IN);
  } else {
    gpio_set_dir(Pin, GPIO_OUT);
  }
}

/**
 * delay x ms
 **/
void DEV_Delay_ms(UDOUBLE xms) { sleep_ms(xms); }
void DEV_GPIO_Init(void) {
  DEV_GPIO_Mode(EPD_RST_PIN, 1);
  DEV_GPIO_Mode(EPD_DC_PIN, 1);
  DEV_GPIO_Mode(EPD_CS_PIN, 1);
  DEV_Digital_Write(EPD_CS_PIN, 1);
}

/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI
protocol parameter: Info:
******************************************************************************/
UBYTE DEV_Module_Init(void) {
  spi_init(SPI_PORT, 12000 * 1000);
  gpio_set_function(EPD_CLK_PIN, GPIO_FUNC_SPI);
  gpio_set_function(EPD_MOSI_PIN, GPIO_FUNC_SPI);
  // GPIO Config
  DEV_GPIO_Init();
  printf("DEV_Module_Init OK \r\n");
  return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_Module_Exit(void) {}
