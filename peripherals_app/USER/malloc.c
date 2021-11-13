/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2020 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			malloc.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2020-4-1 09:00:00
 * @brief			memory management
 ******************************************************************************************
 */
#include "malloc.h"       
  
uint8_t membase[MEM_MAX_SIZE];
uint8_t memmapbase[MEM_ALLOC_TABLE_SIZE];
  
const uint32_t memtblsize=MEM_ALLOC_TABLE_SIZE;
const uint32_t memblksize=MEM_BLOCK_SIZE;
const uint32_t memsize=MEM_MAX_SIZE;
  
struct _m_mallco_dev mallco_dev=  
{  
    mem_init,
    mem_perused,
    membase,
    memmapbase,
    0,
};

int mymemcmp(void*des,void*src,uint32_t n)
{
	int iRet = 0;
	uint8_t *xdes = des;
	uint8_t* xsrc = src;
	
	while(n--)
	{
		if(*xdes++==*xsrc++)
		{
			iRet |= 0;
		}
		else
		{
			iRet |= 1;
		}
	}
	
	return iRet;
}
  
void mymemcpy(void *des,void *src,uint32_t n)    
{    
    uint8_t *xdes=des;
    uint8_t *xsrc=src;
	
    while(n--)
		{
			*xdes++=*xsrc++;
		}			
}    

void mymemset(void *s,uint8_t c,uint32_t count)    
{    
    uint8_t *xs = s;
	
    while(count--)
		{
			*xs++=c;
		}
}        
   
void mem_init(void) 
{    
    mymemset(mallco_dev.memmap, 0,memtblsize*2);
    mymemset(mallco_dev.membase, 0,memsize);
    mallco_dev.memrdy=1;
}    

uint8_t mem_perused(void)    
{    
    uint32_t used=0;    
    uint32_t i;
	
    for(i=0;i<memtblsize;i++)
    {    
        if(mallco_dev.memmap[i])used++;   
    }
		
    return (used*100)/(memtblsize);    
}    
 
uint32_t mem_malloc(uint32_t size)    
{    
    signed long offset=0;    
    uint16_t nmemb;
    uint16_t cmemb=0;
    uint32_t i;
	
    if(!mallco_dev.memrdy)
		{
			mallco_dev.init();
		}
		
    if(size==0)
		{
			return 0XFFFFFFFF;
		}
		
    nmemb=size/memblksize;
    if(size%memblksize)
		{	
			nmemb++;
		}
		
    for(offset=memtblsize-1;offset>=0;offset--)
    {       
        if(!mallco_dev.memmap[offset])
				{
					cmemb++;
				}
        else
				{
					cmemb=0;
				}
				
        if(cmemb==nmemb)
        {  
            for(i=0;i<nmemb;i++)
            {    
                mallco_dev.memmap[offset+i]=nmemb;    
            }
						
            return (offset*memblksize);
        }  
    }
		
    return 0XFFFFFFFF;
}    
  
uint8_t mem_free(uint32_t offset)    
{    
    int i;
	
    if(!mallco_dev.memrdy)
    {  
        mallco_dev.init();      
        return 1;
    }
		
    if(offset<memsize)
    {    
        int index=offset/memblksize;
        int nmemb=mallco_dev.memmap[index];
        for(i=0;i<nmemb;i++)
        {    
            mallco_dev.memmap[index+i]=0;    
        }
				
        return 0;    
    }
		else
		{
			return 2;
		}
}
 
void myfree(void *ptr)    
{    
    uint32_t offset;
	
    if(ptr==NULL)
		{	
			return;
		}
		
    offset=(uint32_t)ptr-(uint32_t)mallco_dev.membase;    
    mem_free(offset);
}    

void *mymalloc(uint32_t size)
{    
    uint32_t offset;
	
    offset=mem_malloc(size);                     
    if(offset==0XFFFFFFFF)
		{
			return NULL;
		}
    else
		{
			return (void*)((uint32_t)mallco_dev.membase+offset);
		}
}
