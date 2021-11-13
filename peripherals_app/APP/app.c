/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			app.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			Applications.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "app.h"
#include "GOWIN_M3_it.h"

/* Functions ------------------------------------------------------------------*/

/******************************** ahb2 application ***************************/
#ifdef AHB2_EXT_APP

//Declarations
static void setMultiplier(uint32_t multi);
static uint32_t getMultiplier(void);
static void setMultiplicand(uint32_t multi);
static uint32_t getMultiplicand(void);
static uint32_t getMultipleResult(void);
static void startMultiple(void);
static void finishMultiple(void);
static STATUS getFinishStatus(void);
static uint32_t getMultipleCmd(void);

void ahb2_ext_app(void)
{
	printf("System initialization finished.\r\n");
	printf("Uart initialization finished.\r\n");
	printf("Multiple initialization finished.\r\n");
	printf("Initialization Status : \r\n");
	printf("--MULTIPLIER = %d\r\n",getMultiplier());
	printf("--MULTIPLICAND = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());

	printf("Start first multiple\r\n");
	setMultiplier(20);
	setMultiplicand(40);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple first finished.\r\n");
	
	printf("Start second multiple\r\n");
	setMultiplier(30);
	setMultiplicand(50);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple second finished.\r\n");
	
  while(1);
}

static void setMultiplier(uint32_t multi)
{
	MULTIPLE->MULTIPLIER = multi & MUL_MULTIPLIER;
}

static uint32_t getMultiplier(void)
{
	return MULTIPLE->MULTIPLIER & MUL_MULTIPLIER;
}

static void setMultiplicand(uint32_t multi)
{
	MULTIPLE->MULTIPLICAND = multi & MUL_MULTIPLICAND;
}

static uint32_t getMultiplicand(void)
{
	return MULTIPLE->MULTIPLICAND & MUL_MULTIPLICAND;
}

static uint32_t getMultipleResult(void)
{
	return MULTIPLE->RESULT & MUL_RESULT;
}

static void startMultiple(void)
{
	MULTIPLE->CMD |= CMD_START;
}

static void finishMultiple(void)
{
	MULTIPLE->CMD = 0;
}

static uint32_t getMultipleCmd(void)
{
	return MULTIPLE->CMD;
}

static STATUS getFinishStatus(void)
{
	if(((MULTIPLE->CMD&STATUS_FINISHED)>>1))
	{
		return FINISHED_STATUS;
	}
	else
	{
		return NO_FINISHED_STATUS;
	}
}
	
#endif
/******************************** ahb2 application ***************************/

/******************************** apb2 application ***************************/
#ifdef APB2_EXT_APP

//Declarations
static void setMultiplier(uint32_t multi);
static uint32_t getMultiplier(void);
static void setMultiplicand(uint32_t multi);
static uint32_t getMultiplicand(void);
static uint32_t getMultipleResult(void);
static void startMultiple(void);
static void finishMultiple(void);
static STATUS getFinishStatus(void);
static uint32_t getMultipleCmd(void);

void apb2_ext_app(void)
{
	printf("System initialization finished.\r\n");
	printf("Uart initialization finished.\r\n");
	printf("Multiple initialization finished.\r\n");
	printf("Initialization Status : \r\n");
	printf("--MULTIPLIER = %d\r\n",getMultiplier());
	printf("--MULTIPLICAND = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());

	printf("Start first multiple\r\n");
	setMultiplier(20);
	setMultiplicand(40);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple first finished.\r\n");
	
	printf("Start second multiple\r\n");
	setMultiplier(30);
	setMultiplicand(50);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple second finished.\r\n");
	
  while(1);
}

static void setMultiplier(uint32_t multi)
{
	MULTIPLE->MULTIPLIER = multi & MUL_MULTIPLIER;
}

static uint32_t getMultiplier(void)
{
	return MULTIPLE->MULTIPLIER & MUL_MULTIPLIER;
}

static void setMultiplicand(uint32_t multi)
{
	MULTIPLE->MULTIPLICAND = multi & MUL_MULTIPLICAND;
}

static uint32_t getMultiplicand(void)
{
	return MULTIPLE->MULTIPLICAND & MUL_MULTIPLICAND;
}

static uint32_t getMultipleResult(void)
{
	return MULTIPLE->RESULT & MUL_RESULT;
}

static void startMultiple(void)
{
	MULTIPLE->CMD |= CMD_START;
}

static void finishMultiple(void)
{
	MULTIPLE->CMD = 0;
}

static uint32_t getMultipleCmd(void)
{
	return MULTIPLE->CMD;
}

static STATUS getFinishStatus(void)
{
	if(((MULTIPLE->CMD&STATUS_FINISHED)>>1))
	{
		return FINISHED_STATUS;
	}
	else
	{
		return NO_FINISHED_STATUS;
	}
}

#endif
/******************************** apb2 application ***************************/

/******************************** ddr3 application ***************************/
#ifdef DDR3_APP

//Variables
uint32_t write_data[6][4] = {
	{0x91234567, 0x89abcdef, 0xfedcba98, 0x76543210},
	{0x66666666, 0x88888888, 0xeeeeeeee, 0xffffffff},
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}, {13, 14, 15, 16}};
uint32_t read_data[6][4];

void ddr3_app(void)
{
	while(! (DDR3_Init() & 0x01));//Initialize DDR3
	
	unsigned int addr = 0x38;
	int i = 0, j = 0;
	
	//Write datas to DDR3 
	for(i = 0;i < 6;i++)
	{
		DDR3_Write(addr + i*8,write_data[i]);
	}
	
	while(1)
	{
	  //Read datas from DDR3
		for(i = 0;i < 6;i++)
		{
			DDR3_Read(addr + i*8,read_data[i]);
		}
	
		//Print datas to UART0
		for(i = 0;i < 6;i++)
		{
			for(j = 0;j < 4;j++)
			{
				printf("%x ",read_data[i][j]);
			}
			printf("\r\n");
		}
		printf("\r\n");
  }
}

#endif
/******************************** ddr3 application ***************************/

/******************************** ethernet application ***************************/
#ifdef ETHERNET_APP

//Macros
#define TX_LENTGH 72

//Variables
uint8_t  rx_data[1536];
uint8_t  tx_data[1536];
uint32_t rx_data_length = 0;
uint32_t miim_rd_data = 0;
uint32_t tx_length = TX_LENTGH;
extern NDS_DRIVER_ETH Driver_ETH;
uint8_t  tx_data[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
	0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
	0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88
};

//Declarations
static void EthernetInit(NDS_DRIVER_ETH *ETH_Dri);
static void Delay_ms(__IO uint32_t delay_ms);

void ethernet_app(void)
{
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
  NDS_DRIVER_ETH *ETH_Dri = &Driver_ETH;
	EthernetInit(ETH_Dri);//Initialize Ethernet

	//Enable Ethernet interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = ENT_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
  ETH_Dri->eth_set_mode(ETH_FULL_DUPLEX_1000M);	
  uint8_t  *tx_ptr = (uint8_t *)tx_data;
	
	printf("Waiting for Ethernet Interrupt Handler.\r\n");
  
  while(1)
  {
	  ETH_Dri->eth_tx(tx_ptr, tx_length);
	  Delay_ms(100);
  }
}

//delay ms
static void Delay_ms(__IO uint32_t delay_ms)
{
	for(delay_ms=(SystemCoreClock>>13)*delay_ms; delay_ms != 0; delay_ms--);
}

//Initialize Ethernet
static void EthernetInit(NDS_DRIVER_ETH *ETH_Dri)
{
  uint8_t  *rx_data_ptr = rx_data;
  uint32_t *rx_data_length_ptr = &rx_data_length;
  uint32_t *miim_rd_data_ptr = &miim_rd_data;
	
  ETH_Dri->init(rx_data_ptr, rx_data_length_ptr, miim_rd_data_ptr);
	
	printf("Ethernet Initialization.\r\n");
}

//Ethernet Interrupt Handler
void ENT_Handler(void)
{
	if(Ethernet->ETH_RX_IS)
	{
		printf("Enternet rx \n\r");
		Ethernet->ETH_RX_IE = 0;
		rx_int_event();
		Ethernet->ETH_RX_IE = 1;
	}
	else if(Ethernet->ETH_TX_IS)
	{
		printf("Enternet tx is %d \n\r",Ethernet->ETH_TX_IE);
		Ethernet->ETH_TX_IE = 0;
		tx_int_event();
		Ethernet->ETH_TX_IE = 1;
	}
	else if(Ethernet->MIIM_IS & 0x1)
	{
		printf("Enternet MIIM1 is %d\n\r",Ethernet->MIIM_IS&0x1);
		Ethernet->MIIM_IE = 0;
		miim_rd_int_event();
		Ethernet->MIIM_IE = 3;
	}
	else if(Ethernet->MIIM_IS & 0x2)
	{
		printf("Enternet MIIM2 is %d\n\r",Ethernet->MIIM_IS&0x2);
		Ethernet->MIIM_IE = 0;
		miim_wr_int_event();
		Ethernet->MIIM_IE = 3;
	}
}

#endif
/******************************** ethernet application ***************************/

/******************************** i2c application ***************************/
#ifdef I2C_APP

//Variables
int temp_add = 0;

void i2c_app(void)
{
	unsigned char Temp1[100];
	unsigned char receive1[100];
	uint32_t i;
	
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
	I2C_Init(I2C,400);//Initialized I2C
	
	for(i=0;i<100;i++)
	{
		Temp1[i] =i;
	}
	
	//Enable I2C interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = I2C_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
	I2C_InterruptOpen(I2C);
	
	//I2C sends bytes
	printf("I2C Master sends data to slave.\r\n");
	I2C_SendBytes(I2C ,0x50,0x00,Temp1, 30);
	for(i=0;i<100;i++)
	{
		printf("%x ",Temp1[i]);
		if(i%8 == 0)
		{
			printf("\r\n");
		}
	}
	printf("\r\n");
	
	//I2C receives bytes
	printf("I2C Master receives data from slave.\r\n");
	I2C_ReadBytes(I2C,0x50,0x00,receive1,30);
	for(i=0;i<100;i++)
	{
		printf("%x ",receive1[i]);
		if(i%8 == 0)
		{
			printf("\r\n");
		}
	}
	printf("\r\n");
	
	printf("Waiting for I2C interrupt handler.\r\n");
	
	while(1);
}

//I2C Interrupt Handler
void I2C_Handler(void)
{
	if(~(I2C->SR &I2C_SR_TIP))//Translate Over
	{
		temp_add ++;
		UART_SendChar(UART0,temp_add);	
	}
	
	I2C->CR = I2C_CMD_IACK;//Clear the Interrupt Flag
}

#endif
/******************************** i2c application ***************************/

/******************************** keyscan application ***************************/
#ifdef KEYSCAN_APP

//Macros
#define KEY_ON	1
#define KEY_OFF	0

//Declarations
static uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
static uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIOInit(void);
static void Delay(__IO uint32_t nCount);

void keyscan_app(void)
{
	char i = 0;
	
	GPIOInit();//Initializes gpio
	
	while(1)
	{
		if(Key_Scan(GPIO0,GPIO_Pin_4)==KEY_ON)//press key_4
		{
			GPIO_SetBit(GPIO0,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
			
			if(0==i)
			{
				GPIO_ResetBit(GPIO0,GPIO_Pin_0);
				i++;
			}
			else if(1==i)
			{
				GPIO_ResetBit(GPIO0,GPIO_Pin_1);
				i++;
			}
			else if(2==i)
			{
				GPIO_ResetBit(GPIO0,GPIO_Pin_2);
				i++;
			}
			else if(3==i)
			{
				GPIO_ResetBit(GPIO0,GPIO_Pin_3);
				i=0;
			}
		}
		
		Delay(166666);
	}
}

static uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	//whether key is down or not.
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		//wait key on
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
	{
		return KEY_OFF;
	}
}

static uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00; 
  
	if ((GPIOx->DATA & GPIO_Pin) != 0)
	{
		bitstatus = (uint8_t)1;
	}
	else
	{
		bitstatus = (uint8_t)0;
	}
	
	return bitstatus;
}

