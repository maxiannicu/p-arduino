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
#include "drivers/hc_s501.hpp"
#include "drivers/led.hpp"
#include "drivers/eight_dot_matrix.hpp"

void checkSensor();
void redraw();

const uint8_t row[8] = {
  45, 35, 44, 39, 30, 42, 32, 38
};

// 2-dimensional array of column pin numbers:
const uint8_t col[8] = {
  37, 34, 36, 43, 40, 41, 33, 31
};

Scheduler runner;
Task task(5,TASK_FOREVER,&redraw,&runner,true);
Task taskCheck(100,TASK_FOREVER,&checkSensor,&runner,true);

hc_s501 motionSensor(7);
eight_dot_matrix matrix(col,row);
led blinkingLed(8);



//Do not add code below this line
#endif /* _p_arduino_H_ */
