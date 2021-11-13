//Copyright (C)2014-2021 GOWIN Semiconductor Corporation.
//All rights reserved.
//File Title: Timing Constraints file
//GOWIN Version: 1.9.8 
//Created Time: 2021-11-13 18:54:24
create_clock -name SWCLK -period 200 -waveform {0 100} [get_ports {SWCLK}] -add
create_clock -name sys_clk -period 20 -waveform {0 5} [get_ports {sys_clk}] -add
