module gw_gao(
    \u_cmos_add/cmos0_data[15] ,
    \u_cmos_add/cmos0_data[14] ,
    \u_cmos_add/cmos0_data[13] ,
    \u_cmos_add/cmos0_data[12] ,
    \u_cmos_add/cmos0_data[11] ,
    \u_cmos_add/cmos0_data[10] ,
    \u_cmos_add/cmos0_data[9] ,
    \u_cmos_add/cmos0_data[8] ,
    \u_cmos_add/cmos0_data[7] ,
    \u_cmos_add/cmos0_data[6] ,
    \u_cmos_add/cmos0_data[5] ,
    \u_cmos_add/cmos0_data[4] ,
    \u_cmos_add/cmos0_data[3] ,
    \u_cmos_add/cmos0_data[2] ,
    \u_cmos_add/cmos0_data[1] ,
    \u_cmos_add/cmos0_data[0] ,
    \u_cmos_add/cmos0_pclk ,
    \u_cmos_add/cmos0_href ,
    \u_cmos_add/cmos1_data[15] ,
    \u_cmos_add/cmos1_data[14] ,
    \u_cmos_add/cmos1_data[13] ,
    \u_cmos_add/cmos1_data[12] ,
    \u_cmos_add/cmos1_data[11] ,
    \u_cmos_add/cmos1_data[10] ,
    \u_cmos_add/cmos1_data[9] ,
    \u_cmos_add/cmos1_data[8] ,
    \u_cmos_add/cmos1_data[7] ,
    \u_cmos_add/cmos1_data[6] ,
    \u_cmos_add/cmos1_data[5] ,
    \u_cmos_add/cmos1_data[4] ,
    \u_cmos_add/cmos1_data[3] ,
    \u_cmos_add/cmos1_data[2] ,
    \u_cmos_add/cmos1_data[1] ,
    \u_cmos_add/cmos1_data[0] ,
    \u_cmos_add/cmos1_pclk ,
    \u_cmos_add/cmos1_href ,
    \u_cmos_add/pixel_href ,
    \u_cmos_add/cmos0_data_splicing[15] ,
    \u_cmos_add/cmos0_data_splicing[14] ,
    \u_cmos_add/cmos0_data_splicing[13] ,
    \u_cmos_add/cmos0_data_splicing[12] ,
    \u_cmos_add/cmos0_data_splicing[11] ,
    \u_cmos_add/cmos0_data_splicing[10] ,
    \u_cmos_add/cmos0_data_splicing[9] ,
    \u_cmos_add/cmos0_data_splicing[8] ,
    \u_cmos_add/cmos0_data_splicing[7] ,
    \u_cmos_add/cmos0_data_splicing[6] ,
    \u_cmos_add/cmos0_data_splicing[5] ,
    \u_cmos_add/cmos0_data_splicing[4] ,
    \u_cmos_add/cmos0_data_splicing[3] ,
    \u_cmos_add/cmos0_data_splicing[2] ,
    \u_cmos_add/cmos0_data_splicing[1] ,
    \u_cmos_add/cmos0_data_splicing[0] ,
    \u_cmos_add/pixel_data[15] ,
    \u_cmos_add/pixel_data[14] ,
    \u_cmos_add/pixel_data[13] ,
    \u_cmos_add/pixel_data[12] ,
    \u_cmos_add/pixel_data[11] ,
    \u_cmos_add/pixel_data[10] ,
    \u_cmos_add/pixel_data[9] ,
    \u_cmos_add/pixel_data[8] ,
    \u_cmos_add/pixel_data[7] ,
    \u_cmos_add/pixel_data[6] ,
    \u_cmos_add/pixel_data[5] ,
    \u_cmos_add/pixel_data[4] ,
    \u_cmos_add/pixel_data[3] ,
    \u_cmos_add/pixel_data[2] ,
    \u_cmos_add/pixel_data[1] ,
    \u_cmos_add/pixel_data[0] ,
    \u_cmos_add/pixel_offset_flag ,
    \u_cmos_add/cam1_pixel_cnt[11] ,
    \u_cmos_add/cam1_pixel_cnt[10] ,
    \u_cmos_add/cam1_pixel_cnt[9] ,
    \u_cmos_add/cam1_pixel_cnt[8] ,
    \u_cmos_add/cam1_pixel_cnt[7] ,
    \u_cmos_add/cam1_pixel_cnt[6] ,
    \u_cmos_add/cam1_pixel_cnt[5] ,
    \u_cmos_add/cam1_pixel_cnt[4] ,
    \u_cmos_add/cam1_pixel_cnt[3] ,
    \u_cmos_add/cam1_pixel_cnt[2] ,
    \u_cmos_add/cam1_pixel_cnt[1] ,
    \u_cmos_add/cam1_pixel_cnt[0] ,
    \u_cmos_add/pixel_increase_flag ,
    \u_cmos_add/fifo_splicing_empty ,
    \u_cmos_add/u_fifo_splicing/RdEn ,
    sys_clk,
    tms_pad_i,
    tck_pad_i,
    tdi_pad_i,
    tdo_pad_o
);

