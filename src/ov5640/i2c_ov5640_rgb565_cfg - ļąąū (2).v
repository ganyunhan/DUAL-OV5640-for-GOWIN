//****************************************Copyright (c)***********************************//
//技术支持：www.openedv.com
//淘宝店铺：http://openedv.taobao.com 
//关注微信公众平台微信号："正点原子"，免费获取FPGA & STM32资料。
//版权所有，盗版必究。
//Copyright(C) 正点原子 2018-2028
//All rights reserved                               
//----------------------------------------------------------------------------------------
// File name:           i2c_ov5640_rgb565_cfg
// Last modified Date:  2018/11/2 14:26:05
// Last Version:        V1.0
// Descriptions:        i2c配置
//----------------------------------------------------------------------------------------
// Created by:          正点原子
// Created date:        2018/3/21 14:26:05
// Version:             V1.0
// Descriptions:        The original version
//
//----------------------------------------------------------------------------------------
//****************************************************************************************//

module i2c_ov5640_rgb565_cfg
   (  
    input                clk      ,     //时钟信号
    input                rst_n    ,     //复位信号，低电平有效
    
    input        [7:0]   i2c_data_r,    //I2C读出的数据
    input                i2c_done ,     //I2C寄存器配置完成信号
    input        [12:0]  cmos_h_pixel ,
    input        [12:0]  cmos_v_pixel ,
    input        [12:0]  total_h_pixel, //水平总像素大小
    input        [12:0]  total_v_pixel, //垂直总像素大小
    output  reg          i2c_exec ,     //I2C触发执行信号   
    output  reg  [23:0]  i2c_data ,     //I2C要配置的地址与数据(高16位地址,低8位数据)
    output  reg          i2c_rh_wl,     //I2C读写控制信号
    output  reg          init_done      //初始化完成信号
    );

//parameter define
localparam  REG_NUM = 9'd250  ;       //总共需要配置的寄存器个数

//reg define
reg   [12:0]   start_init_cnt;        //等待延时计数器
reg    [8:0]   init_reg_cnt  ;        //寄存器配置个数计数器

//*****************************************************
//**                    main code
//*****************************************************