//Initializes GPIO
void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	//gpio pin 0~3 led
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0 |
	                         GPIO_Pin_1 |
	                         GPIO_Pin_2 |
	                         GPIO_Pin_3;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;//out
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;
	GPIO_Init(GPIO0,&GPIO_InitType);
	
	//gpio pin 4 key2
	GPIO_InitType.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_IN;//in
	GPIO_Init(GPIO0,&GPIO_InitType);
	
	GPIO_SetBit(GPIO0,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);//light : low level
}

//delay
static void Delay(__IO uint32_t nCount)//25M 1s = 8333000
{
	for(; nCount != 0; nCount--);
}

#endif
/******************************** keyscan application ***************************/

/******************************** led application ***************************/
#ifdef LED_APP

//Declarations
static void Delay(__IO uint32_t nCount);
static void GPIOInit(void);

void led_app(void)
{
	GPIOInit();//Initializes GPIO0
	
	while(1)
	{
 		GPIO_WriteBits(GPIO0,0x00);
    Delay(4333000);

		GPIO_WriteBits(GPIO0,0x01);
    Delay(4333000);

		GPIO_WriteBits(GPIO0,0x02);
    Delay(4333000);

		GPIO_WriteBits(GPIO0,0xff);
    Delay(4333000);
	}
}

