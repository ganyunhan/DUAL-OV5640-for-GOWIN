/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			GOWIN_M3.h
 * @author		Embedded Development Team
 * @version		V1.0.1
 * @date		  2021-06-22 09:00:00
 * @brief		  CMSIS Cortex-M3 Core Peripheral Access Layer Header File for Gowin_EMPU_M3.
 *				    This file contains all the peripheral register's definitions, bits 
 *				    definitions and memory mapping for Gowin_EMPU_M3 Connectivity line, 
 *				    High density, High density value line, Medium density, 
 *				    Medium density Value line, Low density, Low density Value line 
 *				    and XL-density devices.
 *
 *				    The file is the unique include file that the application programmer
 *				    is using in the C source code, usually in main.c. This file contains:
 *					   - Configuration section that allows to select:
 *						  - The device used in the target application
 *						  - To use or not the peripheral drivers in application code(i.e. 
 *						    code will be based on direct access to peripheral registers 
 *						    rather than drivers API)
 *						  - To change few application-specific parameters such as 
 *						    crystal frequency
 *						  - Data structures and the address mapping for all peripherals
 *						  - Peripheral's registers declarations and bits definition
 *						  - Macros to access peripheral registers hardware
 *
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup Gowin_EMPU_M3
  * @{
  */

#ifndef GOWIN_M3_H
#define GOWIN_M3_H

#ifdef __cplusplus
	extern "C" {
#endif

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/* 
 * Configuration of the Cortex-M3 Processor and Core Peripherals
 */
#define __CM3_REV                 0x0201    /*!< Core Revision r2p1                             */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels        */
		                                        /*!< __NVIC_PRIO_BITS must be set with IPCore       */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used   */
#define __MPU_PRESENT             1         /*!< MPU present or not                             */
																					  /*!< __MPU_PRESENT must be set with IPCore          */

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ********************************/
  NonMaskableInt_IRQn           = -14,    /*!<  2 Cortex-M3 Non Maskable Interrupt                 */
  HardFault_IRQn                = -13,    /*!<  3 Cortex-M3 Hard Fault Interrupt                   */
  MemoryManagement_IRQn         = -12,    /*!<  4 Cortex-M3 Memory Management Interrupt            */
  BusFault_IRQn                 = -11,    /*!<  5 Cortex-M3 Bus Fault Interrupt                    */
  UsageFault_IRQn               = -10,    /*!<  6 Cortex-M3 Usage Fault Interrupt                  */
  SVCall_IRQn                   = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                      */
  DebugMonitor_IRQn             = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                */
  PendSV_IRQn                   = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                      */
  SysTick_IRQn                  = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                  */

/******  Gowin_EMPU_M3 Specific Interrupt Numbers ************************************/
  UART0_IRQn                    =   0,     /*!< 0 UART0 Interrupt                                  */
  UART1_IRQn                    =   1,     /*!< 1 UART1 Interrupt                                  */
  TIMER0_IRQn                   =   2,     /*!< 2 TIMER0 Interrupt                                 */
  TIMER1_IRQn                   =   3,     /*!< 3 TIMER1 Interrupt                                 */
  GPIO0_IRQn                    =   4,     /*!< 4 GPIO0 Interrupt                                  */
  UARTOVF_IRQn                  =   5,     /*!< 5 UART0,1 Overflow Interrupt                       */
  RTC_IRQn                      =   6,     /*!< 6 RTC Interrupt                                    */
  I2C_IRQn                      =   7,     /*!< 7 I2C Interrupt                                    */
  Interrupt8_IRQn               =   8,     /*!< 8 Reserved                                         */
  ENT_IRQn                      =   9,     /*!< 9 Ethernet Interrupt                               */
  Interrupt10_IRQn              =   10,    /*!< 10 Reserved                                        */
  Interrupt11_IRQn              =   11,    /*!< 11 Reserved                                        */
  Interrupt12_IRQn              =   12,    /*!< 12 Reserved                                        */
  Interrupt13_IRQn              =   13,    /*!< 13 Reserved                                        */
  Interrupt14_IRQn              =   14,    /*!< 14 Reserved                                        */
  Interrupt15_IRQn              =   15,    /*!< 15 Reserved                                        */
  GPIO0_0_IRQn                  =   16,    /*!< 16 GPIO0_0 Interrupt                               */
  GPIO0_1_IRQn                  =   17,    /*!< 17 GPIO0_1 Interrupt                               */
  GPIO0_2_IRQn                  =   18,    /*!< 18 GPIO0_2 Interrupt                               */
  GPIO0_3_IRQn                  =   19,    /*!< 19 GPIO0_3 Interrupt                               */
  GPIO0_4_IRQn                  =   20,    /*!< 20 GPIO0_4 Interrupt                               */
  GPIO0_5_IRQn                  =   21,    /*!< 21 GPIO0_5 Interrupt                               */
  GPIO0_6_IRQn                  =   22,    /*!< 22 GPIO0_6 Interrupt                               */
  GPIO0_7_IRQn                  =   23,    /*!< 23 GPIO0_7 Interrupt                               */
  GPIO0_8_IRQn                  =   24,    /*!< 24 GPIO0_8 Interrupt                               */
  GPIO0_9_IRQn                  =   25,    /*!< 25 GPIO0_9 Interrupt                               */
  GPIO0_10_IRQn                 =   26,    /*!< 26 GPIO0_10 Interrupt                              */
  GPIO0_11_IRQn                 =   27,    /*!< 27 GPIO0_11 Interrupt                              */
  GPIO0_12_IRQn                 =   28,    /*!< 28 GPIO0_12 Interrupt                              */
  GPIO0_13_IRQn                 =   29,    /*!< 29 GPIO0_13 Interrupt                              */
  GPIO0_14_IRQn                 =   30,    /*!< 30 GPIO0_14 Interrupt                              */
  GPIO0_15_IRQn                 =   31,    /*!< 31 GPIO0_15 Interrupt                              */
	USER_INT0_IRQn                =   32,    /*!< 32 Extended User Interrupt                         */
	USER_INT1_IRQn                =   33,    /*!< 33 Extended User Interrupt                         */
	USER_INT2_IRQn                =   34,    /*!< 34 Extended User Interrupt                         */
	USER_INT3_IRQn                =   35,    /*!< 35 Extended User Interrupt                         */
	USER_INT4_IRQn                =   36,    /*!< 36 Extended User Interrupt                         */
	USER_INT5_IRQn                =   37,    /*!< 37 Extended User Interrupt                         */
	USER_INT6_IRQn                =   38,    /*!< 38 Extended User Interrupt                         */
	USER_INT7_IRQn                =   39,    /*!< 39 Extended User Interrupt                         */
	USER_INT8_IRQn                =   40,    /*!< 40 Extended User Interrupt                         */
	USER_INT9_IRQn                =   41,    /*!< 41 Extended User Interrupt                         */
	USER_INT10_IRQn               =   42,    /*!< 42 Extended User Interrupt                         */
	USER_INT11_IRQn               =   43,    /*!< 43 Extended User Interrupt                         */
	USER_INT12_IRQn               =   44,    /*!< 44 Extended User Interrupt                         */
	USER_INT13_IRQn               =   45,    /*!< 45 Extended User Interrupt                         */
	USER_INT14_IRQn               =   46,    /*!< 46 Extended User Interrupt                         */
	USER_INT15_IRQn               =   47     /*!< 47 Extended User Interrupt                         */
}IRQn_Type;

/**
  * @}
  */

#include "core_cm3.h"               /* Cortex-M3 processor and core peripherals         */
#include "system_GOWIN_M3.h"        /* Gowin_EMPU_M3 System include file                */

/** @addtogroup Exported_types
  * @{
  */

typedef enum
{
  RESET = 0,
  SET = !RESET
}FlagStatus,ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
}FunctionalState;

