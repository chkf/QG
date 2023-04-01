#include <REGX52.H> 
sbit LED1=P2^0;
void Delay(int xms)
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	xms--;
	}
}

void main()
{
	char ln=0,i;
	while(1)
	{
		P2=0xff;//全灭
		Delay(50);
		for(i=0;i<8;i++)
		{
			Delay(50);
			P2=P2<<1;//一个一个亮
		}
		Delay(50);
		for(i=0;i<9;i++)
		{
			Delay(50);
			P2=P2>>1;
			P2+=0x80;
		}
	}		
}