input \u_cmos_add/cmos0_data[15] ;
input \u_cmos_add/cmos0_data[14] ;
input \u_cmos_add/cmos0_data[13] ;
input \u_cmos_add/cmos0_data[12] ;
input \u_cmos_add/cmos0_data[11] ;
input \u_cmos_add/cmos0_data[10] ;
input \u_cmos_add/cmos0_data[9] ;
input \u_cmos_add/cmos0_data[8] ;
input \u_cmos_add/cmos0_data[7] ;
input \u_cmos_add/cmos0_data[6] ;
input \u_cmos_add/cmos0_data[5] ;
input \u_cmos_add/cmos0_data[4] ;
input \u_cmos_add/cmos0_data[3] ;
input \u_cmos_add/cmos0_data[2] ;
input \u_cmos_add/cmos0_data[1] ;
input \u_cmos_add/cmos0_data[0] ;
input \u_cmos_add/cmos0_pclk ;
input \u_cmos_add/cmos0_href ;
input \u_cmos_add/cmos1_data[15] ;
input \u_cmos_add/cmos1_data[14] ;
input \u_cmos_add/cmos1_data[13] ;
input \u_cmos_add/cmos1_data[12] ;
input \u_cmos_add/cmos1_data[11] ;
input \u_cmos_add/cmos1_data[10] ;
input \u_cmos_add/cmos1_data[9] ;
input \u_cmos_add/cmos1_data[8] ;
input \u_cmos_add/cmos1_data[7] ;
input \u_cmos_add/cmos1_data[6] ;
input \u_cmos_add/cmos1_data[5] ;
input \u_cmos_add/cmos1_data[4] ;
input \u_cmos_add/cmos1_data[3] ;
input \u_cmos_add/cmos1_data[2] ;
input \u_cmos_add/cmos1_data[1] ;
input \u_cmos_add/cmos1_data[0] ;
input \u_cmos_add/cmos1_pclk ;
input \u_cmos_add/cmos1_href ;
input \u_cmos_add/pixel_href ;
input \u_cmos_add/cmos0_data_splicing[15] ;
input \u_cmos_add/cmos0_data_splicing[14] ;
input \u_cmos_add/cmos0_data_splicing[13] ;
input \u_cmos_add/cmos0_data_splicing[12] ;
input \u_cmos_add/cmos0_data_splicing[11] ;
input \u_cmos_add/cmos0_data_splicing[10] ;
input \u_cmos_add/cmos0_data_splicing[9] ;
input \u_cmos_add/cmos0_data_splicing[8] ;
input \u_cmos_add/cmos0_data_splicing[7] ;
input \u_cmos_add/cmos0_data_splicing[6] ;
input \u_cmos_add/cmos0_data_splicing[5] ;
input \u_cmos_add/cmos0_data_splicing[4] ;
input \u_cmos_add/cmos0_data_splicing[3] ;
input \u_cmos_add/cmos0_data_splicing[2] ;
input \u_cmos_add/cmos0_data_splicing[1] ;
input \u_cmos_add/cmos0_data_splicing[0] ;
input \u_cmos_add/pixel_data[15] ;
input \u_cmos_add/pixel_data[14] ;
input \u_cmos_add/pixel_data[13] ;
input \u_cmos_add/pixel_data[12] ;
input \u_cmos_add/pixel_data[11] ;
input \u_cmos_add/pixel_data[10] ;
input \u_cmos_add/pixel_data[9] ;
input \u_cmos_add/pixel_data[8] ;
input \u_cmos_add/pixel_data[7] ;
input \u_cmos_add/pixel_data[6] ;
input \u_cmos_add/pixel_data[5] ;
input \u_cmos_add/pixel_data[4] ;
input \u_cmos_add/pixel_data[3] ;
input \u_cmos_add/pixel_data[2] ;
input \u_cmos_add/pixel_data[1] ;
input \u_cmos_add/pixel_data[0] ;
input \u_cmos_add/pixel_offset_flag ;
input \u_cmos_add/cam1_pixel_cnt[11] ;
input \u_cmos_add/cam1_pixel_cnt[10] ;
input \u_cmos_add/cam1_pixel_cnt[9] ;
input \u_cmos_add/cam1_pixel_cnt[8] ;
input \u_cmos_add/cam1_pixel_cnt[7] ;
input \u_cmos_add/cam1_pixel_cnt[6] ;
input \u_cmos_add/cam1_pixel_cnt[5] ;
input \u_cmos_add/cam1_pixel_cnt[4] ;
input \u_cmos_add/cam1_pixel_cnt[3] ;
input \u_cmos_add/cam1_pixel_cnt[2] ;
input \u_cmos_add/cam1_pixel_cnt[1] ;
input \u_cmos_add/cam1_pixel_cnt[0] ;
input \u_cmos_add/pixel_increase_flag ;
input \u_cmos_add/fifo_splicing_empty ;
input \u_cmos_add/u_fifo_splicing/RdEn ;
input sys_clk;
input tms_pad_i;
input tck_pad_i;
input tdi_pad_i;
output tdo_pad_o;

