/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			app.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			Header file of applications.
 ******************************************************************************************
 */
 
#ifndef APP_H
#define APP_H

/* Includes ------------------------------------------------------------------*/
#include "app_config.h"
#include "GOWIN_M3.h"
#include <stdio.h>

//ahb2 extension
#ifdef AHB2_EXT_APP

//type definition
typedef struct
{
  __IO   uint32_t  MULTIPLIER;        /* Offset: 0x000 (R/W) [7:0] */
  __IO   uint32_t  MULTIPLICAND;      /* Offset: 0x004 (R/W) [7:0] */
  __IO   uint32_t  CMD;               /* Offset: 0x008 (R/W) [1:0] */
  __I    uint32_t  RESULT;            /* Offset: 0x00C (R/ ) [15:0] */
}MULTIPLE_TypeDef;

//base address
#define MULTIPLE_BASE   (AHB2PERIPH_BASE + 0x0000)

//mapping
#define MULTIPLE        ((MULTIPLE_TypeDef   *) MULTIPLE_BASE)

//bit definition
#define MUL_MULTIPLIER		((uint32_t) 0x000000FF)
#define MUL_MULTIPLICAND	((uint32_t) 0x000000FF)
#define CMD_START					((uint32_t) 0x00000001)
#define STATUS_FINISHED		((uint32_t) 0x00000010)
#define MUL_RESULT				((uint32_t) 0x0000FFFF)

typedef enum
{
	FINISHED_STATUS = 0x0,
	NO_FINISHED_STATUS = 0x1
}STATUS;

extern void ahb2_ext_app(void);

#endif

//apb2 extension
#ifdef APB2_EXT_APP

//type definition
typedef struct
{
  __IO   uint32_t  MULTIPLIER;        /* Offset: 0x000 (R/W) [7:0] */
  __IO   uint32_t  MULTIPLICAND;      /* Offset: 0x004 (R/W) [7:0] */
  __IO   uint32_t  CMD;               /* Offset: 0x008 (R/W) [1:0] */
  __I    uint32_t  RESULT;            /* Offset: 0x00C (R/ ) [15:0] */
}MULTIPLE_TypeDef;

//base address
#define MULTIPLE_BASE   (APB2PERIPH_BASE + 0x0000)

//mapping
#define MULTIPLE        ((MULTIPLE_TypeDef   *) MULTIPLE_BASE)

//bit definition
#define MUL_MULTIPLIER		((uint32_t) 0x000000FF)
#define MUL_MULTIPLICAND	((uint32_t) 0x000000FF)
#define CMD_START					((uint32_t) 0x00000001)
#define STATUS_FINISHED		((uint32_t) 0x00000010)
#define MUL_RESULT				((uint32_t) 0x0000FFFF)

typedef enum
{
	FINISHED_STATUS = 0x0,
	NO_FINISHED_STATUS = 0x1
}STATUS;

extern void apb2_ext_app(void);

#endif

//ddr3
#ifdef DDR3_APP
extern void ddr3_app(void);
#endif

//ethernet
#ifdef ETHERNET_APP
extern void ethernet_app(void);
#endif

//i2c
#ifdef I2C_APP
extern void i2c_app(void);
#endif

//keyscan
#ifdef KEYSCAN_APP
extern void keyscan_app(void);
#endif

//led
#ifdef LED_APP
extern void led_app(void);
#endif

//spi
#ifdef SPI_APP
extern void spi_app(void);
#endif

//spi-flash
#ifdef SPI_FLASH_APP
extern void spi_flash_app(void);
#endif

//systick
#ifdef SYSTICK_APP
extern void systick_app(void);
#endif

//timer
#ifdef TIMER_APP
extern void timer_app(void);
#endif

//watchdog
#ifdef WATCHDOG_APP
extern void watchdog_app(void);
#endif

//uart0_irq
#ifdef UART0_IRQ_APP
extern void uart0_irq_app(void);
void GPIOInit(void);
#endif

//rtc
#ifdef RTC_APP
extern void rtc_app(void);
#endif

//interrupt priority
#ifdef NVIC_APP
extern void nvic_app(void);
#endif

#endif
