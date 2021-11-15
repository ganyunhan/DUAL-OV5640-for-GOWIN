# DUAL-OV5640-for-GOWIN

GoWin GW2A-55K Combat开发板，OV5460的双摄像头拼接和融合项目

A dual-camera-fusion project based on OminiVison 5460 for GoWin GW2A-55K Combat Board

2021年FPGA创新设计竞赛作品，实现了双OV5640图像的采集、拼接和融合，同时塞了一个Cortex-M3软核来当控制器。Cortex-M3上跑了个简单的串口命令行作为HMI，之后再加freertos用上真正的CLI。

后期将会把图像处理的所有模块打包成apb外设，利用软核操作寄存器改变融合所需参数。

Bilibili演示视频：[【2021FPGA创新设计竞赛】高云FPGA：Cortex-M3软核+双目摄像头采集处理系统](https://www.bilibili.com/video/BV1UU4y1M7dq)

## 系统架构

 [![IRSeat.jpg](https://z3.ax1x.com/2021/11/15/IRSeat.jpg)](https://imgtu.com/i/IRSeat)

## Cortex-M3软核(还没完全完工)

 半小时写出来的伪CLI

 [![IRpgmj.png](https://z3.ax1x.com/2021/11/15/IRpgmj.png)](https://imgtu.com/i/IRpgmj)

## 感谢贡献者

除了本人之外，感谢队友[@Baymaxly](https://github.com/Baymaxly)和[@TwinkleXL](https://github.com/TwinkleXL)一起熬夜一起抓信号一起完善整个作品

p.s.高云这个Cortex-M3的Core sight调试端口有bug，如果开启Core sight Debug模式，串口接收到一定量的消息后会把PC指针指回初始地址。但它是个黑箱子我也没法查出原因