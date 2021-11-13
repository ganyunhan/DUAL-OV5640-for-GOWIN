; **************************************************************************************
; *
; 		(C) COPYRIGHT 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
; *
; * File Name	:	startup_GOWIN_M3.s
; * Author		:	Embedded Development Team
; * Version		:	V1.0.0
; * Date		:	2020-4-1 09:00:00
; * Description	:	Gowin_EMPU_M3 Devices vector table for ARM toolchain
; *					This module performs:
; *					- Set the initial SP
; *					- Set the initial PC == Reset_Handler
; *					- Set the vector table entries with exceptions ISR address
; *					- Configure the system clock
; *					- Branches to __main in the C library(which eventually calls main())
; *					After Reset the Cortex-M3 processor is in Thread mode,
; *					priority is Privileged and the Stach is set to Main
; *
; * <<< Use Configuration Wizard in Context Menu >>>
; *
; ****************************************************************************************

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00001000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00001000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; -14 NMI Handler
                DCD     HardFault_Handler         ; -13 Hard Fault Handler
                DCD     MemManage_Handler         ; -12 MPU Fault Handler
                DCD     BusFault_Handler          ; -11 Bus Fault Handler
                DCD     UsageFault_Handler        ; -10 Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; -5 SVCall Handler
                DCD     DebugMon_Handler          ; -4 Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; -2 PendSV Handler
                DCD     SysTick_Handler           ; -1 SysTick Handler

                ; External Peripherals Interrupts
                DCD      UART0_Handler            ; 0 UART0 Interrupt handler
                DCD      UART1_Handler            ; 1 UART1 Interrupt handler
                DCD      TIMER0_Handler           ; 2 TIMER0 Interrupt handler
                DCD      TIMER1_Handler           ; 3 TIMER1 Interrupt handler
                DCD      GPIO0_Handler            ; 4 GPIO0 Interrupt handler
                DCD      UARTOVF_Handler          ; 5 UART0,1 Overflow Interrupt handler
                DCD      RTC_Handler              ; 6 RTC Interrupt handler
                DCD      I2C_Handler              ; 7 I2C Interrupt handler
                DCD      Interrupt8_Handler       ; 8 Interrupt8 handler
                DCD      ENT_Handler              ; 9 Ethernet Interrupt handler
				DCD      Interrupt10_Handler      ; 10 Interrupt10 handler
				DCD      Interrupt11_Handler      ; 11 Interrupt11 handler
				DCD      Interrupt12_Handler      ; 12 Interrupt12 handler
				DCD      Interrupt13_Handler      ; 13 Interrupt13 handler
				DCD      Interrupt14_Handler      ; 14 Interrupt14 handler
				DCD      Interrupt15_Handler      ; 15 Interrupt15 handler
				DCD      GPIO0_0_Handler          ; 16 GPIO0_0 Interrupt handler
				DCD      GPIO0_1_Handler          ; 17 GPIO0_1 Interrupt handler
				DCD      GPIO0_2_Handler          ; 18 GPIO0_2 Interrupt handler
				DCD      GPIO0_3_Handler          ; 19 GPIO0_3 Interrupt handler
				DCD      GPIO0_4_Handler          ; 20 GPIO0_4 Interrupt handler
				DCD      GPIO0_5_Handler          ; 21 GPIO0_5 Interrupt handler
				DCD      GPIO0_6_Handler          ; 22 GPIO0_6 Interrupt handler
				DCD      GPIO0_7_Handler          ; 23 GPIO0_7 Interrupt handler
				DCD      GPIO0_8_Handler          ; 24 GPIO0_8 Interrupt handler
				DCD      GPIO0_9_Handler          ; 25 GPIO0_9 Interrupt handler
				DCD      GPIO0_10_Handler         ; 26 GPIO0_10 Interrupt handler
				DCD      GPIO0_11_Handler         ; 27 GPIO0_11 Interrupt handler
				DCD      GPIO0_12_Handler         ; 28 GPIO0_12 Interrupt handler
				DCD      GPIO0_13_Handler         ; 29 GPIO0_13 Interrupt handler
				DCD      GPIO0_14_Handler         ; 30 GPIO0_14 Interrupt handler
				DCD      GPIO0_15_Handler         ; 31 GPIO0_15 Interrupt handler
				DCD      USER_INT0_Handler        ; 32 USER_INT0 Interrupt handler
				DCD      USER_INT1_Handler        ; 33 USER_INT1 Interrupt handler
				DCD      USER_INT2_Handler        ; 34 USER_INT2 Interrupt handler
				DCD      USER_INT3_Handler        ; 35 USER_INT3 Interrupt handler
				DCD      USER_INT4_Handler        ; 36 USER_INT4 Interrupt handler
				DCD      USER_INT5_Handler        ; 37 USER_INT5 Interrupt handler
				DCD      USER_INT6_Handler        ; 38 USER_INT6 Interrupt handler
				DCD      USER_INT7_Handler        ; 39 USER_INT7 Interrupt handler
				DCD      USER_INT8_Handler        ; 40 USER_INT8 Interrupt handler
				DCD      USER_INT9_Handler        ; 41 USER_INT9 Interrupt handler
				DCD      USER_INT10_Handler       ; 42 USER_INT10 Interrupt handler
				DCD      USER_INT11_Handler       ; 43 USER_INT11 Interrupt handler
				DCD      USER_INT12_Handler       ; 44 USER_INT12 Interrupt handler
				DCD      USER_INT13_Handler       ; 45 USER_INT13 Interrupt handler
				DCD      USER_INT14_Handler       ; 46 USER_INT14 Interrupt handler
				DCD      USER_INT15_Handler       ; 47 USER_INT15 Interrupt handler
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler
; Branches to __main in the C library(which eventually calls main())
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT UART0_Handler              [WEAK]
                EXPORT UART1_Handler              [WEAK]
                EXPORT TIMER0_Handler             [WEAK]
                EXPORT TIMER1_Handler             [WEAK]
                EXPORT GPIO0_Handler              [WEAK]
                EXPORT UARTOVF_Handler            [WEAK]
                EXPORT RTC_Handler                [WEAK]
                EXPORT I2C_Handler                [WEAK]
                EXPORT Interrupt8_Handler         [WEAK]
                EXPORT ENT_Handler                [WEAK]
                EXPORT Interrupt10_Handler        [WEAK]
                EXPORT Interrupt11_Handler        [WEAK]
                EXPORT Interrupt12_Handler        [WEAK]
                EXPORT Interrupt13_Handler        [WEAK]
                EXPORT Interrupt14_Handler        [WEAK]
                EXPORT Interrupt15_Handler        [WEAK]
                EXPORT GPIO0_0_Handler            [WEAK]
                EXPORT GPIO0_1_Handler            [WEAK]
                EXPORT GPIO0_2_Handler            [WEAK]
                EXPORT GPIO0_3_Handler            [WEAK]
                EXPORT GPIO0_4_Handler            [WEAK]
                EXPORT GPIO0_5_Handler            [WEAK]
                EXPORT GPIO0_6_Handler            [WEAK]
                EXPORT GPIO0_7_Handler            [WEAK]
                EXPORT GPIO0_8_Handler            [WEAK]
                EXPORT GPIO0_9_Handler            [WEAK]
				EXPORT GPIO0_10_Handler           [WEAK]
                EXPORT GPIO0_11_Handler           [WEAK]
                EXPORT GPIO0_12_Handler           [WEAK]
                EXPORT GPIO0_13_Handler           [WEAK]
                EXPORT GPIO0_14_Handler           [WEAK]
                EXPORT GPIO0_15_Handler           [WEAK]
                EXPORT USER_INT0_Handler          [WEAK]
                EXPORT USER_INT1_Handler          [WEAK]
                EXPORT USER_INT2_Handler          [WEAK]
                EXPORT USER_INT3_Handler          [WEAK]
                EXPORT USER_INT4_Handler          [WEAK]
                EXPORT USER_INT5_Handler          [WEAK]
                EXPORT USER_INT6_Handler          [WEAK]
                EXPORT USER_INT7_Handler          [WEAK]
                EXPORT USER_INT8_Handler          [WEAK]
                EXPORT USER_INT9_Handler          [WEAK]
                EXPORT USER_INT10_Handler         [WEAK]
                EXPORT USER_INT11_Handler         [WEAK]
                EXPORT USER_INT12_Handler         [WEAK]
                EXPORT USER_INT13_Handler         [WEAK]
                EXPORT USER_INT14_Handler         [WEAK]
                EXPORT USER_INT15_Handler         [WEAK]


