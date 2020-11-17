#ifndef VOILES_H
#define VOILES_H

#include "stm32f1xx_ll_gpio.h"

//Config du TIM1 en PWM output
void timer_voiles_conf(int Arr, int Psc);

int voiles_init();

//Conversion de ALPHA reçu du capteur en TETA pour les voiles
float voiles_alpha_to_teta(int alpha);

//Conversion de TETA en ms (servomoteur)
int voiles_teta_to_ms(int teta);

#endif