wire \u_cmos_add/cmos0_data[15] ;
wire \u_cmos_add/cmos0_data[14] ;
wire \u_cmos_add/cmos0_data[13] ;
wire \u_cmos_add/cmos0_data[12] ;
wire \u_cmos_add/cmos0_data[11] ;
wire \u_cmos_add/cmos0_data[10] ;
wire \u_cmos_add/cmos0_data[9] ;
wire \u_cmos_add/cmos0_data[8] ;
wire \u_cmos_add/cmos0_data[7] ;
wire \u_cmos_add/cmos0_data[6] ;
wire \u_cmos_add/cmos0_data[5] ;
wire \u_cmos_add/cmos0_data[4] ;
wire \u_cmos_add/cmos0_data[3] ;
wire \u_cmos_add/cmos0_data[2] ;
wire \u_cmos_add/cmos0_data[1] ;
wire \u_cmos_add/cmos0_data[0] ;
wire \u_cmos_add/cmos0_pclk ;
wire \u_cmos_add/cmos0_href ;
wire \u_cmos_add/cmos1_data[15] ;
wire \u_cmos_add/cmos1_data[14] ;
wire \u_cmos_add/cmos1_data[13] ;
wire \u_cmos_add/cmos1_data[12] ;
wire \u_cmos_add/cmos1_data[11] ;
wire \u_cmos_add/cmos1_data[10] ;
wire \u_cmos_add/cmos1_data[9] ;
wire \u_cmos_add/cmos1_data[8] ;
wire \u_cmos_add/cmos1_data[7] ;
wire \u_cmos_add/cmos1_data[6] ;
wire \u_cmos_add/cmos1_data[5] ;
wire \u_cmos_add/cmos1_data[4] ;
wire \u_cmos_add/cmos1_data[3] ;
wire \u_cmos_add/cmos1_data[2] ;
wire \u_cmos_add/cmos1_data[1] ;
wire \u_cmos_add/cmos1_data[0] ;
wire \u_cmos_add/cmos1_pclk ;
wire \u_cmos_add/cmos1_href ;
wire \u_cmos_add/pixel_href ;
wire \u_cmos_add/cmos0_data_splicing[15] ;
wire \u_cmos_add/cmos0_data_splicing[14] ;
wire \u_cmos_add/cmos0_data_splicing[13] ;
wire \u_cmos_add/cmos0_data_splicing[12] ;
wire \u_cmos_add/cmos0_data_splicing[11] ;
wire \u_cmos_add/cmos0_data_splicing[10] ;
wire \u_cmos_add/cmos0_data_splicing[9] ;
wire \u_cmos_add/cmos0_data_splicing[8] ;
wire \u_cmos_add/cmos0_data_splicing[7] ;
wire \u_cmos_add/cmos0_data_splicing[6] ;
wire \u_cmos_add/cmos0_data_splicing[5] ;
wire \u_cmos_add/cmos0_data_splicing[4] ;
wire \u_cmos_add/cmos0_data_splicing[3] ;
wire \u_cmos_add/cmos0_data_splicing[2] ;
wire \u_cmos_add/cmos0_data_splicing[1] ;
wire \u_cmos_add/cmos0_data_splicing[0] ;
wire \u_cmos_add/pixel_data[15] ;
wire \u_cmos_add/pixel_data[14] ;
wire \u_cmos_add/pixel_data[13] ;
wire \u_cmos_add/pixel_data[12] ;
wire \u_cmos_add/pixel_data[11] ;
wire \u_cmos_add/pixel_data[10] ;
wire \u_cmos_add/pixel_data[9] ;
wire \u_cmos_add/pixel_data[8] ;
wire \u_cmos_add/pixel_data[7] ;
wire \u_cmos_add/pixel_data[6] ;
wire \u_cmos_add/pixel_data[5] ;
wire \u_cmos_add/pixel_data[4] ;
wire \u_cmos_add/pixel_data[3] ;
wire \u_cmos_add/pixel_data[2] ;
wire \u_cmos_add/pixel_data[1] ;
wire \u_cmos_add/pixel_data[0] ;
wire \u_cmos_add/pixel_offset_flag ;
wire \u_cmos_add/cam1_pixel_cnt[11] ;
wire \u_cmos_add/cam1_pixel_cnt[10] ;
wire \u_cmos_add/cam1_pixel_cnt[9] ;
wire \u_cmos_add/cam1_pixel_cnt[8] ;
wire \u_cmos_add/cam1_pixel_cnt[7] ;
wire \u_cmos_add/cam1_pixel_cnt[6] ;
wire \u_cmos_add/cam1_pixel_cnt[5] ;
wire \u_cmos_add/cam1_pixel_cnt[4] ;
wire \u_cmos_add/cam1_pixel_cnt[3] ;
wire \u_cmos_add/cam1_pixel_cnt[2] ;
wire \u_cmos_add/cam1_pixel_cnt[1] ;
wire \u_cmos_add/cam1_pixel_cnt[0] ;
wire \u_cmos_add/pixel_increase_flag ;
wire \u_cmos_add/fifo_splicing_empty ;
wire \u_cmos_add/u_fifo_splicing/RdEn ;
wire sys_clk;
wire tms_pad_i;
wire tck_pad_i;
wire tdi_pad_i;
wire tdo_pad_o;
wire tms_i_c;
wire tck_i_c;
wire tdi_i_c;
wire tdo_o_c;
wire [9:0] control0;
wire gao_jtag_tck;
wire gao_jtag_reset;
wire run_test_idle_er1;
wire run_test_idle_er2;
wire shift_dr_capture_dr;
wire update_dr;
wire pause_dr;
wire enable_er1;
wire enable_er2;
wire gao_jtag_tdi;
wire tdo_er1;

