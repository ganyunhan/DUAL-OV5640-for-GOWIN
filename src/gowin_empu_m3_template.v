
`resetall

module Gowin_EMPU_M3_template (
  //GPIO
  GPIO,
  //Debug Access Port
  SWDIO,   //tms   |       swdio
  SWCLK,   //tck   |       swclk
  //UART0
  UART0RXD,
  UART0TXD,
  //UART1
  UART1RXD,
  UART1TXD,
  //I2C Master
  SCL,
  SDA,
  //SPI Master
  MOSI,
  MISO,
  SCLK,
  NSS,
  //SPI-Flash
  FLASH_SPI_HOLDN,
  FLASH_SPI_CSN,
  FLASH_SPI_MISO,
  FLASH_SPI_MOSI,
  FLASH_SPI_WPN,
  FLASH_SPI_CLK,
  //System Clock
  HCLK,
  //System Reset
  hwRstn
);


inout SWDIO;
inout SWCLK;

inout [15:0] GPIO;
input UART0RXD ;
output UART0TXD ;
input HCLK ;
input hwRstn ;
inout FLASH_SPI_HOLDN;
inout FLASH_SPI_CSN;
inout FLASH_SPI_MISO;
inout FLASH_SPI_MOSI;
inout FLASH_SPI_WPN;
inout FLASH_SPI_CLK;
input UART1RXD;
output UART1TXD;
inout SCL;
inout SDA;
output MOSI;   // SPI output
input MISO;    // SPI input
output SCLK;   // SPI clock
output NSS;    // SPI chip select

//-------------------------Gowin_EMPU_M3_Top----------------------//
wire clkin = HCLK;	//Input 50MHz
wire MCU_SYS_CLK;	//MCU 20MHz
wire RTCSRCCLK;     //RTC 3.072MHz

Gowin_rPLL u_Gowin_rPLL(
  .clkout(MCU_SYS_CLK),     //MCU 20MHz
  .clkoutd(RTCSRCCLK),      //RTC 3.072MHz
  .clkin(clkin)             //input 50MHz
);

wire LOCKUP;
wire HALTED;

Gowin_EMPU_M3_Top u_Gowin_EMPU_M3_Top (
  .LOCKUP(LOCKUP),
  .HALTED(HALTED),
  .GPIO(GPIO),
  .JTAG_7(SWDIO),
  .JTAG_9(SWCLK),
  .UART0RXD(UART0RXD),
  .UART0TXD(UART0TXD),
  .UART1RXD(UART1RXD),
  .UART1TXD(UART1TXD),
  .TIMER0EXTIN(1'b0),
  .TIMER1EXTIN(1'b0),
  .RTCSRCCLK(RTCSRCCLK),
  .SCL(SCL),
  .SDA(SDA),
  .MOSI(MOSI),
  .MISO(MISO),
  .SCLK(SCLK),
  .NSS(NSS),
  .HCLK(MCU_SYS_CLK),
  .hwRstn(hwRstn)
);
//-------------------------Gowin_EMPU_M3_Top----------------------//

endmodule