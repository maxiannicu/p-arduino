// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _p_arduino_H_
#define _p_arduino_H_
#include "Arduino.h"

#include "drivers/digital_humidity_temperature_sensor.hpp"
#include "drivers/four_digit_display.hpp"
#include "sys/task_scheduler.hpp"



void redraw();
void computeMetrics();

Scheduler runner;
four_digit_display fdp(5,4,3,2,26,24,27,23,31,22,29,25);
digital_humidity_temperature_sensor dhts(7);


Task displayTask(5, TASK_FOREVER, &redraw,&runner,true);
Task computeMetricsTask(3000, TASK_FOREVER, &computeMetrics,&runner,true);


//Do not add code below this line
#endif /* _p_arduino_H_ */
