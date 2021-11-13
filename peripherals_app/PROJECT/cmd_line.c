#include "cmd_line.h"

const char menu[512]="\
HELP:\r\n\
[command]: function\r\n\
[1] or [cam0]: display camera 0\r\n\
[2] or [cam1]: display camera 1\r\n\
[3] or [cam_all]: 3display camera 0 and camera 1\r\n\
[4] or [fusion]: display fusion graphics\r\n\
[5] or [cam_and_fusion]: display cameras and fusion graphics\r\n\
[6] or [help]: help\r\n\
";

char cmd_line[128];

static void sw_edition_print(void)
{
	GPIOInit();
	printf("\r\n");
	printf("************************************************\r\n");
	printf("Name:     "SW_STR_NAME"\r\n"
           "Edition:  "SW_STR_EDITION"\r\n"
		   "Compiled: "__DATE__", "__TIME__"\r\n"
			"Author:   "SW_STR_AUTHOR"\r\n");
	printf("************************************************\r\n");
	printf("\r\n\r\n");
}

void start_cmd_line()
{
	sw_edition_print();
	printf("%s",menu);
	while(1)
	{
		if(scanf("%s",cmd_line))
//		if(gets(cmd_line))
		{
			printf("cmd is :%s\r\n",cmd_line);
			if(!strcmp(cmd_line,"cam0") || !strcmp(cmd_line,"1"))
			{
				printf("Switching to mode :  Only display camera 0\r\n");
				GPIO_WriteBits(GPIO0,0x02);
			}
			if(!strcmp(cmd_line,"cam1") || !strcmp(cmd_line,"2"))
			{
				printf("Switching to mode :  Only display camera 1\r\n");
				GPIO_WriteBits(GPIO0,0x01);
			}
			if(!strcmp(cmd_line,"cam_all") || !strcmp(cmd_line,"3"))
			{
				printf("Switching to mode :  Display camera 0 and camera 1\r\n");
				GPIO_WriteBits(GPIO0,0x03);
			}
			if(!strcmp(cmd_line,"fusion") || !strcmp(cmd_line,"4"))
			{
				printf("Switching to mode :  Display fusion graphics\r\n");
				GPIO_WriteBits(GPIO0,0x04);
			}
			if(!strcmp(cmd_line,"cam_and_fusion") || !strcmp(cmd_line,"5"))
			{
				printf("Switching to mode :  Display cameras and fusion graphics\r\n");
				GPIO_WriteBits(GPIO0,0x07);
			}
			if(!strcmp(cmd_line,"help") || !strcmp(cmd_line,"6"))
			{
				printf("%s",menu);
			}
			free(cmd_line);
		}
	}
}


