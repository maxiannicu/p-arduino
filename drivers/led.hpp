#ifndef led_hpp
#define led_hpp
#include <stdint.h>

class led {
private:
	uint8_t pin;
public:
	led(uint8_t pin);
	void turnOn();
	void turnOff();
	int8_t isOn();
};

#endif
