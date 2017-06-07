// Do not remove the include below
#include "p_arduino.h"

void redraw();

Task displayTask(5, TASK_FOREVER, &redraw,&runner,true);

int number = -999;

//The setup function is called once at startup of the sketch
void setup()
{
	fdp.set_number(number);
}

// The loop function is called in an endless loop
void loop()
{
	runner.execute();
}

void redraw(){
	fdp.redraw();
}
