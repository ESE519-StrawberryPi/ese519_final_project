#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

//#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "stdio.h"

/**
 * data
 **/
#define UBYTE uint8_t
#define UWORD uint16_t
#define UDOUBLE uint32_t
#define SPI_PORT spi1
/**
 * GPIOI config
 **/
extern int EPD_RST_PIN;
extern int EPD_DC_PIN;
extern int EPD_CS_PIN;
extern int EPD_BL_PIN;
extern int EPD_CLK_PIN;
extern int EPD_MOSI_PIN;

/*------------------------------------------------------------------------------------------------------*/
void DEV_Digital_Write(UWORD Pin, UBYTE Value);
UBYTE DEV_Digital_Read(UWORD Pin);

void DEV_SPI_WriteByte(UBYTE Value);
void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len);
void DEV_Delay_ms(UDOUBLE xms);

void DEV_SET_PWM(uint8_t Value);

UBYTE DEV_Module_Init(void);
void DEV_Module_Exit(void);

#endif