typedef enum
{
  ERROR = 0,
  SUCCESS = !ERROR
}ErrorStatus;

/**
  * @}
  */

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/* --------------------  Begin of section using anonymous unions  ------------------- */
#if defined ( __CC_ARM   )
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/******************************************************************************/
/*                         Peripheral Registers Definition                    */
/******************************************************************************/

/*--------- Universal Asynchronous Receiver Transmitter (UART) --------*/
typedef struct
{
  __IO   uint32_t  DATA;          /*!< Offset: 0x000 Data Register    (R/W)          */
  __IO   uint32_t  STATE;         /*!< Offset: 0x004 Status Register  (R/W)          */
  __IO   uint32_t  CTRL;          /*!< Offset: 0x008 Control Register (R/W)          */
  union
  {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W)  */
  };
  __IO   uint32_t  BAUDDIV;       /*!< Offset: 0x010 Baudrate Divider Register (R/W) */
}UART_TypeDef;

/*------------------------ Timer (TIMER) ------------------------*/
typedef struct
{
  __IO   uint32_t  CTRL;          /*!< Offset: 0x000 Control Register (R/W)          */
  __IO   uint32_t  VALUE;         /*!< Offset: 0x004 Current Value Register (R/W)    */
  __IO   uint32_t  RELOAD;        /*!< Offset: 0x008 Reload Value Register  (R/W)    */
  union
  {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W)  */
  };
}TIMER_TypeDef;