//Initialize GPIO
static void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
//	GPIO_InitType.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0 |
	                         GPIO_Pin_1 |
	                         GPIO_Pin_2 |
	                         GPIO_Pin_3;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_WriteBits(GPIO0,0xFFFF);//light : low level
}

//delay
static void Delay(__IO uint32_t nCount)//25M 1s = 8333000
{
	for(; nCount != 0; nCount--);
}

#endif
/******************************** led application ***************************/

/******************************** spi application ***************************/
#ifdef SPI_APP

static void SPIInit(void);

void spi_app(void)
{
	SPIInit();								//Initialize SPI
	
	SPI_Select_Slave(0x01) ;	//Select The SPI Slave	
	SPI_WriteData(0x9F);			//Send Jedec
	
	while(1)
	{
		if(~SPI_GetToeStatus() && SPI_GetTrdyStatus() == 1)
		{
			SPI_WriteData(0x9F);//Send Jedec
		}
		
		if(~SPI_GetRoeStatus() && SPI_GetRrdyStatus() == 1)
		{
			printf("%x\r\n",SPI_ReadData());		
		}
	}
}

//Initialize SPI
static void SPIInit(void)
{
	SPI_InitTypeDef init_spi;
	
	init_spi.CLKSEL= CLKSEL_CLK_DIV_8;		//50MHZ / 8
	init_spi.DIRECTION = DISABLE;					//MSB First
	init_spi.PHASE =DISABLE;							//posedge
	init_spi.POLARITY =DISABLE;						//polarity 0
	
	SPI_Init(&init_spi);
	
	printf("SPI Initialization OK.\r\n");
}

