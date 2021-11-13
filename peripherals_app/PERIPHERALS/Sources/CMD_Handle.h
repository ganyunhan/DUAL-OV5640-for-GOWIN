/**
  ******************************************************************************
  * @file    CMD_Handle.h
  * @author  MGDG
  * @version V1.0.0
  * @date    2017-08-09
  * @brief   
  ******************************************************************************
 **/

#ifndef _CMD_HANDLE_H
#define _CMD_HANDLE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void CMDHandle_Help(size_t paranum,const char *para[]);
void CMDHandle_cmdtest(size_t paranum,const char *para[]);

#endif