/*--------------------- General Purpose Input Output (GPIO) ----------*/
typedef struct
{
  __IO   uint32_t  DATA;          /* Offset: 0x000 (R/W) DATA Register                     */
  __IO   uint32_t  DATAOUT;       /* Offset: 0x004 (R/W) Data Output Latch Register        */
         uint32_t  RESERVED0[2];  /* Offset: 0x010-0x004                                   */
  __IO   uint32_t  OUTENSET;      /* Offset: 0x010 (R/W) Output Enable Set Register        */
  __IO   uint32_t  OUTENCLR;      /* Offset: 0x014 (R/W) Output Enable Clear Register      */
  __IO   uint32_t  ALTFUNCSET;    /* Offset: 0x018 (R/W) Alternate Function Set Register   */
  __IO   uint32_t  ALTFUNCCLR;    /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IO   uint32_t  INTENSET;      /* Offset: 0x020 (R/W) Interrupt Enable Set Register     */
  __IO   uint32_t  INTENCLR;      /* Offset: 0x024 (R/W) Interrupt Enable Clear Register   */
  __IO   uint32_t  INTTYPESET;    /* Offset: 0x028 (R/W) Interrupt Type Set Register       */
  __IO   uint32_t  INTTYPECLR;    /* Offset: 0x02C (R/W) Interrupt Type Clear Register     */
  __IO   uint32_t  INTPOLSET;     /* Offset: 0x030 (R/W) Interrupt Polarity Set Register   */
  __IO   uint32_t  INTPOLCLR;     /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union
  {
    __I    uint32_t  INTSTATUS;      /* Offset: 0x038 (R/ ) Interrupt Status Register                 */
    __O    uint32_t  INTCLEAR;       /* Offset: 0x038 ( /W) Interrupt Clear Register                  */
  };
         uint32_t RESERVED1[241];    /* Offset : 0x400-0x0038                                         */
  __IO   uint32_t MASKLOWBYTE[256];  /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IO   uint32_t MASKHIGHBYTE[256]; /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
}GPIO_TypeDef;

/*----------------------------- WatchDog ------------------------*/
typedef struct
{
  __IO    uint32_t  LOAD;           /* Offset: 0x000 (R/W) Watchdog Load Register                         */
  __I     uint32_t  VALUE;          /* Offset: 0x004 (R/ ) Watchdog Value Register                        */
  __IO    uint32_t  CTRL;           /* Offset: 0x008 (R/W) Watchdog Control Register                      */
  __O     uint32_t  INTCLR;         /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register              */
  __I     uint32_t  RIS;            /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register         */
  __I     uint32_t  MIS;            /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register             */
          uint32_t  RESERVED0[762]; /* Offset: 0xC00-0x014                                                */
  __IO    uint32_t  LOCK;           /* Offset: 0xC00 (R/W) Watchdog Lock Register                         */
          uint32_t  RESERVED1[191]; /* Offset: 0xF00-0xC00                                                */
  __IO    uint32_t  ITCR;           /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register     */
  __O     uint32_t  ITOP;           /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register  */
}WDOG_TypeDef;

/*----------------------------- I2C --------------------------*/
typedef struct {
	__IO uint32_t PRER;          /* Offset: 0x00 (R/W) I2C Prescale Register                              */
	__IO uint32_t CTR;           /* Offset: 0x04 (R/W) I2C Control Register                               */
	union
	{
		__I uint32_t RXR;          /* Offset: 0x0C (R/ ) I2C Data Receive Register                          */
		__O uint32_t TXR;          /* Offset: 0x08 ( /W) I2C Data Transmit Register                         */
	};
	union
	{
		__I uint32_t SR;           /* Offset: 0x14 (R/ ) I2C Status Register                                */
		__O uint32_t CR;           /* Offset: 0x10 ( /W) I2C Command Register                               */
	};
}I2C_TypeDef;