#endif
/******************************** spi application ***************************/

/******************************** spi-flash Application ***************************/
#ifdef SPI_FLASH_APP

//Declarations
static void Delay_ms(__IO uint32_t delay_ms);

//Variables
uint8_t tx_buffer[100] = {0};
uint8_t rx_buffer[100] = {0};

void spi_flash_app(void)
{
	spi_flash_init();//Initialize SPI-Flash
	Delay_ms(10);
	
	//switch SPI-Flash status : download to memory
	change_mode_spi_flash();
	
	//first read the data from flash
	printf("Read initialized data from SPI-Flash\r\n");
	spi_flash_read(100,0x03,0x600000,rx_buffer);
	printf("Initialized data :\r\n");
	for(int i =0 ; i< 100 ; i ++ )
	{
		printf("%x ",rx_buffer[i]);
	}
	printf("\r\n");
		
	//and erase the sector
	spi_flash_sector_erase(0x600000);
	printf("After erase SPI-Flash :\r\n");
		
	//secone read the data from flash
	spi_flash_read(100,0x03,0x600000,rx_buffer);
	for(int i =0 ; i< 100 ; i ++ )
	{
		printf("%x ",rx_buffer[i]);
	}
	printf("\r\n");
		
	//Write data to spi flash
	uint8_t i = 0;
	for(;i<100;i++)
	{
		tx_buffer[i] = i;
	}
	
	printf("Write page data into SPI-Flash\r\n");
	spi_flash_page_program(100,0x600000,tx_buffer);
	
	//read the data we write
	printf("Read data after page write :\r\n");
	spi_flash_read(100,0x03,0x600000,rx_buffer);
	for(int i =0 ; i< 100 ; i ++ )
	{
		printf("%x ",rx_buffer[i]);
	}
	printf("\r\n");
	
	//Erase data
	spi_flash_sector_erase(0x600000);
	printf("Erase SPI-Flash sector data\r\n");
	
	printf("\r\nSPI-Flash memory write, read and erase successfully.\r\n");
	
	while(1);
}

