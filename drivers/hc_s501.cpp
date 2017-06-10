#include "hc_s501.hpp"
#include "Arduino.h"

hc_s501::hc_s501(uint8_t pin){
	this->pin = pin;
	pinMode(pin, INPUT);
}

int8_t hc_s501::isMotion(){
	return digitalRead(pin);
}