/*----------------------------- Ethernet Mac--------------------------*/
typedef struct {
	union
	{
		__O  uint32_t ETH_TX_DATA[384];       /* 0x000~0x5ff transmit data registers          */
		__I  uint32_t ETH_RX_DATA[384];       /* 0x000~0x5ff receive data registers           */
	};
	__IO uint32_t ETH_TX_LENGTH;            /* 0x600 transmit data length, bit[10:0]        */
	__IO uint32_t ETH_TX_EN;                /* 0x604 transmit enable, bit[0]                */
	__IO uint32_t ETH_TX_FAIL;              /* 0x608 transmit fail, bit[2,1,0]              */
	__I  uint32_t ETH_TX_IS;                /* 0x60c transmit interrupt status, bit[0]      */
	__O  uint32_t ETH_TX_IC;                /* 0x610 transmit interrupt clear, bit[0]       */
	__IO uint32_t ETH_TX_IE;                /* 0x614 transmit interrupt enable, bit[0]      */
	     uint32_t RESERVED_1[26];           /* 0x618~0x67f reserved                         */
	__I  uint32_t ETH_RX_LENGTH;            /* 0x680 receive data length                    */
	__I  uint32_t ETH_RX_IS;                /* 0x684 receive interrupt status, bit[0]       */
	__IO uint32_t ETH_RX_IE;                /* 0x688 receive interrupt enable, bit[0]       */
	__O  uint32_t ETH_RX_IC;                /* 0x68c receive interrupt clear, bit[0]        */
	     uint32_t RESERVED_2[28];           /* 0x690~0x6ff reserved                         */
	__IO uint32_t MIIM_OP_MODE;             /* 0x700 miim operation mode, bit[0]            */
	__IO uint32_t MIIM_PHY_ADDR;            /* 0x704 miim phy address, bit[4:0]             */
	__IO uint32_t MIIM_REG_ADDR;            /* 0x708 miim reg address, bit[4:0]             */
	__IO uint32_t MIIM_WR_DATA;             /* 0x70c miim write data, bit[15:0]             */
	__I  uint32_t MIIM_RD_DATA;             /* 0x710 miim read data, bit[15:0]              */
	__I  uint32_t MIIM_IS;                  /* 0x714 miim interrupt status, bit[1,0]        */
	__IO uint32_t MIIM_IE;                  /* 0x718 miim interrupt enable, bit[1,0]        */
	__O  uint32_t MIIM_IC;                  /* 0x71c miim interrupt clear, bit[1,0]         */
	__IO uint32_t MIIM_OP_EN;               /* 0x720 miim operation enable, bit[0]          */
	__IO uint32_t ETH_MODE;                 /* 0x724 ethernet operation mode, bit[2,1,0]    */
}ETH_RegDef;

/*----------------Serial Peripheral Interface (SPI)-----------------*/
typedef struct
{
  __I     uint32_t RDATA;        /* Offset: 0x00 (R/ ) Data Read Register          */
  __O     uint32_t WDATA;        /* Offset: 0x04 (/W ) Data Write Register         */
  __IO    uint32_t STATUS;       /* Offset: 0x08 (R/W) Status Register             */
  __IO    uint32_t SSMASK;       /* Offset: 0x0C (R/W) Unused Select slave address */
  __IO    uint32_t CTRL;         /* Offset: 0x10 (R/W) Control Register            */
}SPI_TypeDef;

/*--------------------------RTC----------------------------*/
typedef struct
{
	__I  uint32_t RTC_CURRENT_DATA;       /* Offset: 0x000 (R/ ) Data Register                          */
	__IO uint32_t RTC_MATCH_VALUE;        /* Offset: 0x004 (R/W) Match Register                         */
	__IO uint32_t RTC_LOAD_VALUE;         /* Offset: 0x008 (R/W) Load Register                          */
	__IO uint32_t RTC_CTROLLER_REG;       /* Offset: 0x00C (R/W) Control Register                       */
	__IO uint32_t RTC_IMSC;               /* Offset: 0x010 (R/W) Interrupt Mask Set and Clear Register  */
	__I  uint32_t RTC_RIS;                /* Offset: 0x014 (R/ ) Raw Interrupt Status Register          */
	__I  uint32_t RTC_MIS;                /* Offset: 0x018 (R/ ) Masked Interrupt Status Register       */
	__O  uint32_t RTC_INTR_CLEAR;         /* Offset: 0x01C ( /W) Interrupt Clear Register               */
}RTC_RegDef;

