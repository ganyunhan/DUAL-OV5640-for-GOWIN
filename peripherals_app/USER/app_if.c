/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			app_if.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			Application call interface.
 ******************************************************************************************
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app.h"
#include "app_if.h"

void UartInit(uint32_t baudrate)
{
	UART_InitTypeDef UART_InitStruct;

	UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
	UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
	UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;//TX Interrupt
	UART_InitStruct.UART_Int.UARTInt_Rx = ENABLE;//RX Interrupt
	UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
	UART_InitStruct.UART_Hstm = DISABLE;
	UART_InitStruct.UART_BaudRate = baudrate;//Baud Rate

	UART_Init(UART0,&UART_InitStruct);
}

void app_call_if(void)
{
	//ahb2 extension
#ifdef AHB2_EXT_APP
	printf("\r\n****** AHB2 Extension Application ******\r\n");
	ahb2_ext_app();
#endif

	//apb2 extension
#ifdef APB2_EXT_APP
	printf("\r\n****** APB2 Extension Application ******\r\n");
	apb2_ext_app();
#endif

	//ddr3
#ifdef DDR3_APP
	printf("\r\n****** DDR3 Application ******\r\n");
	ddr3_app();
#endif

	//ethernet
#ifdef ETHERNET_APP
	printf("\r\n****** Ethernet Application ******\r\n");
	ethernet_app();
#endif

	//i2c
#ifdef I2C_APP
	printf("\r\n****** I2C Application ******\r\n");
	i2c_app();
#endif

	//keyscan
#ifdef KEYSCAN_APP
	printf("\r\n****** Keyscan Application ******\r\n");
	keyscan_app();
#endif

	//led
#ifdef LED_APP
	printf("\r\n****** LED Application ******\r\n");
	led_app();
#endif

	//spi
#ifdef SPI_APP
	printf("\r\n****** SPI Application ******\r\n");
	spi_app();
#endif

	//spi-flash
#ifdef SPI_FLASH_APP
	printf("\r\n****** SPI-Flash Memory Application ******\r\n");
	spi_flash_app();
#endif

	//systick
#ifdef SYSTICK_APP
	printf("\r\n****** Systick Application ******\r\n");
	systick_app();
#endif

	//timer
#ifdef TIMER_APP
	printf("\r\n****** Timer0 Application ******\r\n");
	timer_app();
#endif

	//watchdog
#ifdef WATCHDOG_APP
	printf("\r\n****** WatchDog Application ******\r\n");
	watchdog_app();
#endif

	//uart0_irq
#ifdef UART0_IRQ_APP
	printf("\r\n****** UART0 Interrupt Application ******\r\n");
	uart0_irq_app();
#endif

	//rtc
#ifdef RTC_APP
	printf("\r\n****** RTC Application ******\r\n");
	rtc_app();
#endif

  //interrupt priority
#ifdef NVIC_APP
  printf("\r\n****** NVIC Application ******\r\n");
	nvic_app();
#endif
}
