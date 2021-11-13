/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        GOWIN_M3_ddr3.c
 * @author	    Embedded Development Team
 * @version	    V1.0.0
 * @date        2030-4-1 09:00:00
 * @brief       This file contains all the functions prototypes for the DDR3 firmware library.
 ******************************************************************************************
 */

 /* Includes ------------------------------------------------------------------*/
#include "GOWIN_M3_ddr3.h"

uint8_t DDR3_Init(void)
{
	uint32_t init_flag = 0;
	
	do
	{
		init_flag = DDR3->INIT;
	}
	while(!init_flag);
	
	return init_flag;
}

void DDR3_Read(uint32_t addr, uint32_t *rd_buff)
{
	uint32_t *rd_ptr = rd_buff;
	uint32_t rd_en;
	
	do
	{
		rd_en = DDR3->RD_EN;
	}
	while(rd_en);  //wait until the rd_en is 0

	DDR3->RD_ADDR = addr;
	DDR3->RD_EN = 1;
	
	do
	{
		rd_en = DDR3->RD_EN;
	}
	while(rd_en);  //wait until the rd_en is 0

	for(int i = 0; i < 4; i++)
	{
		*rd_ptr = DDR3->RD_DATA[i];
		rd_ptr++;
	}
}

void DDR3_Write(uint32_t addr, uint32_t *wr_buff)
{
	uint32_t *wr_ptr = wr_buff;
	uint32_t wr_en;
	
	do
	{
		wr_en = DDR3->WR_EN;
	}
	while(wr_en);   // wait until the wr_en is 0

	DDR3->WR_ADDR = addr;
	
	for(int i = 0; i < 4; i++)
	{
		DDR3->WR_DATA[i] = *wr_ptr;
		wr_ptr++;
	}
	
	DDR3->WR_EN = 1;
	
	do
	{
		wr_en = DDR3->WR_EN;
	}
	while(wr_en);   // wait until the wr_en is 0,
	                // which means the write operation is finished.
}

/************************GowinSemiconductor******END OF FILE*******************/
