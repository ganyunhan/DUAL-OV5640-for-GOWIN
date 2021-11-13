/**
  ******************************************************************************
  * @file    CMD_Handle.c
  * @author  MGDG
  * @version V1.0.0
  * @date    2017-08-09
  * @brief   
  ******************************************************************************
 **/

#include "CMD_Handle.h"

#define CMDPRINTF(...)  printf(__VA_ARGS__)

void CMDHandle_Help(size_t paranum,const char *para[])
{
	size_t count;
	extern volatile bool CMDSuperUser;
	
	CMDPRINTF("CMD List:\r\n");
	for(size_t i=0;CMD_List[i].cmd_name != NULL ;i++)
	{
		//让打印的信息对齐
		count = (strlen(CMD_List[i].cmd_name)+1)/8;
		
		if(count <= 2)
			count = 2-count;
		else
			count = 0;
		
		CMDPRINTF("%s:",CMD_List[i].cmd_name);
		
		for(size_t j=0;j<count;j++)
			CMDPRINTF("\t");
		
		CMDPRINTF("%s\r\n",CMD_List[i].cmd_help);
	}
}

void CMDHandle_cmdtest(size_t paranum,const char *para[])
{
	for(size_t i=0;i<paranum;i++)
	{
		CMDPRINTF("parameter %d : %s\r\n",i,para[i]);
	}
}
