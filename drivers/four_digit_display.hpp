/*
 * 4_digit_display.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: Maxian Nicu
 */

#ifndef DRIVERS_FOUR_DIGIT_DISPLAY_HPP_
#define DRIVERS_FOUR_DIGIT_DISPLAY_HPP_
#include <stdint.h>
#include "../sys/task_scheduler.hpp"

class four_digit_display : Task {
private:
	uint8_t digitSegmentMask[4];
	uint8_t digit0;
	uint8_t digit1;
	uint8_t digit2;
	uint8_t digit3;
	uint8_t segmentA;
	uint8_t segmentB;
	uint8_t segmentC;
	uint8_t segmentD;
	uint8_t segmentE;
	uint8_t segmentF;
	uint8_t segmentG;
	uint8_t segmentDot;

	void display_digit(uint8_t digit,uint8_t segmentMask);
public:
	four_digit_display(uint8_t digit0,uint8_t digit1,uint8_t digit2,uint8_t digit3,uint8_t segmentA,uint8_t segmentB,uint8_t segmentC,uint8_t segmentD,uint8_t segmentE,uint8_t segmentF,uint8_t segmentG, uint8_t segmentDot);
	void set(uint8_t digit,int8_t value,uint8_t dot);
	void set_number(int16_t number);
	void redraw();
};



#endif /* DRIVERS_FOUR_DIGIT_DISPLAY_HPP_ */
