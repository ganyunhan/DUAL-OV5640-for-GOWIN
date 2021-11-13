//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: GowinSynthesis V1.9.8
//Part Number: GW2A-LV55PG484C8/I7
//Device: GW2A-55C
//Created Time: Sat Nov 13 17:48:24 2021

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

	Gowin_EMPU_M3_Top your_instance_name(
		.LOCKUP(LOCKUP_o), //output LOCKUP
		.HALTED(HALTED_o), //output HALTED
		.JTAG_3(JTAG_3_io), //inout JTAG_3
		.JTAG_4(JTAG_4_io), //inout JTAG_4
		.JTAG_5(JTAG_5_io), //inout JTAG_5
		.JTAG_6(JTAG_6_io), //inout JTAG_6
		.JTAG_7(JTAG_7_io), //inout JTAG_7
		.JTAG_8(JTAG_8_io), //inout JTAG_8
		.JTAG_9(JTAG_9_io), //inout JTAG_9
		.JTAG_10(JTAG_10_io), //inout JTAG_10
		.JTAG_11(JTAG_11_io), //inout JTAG_11
		.JTAG_12(JTAG_12_io), //inout JTAG_12
		.JTAG_13(JTAG_13_io), //inout JTAG_13
		.JTAG_14(JTAG_14_io), //inout JTAG_14
		.JTAG_15(JTAG_15_io), //inout JTAG_15
		.JTAG_16(JTAG_16_io), //inout JTAG_16
		.JTAG_17(JTAG_17_io), //inout JTAG_17
		.JTAG_18(JTAG_18_io), //inout JTAG_18
		.GPIO(GPIO_io), //inout [15:0] GPIO
		.UART0RXD(UART0RXD_i), //input UART0RXD
		.UART0TXD(UART0TXD_o), //output UART0TXD
		.FLASH_SPI_HOLDN(FLASH_SPI_HOLDN_io), //inout FLASH_SPI_HOLDN
		.FLASH_SPI_CSN(FLASH_SPI_CSN_io), //inout FLASH_SPI_CSN
		.FLASH_SPI_MISO(FLASH_SPI_MISO_io), //inout FLASH_SPI_MISO
		.FLASH_SPI_MOSI(FLASH_SPI_MOSI_io), //inout FLASH_SPI_MOSI
		.FLASH_SPI_WPN(FLASH_SPI_WPN_io), //inout FLASH_SPI_WPN
		.FLASH_SPI_CLK(FLASH_SPI_CLK_io), //inout FLASH_SPI_CLK
		.HCLK(HCLK_i), //input HCLK
		.hwRstn(hwRstn_i) //input hwRstn
	);

//--------Copy end-------------------
