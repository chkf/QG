#include <REGX52.H>
#include <RTX51TNY.H>
#include "nixie.h"

void task0(void) _task_ 0 
{  
	//os_create_task(1);  
	os_create_task(2);  
   	os_delete_task(0);
}  

void task1(void) _task_ 1 
{  
	char i;
	while (1) 
	{    
		for(i=0;i<8;i++)
		{
			os_wait2(K_TMO, 500);
			nixie(i);
		}    
	}  
}

void task2(void) _task_ 2
{
	os_wait2(K_TMO, 2);
	P0_0=!P0_0;
}

void task3(void) _task_ 3
{
	char i;
	while(1)  
    {  
        P1=0xff;//全灭
		os_wait2(K_TMO, 50);
		for(i=0;i<8;i++)
		{
			os_wait2(K_TMO, 50);
			P1=P1<<1;				//一个一个亮
		}
		P1=1;						//最后一个灭
		os_wait2(K_TMO, 50);
		for(i=0;i<9;i++)
		{
			os_wait2(K_TMO, 50);
			P1=(P1<<1)+1;;			//一个一个灭
		}
   	}  
}