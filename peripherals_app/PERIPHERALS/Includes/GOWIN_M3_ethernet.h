/*
 * **************************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        GOWIN_M3_ethernet.h
 * @author      Embedded Development Team
 * @version     V1.0.0
 * @date        2020-4-1 09:00:00
 * @brief       This file contains all the functions prototypes for the Ethernet firmware library.
 ****************************************************************************************************
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GOWIN_M3_ETHERNET_H
#define GOWIN_M3_ETHERNET_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "GOWIN_M3.h"

/* Macros --------------------------------------------------------------------*/
#define BIT0                  (1UL << 0)

#define ETH_TX_LATE_COL       (1UL << 2)
#define ETH_TX_EXCESSIVE_COL  (1UL << 1)
#define ETH_TX_FAIL_FAIL      (1UL << 0)

#define MIIM_OP_END_IS        (1UL << 1)
#define MIIM_RD_DATA_VALID_IS (1UL << 0)

#define MIIM_OP_END_IE        (1UL << 1)
#define MIIM_RD_DATA_VALID_IE (1UL << 0)

#define MIIM_OP_END_IC        (1UL << 1)
#define MIIM_RD_DATA_VALID_IC (1UL << 0)

#define ETH_DUPLEX_MODE       (1UL << 2)

#define ETH_FULL_DUPLEX_100M    0UL
#define ETH_FULL_DUPLEX_1000M   1UL
#define ETH_FULL_DUPLEX_10M     2UL
#define ETH_HALF_DUPLEX_100M    4UL
#define ETH_HALF_DUPLEX_10M     6UL

#define ETH_RX 0
#define ETH_TX 1

/* Variables ------------------------------------------------------------------*/
typedef void (*NDS_ETH_SignalEvent_t) (uint32_t event);

typedef struct _NDS_DRIVER_ETH
{
	int32_t (*init)             (uint8_t *rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr);
	int32_t (*eth_tx)           (uint8_t *tx_message, uint32_t tx_length);
	void    (*miim_write)       (uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data);
	void    (*miim_receive)     (uint8_t miim_phy_address, uint8_t miim_reg_addr);
	void    (*eth_set_mode)     (uint32_t eth_mode);
}const NDS_DRIVER_ETH;

typedef struct _ETH_INFO
{
	uint8_t  *rx_ptr;
	uint32_t *rx_data_length;
	uint32_t *miim_rd_ptr;
}ETH_INFO;

/* Functions ------------------------------------------------------------------*/
extern void tx_int_event(void);
extern void rx_int_event(void);
extern void miim_wr_int_event(void);
extern void miim_rd_int_event(void);
extern int32_t eth_init(uint8_t* rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr);
extern int32_t eth_tx (uint8_t *tx_message, uint32_t tx_length);
extern void miim_write(uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data);
extern void miim_receive(uint8_t miim_phy_address, uint8_t miim_reg_addr);
extern void eth_set_mode(uint32_t eth_mode);

#ifdef __cplusplus
}
#endif

#endif /* GOWIN_M3_ETHERNET_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
