#ifndef CAP_H
#define CAP_H


#include "stm32f1xx_ll_bus.h" 
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"
#define FREQ_HORLOGE 72000000
#define RESOLUTION FREQ_HORLOGE/938

void cap_init (double ARR, double PSC);
void cap_generate_pwm(double pulsation, double PSC_cap);
void cap_send_to_moteur(double pulse, double PSC_cap);
#endif
