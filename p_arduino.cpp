// Do not remove the include below
#include "p_arduino.h"

int pirValue; // Place to store read PIR Value


//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
}


// The loop function is called in an endless loop
void loop()
{
	runner.execute();
}

void resetMatrix(){
	for(uint8_t x = 0 ; x < 8; x++){
		for(uint8_t y = 0 ; y < 8; y++){
			matrix.set(x, y, DOT_OFF);
		}
	}
}

void drawStatic(){
	resetMatrix();
	for(uint8_t i = 0 ; i < 8; i++){
		matrix.set(i, i, DOT_ON);
		matrix.set(i, 7-i, DOT_ON);
	}
}

void drawMotion(){
	resetMatrix();
	matrix.set(1,3, DOT_ON);
	matrix.set(2,4, DOT_ON);
	matrix.set(3,5, DOT_ON);
	matrix.set(4,4, DOT_ON);
	matrix.set(5,3, DOT_ON);
	matrix.set(6,2, DOT_ON);
}

void checkSensor(){
	pirValue = motionSensor.isMotion();
	if(pirValue)
		blinkingLed.turnOn();
	else
		blinkingLed.turnOff();
	if(pirValue){
		drawMotion();
	} else {
		drawStatic();
	}
}


void redraw(){
	matrix.redraw();
}
