/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			system_GOWIN_M3.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			CMSIS Cortex-M3 Device Peripheral Access Layer System Source File.
 *              This file contains the system clock configuration for Gowin_EMPU_M3.
 *
 *              This file provides two functions and one global variable to be called from
 *              user application:
 *                - SystemInit(): Setups the system clock.
 *                                This function is called at startup just after reset and
 *                                before branch to main program. This call is mad inside
 *                                the "startup_GOWIN_M3.s" file.
 *                - SystemCoreClock variable: Contains the core clock, it can be used
 *                                by the user application to setup the SysTick 
 *                                timer or configure other parameters.
 *                - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
 *                                be called whenever the core clock is changed
 *                                during program execution.
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup Gowin_EMPU_M3_system
  * @{
  */  
  
/** @addtogroup Gowin_EMPU_M3_System_Private_Includes
  * @{
  */

#include "GOWIN_M3.h"

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Private_Macros
  * @{
  */

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __XTAL            (40000000UL)    /* Oscillator frequency             */

#define __SYSTEM_CLOCK    (__XTAL / 2)		/*	20MHz */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Private_Variables
  * @{
  */

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __SYSTEM_CLOCK;/*!< System Clock Frequency (Core Clock)*/

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Private_Functions
  * @{
  */

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate (void)
{
  SystemCoreClock = __SYSTEM_CLOCK;
}

/**
 * @param  none
 * @return none
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
#ifdef UNALIGNED_SUPPORT_DISABLE
  SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

  SystemCoreClock = __SYSTEM_CLOCK;
}

/**
  * @}
  */

/**
  * @}
  */
  
/**
  * @}
  */

/***********************GowinSemiconductor*******END OF FILE***************/
