#ifndef eight_dot_matrix_hpp
#define eight_dot_matrix_hpp

#include <stdint.h>
#define DOT_ON LOW
#define DOT_OFF HIGH
class eight_dot_matrix {
public:
	eight_dot_matrix(const uint8_t colPins[8],const uint8_t rowPins[8]);
	void redraw();
	void set(int8_t x,int8_t y,uint8_t val);
private:
	uint8_t colPins[8];
	uint8_t rowPins[8];
	uint8_t pixels[8][8];
};

#endif
