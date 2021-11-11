//Copyright (C)2014-2021 GOWIN Semiconductor Corporation.
//All rights reserved.
//File Title: Timing Constraints file
//GOWIN Version: 1.9.8 Beta
//Created Time: 2021-07-16 15:42:03
create_clock -name SWCLK -period 200 -waveform {0 100} [get_ports {SWCLK}] -add
create_clock -name HCLK -period 20 -waveform {0 10} [get_ports {HCLK}] -add
