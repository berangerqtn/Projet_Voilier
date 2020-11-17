#ifndef CAP_H
#define CAP_H


#include "stm32f1xx_ll_bus.h" 
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"

#define RESOLUTION 75000000/938 //Clock interne divisé par le PSC du tim 4

int cap_init (int pwm);
int cap_generate_pwm();
int cap_send_to_moteur(int pulsation);
#endif