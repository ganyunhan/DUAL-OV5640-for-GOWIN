/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      GOWIN_M3_conf.h
 * @author    Embedded Development Team
 * @version   V1.0.1
 * @date      2021-07-01 09:00:00
 * @brief     Library configuration file.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion--------------------------------------*/
#ifndef GOWIN_M3_CONF_H
#define GOWIN_M3_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable peripheral header file inclusion */
#include "GOWIN_M3_uart.h"			  //UART
#include "GOWIN_M3_wdog.h"			  //WatchDog
#include "GOWIN_M3_timer.h"			  //Timer
#include "GOWIN_M3_rtc.h"			    //RTC
#include "GOWIN_M3_i2c.h"			    //I2C
#include "GOWIN_M3_spi.h"			    //SPI
#include "GOWIN_M3_ethernet.h"		//Ethernet
#include "GOWIN_M3_gpio.h"			  //GPIO
#include "GOWIN_M3_ddr3.h"			  //DDR3
#include "GOWIN_M3_spi_flash.h"		//SPI-Flash
#include "GOWIN_M3_misc.h"			  //NVIC

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1 */

/* Exported macro ------------------------------------------------------------*/

//#define USE_FULL_ASSERT
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* GOWIN_M3_CONF_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
