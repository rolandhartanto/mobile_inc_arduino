#include "LED.h"
#include "Arduino.h"

LED::LED(int _pin){
	pinMode(pin, OUTPUT);
	pin = _pin;
	turnOff();
}

void LED::breathFade(){
	int brightness = 0, fadeConstant = 5;
	while(brightness <255){
		brightness += fadeConstant;
		analogWrite(pin,brightness);
		delay(10);
	}
	
	while(brightness >0){
		brightness -= fadeConstant;
		analogWrite(pin,brightness);
		delay(10);
	}
	
	state = 1;
}

void LED::turnOn(){
	digitalWrite(pin,HIGH);
	state = 1;
}

void LED::turnOff(){
	digitalWrite(pin,LOW);
	state = 0;
}

bool LED::isOn(){
	return (state == 1);
}