//clk时钟配置成250khz,周期为4us 5000*4us = 20ms
//OV5640上电到开始配置IIC至少等待20ms
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        start_init_cnt <= 13'b0;
    else if(start_init_cnt < 13'd5000) begin
        start_init_cnt <= start_init_cnt + 1'b1;                    
    end
end

//寄存器配置个数计数    
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        init_reg_cnt <= 8'd0;
    else if(i2c_exec)   
        init_reg_cnt <= init_reg_cnt + 8'b1;
end

//i2c触发执行信号   
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        i2c_exec <= 1'b0;
    else if(start_init_cnt == 13'd4999)
        i2c_exec <= 1'b1;
    else if(i2c_done && (init_reg_cnt < REG_NUM))
        i2c_exec <= 1'b1;
    else
        i2c_exec <= 1'b0;
end 

//配置I2C读写控制信号
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        i2c_rh_wl <= 1'b1;
    else if(init_reg_cnt == 8'd2)  
        i2c_rh_wl <= 1'b0;  
end

//初始化完成信号
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        init_done <= 1'b0;
    else if((init_reg_cnt == REG_NUM) && i2c_done)  
        init_done <= 1'b1;  
end

//配置寄存器地址与数据
always @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        i2c_data <= 24'b0;
    else begin
        case(init_reg_cnt)
             0:i2c_data<=24'h310311;// system clock from pad, bit[1]
             1:i2c_data<=24'h300882;// software reset, bit[7]// delay 5ms 
             2:i2c_data<=24'h300842;// software power down, bit[6]
             3:i2c_data<=24'h310303;// system clock from PLL, bit[1]
             4:i2c_data<=24'h3017ff;// FREX, Vsync, HREF, PCLK, D[9:6] output enable
             5:i2c_data<=24'h3018ff;// D[5:0], GPIO[1:0] output enable
             6:i2c_data<=24'h30341A;// MIPI 10-bit
             7:i2c_data<=24'h303713;// PLL root divider, bit[4], PLL pre-divider, bit[3:0]
             8:i2c_data<=24'h310801;// PCLK root divider, bit[5:4], SCLK2x root divider, bit[3:2] // SCLK root divider, bit[1:0] 
             9:i2c_data<=24'h363036;
             10:i2c_data<=24'h36310e;
             11:i2c_data<=24'h3632e2;
             12:i2c_data<=24'h363312;
             13:i2c_data<=24'h3621e0;
             14:i2c_data<=24'h3704a0;
             15:i2c_data<=24'h37035a;
             16:i2c_data<=24'h371578;
             17:i2c_data<=24'h371701;
             18:i2c_data<=24'h370b60;
             19:i2c_data<=24'h37051a;
             20:i2c_data<=24'h390502;
             21:i2c_data<=24'h390610;
             22:i2c_data<=24'h39010a;
             23:i2c_data<=24'h373112;
             24:i2c_data<=24'h360008;// VCM control
             25:i2c_data<=24'h360133;// VCM control
             26:i2c_data<=24'h302d60;// system control
             27:i2c_data<=24'h362052;
             28:i2c_data<=24'h371b20;
             29:i2c_data<=24'h471c50;
             30:i2c_data<=24'h3a1343;// pre-gain = 1.047x
             31:i2c_data<=24'h3a1800;// gain ceiling
             32:i2c_data<=24'h3a19f8;// gain ceiling = 15.5x
             33:i2c_data<=24'h363513;
             34:i2c_data<=24'h363603;
             35:i2c_data<=24'h363440;
             36:i2c_data<=24'h362201; // 50/60Hz detection     50/60Hz 灯光条纹过滤
             37:i2c_data<=24'h3c0134;// Band auto, bit[7]
             38:i2c_data<=24'h3c0428;// threshold low sum	 
             39:i2c_data<=24'h3c0598;// threshold high sum
             40:i2c_data<=24'h3c0600;// light meter 1 threshold[15:8]
             41:i2c_data<=24'h3c0708;// light meter 1 threshold[7:0]
             42:i2c_data<=24'h3c0800;// light meter 2 threshold[15:8]
             43:i2c_data<=24'h3c091c;// light meter 2 threshold[7:0]
             44:i2c_data<=24'h3c0a9c;// sample number[15:8]
             45:i2c_data<=24'h3c0b40;// sample number[7:0]
             46:i2c_data<=24'h381000;// Timing Hoffset[11:8]
             47:i2c_data<=24'h381110;// Timing Hoffset[7:0]
             48:i2c_data<=24'h381200;// Timing Voffset[10:8] 
             49:i2c_data<=24'h370864;
             50:i2c_data<=24'h400102;// BLC start from line 2
             51:i2c_data<=24'h40051a;// BLC always update
             52:i2c_data<=24'h300000;// enable blocks
             53:i2c_data<=24'h3004ff;// enable clocks 
             54:i2c_data<=24'h300e58;// MIPI power down, DVP enable
             55:i2c_data<=24'h302e00;
             56:i2c_data<=24'h430060;// RGB565
             57:i2c_data<=24'h501f01;// ISP RGB 
             58:i2c_data<=24'h440e00;
             59:i2c_data<=24'h5000a7; // Lenc on, raw gamma on, BPC on, WPC on, CIP on // AEC target    自动曝光控制
             60:i2c_data<=24'h3a0f30;// stable range in high
             61:i2c_data<=24'h3a1028;// stable range in low
             62:i2c_data<=24'h3a1b30;// stable range out high
             63:i2c_data<=24'h3a1e26;// stable range out low
             64:i2c_data<=24'h3a1160;// fast zone high
             65:i2c_data<=24'h3a1f14;// fast zone low// Lens correction for ?   镜头补偿
             66:i2c_data<=24'h580023;
             67:i2c_data<=24'h580114;
             68:i2c_data<=24'h58020f;
             69:i2c_data<=24'h58030f;
             70:i2c_data<=24'h580412;
             71:i2c_data<=24'h580526;
             72:i2c_data<=24'h58060c;
             73:i2c_data<=24'h580708;
             74:i2c_data<=24'h580805;
             75:i2c_data<=24'h580905;
             76:i2c_data<=24'h580a08;
             77:i2c_data<=24'h580b0d;
             78:i2c_data<=24'h580c08;
             79:i2c_data<=24'h580d03;
             80:i2c_data<=24'h580e00;
             81:i2c_data<=24'h580f00;
             82:i2c_data<=24'h581003;
             83:i2c_data<=24'h581109;
             84:i2c_data<=24'h581207;
             85:i2c_data<=24'h581303;
             86:i2c_data<=24'h581400;
             87:i2c_data<=24'h581501;
             88:i2c_data<=24'h581603;
             89:i2c_data<=24'h581708;
             90:i2c_data<=24'h58180d;
             91:i2c_data<=24'h581908;
             92:i2c_data<=24'h581a05;
             93:i2c_data<=24'h581b06;
             94:i2c_data<=24'h581c08;
             95:i2c_data<=24'h581d0e;
             96:i2c_data<=24'h581e29;
             97:i2c_data<=24'h581f17;
             98:i2c_data<=24'h582011;
             99:i2c_data<=24'h582111;
             100:i2c_data<=24'h582215;
             101:i2c_data<=24'h582328;
             102:i2c_data<=24'h582446;
             103:i2c_data<=24'h582526;
             104:i2c_data<=24'h582608;
             105:i2c_data<=24'h582726;
             106:i2c_data<=24'h582864;
             107:i2c_data<=24'h582926;
             108:i2c_data<=24'h582a24;
             109:i2c_data<=24'h582b22;
             110:i2c_data<=24'h582c24;
             111:i2c_data<=24'h582d24;
             112:i2c_data<=24'h582e06;
             113:i2c_data<=24'h582f22;
             114:i2c_data<=24'h583040;
             115:i2c_data<=24'h583142;
             116:i2c_data<=24'h583224;
             117:i2c_data<=24'h583326;
             118:i2c_data<=24'h583424;
             119:i2c_data<=24'h583522;
             120:i2c_data<=24'h583622;
             121:i2c_data<=24'h583726;
             122:i2c_data<=24'h583844;
             123:i2c_data<=24'h583924;
             124:i2c_data<=24'h583a26;
             125:i2c_data<=24'h583b28;
             126:i2c_data<=24'h583c42;
             127:i2c_data<=24'h583dce;// lenc BR offset // AWB   自动白平衡
             128:i2c_data<=24'h5180ff;// AWB B block
             129:i2c_data<=24'h5181f2;// AWB control 
             130:i2c_data<=24'h518200;// [7:4] max local counter, [3:0] max fast counter
             131:i2c_data<=24'h518314;// AWB advanced 
             132:i2c_data<=24'h518425;
             133:i2c_data<=24'h518524;
             134:i2c_data<=24'h518609;
             135:i2c_data<=24'h518709;
             136:i2c_data<=24'h518809;
             137:i2c_data<=24'h518975;
             138:i2c_data<=24'h518a54;
             139:i2c_data<=24'h518be0;
             140:i2c_data<=24'h518cb2;
             141:i2c_data<=24'h518d42;
             142:i2c_data<=24'h518e3d;
             143:i2c_data<=24'h518f56;
             144:i2c_data<=24'h519046;
             145:i2c_data<=24'h5191f8;// AWB top limit
             146:i2c_data<=24'h519204;// AWB bottom limit
             147:i2c_data<=24'h519370;// red limit
             148:i2c_data<=24'h5194f0;// green limit
             149:i2c_data<=24'h5195f0;// blue limit
             150:i2c_data<=24'h519603;// AWB control
             151:i2c_data<=24'h519701;// local limit 
             152:i2c_data<=24'h519804;
             153:i2c_data<=24'h519912;
             154:i2c_data<=24'h519a04;
             155:i2c_data<=24'h519b00;
             156:i2c_data<=24'h519c06;
             157:i2c_data<=24'h519d82;
             158:i2c_data<=24'h519e38;// AWB control // Gamma    伽玛曲线
             159:i2c_data<=24'h548001;// Gamma bias plus on, bit[0] 
             160:i2c_data<=24'h548108;
             161:i2c_data<=24'h548214;
             162:i2c_data<=24'h548328;
             163:i2c_data<=24'h548451;
             164:i2c_data<=24'h548565;
             165:i2c_data<=24'h548671;
             166:i2c_data<=24'h54877d;
             167:i2c_data<=24'h548887;
             168:i2c_data<=24'h548991;
             169:i2c_data<=24'h548a9a;
             170:i2c_data<=24'h548baa;
             171:i2c_data<=24'h548cb8;
             172:i2c_data<=24'h548dcd;
             173:i2c_data<=24'h548edd;
             174:i2c_data<=24'h548fea;
             175:i2c_data<=24'h54901d;// color matrix   色彩矩阵
             176:i2c_data<=24'h53811e;// CMX1 for Y
             177:i2c_data<=24'h53825b;// CMX2 for Y
             178:i2c_data<=24'h538308;// CMX3 for Y
             179:i2c_data<=24'h53840a;// CMX4 for U
             180:i2c_data<=24'h53857e;// CMX5 for U
             181:i2c_data<=24'h538688;// CMX6 for U
             182:i2c_data<=24'h53877c;// CMX7 for V
             183:i2c_data<=24'h53886c;// CMX8 for V
             184:i2c_data<=24'h538910;// CMX9 for V
             185:i2c_data<=24'h538a01;// sign[9]
             186:i2c_data<=24'h538b98; // sign[8:1] // UV adjust   UV色彩饱和度调整
             187:i2c_data<=24'h558006;// saturation on, bit[1]
             188:i2c_data<=24'h558340;
             189:i2c_data<=24'h558410;
             190:i2c_data<=24'h558910;
             191:i2c_data<=24'h558a00;
             192:i2c_data<=24'h558bf8;
             193:i2c_data<=24'h501d40;// enable manual offset of contrast// CIP  锐化和降噪 
             194:i2c_data<=24'h530008;// CIP sharpen MT threshold 1
             195:i2c_data<=24'h530130;// CIP sharpen MT threshold 2
             196:i2c_data<=24'h530210;// CIP sharpen MT offset 1
             197:i2c_data<=24'h530300;// CIP sharpen MT offset 2
             198:i2c_data<=24'h530408;// CIP DNS threshold 1
             199:i2c_data<=24'h530530;// CIP DNS threshold 2
             200:i2c_data<=24'h530608;// CIP DNS offset 1
             201:i2c_data<=24'h530716;// CIP DNS offset 2 
             202:i2c_data<=24'h530908;// CIP sharpen TH threshold 1
             203:i2c_data<=24'h530a30;// CIP sharpen TH threshold 2
             204:i2c_data<=24'h530b04;// CIP sharpen TH offset 1
             205:i2c_data<=24'h530c06;// CIP sharpen TH offset 2
             206:i2c_data<=24'h502500;
             207:i2c_data<=24'h300802; // wake up from standby, bit[6]
             //set OV5640 to video mode 720p 
             208:i2c_data<=24'h303521;// PLL     input clock =24Mhz, PCLK =84Mhz
             209:i2c_data<=24'h303669;// PLL
             210:i2c_data<=24'h3c0707; // lightmeter 1 threshold[7:0]
             211:i2c_data<=24'h382041; // flip
             212:i2c_data<=24'h382107; // mirror
             213:i2c_data<=24'h381431; // timing X inc
             214:i2c_data<=24'h381531; // timing Y inc
             215:i2c_data<=24'h380000; // HS
             216:i2c_data<=24'h380100; // HS
             217:i2c_data<=24'h380200; // VS
             218:i2c_data<=24'h3803fa; // VS
             219:i2c_data<=24'h38040a; // HW (HE)
             220:i2c_data<=24'h38053f; // HW (HE)
             221:i2c_data<=24'h380606; // VH (VE)
             222:i2c_data<=24'h3807a9; // VH (VE)
             223:i2c_data<=24'h380805; // DVPHO     (1024)
             224:i2c_data<=24'h380900; // DVPHO     (1024)
             225:i2c_data<=24'h380a02; // DVPVO     (720)->
             226:i2c_data<=24'h380bd0; // DVPVO     (720)->
             227:i2c_data<=24'h380c07; // HTS
             228:i2c_data<=24'h380d64; // HTS
             229:i2c_data<=24'h380e02; // VTS
             230:i2c_data<=24'h380fe4; // VTS
             231:i2c_data<=24'h381304; // timing V offset
             232:i2c_data<=24'h361800;
             233:i2c_data<=24'h361229;
             234:i2c_data<=24'h370952;
             235:i2c_data<=24'h370c03;
             236:i2c_data<=24'h3a0202; // 60Hz max exposure
             237:i2c_data<=24'h3a03e0; // 60Hz max exposure
             238:i2c_data<=24'h3a1402; // 50Hz max exposure
             239:i2c_data<=24'h3a15e0; // 50Hz max exposure
             240:i2c_data<=24'h400402; // BLC line number
             241:i2c_data<=24'h30021c; // reset JFIFO, SFIFO, JPG
             242:i2c_data<=24'h3006c3; // disable clock of JPEG2x, JPEG
             243:i2c_data<=24'h471303; // JPEG mode 3
             244:i2c_data<=24'h440704; // Quantization sacle
             245:i2c_data<=24'h460b37;
             246:i2c_data<=24'h460c20;
             247:i2c_data<=24'h483716; // MIPI global timing
             248:i2c_data<=24'h382404; // PCLK manual divider
             249:i2c_data<=24'h500183; // SDE on, CMX on, AWB on, scale on
             250:i2c_data<=24'h350300; // AEC/AGC on 
             //302:i2c_data<=24'h503d80;            //i2c_data<=24'h503d80; test pattern selection control, 80:color bar,00: test disable
             //303:i2c_data<=24'h474101;            //i2c_data<=24'h47401; test pattern enable, Test pattern 8-bit	 
             default:i2c_data<=24'h000000;
        endcase
    end
end

endmodule