// Do not remove the include below
#include "p_arduino.h"

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

void computeMetrics(){
	int chk = dhts.read11();
	if(chk == DHTLIB_OK){
		fdp.set_number(dhts.temperature, 1);
	} else {
		fdp.set_number(-1);
	}
}

void redraw(){
	fdp.redraw();
}