//delay ms
static void Delay_ms(__IO uint32_t delay_ms)
{
	for(delay_ms=(SystemCoreClock>>13)*delay_ms; delay_ms != 0; delay_ms--);
}

#endif
/******************************** spi-flash application ***************************/

/******************************** systick application ***************************/
#ifdef SYSTICK_APP

//Variables
static __IO uint32_t TimingDelay;

//Declarations
static void SystickInit(void);
static void delay_us(__IO uint32_t nTime);
static void TimingDelay_Decrement(void);
static void GPIOInit(void);

//Macros
#define delay_ms(x) delay_us(100*x);

void systick_app(void)
{
	SystickInit();									//Initialize systick
	GPIOInit();											//Initialize GPIO0
	
	while(1)
	{
		//LED1
		GPIO_SetBit(GPIO0,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
		GPIO_ResetBit(GPIO0,GPIO_Pin_0);
		delay_ms(50);
		
		//LE2
		GPIO_SetBit(GPIO0,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3);
		GPIO_ResetBit(GPIO0,GPIO_Pin_1);
		delay_ms(50);
		
		//LED3
		GPIO_SetBit(GPIO0,GPIO_Pin_1|GPIO_Pin_0|GPIO_Pin_3);
		GPIO_ResetBit(GPIO0,GPIO_Pin_2);
		delay_ms(50);
		
		//LED4
		GPIO_SetBit(GPIO0,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_0);
		GPIO_ResetBit(GPIO0,GPIO_Pin_3);
		delay_ms(50);
	}
}

//Initialize GPIO
static void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0 |
	                         GPIO_Pin_1 |
	                         GPIO_Pin_2 |
	                         GPIO_Pin_3;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_WriteBits(GPIO0,0xF);//light : low level
}

//Initialize systick
static void SystickInit(void)
{
	//SystemCoreClock / 1000 : 1ms interrupt
	uint32_t temp = SystemCoreClock / 10000;
	SysTick->LOAD = temp;
	SysTick->VAL = temp;//Reset current counter's value
	
	//select clock source, enable interrupt, enable counter
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; 
}

//delay 10us
static void delay_us(__IO uint32_t nTime)
{
	TimingDelay = nTime;
	
	//enable systick
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
	while(TimingDelay != 0);
}

