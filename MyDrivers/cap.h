#ifndef CAP_H
#define CAP_H


#include "stm32f1xx_ll_bus.h" 
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"
#define FREQ_HORLOGE 75000000
#define RESOLUTION FREQ_HORLOGE/938

void cap_init (int ARR, int PSC);
void cap_generate_pwm(int pulsation, int PSC_cap);
void cap_send_to_moteur(double pulse, int PSC_cap);
#endif