/*--------------------------DDR3 Memory-----------------------------*/
typedef struct {
	__IO unsigned int RESERVED;    /* Offset: 0x0000 (R/W) Reserved                               */
	__IO unsigned int WR_ADDR;     /* Offset: 0x0004 (R/W) Write Address Register                 */
	__O  unsigned int WR_DATA[4];  /* Offset: 0x0008~0x0014 ( /W) Write Data Register             */
	__IO unsigned int RD_ADDR;     /* Offset: 0x0018 (R/W) Read Address Register                  */
	__IO unsigned int RD_EN;       /* Offset: 0x001c (R/W) Read Enable Register                   */
	__I  unsigned int RD_DATA[4];  /* Offset: 0x0020~0x002c (R/ ) Read Data Register              */
	__IO unsigned int INIT;        /* Offset: 0x0030 (R/W) Init Done Flag Register                */
	__IO unsigned int WR_EN;       /* Offset: 0x0034 (R/W) Write Enable and End flag Register     */
}DDR3_RegDef;

/*--------------------------SPI-Flash Memory-----------------------------*/
typedef struct 
{
	__I  unsigned int IDREV;                /* Offset: 0x00 (R/ ) ID and revision Register           */
	     unsigned int RESERVED0[3];         /* Offset: 0x04~0x0c Reserved                            */
	__IO unsigned int TRANSFMT;             /* Offset: 0x10 (R/W) SPI transfer format Register       */
	__IO unsigned int DIRECTIO;             /* Offset: 0x14 (R/W) SPI direct IO control Register     */
	     unsigned int RESERVED1[2];         /* Offset: 0x18~0x1c Reserved                            */
	__IO unsigned int TRANSCTRL;            /* Offset: 0x20 (R/W) SPI transfer control Register      */
	__IO unsigned int CMD;                  /* Offset: 0x24 (R/W) SPI command Register               */
	__IO unsigned int ADDR;                 /* Offset: 0x28 (R/W) SPI address Register               */
	__IO unsigned int DATA;                 /* Offset: 0x2c (R/W) SPI data Register                  */
	__IO unsigned int CTRL;                 /* Offset: 0x30 (R/W) SPI control Register               */
	__I  unsigned int STATUS;               /* Offset: 0x34 (R/ ) SPI status Register                */
	__IO unsigned int INTREN;               /* Offset: 0x38 (R/W) SPI interrupt enable Register      */
	__O  unsigned int INTRST;               /* Offset: 0x3c ( /W)SPI interrupt status Register       */
	__IO unsigned int TIMING;               /* Offset: 0x40 (R/W) SPI interface timing Register      */
	     unsigned int RESERVED2[3];         /* Offset: 0x44~0x4c Reserved                            */
	__IO unsigned int MEMCTRL;              /* Offset: 0x50 (R/W) SPI memory access control Register */
	     unsigned int RESERVED3[3];         /* Offset: 0x54~0x5c Reserved                            */
	__IO unsigned int SLVST;                /* Offset: 0x60 (R/W) SPI slave status Register          */
	__I  unsigned int SLVDATACNT;           /* Offset: 0x64 (R/ ) SPI slave data count Register      */
	     unsigned int RESERVED4[5];         /* Offset: 0x68~0x78 Reserved                            */
	__I  unsigned int CONFIG;               /* Offset: 0x7c (R/ ) Configuration Register             */
}SPI_FLASH_RegDef;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined ( __CC_ARM   )
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

/* Peripheral and SRAM base address */
#define FLASH_BASE        ((uint32_t)0x00000000)   /*!< (FLASH     ) Base Address */
#define SRAM_BASE         ((uint32_t)0x20000000)   /*!< (SRAM      ) Base Address */