UART0_Handler
UART1_Handler
TIMER0_Handler
TIMER1_Handler
GPIO0_Handler
UARTOVF_Handler
RTC_Handler
I2C_Handler
Interrupt8_Handler
ENT_Handler
Interrupt10_Handler
Interrupt11_Handler
Interrupt12_Handler
Interrupt13_Handler
Interrupt14_Handler
Interrupt15_Handler
GPIO0_0_Handler
GPIO0_1_Handler
GPIO0_2_Handler
GPIO0_3_Handler
GPIO0_4_Handler
GPIO0_5_Handler
GPIO0_6_Handler
GPIO0_7_Handler
GPIO0_8_Handler
GPIO0_9_Handler
GPIO0_10_Handler
GPIO0_11_Handler
GPIO0_12_Handler
GPIO0_13_Handler
GPIO0_14_Handler
GPIO0_15_Handler
USER_INT0_Handler
USER_INT1_Handler
USER_INT2_Handler
USER_INT3_Handler
USER_INT4_Handler
USER_INT5_Handler
USER_INT6_Handler
USER_INT7_Handler
USER_INT8_Handler
USER_INT9_Handler
USER_INT10_Handler
USER_INT11_Handler
USER_INT12_Handler
USER_INT13_Handler
USER_INT14_Handler
USER_INT15_Handler
                B       .

                ENDP


                ALIGN

;*******************************************************
; User Initial Stack and Heap
;*******************************************************

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END

;*************************GowinSemiconductor*****END OF FILE*********************
