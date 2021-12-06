//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.8
//Part Number: GW2A-LV55PG484C8/I7
//Device: GW2A-55
//Created Time: Mon Nov 29 12:52:10 2021

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    hdmi_rpll your_instance_name(
        .clkout(clkout_o), //output clkout
        .lock(lock_o), //output lock
        .clkin(clkin_i) //input clkin
    );

//--------Copy end-------------------
