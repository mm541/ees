#include<p89v51rx2.h>

void delay(unsigned int d){
	unsigned int i, j;
	for(i = 0; i <= d; i++){
		for(j = 0; j <= 1000; j++){
		}
	}
}


byte LEDPinArray[LED_NUMBER] = { LED_PIN_1,
                                 LED_PIN_2,
                                 LED_PIN_3 };
void initAllLEDs()
{
  for (int i = 0; i < LED_NUMBER; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}
void powerOnAllLEDs(bool powerOn)
{
  for (int i = 0; i < LED_NUMBER; i++) {
    if (powerOn) {
      digitalWrite(LEDPinArray[i], HIGH);
    }
    else {
      digitalWrite(LEDPinArray[i], LOW);
    }
  }
}
void setup()
{
  initAllLEDs();
}
void loop() 
{
  powerOnAllLEDs(true);
  delay(1000);
  powerOnAllLEDs(false);
  delay(1000);
}

void main(){
	sbit LED_ARR[5];
	while(1){
		LED_ONE = 0;
		LED_ZERO = 1;
		delay(20);
		LED_ONE = 1;
		LED_ZERO = 0;
		delay(20);
	}
}