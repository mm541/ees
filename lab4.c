#include<p89v51rx2.h>

#define LED_ON 0
#define SWITCH_ON 0
#define BUZ_ON 0

sbit  buz =  P0^3;
sbit  L3      =   P3^7;
sbit  L2      =   P3^6;
sbit  S3      =   P3^5;
sbit  S2      =   P3^4;
sbit  S1    =   P3^3;
sbit  S0    =   P3^2;
sbit  L1     =   P3^1;
sbit  L0     =   P3^0;

void delay(unsigned int d){
	unsigned int K = 25;
	while(d--)while(K--);
}

void leds_toggle(int l0, int l1, int l2, int l3){
	L0 = (l0 == LED_ON);
	L1 = (l1 == LED_ON);
	L2 = (l2 == LED_ON);
	L3 = (l3 == LED_ON);
}

void switch_check(){
	
	int number = 0;
	
	if(S0 == SWITCH_ON)number += 1;
	if(S1 == SWITCH_ON)number += 2;
	if(S2 == SWITCH_ON)number += 4;
	if(S3 == SWITCH_ON)number += 8;
	
	while(number > 0 && number <= 15){
		int bits[4] = {0};
		int temp = number, i = 0;
		while(temp){
			bits[i] = temp % 2;
			temp /= 2;
			i++;
		}
		number++;
		leds_toggle(bits[0], bits[1], bits[2], bits[3]);
		delay(6);
	}
	if(number){
		buz = BUZ_ON;
		delay(3);
		buz = !BUZ_ON;
	}
}

int main(){
	leds_toggle(!LED_ON, !LED_ON, !LED_ON, !LED_ON);
	S0 = !SWITCH_ON, S1 = !SWITCH_ON, S2 = !SWITCH_ON, S3 = !SWITCH_ON;
	while(1){
		delay(5);
		switch_check();
	}
}


/**
sbit  RD      =   P3^7;
sbit  WR      =   P3^6;
sbit  T1      =   P3^5;
sbit  T0      =   P3^4;
sbit  INT1    =   P3^3;
sbit  INT0    =   P3^2;
sbit  TXD     =   P3^1;
sbit  RXD     =   P3^0;
*/

/**
buz = BUZ_ON;
		delay(2);
		buz = !BUZ_ON;
		delay(1);
		buz = BUZ_ON;
		delay(2);
		buz = !BUZ_ON;
		delay(1);
		buz = BUZ_ON;
		delay(3);
		buz = !BUZ_ON;
		delay(1);
		buz = BUZ_ON;
		delay(1);
		buz = !BUZ_ON;
*/