#define AHB1PERIPH_BASE   ((uint32_t)0x40000000)   /*!< (AHB1 Peripheral) Base Address                       */
#define AHB2PERIPH_BASE   ((uint32_t)0x52000000)   /*!< (AHB2 Peripheral) Base Address                       */
#define APB1PERIPH_BASE   ((uint32_t)0x50000000)   /*!< (APB1 Peripheral) Base Address                       */
#define APB2PERIPH_BASE   ((uint32_t)0x51000000)   /*!< (APB2 Peripheral) Base Address                       */

/* APB1 Peripheral base address */
#define TIMER0_BASE       (APB1PERIPH_BASE + 0x0000)    /* !< TIMER0 Base Address     */
#define TIMER1_BASE       (APB1PERIPH_BASE + 0x1000)    /* !< TIMER1 Base Address     */
#define SPI_FLASH_BASE    (APB1PERIPH_BASE + 0x3000)    /* !< SPI Flash Base Address> */
#define UART0_BASE        (APB1PERIPH_BASE + 0x4000)    /* !< UART0  Base Address     */
#define UART1_BASE        (APB1PERIPH_BASE + 0x5000)    /* !< UART1  Base Address     */
#define RTC_BASE          (APB1PERIPH_BASE + 0x6000)    /* !< RTC Base Address        */
#define WDOG_BASE         (APB1PERIPH_BASE + 0x8000)    /* !< WATCHDOG  Base Address  */
#define I2C_BASE          (APB1PERIPH_BASE + 0xA000)    /* !< I2C Base Address        */
#define SPI_BASE          (APB1PERIPH_BASE + 0xB000)    /* !< SPI Base Address        */

/* AHB Peripheral base address */
#define GPIO0_BASE        (AHB1PERIPH_BASE + 0x0000000)    /* !< GPIO0 Base Address     */
#define ENT_BASE          (AHB1PERIPH_BASE + 0x6000000)    /* !< Ethernet Base Address  */
#define DDR3_BASE         (AHB2PERIPH_BASE + 0x3000000)    /* !< DDR3 Base Address      */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define UART0             ((UART_TypeDef      *) UART0_BASE)
#define UART1             ((UART_TypeDef      *) UART1_BASE)
#define TIMER0            ((TIMER_TypeDef     *) TIMER0_BASE)
#define TIMER1            ((TIMER_TypeDef     *) TIMER1_BASE)
#define WDOG              ((WDOG_TypeDef      *) WDOG_BASE)
#define I2C               ((I2C_TypeDef       *) I2C_BASE) 
#define GPIO0             ((GPIO_TypeDef      *) GPIO0_BASE)
#define Ethernet          ((ETH_RegDef        *) ENT_BASE)
#define DDR3              ((DDR3_RegDef       *) DDR3_BASE)
#define SPI               ((SPI_TypeDef       *) SPI_BASE)
#define RTC               ((RTC_RegDef        *) RTC_BASE)
#define SPI_FLASH         ((SPI_FLASH_RegDef  *) SPI_FLASH_BASE)

/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
 
/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*           Universal Asynchronous Receiver Transmitter (UART)               */
/******************************************************************************/
/* bit definitions for DATA register */
#define UART_DATA              ((uint32_t) 0x000000FF) /* UART DATA: Data value */

/* bit definitions for STATE register */
#define UART_STATE_TXBF        ((uint32_t) 0x00000001) /* UART STATE: Tx buffer full    */
#define UART_STATE_RXBF        ((uint32_t) 0x00000002) /* UART STATE: Rx buffer full    */
#define UART_STATE_TXOR        ((uint32_t) 0x00000004) /* UART STATE: Tx buffer overrun */
#define UART_STATE_RXOR        ((uint32_t) 0x00000008) /* UART STATE: Rx buffer overrun */

/* bit definitions for CTRL register */
#define UART_CTRL_TXEN         ((uint32_t) 0x00000001) /* UART CTRL: TX enable                           */
#define UART_CTRL_RXEN         ((uint32_t) 0x00000002) /* UART CTRL: RX enable           
            */
#define UART_CTRL_TXIRQEN      ((uint32_t) 0x00000004) /* UART CTRL: TX interrupt enable 
            */
#define UART_CTRL_RXIRQEN      ((uint32_t) 0x00000008) /* UART CTRL: RX interrupt enable 
            */
