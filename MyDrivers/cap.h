#ifndef CAP_H
#define CAP_H

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h" 


int cap_init (int pwm);
int cap_sendpwm(int pwm); 




#endif