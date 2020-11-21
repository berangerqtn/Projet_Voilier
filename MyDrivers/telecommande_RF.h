#ifndef TELECOMMANDERF_H
#define TELECOMMANDERF_H

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h" 
#include "stm32f1xx_ll_gpio.h"

#define FREQ_HORLOGE 72000000

void telecommandeRF_init(void);
void telecommandeRF_getpwm(double *pulsation);




#endif