//get systick
//add into SysTick_Handler
static void TimingDelay_Decrement(void)
{
	if(TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

//Systick Interrupt Handler
void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}

#endif
/******************************** systick application ***************************/

/******************************** timer application ***************************/
#ifdef TIMER_APP

//Declarations
static void TimerInit(TIMER_TypeDef* TIMERx);

//Variables
volatile uint32_t counter;

void timer_app(void)
{
	int num = 0;
	
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
	TimerInit(TIMER0);//Initialize timer0
	counter = 0;
	
	//Enable Timer0 interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = TIMER0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
	TIMER_EnableIRQ(TIMER0);
	
	printf("Timer0 counter interrupt from 0~60.\r\n");
	
	TIMER_StartTimer(TIMER0);//Start Timer0
	
	while(1)
	{
		if(counter==2)
		{
			counter=0;
			printf("Timer0 counter : %d\r\n",num);
			num++;
		}
		
		if(num==60)
		{
			num=0;
		}
	}
}

//Initialize Timer0
static void TimerInit(TIMER_TypeDef* TIMERx)
{ 
	TIMERx->INTCLEAR = 0;
	TIMER0->RELOAD=25000026;				//Set the value of the Timer 1s
	TIMER0->VALUE= TIMER0->RELOAD; 	//Set the initial value
	TIMER0->CTRL=0;									//Timer interrupt
	
	printf("TIMERx->INTCLEAR = 0;\r\n");
	printf("TIMER0->RELOAD=25000026;\r\n");
	printf("TIMERx->VALUE= TIMER0->RELOAD;\r\n");
	printf("TIMERx->CTRL = 0;\r\n");
}

//Timer0 Interrupt Handler
void TIMER0_Handler(void)
{
	if(TIMER_GetIRQStatus(TIMER0) != RESET)
	{
		counter++;
		TIMER_ClearIRQ(TIMER0);
	}
}

#endif
/******************************** timer application ***************************/

/******************************** watchdog application ***************************/
#ifdef WATCHDOG_APP

/*
 * Program watchdog :
 *      type = 0 : No action;
 *      type = 1 : Interrupt;
 *      type = 2 : Reset.
 */
static void watchdog_init(unsigned int cycle,int type);

void watchdog_app(void)
{
	watchdog_init(86666666,0);//Initialize watchdog
	
	while(1)
	{
		printf("Watchdog feed...\r\n");
		watchdog_init(86666666,2);
	}
}

static void watchdog_init(unsigned int cycle, int type)
{
	printf("WatchDog Initialization!\r\n");

	WDOG_UnlockWriteAccess();
	WDOG_RestartCounter(cycle);
  
	if (type==0)
	{
		printf("No action.\r\n");
		WDOG->CTRL = 0;
	}
	else if (type==1)
	{
		printf("Generate NMI Interrupt.\r\n");
		WDOG_SetIntEnable();
	}
	else
	{
		printf("Generate reset.\r\n");
		WDOG_SetResetEnable();
		WDOG_SetIntEnable();
	}

	printf("Lock watchdog...\r\n");
	WDOG_LockWriteAccess();
}

#endif
/******************************** watchdog application ***************************/

/******************************** uart0 irq application ***************************/
#ifdef UART0_IRQ_APP

//Initialize GPIO
void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0 |
	                         GPIO_Pin_1 |
	                         GPIO_Pin_2 |
	                         GPIO_Pin_3;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_WriteBits(GPIO0,0xF);//light : low level
}

void uart0_irq_app(void)
{
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
	//Enable UART0 interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = UART0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 0;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
	//Initializes GPIO
	GPIOInit();
	
	printf("Input a number to trigger a UART0 RX interrupt through PC UART:\r\n");
	printf("1 --> LED1 and output 1.\r\n");
	printf("2 --> LED2 and output 2.\r\n");
	printf("3 --> LED3 and output 3.\r\n");
	printf("4 --> LED4 and output 4.\r\n");
	printf("Other numbers --> No LED operation and output this number.\r\n");
	
//	while(1);
}

//UART0 Interrupt Handler
void UART0_Handler(void)
{
	char num = '0';
	
	if(UART_GetRxIRQStatus(UART0) == SET)
	{
		num  = UART_ReceiveChar(UART0);
		printf("UART0 receives a Rx interrupt value %c\r\n",num);
		
		if(num == '1')
		{
			GPIO0->DATAOUT = 0xe;
		}
		else if(num == '2')
		{
			GPIO0->DATAOUT = 0xd;
		}
		else if(num == '3')
		{
			GPIO0->DATAOUT = 0xb;
		}
		else if(num == '4')
		{
			GPIO0->DATAOUT = 0x7;
		}
		else
		{
			printf("No operation!\r\n");
		}
	}
	
	UART_ClearRxIRQ(UART0);
}

#endif
/******************************** uart0 irq application ***************************/

/******************************** rtc application ***************************/
#ifdef RTC_APP

#include <stdbool.h>

//Initializes GPIO
void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0 |
	                         GPIO_Pin_1 |
	                         GPIO_Pin_2 |
	                         GPIO_Pin_3;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_WriteBits(GPIO0,0xF);//light : low level
}

//Initializes RTC
void RTCInit(void)
{
	Set_Match_Value(10);	//Match 10
	Set_Load_Value(0);		//0 Start
	RTC_Inter_Mask_Set();

	Start_RTC();
}

