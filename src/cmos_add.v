/*
20211025
2021.10.27 
*/

module cmos_add(
    input           sys_rst_n,
    input           cmos0_pclk,
    input           cmos0_href,
    input[15:0]     cmos0_data,
    input           cmos0_vsync,

    input           cmos1_pclk,
    input           cmos1_href,
    input[15:0]     cmos1_data,
    input           cmos1_vsync,

    output          pixel_vsync,
    output          pixel_href,
    output reg [15:0]    pixel_data
);


/*
reg [11:0]      pixel_cnt;//行像素计数器
reg             pixel_href_reg;
*/

wire [15:0]     cmos0_data_rd;
wire            cmos1_write_full;

wire [15:0]     pixel_data_add; //未配准直接加权的像素,存FIFO
wire [15:0]     pixel_data_add_rd; //FIFO读取用
wire            pixel_vsync_add; //后半周期场扫描使能，如何控制?
wire            pixel_data_empty;
wire            pixel_data_full;

reg [1:0] vsync_add_clk_cnt;
reg     empty_vsync;

//计数器对系统时钟计数，计时0.2秒
reg [23:0] counter;
reg counter_clk;
always @(posedge cmos0_pclk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        counter <= 24'd0;
        counter_clk <= 1'b0;
    end
    else if (counter < 24'd10_0000)
        counter <= counter + 1'b1;
    else begin
        counter <= 24'd0;
        counter_clk <= ~counter_clk;
    end
end
/*
always @(posedge cmos1_pclk or negedge sys_rst_n) begin
    if(!sys_rst_n)
        pixel_cnt <= 12'd0;
    else if(cmos0_href) begin
        pixel_href_reg <= 1'b1;
        pixel_cnt <= 12'd0;
    end
    else if((!cmos0_href) && pixel_cnt < 12'd640) begin
        pixel_cnt <= pixel_cnt + 12'd1;
        pixel_href_reg <= 1'b1;
    end
end
*/

fifo_pong u_fifo_pong(
    .Data       (cmos0_data         ), //input [15:0] Data
    .Reset      (~sys_rst_n         ), //input Reset
    .WrClk      (cmos0_pclk         ), //input WrClk
    .RdClk      (cmos0_pclk         ), //input RdClk
    .WrEn       (cmos0_href         ), //input WrEn
    .RdEn       (~cmos1_href        ), //input RdEn
    .Q          (cmos0_data_rd      ), //output [15:0] Q
    .Empty      (empty              ), //output Empty
    .Full       (cmos1_write_full   ) //output Full
);

//assign pixel_data =  cmos1_data;
//assign pixel_vsync = cmos0_vsync;//低有效扩充，垂直360原始信号


/************2分频后begin**************/
always @(posedge cmos0_vsync or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        vsync_add_clk_cnt <= 2'b0;
    end
    else if (vsync_add_clk_cnt >= 2'd2) begin
        vsync_add_clk_cnt <= 2'b0;
    end
    else begin
        vsync_add_clk_cnt <= vsync_add_clk_cnt + 2'b1;
    end
end
/****************end*******************/

assign pixel_vsync = (vsync_add_clk_cnt ^ 2'd1) ? 1'b0 : cmos0_vsync ;

/*************将empty信号打到cmos0_pclk里**********/
reg fifo_empty;
always @(posedge cmos1_pclk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        empty_vsync <= 1'b0;
        fifo_empty <= 1'b0;
    end
    else if(~empty) begin
        fifo_empty <= ~empty;
        empty_vsync <= fifo_empty;
    end
    else begin
        fifo_empty <= 1'b0;
        empty_vsync <= 1'b0;
    end
end
/**************************************************/

//对cmos0_href进行计数
reg  [10:0]     cmos0_href_cnt;
always @(posedge cmos0_pclk or negedge sys_rst_n) begin
    if(!sys_rst_n)
        cmos0_href_cnt <= 11'd0;
    else if(cmos0_href)
        cmos0_href_cnt <= cmos0_href_cnt + 11'd1;
    else if(empty)
        cmos0_href_cnt <= 11'd0;
end

//在cmos1_href后继续延时cmos0_href长度，以达到两个摄像头数据拼接成一行的效果
reg             cmos0_href_reg;
reg   [10:0]    cmos0_delay;
always @(posedge cmos0_pclk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        cmos0_href_reg <= 1'b0;
        cmos0_delay <= 11'd0;
    end
    else if(~cmos1_href && cmos0_delay < 10'd640) begin
        cmos0_delay <= cmos0_delay + 11'd1;
        cmos0_href_reg <= 1'b1;
    end
    else if(~cmos1_href && cmos0_delay >= 10'd640) begin
        cmos0_href_reg <= 1'b0;
    end
    else if(cmos1_href) cmos0_delay <= 10'd0;
end

//垂直信号分割
reg [10:0] pixel_href_cnt;
reg        pixel_flip_flag;
always @(posedge pixel_href or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        pixel_href_cnt <= 11'd0;
        pixel_flip_flag <= 1'b0;
    end
    else if(pixel_href_cnt < 11'd360) begin
        pixel_href_cnt <= pixel_href_cnt + 1'b1;
        pixel_flip_flag <= 1'b0;
    end
    else if(pixel_href_cnt >= 11'd720) begin
        pixel_href_cnt <= 11'd0;
        pixel_flip_flag <= 1'b0;
    end
    else if(pixel_href_cnt >= 11'd360) begin
        pixel_href_cnt <= pixel_href_cnt + 1'b1;
        pixel_flip_flag <= 1'b1;
    end
end

reg [4:0] R;
reg [5:0] G;
reg [4:0] B;
/*
always @(*) begin
    if (!pixel_flip_flag) begin //上半屏
        pixel_data <= cmos1_href ? cmos1_data : cmos0_data_rd;
//          pixel_data <= cmos1_href ? 16'd0 : 16'd0;
    end
    else if(pixel_flip_flag) begin

//        R <= cmos1_data[14:11] + cmos0_data_rd[14:11];
//        G <= cmos1_data[9:5]   + cmos0_data_rd[9:5];
//        B <= cmos1_data[3:0]   + cmos0_data_rd[3:0];
//        pixel_data <= {R,G,B};

        pixel_data <= cmos1_href ? 16'd0 : 16'd0;
    end
end
*/

//上下分屏显示，用vsync分屏信号做标志
always @(*) begin
    pixel_data <= (vsync_add_clk_cnt ^ 2'd1) ?  (cmos1_href ? cmos1_data : cmos0_data_rd) : 16'd0;
end

//assign pixel_data = cmos1_href ? cmos1_data : cmos0_data_rd;//场信号后半周期更新行信号
assign pixel_href =  cmos1_href | (~ empty);
//assign pixel_href =  cmos0_href_reg|cmos1_href;//保证href信号上升沿对齐第一个像素
//assign pixel_href =  cmos1_href;

endmodule
