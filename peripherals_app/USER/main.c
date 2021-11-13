/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			main.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			Main body.
 ******************************************************************************************
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app_if.h"
#include "string.h"
#include "cmd_line.h"

int main(void)
{
	SystemInit();	//Initialize system
	UartInit(115200);		//Init UART0
	start_cmd_line();
	return 0;
}
