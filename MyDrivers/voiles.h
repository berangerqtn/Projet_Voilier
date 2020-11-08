#ifndef VOILES_H
#define VOILES_H

#include "stm32f1xx_ll_gpio.h"

int voiles_init();
int voiles_alpha_to_teta(int alpha);
int voiles_teta_to_ms(int teta);

#endif