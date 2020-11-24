#ifndef ROULIS_H
#define ROULIS_H

#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h" 
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_adc.h"
#include "stm32f1xx_ll_utils.h"
#include "stdlib.h"
#include "time.h"

//Configuration de l'ADC utilisé
void ADC_init (void);

//Configuration de l'IT pour lâcher les voiles
int roulis_get(int num_channel);



#endif
