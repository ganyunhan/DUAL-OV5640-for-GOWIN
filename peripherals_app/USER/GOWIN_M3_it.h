/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			GOWIN_M3_it.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			This file contains the headers of the interrupt handlers.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GOWIN_M3_IT_H
#define GOWIN_M3_IT_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "GOWIN_M3.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* Core Exceptions Handler */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
//void SysTick_Handler(void);

/* StdPeriph Interrupts Handler */
//void UART0_Handler(void);
void UART1_Handler(void);
//void TIMER0_Handler(void);
void TIMER1_Handler(void);
void GPIO0_Handler(void);
//void RTC_Handler(void);
//void I2C_Handler(void);
//void ENT_Handler(void);
void GPIO0_0_Handler(void);
void GPIO0_1_Handler(void);
void GPIO0_2_Handler(void);
void GPIO0_3_Handler(void);
void GPIO0_4_Handler(void);
void GPIO0_5_Handler(void);
void GPIO0_6_Handler(void);
void GPIO0_7_Handler(void);
void GPIO0_8_Handler(void);
void GPIO0_9_Handler(void);
void GPIO0_10_Handler(void);
void GPIO0_11_Handler(void);
void GPIO0_12_Handler(void);
void GPIO0_13_Handler(void);
void GPIO0_14_Handler(void);
void GPIO0_15_Handler(void);

//Extended user interrupts handler
void USER_INT0_Handler(void);
void USER_INT1_Handler(void);
void USER_INT2_Handler(void);
void USER_INT3_Handler(void);
void USER_INT4_Handler(void);
void USER_INT5_Handler(void);
void USER_INT6_Handler(void);
void USER_INT7_Handler(void);
void USER_INT8_Handler(void);
void USER_INT9_Handler(void);
void USER_INT10_Handler(void);
void USER_INT11_Handler(void);
void USER_INT12_Handler(void);
void USER_INT13_Handler(void);
void USER_INT14_Handler(void);
void USER_INT15_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* GOWIN_M3_IT_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
