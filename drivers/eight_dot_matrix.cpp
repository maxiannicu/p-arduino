#include "eight_dot_matrix.hpp"
#include <Arduino.h>

eight_dot_matrix::eight_dot_matrix(const uint8_t colPins[8],const uint8_t rowPins[8]){
	for (uint8_t x = 0; x < 8; x++) {
		this->colPins[x] = colPins[x];
		this->rowPins[x] = rowPins[x];
		pinMode(colPins[x], OUTPUT);
		pinMode(rowPins[x], OUTPUT);
	}


	// initialize the pixel matrix:
	for (uint8_t x = 0; x < 8; x++) {
		for (uint8_t y = 0; y < 8; y++) {
		  pixels[x][y] = HIGH;
		}
	}
}

void eight_dot_matrix::set(int8_t x,int8_t y,uint8_t val){
	if(x >= 0 && x < 8 && y >= 0 && y < 8){
		pixels[x][y] = val;
	}
}

void eight_dot_matrix::redraw(){
	// iterate over the rows (anodes):
	  for (int thisRow = 0; thisRow < 8; thisRow++) {
	    // take the row pin (anode) high:
	    digitalWrite(rowPins[thisRow], HIGH);
	    // iterate over the cols (cathodes):
	    for (int thisCol = 0; thisCol < 8; thisCol++) {
	      // get the state of the current pixel;
	      int thisPixel = pixels[thisRow][thisCol];
	      // when the row is HIGH and the col is LOW,
	      // the LED where they meet turns on:
	      digitalWrite(colPins[thisCol], thisPixel);
	      // turn the pixel off:
	      if (thisPixel == LOW) {
	        digitalWrite(colPins[thisCol], HIGH);
	      }
	    }
	    // take the row pin low to turn off the whole row:
	    digitalWrite(rowPins[thisRow], LOW);
	  }
}
