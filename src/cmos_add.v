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


//计数器对系统时钟计数，计时0.2秒，场信号采样时钟
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


wire [15:0]     cmos0_data_rd;
wire            cmos1_write_full;
fifo_pong u_fifo_pong(
    .Data       (cmos0_data         ), //input [15:0] Data
    .Reset      (~sys_rst_n         ), //input Reset
    .WrClk      (cmos0_pclk         ), //input WrClk
    .RdClk      (cmos0_pclk         ), //input RdClk
    .WrEn       (cmos0_href         ), //input WrEn
    .RdEn       (~cmos1_href        ), //input RdEn
//    .RdEn       (~empty        ), //input RdEn
    .Q          (cmos0_data_rd      ), //output [15:0] Q
    .Empty      (empty              ), //output Empty
    .Full       (cmos1_write_full   ) //output Full
);

//将empty信号打到cmos0_pclk里
reg empty_vsync;
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


///cmos_vsync信号2分频作pixel_vsync信号
reg [1:0] vsync_add_clk_cnt;
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

assign pixel_vsync = (vsync_add_clk_cnt ^ 2'd1) ? 1'b0 : cmos0_vsync ;



//cam1行像素点计数
reg [11:0]      cam1_pixel_cnt;//行像素计数器
always @(posedge cmos1_pclk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        cam1_pixel_cnt <= 12'd0;
    else if (!cmos1_href) begin
        cam1_pixel_cnt <= 12'd0;
    end
    else if (cam1_pixel_cnt > 12'd639) begin
        cam1_pixel_cnt <= 12'd0;
    end
    else if (cmos1_href && cam1_pixel_cnt < 12'd640) begin
        cam1_pixel_cnt <= cam1_pixel_cnt + 12'd1;
    end
end

localparam PIXEL_OFFSET = 12'd200;
wire pixel_offset_flag = cam1_pixel_cnt < PIXEL_OFFSET ? 1'b1 : 1'b0;

wire [15:0]     cmos0_data_splicing;
wire            fifo_splicing_full;
wire            fifo_splicing_empty;
fifo_pong u_fifo_splicing(
    .Data       (cmos0_data         ), //input [15:0] Data
    .Reset      (~sys_rst_n         ), //input Reset
    .WrClk      (cmos0_pclk         ), //input WrClk
    .RdClk      (cmos0_pclk         ), //input RdClk
    .WrEn       (cmos0_href         ), //input WrEn
//    .RdEn       (~pixel_offset_flag), //input RdEn
    .RdEn       (1'b1), //input RdEn
    .Q          (cmos0_data_splicing), //output [15:0] Q
    .Empty      (fifo_splicing_empty), //output Empty
    .Full       (fifo_splicing_full ) //output Full
);


//移位拼接
always @(*) begin
//pixel_data = (vsync_add_clk_cnt ^ 2'd1) ?  (cmos1_href ? cmos1_data : cmos0_data_rd) : 16'd0;
    case (vsync_add_clk_cnt)//上下分屏显示，用vsync分屏信号做标志
        2'd0 : begin
            pixel_data = pixel_offset_flag ? cmos1_data : ~fifo_splicing_empty ? cmos0_data_splicing : 1'b0;
        end
        2'd1 : begin
            pixel_data = cmos1_href ? cmos1_data : cmos0_data_rd;
        end
        default : 
            pixel_data = pixel_offset_flag ? cmos1_data : ~fifo_splicing_empty ? cmos0_data_splicing : 1'b0;
    endcase
end

assign pixel_href =  cmos1_href | (~ empty);

endmodule