//delay ms
void delay_ms(__IO uint32_t delay_ms)
{
  for(delay_ms=delay_ms*8500; delay_ms != 0; delay_ms--);
}

void rtc_app(void)
{
	NVIC_InitTypeDef InitTypeDef_NVIC;
	uint32_t rtc_current_val = 0;
	
	//Enable RTC interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = RTC_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
  GPIO0->OUTENSET = 0xFFFFFFFF;
  GPIO0->DATA = 0xFFFFFFFF;

  GPIOInit();	//Initializes GPIO
  RTCInit();	//Initializes RTC
	
	while(1)
	{
		rtc_current_val = Get_Current_Value();
		printf("Current RTC Value : 0x%X\r\n", rtc_current_val);
		delay_ms(250);
	}
}

//RTC Interrupt Handler
static bool led_flag = true;

void RTC_Handler(void)
{
	printf("Enter RTC Interrupt.\r\n");
	
	if(led_flag)
	{
		GPIO_ResetBit(GPIO0, GPIO_Pin_2);
		GPIO_ResetBit(GPIO0, GPIO_Pin_3);
	}
	else
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_2);
		GPIO_SetBit(GPIO0, GPIO_Pin_3);
	}
	led_flag = !led_flag;
	
	//Clear Inetrrupt
	Clear_RTC_interrupt();
	
	Set_Load_Value(0);
	
	printf("Exit RTC Interrupt.\r\n");
}

#endif
/******************************** rtc application ***************************/

/******************************** nvic application ***************************/
#ifdef NVIC_APP

//Macros
#define true 1
#define false 0

//Types
typedef uint8_t bool;

//Declarations
void TimerInit(TIMER_TypeDef* TIMERx);

//Variables
volatile uint32_t counter;
bool timer_flag = false;
bool counter_flag = false;

void nvic_app(void)
{
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
  TimerInit(TIMER0);//timer0 initialization
	
	//Interrupt priority configuration
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);

	//Enable Timer0 interrupt
  InitTypeDef_NVIC.NVIC_IRQChannel = TIMER0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);

  TIMER_EnableIRQ(TIMER0);//enable timer0 interrupt register
	TIMER_StartTimer(TIMER0);//startup timer0
	
	//Enable UART0 RX interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = UART0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 0;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	
	timer_flag = true;

  int num=0;

	while(1)
   {
     if(counter==2)
     {
       counter=0;
			 printf("%d\r\n",num);
       num++;
     }
		
     if(num==60)
	   {	
			 num=0;
		 }
  }
}

//UART0 interrupt handler
void UART0_Handler(void)
{
	if(UART_GetRxIRQStatus(UART0) == SET)
	{
		printf("UART0 Rx interrupt receives a value %c.\r\n",UART_ReceiveChar(UART0));
		printf("UART0 is Rx in interrupt status.\r\n");
		
		if(timer_flag == true)
		{
			counter_flag = true;
		}
		
		UART_ClearRxIRQ(UART0);
		
		if(timer_flag == false)
		{
			TIMER_StartTimer(TIMER0);//startup timer0
			timer_flag = true;
		}
	}
}

void TimerInit(TIMER_TypeDef* TIMERx)
{ 
  TIMER0->INTCLEAR = 0;
  TIMER0->RELOAD=25000026;//Set the value of the Timmer 1s
  TIMER0->VALUE= TIMER0->RELOAD; //Set the init value
  TIMER0->CTRL=0;  // timmer interrupt
	
	printf("TIMER0 registers begin initialized status.\r\n");
	printf("TIMER0 registers finish initialized status.\r\n");
}

//Timer0 interrupt handler
void TIMER0_Handler(void)
{
  if(TIMER_GetIRQStatus(TIMER0) != RESET)
  {
    while(1)
    {
		  counter ++;
		  printf("Timer0 interrupt counter is %d.\r\n",counter);
			
			if(counter_flag == true)
			{
				break;
			}
    }
		
		TIMER_ClearIRQ(TIMER0);
		TIMER_StopTimer(TIMER0);
		counter = 0;
		timer_flag = false;
		
		counter_flag = false;
  }
}

#endif
/******************************** nvic application ***************************/
