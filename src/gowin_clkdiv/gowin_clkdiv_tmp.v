//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.8
//Part Number: GW2A-LV55PG484C8/I7
//Device: GW2A-55
//Created Time: Tue Oct 19 20:08:56 2021

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    Gowin_CLKDIV your_instance_name(
        .clkout(clkout_o), //output clkout
        .hclkin(hclkin_i), //input hclkin
        .resetn(resetn_i), //input resetn
        .calib(calib_i) //input calib
    );

//--------Copy end-------------------
