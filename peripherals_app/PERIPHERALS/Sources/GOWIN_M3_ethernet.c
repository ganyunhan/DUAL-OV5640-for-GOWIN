/*
 * ***************************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        GOWIN_M3_ethernet.c
 * @author      Embedded Development Team
 * @version     V1.0.1
 * @date        2021-07-01 09:00:00
 * @brief       This file contains all the functions prototypes for the Ethernet firmware library.
 ****************************************************************************************************
 */

 /* Includes ------------------------------------------------------------------*/
#include "GOWIN_M3_ethernet.h"
#include <stdio.h>

static ETH_INFO eth_info = {NULL, NULL, NULL};

void tx_int_event(void)
{
	if(!Ethernet->ETH_TX_FAIL)
	{
		Ethernet->ETH_TX_IC |= BIT0;
	}
	else if(Ethernet->ETH_TX_FAIL & ETH_TX_EXCESSIVE_COL)
	{
		Ethernet->ETH_TX_EN |= BIT0;
		Ethernet->ETH_TX_IC |= BIT0;
	}
	else if(Ethernet->ETH_TX_FAIL & ETH_TX_LATE_COL)
	{
		Ethernet->ETH_TX_EN |= BIT0;
		Ethernet->ETH_TX_IC |= BIT0;
	}
}

void rx_int_event(void)
{
	uint8_t *rx_message = eth_info.rx_ptr;
	uint32_t *rx_data_length = eth_info.rx_data_length;
	
	if(rx_message == NULL)
	{
		return;
	}
	
	uint32_t rx_length = Ethernet->ETH_RX_LENGTH;
	*rx_data_length = rx_length;
	uint8_t *rx_buffer = (uint8_t *)(Ethernet->ETH_RX_DATA);
	
	for(int i = 0; i < rx_length; i++)
	{
		rx_message[i] = rx_buffer[i];
	}

	Ethernet->ETH_RX_IC |= BIT0;
}

void miim_wr_int_event(void)
{
	uint32_t miim_is = Ethernet->MIIM_IS;
	Ethernet->MIIM_IC |= miim_is;
}

void miim_rd_int_event(void)
{
	uint32_t *miim_rd_data = eth_info.miim_rd_ptr;
	
	if(miim_rd_data == NULL)
	{
		return;
	}
	
	*miim_rd_data = Ethernet->MIIM_RD_DATA;
	uint32_t miim_is = Ethernet->MIIM_IS;
	Ethernet->MIIM_IC |= miim_is;
}

int32_t eth_init(uint8_t* rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr)
{
	Ethernet->ETH_TX_LENGTH = 0;
	Ethernet->ETH_TX_EN = 0;
	Ethernet->ETH_TX_FAIL = 0;
	Ethernet->ETH_TX_IE = 1;
	Ethernet->ETH_RX_IE = 1;
	Ethernet->MIIM_OP_MODE = 0;
	Ethernet->MIIM_PHY_ADDR = 0;
	Ethernet->MIIM_REG_ADDR = 0;
	Ethernet->MIIM_WR_DATA = 0;
	Ethernet->MIIM_IE = 1;
	Ethernet->MIIM_OP_EN = 0;
	Ethernet->ETH_MODE = 0;
	
	eth_info.rx_ptr = rx_ptr;
	eth_info.rx_data_length = rx_data_length;
	eth_info.miim_rd_ptr = miim_rd_ptr;

	return 0;
}

int32_t eth_tx (uint8_t *tx_message, uint32_t tx_length)
{
	while(Ethernet->ETH_TX_EN);
	
	Ethernet->ETH_TX_LENGTH = tx_length;
	
	uint32_t *tx_message_ptr = (uint32_t *)(tx_message);
	uint32_t tx_word_num = tx_length / 4 + (tx_length % 4 ? 1 : 0);
	
	for(int i = 0; i < tx_word_num; i++)
	{
		Ethernet->ETH_TX_DATA[i] = tx_message_ptr[i];
	}
	
	Ethernet->ETH_TX_EN |= BIT0;
	
	return 0;
}

void miim_write(uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data)
{
	Ethernet->MIIM_IE = 0x03;
	Ethernet->MIIM_OP_MODE = 1;
	Ethernet->MIIM_PHY_ADDR = miim_phy_address;
	Ethernet->MIIM_REG_ADDR = miim_reg_addr;
	Ethernet->MIIM_WR_DATA = miim_wr_data;
	Ethernet->MIIM_OP_EN = 1;
}

void miim_receive(uint8_t miim_phy_address, uint8_t miim_reg_addr)
{
	Ethernet->MIIM_IE = 0x03;
	Ethernet->MIIM_OP_MODE = 0;
	Ethernet->MIIM_PHY_ADDR = miim_phy_address;
	Ethernet->MIIM_REG_ADDR = miim_reg_addr;
	Ethernet->MIIM_OP_EN = 1;
}

void eth_set_mode(uint32_t eth_mode)
{
	Ethernet->ETH_MODE = eth_mode;
}

NDS_DRIVER_ETH Driver_ETH =
{
	eth_init,
	eth_tx,
	miim_write,
	miim_receive,
	eth_set_mode
};

/************************GowinSemiconductor******END OF FILE*******************/
