/*
 * led.cpp
 *
 *  Created on: Jun 10, 2017
 *      Author: Maxian Nicu
 */

#include "led.hpp"
#include <Arduino.h>

led::led(uint8_t pin){
	this->pin = pin;
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void led::turnOn(){
	digitalWrite(pin, HIGH);
}

void led::turnOff(){
	digitalWrite(pin, LOW);
}

int8_t led::isOn(){
	return digitalRead(pin);
}
