/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			system_GOWIN_M3.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			CMSIS Cortex-M3 Device Peripheral Access Layer Header File for Gowin_EMPU_M3
 *
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup Gowin_EMPU_M3_system
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef SYSTEM_GOWIN_M3_H
#define SYSTEM_GOWIN_M3_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Gowin_EMPU_M3_System_Includes
  * @{
  */

#include <stdint.h>

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;    /*!< Processor Clock Frequency */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup Gowin_EMPU_M3_System_Exported_Functions
  * @{
  */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_GOWIN_M3_H */

/**
  * @}
  */
  
/**
  * @}
  */

/**********************GowinSemiconductor**********END OF FILE*****************/
