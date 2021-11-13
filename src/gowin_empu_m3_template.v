
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
  .HCLK(MCU_SYS_CLK),
  .hwRstn(hwRstn)
);
//-------------------------Gowin_EMPU_M3_Top----------------------//

endmodule