/*
 * hc_s501.hpp
 *
 *  Created on: Jun 10, 2017
 *      Author: Maxian Nicu
 */

#ifndef hc_s501_hpp
#define hc_s501_hpp
#include <stdint.h>

class hc_s501 {
public:
	hc_s501(uint8_t pin);
	int8_t isMotion();
private:
	uint8_t pin;
};

#endif



