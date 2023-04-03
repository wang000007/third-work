#include <reg51.h>

sbit P3_5=P3^5;
sbit P3_6=P3^6;
sbit P3_7=P3^7;
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char count;

void delay(unsigned int time);
void ButtonShort(void);
void ButtonLong(void);
void ButtClear(void);

void main()
{
    count=0;
	P0=table[count/10];
	P1=table[count%10];
	while(1)
	{
	   ButtonShort();
		ButtonLong();
		ButtClear();
	}
}

void delay(unsigned int time)
{
	unsigned int j=0;
	for(;time>0;time--)
	   for(j=0;j<125;j++);
}

void ButtonShort(void)
{
   if(P3_6==0)
	 {
			delay(10);
		 if(P3_6==0)
		 {
				count++;
			 if(count==100)
				  count=0;
			 P0=table[count/10];
			 P1=table[count%10];
			 while(P3_6==0);
		 }
	 }
}

void ButtonLong(void)
{
   if(P3_7==0)
	 {
			delay(10);
		 if(P3_7==0)
		 {
				count++;
			 if(count==100)
				  count=0;
			 P0=table[count/10];
			 P1=table[count%10];
			 delay(120);
		 }
	 }
}

void ButtClear(void)
{
   if(P3_5==0)
	 {
			delay(10);
		 if(P3_5==0)
		 {
			 count=0;
			 P0=table[count/10];
			 P1=table[count%10];
			 while(P3_5==0);
		 }
	 }
}