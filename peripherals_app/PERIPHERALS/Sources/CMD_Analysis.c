/**
  ******************************************************************************
  * @file    CMD_Analysis.c
  * @author  MGDG
  * @version V1.0.0
  * @date    2017-08-09
  * @brief   
  ******************************************************************************
 **/

#include "CMD_Analysis.h"
#include "CMD_Handle.h"

#define CMD_MAXPARANUM 	10									//支持的最大参数个数
#define CMD_BUFLEN 		512									//命令包括参数的最大长度


typedef struct
{
	const char *cmd_name;									//命令字符串
	const char *cmd_help;									//命令帮助信息
	void (*cmd_handle)(size_t paranum,const char *para[]);	//回调函数定义
															//paranum: 参数个数，包括命令在内
															//para[]: 命令及参数字符串的起始指针，其中命令字符串指针为para[0],参数字符串指针为para[1]~para[paranum-1];
}CMD_Tydef;

/**
  * @brief	命令结构体数组
  * @remark	格式：“命令”，“命令说明信息”，“命令回调函数”
  * @remark 在此处添加自己的命令
  */
static const CMD_Tydef CMD_List[]=
{
	{"help","printf information of all commands",CMDHandle_Help},
	{"cmdtest","cmd test,printf all parameter e.g: (cmdtest <para1> <para2> ...)",CMDHandle_cmdtest},
	{NULL,NULL,NULL}
};


/**
  * @brief	获取输入的命令与参数的起始指针，参数之间由空格隔开
  * @param	*strbuf：命令字符串
  * @param	**paramn：指针数组

  * @return	size_t：参数个数，包括命令本身
  * @remark	命令以及每个参数后的第一个空格替换成空字符
  */
static size_t CMD_GetPara(char *strbuf,char **paramn)
{
	size_t i = 0;
	volatile size_t paranum = 0;
	size_t para_len = 0;
	size_t strbuflen;
	
	if(strbuf==NULL || paramn==NULL)
		return paranum;
	
	strbuflen = strlen(strbuf);

	while(paranum < CMD_MAXPARANUM)
	{
		while(strbuf[i] == 0x20)			//Filter out spaces before parameter
		{
			i++;
			if(i>=strbuflen)
				return paranum;
		}

		paramn[paranum] = &strbuf[i];		//Get parameter pointers
		
		for(;( (strbuf[i]!=0x20) && (strbuf[i]!='\0') );i++)
		{
			if(i>=strbuflen)
				return paranum+para_len;

			para_len = 1;
		}
		strbuf[i++] = '\0';					//Replace with null characters

		if(para_len)
		{
			paranum++;
			para_len = 0;
		}
		else
			return paranum;
	}
	return paranum;
}


/**
  * @brief	解析命令字符串
  * @param	*strbuf：命令字符串

  * @return	bool
  * @remark	查找结构体中是否存在与命令字符串相符合的命令，并执行回调函数
  */
static bool CMD_Process(char *strbuf)
{
	char *param[CMD_MAXPARANUM];					//存放参数指针
	size_t paranum = CMD_GetPara(strbuf,(char **)param);

	if(paranum == 0)
		return false;

	for(size_t i=0;CMD_List[i].cmd_name != NULL ;i++)
	{
		if(CMD_List[i].cmd_name[0] != param[0][0])				//skip if the first characters is different
			continue;
		if(strcmp(CMD_List[i].cmd_name,param[0]) == 0)
		{
			if(CMD_List[i].cmd_handle != NULL)
				CMD_List[i].cmd_handle(paranum,(const char **)param);
			return true;
		}
	}
	return false;			//Can't find the command
}


/**
  * @brief	查找命令字符串的开头，弹掉队列中非有效字母或数字的队尾，弹完后返回剩余队列长度
  * @param	*queue：队列指针

  * @return	size_t：剩余队列的长度	
  * @remark		
  */
static size_t CMD_FindStart(MyQueue_Typedef *queue)
{
	char temp;
	size_t index=0;
	
	while(1)
	{
		if(!MyQueue_Peek(queue,&temp,1,index))
			break;
		
		if((temp>='a' && temp <= 'z') || (temp>='A' && temp <= 'Z'))
			break;
		
		else
			index++;
	}
	
	if(index)
		MyQueue_Pop(queue,index);
	
	return MyQueue_GetCount(queue);
}


/**
  * @brief	从队列中提取一条命令字符串并处理
  * @param	*queue：队列指针

  * @return	bool	
  * @remark		
  */
bool CMD_Analysis(MyQueue_Typedef *queue)
{
	bool end_flag = false;
	char temp;
	size_t pack_length;
	size_t cmd_length;
	char cmd_buf[CMD_BUFLEN];							//存放接收到的整个命令包括参数
	
	if(cmd_buf == NULL)
		return false;
	
	pack_length = CMD_FindStart(queue);				//弹掉无效的起始字符
	
	if(pack_length == 0)
		return false;
	
	for(cmd_length=0;cmd_length<pack_length-1;cmd_length++)
	{
		MyQueue_Peek(queue,&temp,1,cmd_length);
		if(temp == 0x0D)
		{
			MyQueue_Peek(queue,&temp,1,cmd_length+1);
			if(temp == 0x0A)
			{
				end_flag = true;		//找到结尾
				break;
			}
		}
	}
	if(end_flag)
	{
		if(cmd_length >= CMD_BUFLEN)
			cmd_length = CMD_BUFLEN - 1;						//这样有bug，命令超过长度会被截取
		MyQueue_Get(queue,cmd_buf,cmd_length);					//取出指定长度并弹出
		cmd_buf[cmd_length] = '\0';								//末尾补上空字符串
		MyQueue_Pop(queue,2);									//弹掉回车符
		return CMD_Process(cmd_buf);
	}
	else
	{
		MyQueue_Pop(queue,pack_length);							//没找到回车符，弹掉数据
		return false;
	}
}

