//Copyright (C)2014-2021 GOWIN Semiconductor Corporation.
//All rights reserved.
//File Title: Timing Constraints file
//GOWIN Version: 1.9.8 
//Created Time: 2021-11-11 20:26:25
create_clock -name sys_clk -period 20 -waveform {0 10} [get_ports {sys_clk}] -add
create_clock -name SWCLK -period 200 -waveform {0 100} [get_ports {SWCLK}] -add