IBUF tms_ibuf (
    .I(tms_pad_i),
    .O(tms_i_c)
);

IBUF tck_ibuf (
    .I(tck_pad_i),
    .O(tck_i_c)
);

IBUF tdi_ibuf (
    .I(tdi_pad_i),
    .O(tdi_i_c)
);

OBUF tdo_obuf (
    .I(tdo_o_c),
    .O(tdo_pad_o)
);

GW_JTAG  u_gw_jtag(
    .tms_pad_i(tms_i_c),
    .tck_pad_i(tck_i_c),
    .tdi_pad_i(tdi_i_c),
    .tdo_pad_o(tdo_o_c),
    .tck_o(gao_jtag_tck),
    .test_logic_reset_o(gao_jtag_reset),
    .run_test_idle_er1_o(run_test_idle_er1),
    .run_test_idle_er2_o(run_test_idle_er2),
    .shift_dr_capture_dr_o(shift_dr_capture_dr),
    .update_dr_o(update_dr),
    .pause_dr_o(pause_dr),
    .enable_er1_o(enable_er1),
    .enable_er2_o(enable_er2),
    .tdi_o(gao_jtag_tdi),
    .tdo_er1_i(tdo_er1),
    .tdo_er2_i(1'b0)
);

gw_con_top  u_icon_top(
    .tck_i(gao_jtag_tck),
    .tdi_i(gao_jtag_tdi),
    .tdo_o(tdo_er1),
    .rst_i(gao_jtag_reset),
    .control0(control0[9:0]),
    .enable_i(enable_er1),
    .shift_dr_capture_dr_i(shift_dr_capture_dr),
    .update_dr_i(update_dr)
);

ao_top u_ao_top(
    .control(control0[9:0]),
    .data_i({\u_cmos_add/cmos0_data[15] ,\u_cmos_add/cmos0_data[14] ,\u_cmos_add/cmos0_data[13] ,\u_cmos_add/cmos0_data[12] ,\u_cmos_add/cmos0_data[11] ,\u_cmos_add/cmos0_data[10] ,\u_cmos_add/cmos0_data[9] ,\u_cmos_add/cmos0_data[8] ,\u_cmos_add/cmos0_data[7] ,\u_cmos_add/cmos0_data[6] ,\u_cmos_add/cmos0_data[5] ,\u_cmos_add/cmos0_data[4] ,\u_cmos_add/cmos0_data[3] ,\u_cmos_add/cmos0_data[2] ,\u_cmos_add/cmos0_data[1] ,\u_cmos_add/cmos0_data[0] ,\u_cmos_add/cmos0_pclk ,\u_cmos_add/cmos0_href ,\u_cmos_add/cmos1_data[15] ,\u_cmos_add/cmos1_data[14] ,\u_cmos_add/cmos1_data[13] ,\u_cmos_add/cmos1_data[12] ,\u_cmos_add/cmos1_data[11] ,\u_cmos_add/cmos1_data[10] ,\u_cmos_add/cmos1_data[9] ,\u_cmos_add/cmos1_data[8] ,\u_cmos_add/cmos1_data[7] ,\u_cmos_add/cmos1_data[6] ,\u_cmos_add/cmos1_data[5] ,\u_cmos_add/cmos1_data[4] ,\u_cmos_add/cmos1_data[3] ,\u_cmos_add/cmos1_data[2] ,\u_cmos_add/cmos1_data[1] ,\u_cmos_add/cmos1_data[0] ,\u_cmos_add/cmos1_pclk ,\u_cmos_add/cmos1_href ,\u_cmos_add/pixel_href ,\u_cmos_add/cmos0_data_splicing[15] ,\u_cmos_add/cmos0_data_splicing[14] ,\u_cmos_add/cmos0_data_splicing[13] ,\u_cmos_add/cmos0_data_splicing[12] ,\u_cmos_add/cmos0_data_splicing[11] ,\u_cmos_add/cmos0_data_splicing[10] ,\u_cmos_add/cmos0_data_splicing[9] ,\u_cmos_add/cmos0_data_splicing[8] ,\u_cmos_add/cmos0_data_splicing[7] ,\u_cmos_add/cmos0_data_splicing[6] ,\u_cmos_add/cmos0_data_splicing[5] ,\u_cmos_add/cmos0_data_splicing[4] ,\u_cmos_add/cmos0_data_splicing[3] ,\u_cmos_add/cmos0_data_splicing[2] ,\u_cmos_add/cmos0_data_splicing[1] ,\u_cmos_add/cmos0_data_splicing[0] ,\u_cmos_add/pixel_data[15] ,\u_cmos_add/pixel_data[14] ,\u_cmos_add/pixel_data[13] ,\u_cmos_add/pixel_data[12] ,\u_cmos_add/pixel_data[11] ,\u_cmos_add/pixel_data[10] ,\u_cmos_add/pixel_data[9] ,\u_cmos_add/pixel_data[8] ,\u_cmos_add/pixel_data[7] ,\u_cmos_add/pixel_data[6] ,\u_cmos_add/pixel_data[5] ,\u_cmos_add/pixel_data[4] ,\u_cmos_add/pixel_data[3] ,\u_cmos_add/pixel_data[2] ,\u_cmos_add/pixel_data[1] ,\u_cmos_add/pixel_data[0] ,\u_cmos_add/pixel_offset_flag ,\u_cmos_add/cam1_pixel_cnt[11] ,\u_cmos_add/cam1_pixel_cnt[10] ,\u_cmos_add/cam1_pixel_cnt[9] ,\u_cmos_add/cam1_pixel_cnt[8] ,\u_cmos_add/cam1_pixel_cnt[7] ,\u_cmos_add/cam1_pixel_cnt[6] ,\u_cmos_add/cam1_pixel_cnt[5] ,\u_cmos_add/cam1_pixel_cnt[4] ,\u_cmos_add/cam1_pixel_cnt[3] ,\u_cmos_add/cam1_pixel_cnt[2] ,\u_cmos_add/cam1_pixel_cnt[1] ,\u_cmos_add/cam1_pixel_cnt[0] ,\u_cmos_add/pixel_increase_flag ,\u_cmos_add/fifo_splicing_empty ,\u_cmos_add/u_fifo_splicing/RdEn }),
    .clk_i(sys_clk)
);

endmodule
