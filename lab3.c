#include<p89v51rx2.h>


/**
sbit RxD = P3^0;
sbit TxD = P3^1;
sbit WR = P3^6;
sbit RD = P3^7;
sbit INT0 = P3^2;
sbit INT1 = P3^3;
sbit T0 = P3^4;
sbit T1 = P3^5;
*/
void delay(int c){
	while(c > 0){
		int a = 1000;
		while(a > 0){
			a--;
		}
		c--;
	}
}

void led_switch(int a, int b, int c, int d){
	if(a == 0)RxD = 1;
	else RxD = 0;
	
	if(b == 0)TxD = 1;
	else TxD = 0;
	
	if(c == 0)WR = 1;
	else WR = 0;
	
	if(d == 0)RD = 1;
	else RD = 0;
}

void executor(int K){
	int t=K;
	while(1){
		int a[4]={0,0,0,0};
		int i = 0;
		int temp = K;
		while(temp) {
			if((temp&1)==1) {
				a[i] = 1;
			}
			i++;
			temp = (temp/2);
		}
		led_switch(a[0],a[1],a[2],a[3]);
		delay(600);
		K--;
		if(K==-1)K=t;
	}
}

void switch_counter(){
	while(1){
		if(INT0 == 0){
			executor(1);
		}
		else if(INT1 == 0){
			executor(3);
		}
		else if(T0 == 0){
			executor(7);
		}
		else if(T1 == 0){
			executor(15);
		}
	}
}

void main(){
	led_switch(0, 0, 0, 0);
	T0 = 1;
	T1 = 1;
	INT0 = 1;
	INT1 = 1;
	switch_counter();
}