#define UART_CTRL_TXORIRQEN    ((uint32_t) 0x00000010) /* UART CTRL: TX overrun interrupt enable         */
#define UART_CTRL_RXORIRQEN    ((uint32_t) 0x00000020) /* UART CTRL: RX overrun interrupt enable         */
#define UART_CTRL_HSTM         ((uint32_t) 0x00000040) /* UART CTRL: High-speed test mode for TX enable  */

/* bit definitions for INTSTATUS register */
#define UART_INTSTATUS_TXIRQ    ((uint32_t) 0x00000001) /* UART INTCLEAR: Get TX interrupt status         */
#define UART_INTSTATUS_RXIRQ    ((uint32_t) 0x00000002) /* UART INTCLEAR: Get RX interrupt status         */
#define UART_INTSTATUS_TXORIRQ  ((uint32_t) 0x00000004) /* UART INTCLEAR: Get TX overrun interrupt status */
#define UART_INTSTATUS_RXORIRQ  ((uint32_t) 0x00000008) /* UART INTCLEAR: Get RX overrun interrupt status */

/* bit definitions for INTCLEAR register */
#define UART_INTCLEAR_TXIRQ    ((uint32_t) 0x00000001) /* UART INTCLEAR: Clear TX interrupt         */
#define UART_INTCLEAR_RXIRQ    ((uint32_t) 0x00000002) /* UART INTCLEAR: Clear RX interrupt         */
#define UART_INTCLEAR_TXORIRQ  ((uint32_t) 0x00000004) /* UART INTCLEAR: Clear TX overrun interrupt */
#define UART_INTCLEAR_RXORIRQ  ((uint32_t) 0x00000008) /* UART INTCLEAR: Clear RX overrun interrupt */

/* bit definitions for BAUDDIV register */
#define UART_BAUDDIV           ((uint32_t) 0x000FFFFF) /* UART BAUDDIV: Baud rate divider*/


/******************************************************************************/
/*                                Timer (TIMER)                               */
/******************************************************************************/
/* bit definitions for CTRL register */
#define TIMER_CTRL_EN          ((uint32_t) 0x00000001) /* TIMER CTRL: Enable                          */
#define TIMER_CTRL_SELEXTEN    ((uint32_t) 0x00000002) /* TIMER CTRL: Select external input as enable */
#define TIMER_CTRL_SELEXTCLK   ((uint32_t) 0x00000004) /* TIMER CTRL: Select external input as clock  */
#define TIMER_CTRL_IRQEN       ((uint32_t) 0x00000008) /* TIMER CTRL: Timer interrupt enable */

/* bit definitions for VALUE register */
#define TIMER_VALUE            ((uint32_t) 0xFFFFFFFF) /* TIMER VALUE: Current value */

/* bit definitions for RELOAD register */
#define TIMER_RELOAD           ((uint32_t) 0xFFFFFFFF) /* TIMER RELOAD: Reload value */

/* bit definitions for INTSTATUS register */
#define TIMER_INTSTATUS        ((uint32_t) 0x00000001) /* TIMER INTSTATUS: Get Timer interrupt status */

/* bit definitions for INTCLEAR register */
#define TIMER_INTCLEAR         ((uint32_t) 0x00000001) /* TIMER INTCLEAR: Clear Timer interrupt */


/******************************************************************************/
/*                   General Purpose Input Output (GPIO)                      */
/******************************************************************************/
/* bit definitions for  DATA register */
#define GPIO_DATA           ((uint32_t) 0x0000FFFF)  /* GPIO DATA: Data value */

/* bit definitions for DATAOUT register */
#define GPIO_DATAOUT        ((uint32_t) 0x0000FFFF)  /* GPIO DATAOUT: Data output value */

/* bit definitions for OUTENSET register */
#define GPIO_OUTENSET       ((uint32_t) 0x0000FFFF)  /* GPIO OUTENSET: Output enable set */

/* bit definitions for OUTENCLR register */
#define GPIO_OUTENCLR       ((uint32_t) 0x0000FFFF)  /* GPIO OUTENCLR: Output enable clear */

/* bit definitions for ALTFUNCSET register */
#define GPIO_ALTFUNSET      ((uint32_t) 0x0000FFFF)  /* GPIO ALTFUNCSET: Alternative function set */

