/*
 * 4_digit_display.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: Maxian Nicu
 */

#include "four_digit_display.hpp"
#include "Arduino.h"
#include "string.h"
#include <math.h>

four_digit_display::four_digit_display(uint8_t digit0,uint8_t digit1,uint8_t digit2,uint8_t digit3,uint8_t segmentA,uint8_t segmentB,uint8_t segmentC,uint8_t segmentD,uint8_t segmentE,uint8_t segmentF,uint8_t segmentG, uint8_t segmentDot){
	this->digit0 = digit0;
	this->digit1 = digit1;
	this->digit2 = digit2;
	this->digit3 = digit3;

	this->segmentA = segmentA;
	this->segmentB = segmentB;
	this->segmentC = segmentC;
	this->segmentD = segmentD;
	this->segmentE = segmentE;
	this->segmentF = segmentF;
	this->segmentG = segmentG;
	this->segmentDot = segmentDot;

	pinMode(digit0,OUTPUT);
	pinMode(digit1,OUTPUT);
	pinMode(digit2,OUTPUT);
	pinMode(digit3,OUTPUT);
	pinMode(segmentA,OUTPUT);
	pinMode(segmentB,OUTPUT);
	pinMode(segmentC,OUTPUT);
	pinMode(segmentD,OUTPUT);
	pinMode(segmentE,OUTPUT);
	pinMode(segmentF,OUTPUT);
	pinMode(segmentG,OUTPUT);
	pinMode(segmentDot,OUTPUT);
}

void four_digit_display::set(uint8_t digit,int8_t value,uint8_t dot){
	if(digit >= 0 && digit < 4 && value >= -1 && value < 10){
		uint8_t segmentMask = 0;

		switch(value){
		case 0:
			segmentMask = 0b00111111;
			break;
		case 1:
			segmentMask = 0b00000110;
			break;
		case 2:
			segmentMask = 0b01011011;
			break;
		case 3:
			segmentMask = 0b01001111;
			break;
		case 4:
			segmentMask = 0b01100110;
			break;
		case 5:
			segmentMask = 0b01101101;
			break;
		case 6:
			segmentMask = 0b01111101;
			break;
		case 7:
			segmentMask = 0b00000111;
			break;
		case 8:
			segmentMask = 0b01111111;
			break;
		case 9:
			segmentMask = 0b01101111;
			break;
		case -1:
			segmentMask = 0b01000000;
			break;
		}

		if(dot){
			segmentMask |= (1 << 7);
		}
		this->digitSegmentMask[digit] = segmentMask;
	}
}

void four_digit_display::display_digit(uint8_t digit,uint8_t segmentMask){
	digitalWrite(digit0,digit == 0 ? LOW : HIGH);
	digitalWrite(digit1,digit == 1 ? LOW : HIGH);
	digitalWrite(digit2,digit == 2 ? LOW : HIGH);
	digitalWrite(digit3,digit == 3 ? LOW : HIGH);

	digitalWrite(segmentA,segmentMask & (1 << 0) ? HIGH : LOW);
	digitalWrite(segmentB,segmentMask & (1 << 1) ? HIGH : LOW);
	digitalWrite(segmentC,segmentMask & (1 << 2) ? HIGH : LOW);
	digitalWrite(segmentD,segmentMask & (1 << 3) ? HIGH : LOW);
	digitalWrite(segmentE,segmentMask & (1 << 4) ? HIGH : LOW);
	digitalWrite(segmentF,segmentMask & (1 << 5) ? HIGH : LOW);
	digitalWrite(segmentG,segmentMask & (1 << 6) ? HIGH : LOW);
	digitalWrite(segmentDot,segmentMask & (1 << 7) ? HIGH : LOW);
}

void four_digit_display::set_number(int16_t number){
	if(number > -1000 && number < 10000){
		uint8_t minusSign = 0;
		for(uint8_t i = 0; i < 4;i++){
			this->digitSegmentMask[i] = 0;
		}

		if(number < 0) {
			minusSign = 1;
			number *= -1;
		}
		uint8_t i = 0;
		while(number != 0){
			uint8_t x = number % 10;
			number = number / 10;
			set(i++,x,0);
		}
		if(i == 0){
			set(0,0,0);
		}
		if(minusSign){
			set(i,-1,0);
		}
	}
}

void four_digit_display::set_number(double number,uint8_t precission){
	if(precission >= 0 && precission < 4){
		char chars[20] = "23.0";
		char format[10];
		sprintf(format, "%%.%df",precission);
		dtostrf(number, 1, precission, chars);
		uint8_t len = strlen(chars);
		uint8_t digit = 0;
		uint8_t drawDot = 0;
		for(int8_t i = len-1; i >= 0;i--){
			if(chars[i] == '.'){
				drawDot = 1;
				continue;
			}
			this->set(digit++,chars[i] - '0' ,drawDot);
			if(digit > 3)
				break;
			drawDot = 0;
		}

		for(; digit < 4;digit++){
			this->digitSegmentMask[digit] = 0;
		}
	}
}

void four_digit_display::redraw(){
	this->display_digit(lastDrawnDigit, digitSegmentMask[lastDrawnDigit]);
	lastDrawnDigit++;
	if(lastDrawnDigit > 3)
		lastDrawnDigit = 0;
}
