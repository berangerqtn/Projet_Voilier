#ifndef ROULIS_H
#define ROULIS_H

#include "stm32f1xx_ll_gpio.h"

//Configuration de l'ADC utilis�
void ADC_init (void);

//Configuration de l'IT pour l�cher les voiles
int roulis_get(int num_channel);



#endif