/* bit definitions for ALTFUNCCLR register */
#define GPIO_ALTFUNCCLR     ((uint32_t) 0x0000FFFF)  /* GPIO ALTFUNCCLR: Alternative function clear */

/* bit definitions for INTENSET register */
#define GPIO_INTENSET       ((uint32_t) 0x0000FFFF)  /* GPIO INTENSET: Interrupt enable set */

/* bit definitions for INTENCLR register */
#define GPIO_INTENCLR       ((uint32_t) 0x0000FFFF)  /* GPIO INTENCLR: Interrupt enable clear */

/* bit definitions for INTTYPESET register */
#define GPIO_INTTYPESET     ((uint32_t) 0x0000FFFF)  /* GPIO INTTYPESET: Interrupt type set */

/* bit definitions for INTTYPECLR register */
#define GPIO_INTTYPECLR     ((uint32_t) 0x0000FFFF)  /* GPIO INTTYPECLR: Interrupt type clear */

/* bit definitions for INTPOLSET register */
#define GPIO_INTPOLSET      ((uint32_t) 0x0000FFFF)  /* GPIO INTPOLSET: Interrupt polarity set */

/* bit definitions for INTPOLCLR register */
#define GPIO_INTPOLCLR      ((uint32_t) 0x0000FFFF)  /* GPIO INTPOLCLR: Interrupt polarity clear */

/*  bit definitions for INTSTATUS register */
#define GPIO_INTSTATUS      ((uint32_t) 0x0000FFFF)  /* GPIO INTSTATUS: Get Interrupt status */

/*  bit definitions for INTCLEAR register */
#define GPIO_INTCLEAR       ((uint32_t) 0x0000FFFF)  /* GPIO INTCLEAR: Interrupt request clear*/

/*  bit definitions for MASKLOWBYTE register */
#define GPIO_MASKLOWBYTE    ((uint32_t) 0x000000FF)  /* GPIO MASKLOWBYTE: Data for lower byte access */

/*  bit definitions for MASKHIGHBYTE register */
#define GPIO_MASKHIGHBYTE   ((uint32_t) 0x0000FF00)  /* GPIO MASKHIGHBYTE: Data for high byte access */


/******************************************************************************/
/*                             WatchDog (WDOG)                                */
/******************************************************************************/
/*  bit definitions for LOAD register */
#define WDOG_LOAD              ((uint32_t) 0xFFFFFFFF)  /* the value from which the counter is to decrement */

/*  bit definitions for VALUE register */
#define WDOG_VALUE             ((uint32_t) 0xFFFFFFFF) /* the current value of the decrementing counter     */

/*  bit definitions for CTRL register */
#define WDOG_CTRL_INTEN        ((uint32_t) 0x00000001)  /* Enable the interrupt         */
#define WDOG_CTRL_RESEN        ((uint32_t) 0x00000002)  /* Enable watchdog reset output */

/*  bit definitions for INTCLR register */
#define WDOG_INTCLR            ((uint32_t) 0x00000001)  /* clear the watchdog interrupt and reloads the counter */

/*  bit definitions for RAWINTSTAT register */
#define WDOG_RAWINTSTAT        ((uint32_t) 0x00000001)  /* Raw interrupt status from the counter */

/*  bit definitions for MASKINTSTAT register */
#define WDOG_MASKINTSTAT       ((uint32_t) 0x00000001)  /* Enable interrupt status from the counter */

/*  bit definitions for LOCK register */
#define WDOG_LOCK_ENSTAT       ((uint32_t) 0x00000001)  /* Register write enable status */
#define WDOG_LOCK_EN           ((uint32_t) 0xFFFFFFFE)  /* Enable register writes */

/*  bit definitions for ITCR register */
#define WDOG_ITCR_INTEGTESTEN  ((uint32_t) 0x00000001)  /* Integration test mode enable */

/*  bit definitions for ITOP register */
#define WDOG_ITOP_WDOGRES      ((uint32_t) 0x00000001)  /* Integration test WDOGINT value */
#define WDOG_ITOP_WDOGINT      ((uint32_t) 0x00000002)  /* Integration test WDOGRES value */

/**
  * @}
  */

/* ---------Include peripherals------------ */
#include "GOWIN_M3_conf.h"

#ifdef __cplusplus
}
#endif

#endif /* GOWIN_M3_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************GowinSemiconductor******END OF FILE*******************/
