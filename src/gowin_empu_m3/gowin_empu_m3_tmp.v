//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: GowinSynthesis V1.9.8Beta
//Part Number: GW2A-LV55PG484C8/I7
//Device: GW2A-55C
//Created Time: Fri Jul 16 15:17:28 2021

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
		.UART1RXD(UART1RXD_i), //input UART1RXD
		.UART1TXD(UART1TXD_o), //output UART1TXD
		.TIMER0EXTIN(TIMER0EXTIN_i), //input TIMER0EXTIN
		.TIMER1EXTIN(TIMER1EXTIN_i), //input TIMER1EXTIN
		.APB2PADDR(APB2PADDR_o), //output [31:0] APB2PADDR
		.APB2PENABLE(APB2PENABLE_o), //output APB2PENABLE
		.APB2PWRITE(APB2PWRITE_o), //output APB2PWRITE
		.APB2PSTRB(APB2PSTRB_o), //output [3:0] APB2PSTRB
		.APB2PPROT(APB2PPROT_o), //output [2:0] APB2PPROT
		.APB2PWDATA(APB2PWDATA_o), //output [31:0] APB2PWDATA
		.APB2PSEL(APB2PSEL_o), //output APB2PSEL
		.APB2PRDATA(APB2PRDATA_i), //input [31:0] APB2PRDATA
		.APB2PREADY(APB2PREADY_i), //input APB2PREADY
		.APB2PSLVERR(APB2PSLVERR_i), //input APB2PSLVERR
		.APB2PCLK(APB2PCLK_o), //output APB2PCLK
		.APB2PRESET(APB2PRESET_o), //output APB2PRESET
		.AHB2HRDATA(AHB2HRDATA_i), //input [31:0] AHB2HRDATA
		.AHB2HREADYOUT(AHB2HREADYOUT_i), //input AHB2HREADYOUT
		.AHB2HRESP(AHB2HRESP_i), //input [1:0] AHB2HRESP
		.AHB2HTRANS(AHB2HTRANS_o), //output [1:0] AHB2HTRANS
		.AHB2HBURST(AHB2HBURST_o), //output [2:0] AHB2HBURST
		.AHB2HPROT(AHB2HPROT_o), //output [3:0] AHB2HPROT
		.AHB2HSIZE(AHB2HSIZE_o), //output [2:0] AHB2HSIZE
		.AHB2HWRITE(AHB2HWRITE_o), //output AHB2HWRITE
		.AHB2HMASTLOCK(AHB2HMASTLOCK_o), //output AHB2HMASTLOCK
		.AHB2HREADYMUX(AHB2HREADYMUX_o), //output AHB2HREADYMUX
		.AHB2HMASTER(AHB2HMASTER_o), //output [3:0] AHB2HMASTER
		.AHB2HADDR(AHB2HADDR_o), //output [31:0] AHB2HADDR
		.AHB2HWDATA(AHB2HWDATA_o), //output [31:0] AHB2HWDATA
		.AHB2HSEL(AHB2HSEL_o), //output AHB2HSEL
		.AHB2HCLK(AHB2HCLK_o), //output AHB2HCLK
		.AHB2HRESET(AHB2HRESET_o), //output AHB2HRESET
		.RTCSRCCLK(RTCSRCCLK_i), //input RTCSRCCLK
		.SCL(SCL_io), //inout SCL
		.SDA(SDA_io), //inout SDA
		.MOSI(MOSI_o), //output MOSI
		.MISO(MISO_i), //input MISO
		.SCLK(SCLK_o), //output SCLK
		.NSS(NSS_o), //output NSS
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
