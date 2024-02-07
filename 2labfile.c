#include<p89v51rx2.h>
void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<time;j++);
	
}
		
void main(void)
{
	while(1)
	{
		RxD=0;
		delay(20);
		RxD=1;
	  delay(20);
	
	}
}