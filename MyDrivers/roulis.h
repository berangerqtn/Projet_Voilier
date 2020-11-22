#ifndef ROULIS_H
#define ROULIS_H

#include "stm32f1xx_ll_gpio.h"


//Configuration de l'IT pour lâcher les voiles
int roulis_IT_conf(void (*roulis_lacher_voiles)(void), int Prio);


int roulis_get();



#endif
