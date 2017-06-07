// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _p_arduino_H_
#define _p_arduino_H_
#include "Arduino.h"
#include "drivers/four_digit_display.hpp"
#include "sys/task_scheduler.hpp"
//add your includes for the project p_arduino here

Scheduler runner;
four_digit_display fdp(5,4,3,2,26,24,27,23,31,22,29,25);

//end of add your includes here


//add your function definitions for the project p_arduino here




//Do not add code below this line
#endif /* _p_arduino_H_ */
