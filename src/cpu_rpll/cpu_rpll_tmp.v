//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.8
//Part Number: GW2A-LV55PG484C8/I7
//Device: GW2A-55C
//Created Time: Sat Nov 13 18:35:38 2021

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    cpu_rpll your_instance_name(
        .clkout(clkout_o), //output clkout
        .reset(reset_i), //input reset
        .clkin(clkin_i) //input clkin
    );

//--------Copy end-------------------
