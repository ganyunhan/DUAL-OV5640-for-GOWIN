module Cortex_M3_DualCam(
    input         sys_clk    ,  //系统时钟
    input         sys_rst_n  ,  //系统复位，低电平有效

    //Cortex_M3
    inout         SWDIO      ,
    inout         SWCLK      ,
    input         UART0RXD_i ,
    output        UART0TXD_o ,
    inout         cmos0_en       ,
    inout         cmos1_en       ,
    inout         splicing_en       ,
    inout         OUT1       ,
    inout         OUT2       ,
    inout         OUT3       ,
    inout         LED1       ,
    inout         LED2       ,
    inout         LED3       ,
    //摄像头0 
    input         cam0_pclk  ,  //cmos 数据像素时钟
    input         cam0_vsync ,  //cmos 场同步信号
    input         cam0_href  ,  //cmos 行同步信号
    input  [7:0]  cam0_data  ,  //cmos 数据  
    output        cam0_rst_n ,  //cmos 复位信号，低电平有效
    output        cam0_scl   ,  //cmos SCCB_SCL线
    inout         cam0_sda   ,  //cmos SCCB_SDA线
    
    //摄像头1 
    input         cam1_pclk  ,  //cmos 数据像素时钟
    input         cam1_vsync ,  //cmos 场同步信号
    input         cam1_href  ,  //cmos 行同步信号
    input  [7:0]  cam1_data  ,  //cmos 数据  
    output        cam1_rst_n ,  //cmos 复位信号，低电平有效
    output        cam1_scl   ,  //cmos SCCB_SCL线
    inout         cam1_sda   ,  //cmos SCCB_SDA线    

    //HDMI
	output	   		  O_tmds_clk_p      ,
	output	   		  O_tmds_clk_n      ,
	output	   [2:0]  O_tmds_data_p     ,//{r,g,b}
	output	   [2:0]  O_tmds_data_n     ,

    //SDRAM 
	output	   [13:0] O_ddr_addr      ,
	output	   [2:0]  O_ddr_ba        ,
	output 	   	      O_ddr_cs_n      ,
	output 	   	      O_ddr_ras_n     ,
	output 	   	      O_ddr_cas_n     ,
	output 	   	      O_ddr_we_n      ,
	output 	   	      O_ddr_clk       ,
	output 	   	      O_ddr_clk_n     ,
	output 	   	      O_ddr_cke       ,
	output 	   	      O_ddr_odt       ,
	output 	   	      O_ddr_reset_n   ,
	output 	   [1:0]  O_ddr_dqm       ,
	inout  	   [15:0] IO_ddr_dq       ,
	inout  	   [1:0]  IO_ddr_dqs      ,
	inout  	   [1:0]  IO_ddr_dqs_n      
);

wire LOCKUP_o;
wire HALTED_o;

//wire [15:0] GPIO_io = {cmos0_en,cmos1_en,splicing_en,13'b0};
wire [15:0] GPIO_io;

assign GPIO_io[0] = OUT1;
assign GPIO_io[1] = OUT2;
assign GPIO_io[2] = OUT3;

assign LED1 = OUT1;
assign LED2 = OUT2;
assign LED3 = OUT3;


Gowin_EMPU_M3_template Cortex_M3(
    .GPIO           (GPIO_io),
    .SWDIO          (SWDIO),
    .SWCLK          (SWCLK),
    .UART0RXD       (UART0RXD_i),
    .UART0TXD       (UART0TXD_o),
    .HCLK           (sys_clk),
    .hwRstn         (sys_rst_n)
);

dual_ov5640_lcd graphics_processing_unit(    
    .sys_clk        (sys_clk),  //系统时钟
    .sys_rst_n      (sys_rst_n),  //系统复位，低电平有效

    //摄像头0 
    .cam0_pclk      (cam0_pclk)  ,  //cmos 数据像素时钟
    .cam0_vsync     (cam0_vsync) ,  //cmos 场同步信号
    .cam0_href      (cam0_href)  ,  //cmos 行同步信号
    .cam0_data      (cam0_data)  ,  //cmos 数据  
    .cam0_rst_n     (cam0_rst_n) ,  //cmos 复位信号，低电平有效
    .cam0_scl       (cam0_scl)   ,  //cmos SCCB_SCL线
    .cam0_sda       (cam0_sda)   ,  //cmos SCCB_SDA线
    
    //摄像头1 
    .cam1_pclk      (cam1_pclk  ),  //cmos 数据像素时钟
    .cam1_vsync     (cam1_vsync ),  //cmos 场同步信号
    .cam1_href      (cam1_href  ),  //cmos 行同步信号
    .cam1_data      (cam1_data  ),  //cmos 数据  
    .cam1_rst_n     (cam1_rst_n ),  //cmos 复位信号，低电平有效
    .cam1_scl       (cam1_scl   ),  //cmos SCCB_SCL线
    .cam1_sda       (cam1_sda   ),  //cmos SCCB_SDA线    

    //输出使能，连接ARM核
    .cmos0_en       (cmos0_en),
    .cmos1_en       (cmos1_en),
    .splicing_en    (splicing_en),


    //HDMI
	.O_tmds_clk_p   (O_tmds_clk_p   ),
	.O_tmds_clk_n   (O_tmds_clk_n   ),
	.O_tmds_data_p  (O_tmds_data_p  ),//{r,g,b}
	.O_tmds_data_n  (O_tmds_data_n  ),

    //SDRAM 
	.O_ddr_addr     (O_ddr_addr    ),
	.O_ddr_ba       (O_ddr_ba      ),
	.O_ddr_cs_n     (O_ddr_cs_n    ),
	.O_ddr_ras_n    (O_ddr_ras_n   ),
	.O_ddr_cas_n    (O_ddr_cas_n   ),
	.O_ddr_we_n     (O_ddr_we_n    ),
	.O_ddr_clk      (O_ddr_clk     ),
	.O_ddr_clk_n    (O_ddr_clk_n   ),
	.O_ddr_cke      (O_ddr_cke     ),
	.O_ddr_odt      (O_ddr_odt     ),
	.O_ddr_reset_n  (O_ddr_reset_n ),
	.O_ddr_dqm      (O_ddr_dqm     ),
	.IO_ddr_dq      (IO_ddr_dq     ),
	.IO_ddr_dqs     (IO_ddr_dqs    ),
	.IO_ddr_dqs_n   (IO_ddr_dqs_n  )   
);
endmodule