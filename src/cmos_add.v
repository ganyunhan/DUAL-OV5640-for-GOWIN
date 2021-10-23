module cmos_add(
    input           sys_rst_n,
    input           cmos0_pclk,
    input           cmos0_href,
    input[15:0]     cmos0_data,
    input           cmos0_vsync,

    input           cmos1_pclk,
    input           cmos1_href,
    input[15:0]     cmos1_data,

    output          pixel_vsync,
    output          pixel_href,
    output          pixel_de,
    output[15:0]    pixel_data
);

reg [11:0]      pixel_cnt;//行像素计数器
reg             pixel_href_reg;
wire [15:0]     cmos1_data_rd;
wire            cmos1_write_full;

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

fifo_pong u_fifo_pong(
    .Data       (cmos1_data         ), //input [15:0] Data
    .Reset      (~sys_rst_n         ), //input Reset
    .WrClk      (cmos1_pclk         ), //input WrClk
    .RdClk      (cmos1_pclk          ), //input RdClk
    .WrEn       (cmos1_href         ), //input WrEn
    .RdEn       (~cmos0_href   ), //input RdEn
    .Q          (cmos1_data_rd      ), //output [15:0] Q
    .Empty      (empty                   ), //output Empty
    .Full       (cmos1_write_full   ) //output Full
);

assign pixel_data = cmos0_href ? cmos0_data : cmos1_data_rd;
assign pixel_vsync = cmos0_vsync;
assign pixel_href =  ~empty;

endmodule