/*
 * *************************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      GOWIN_M3_spi_flash.h
 * @author    Embedded Development Team
 * @version   V1.0.0
 * @date      2020-4-1 09:00:00
 * @brief     This file contains all the functions prototypes for the SPI-Flash firmware library.
 **************************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GOWIN_M3_SPI_FLASH_H
#define GOWIN_M3_SPI_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "GOWIN_M3.h"

/** @addtogroup GOWIN_M3_StdPeriph_Driver
  * @{
  */
/** @addtogroup SPI_FLASH
  * @{
  */

/* Macros ------------------------------------------------------------------*/
#define SPI_CMDEN                     (1UL << 30)
#define SPI_ADDREN                    (1UL << 29)

//The winbone spi-flash command
#define CHIP_ERASE                    0x60
#define WRITE_ENABLE                  0x06
#define WRITE_DISABLE                 0x04

/* Functions ------------------------------------------------------------------*/
/**
  * @brief Initializes SPI-Flash
  */
extern void spi_flash_init(void);

/**
  * @brief Switch SPI-Flash mode between download and read/write/erase memory
  */
extern void change_mode_spi_flash(void);

/**
  * @brief Read data from SPI-Flash
  */
extern void spi_flash_read(uint8_t rd_len, uint32_t cmd, uint32_t address,uint8_t *read_buffer);

/**
  * @brief Write data into SPI-Flash
  */
extern void spi_flash_write(uint8_t wr_len, uint32_t cmd, uint32_t address,uint8_t *write_buffer);

/**
  * @brief Write data into SPI-Flash and read data from SPI-Flash
  */
extern void spi_flash_write_read(uint8_t wr_len, uint8_t rd_len, uint32_t cmd, uint8_t *wr_buffer, uint8_t *rd_buffer);

/**
  * @brief Write data into a page of SPI-Flash
  */
extern void spi_flash_page_program(uint8_t wr_len,uint32_t address,uint8_t *write_buffer);

/**
  * @brief Erase a sector of SPI-Flash
  */
extern void spi_flash_sector_erase(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif	/* GOWIN_M3_SPI_FLASH_H */

/**
  * @}
  */ 

/**
  * @}
  */

/************************GowinSemiconductor******END OF FILE*******************/
