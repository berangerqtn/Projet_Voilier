#ifndef VOILES_H
#define VOILES_H

#include "stm32f1xx_ll_gpio.h"

//Config du TIM1 en PWM output
void timer_voiles_conf(int Arr, int Psc);

//Conversion de ALPHA reçu du capteur en TETA pour les voiles
float voiles_alpha_to_teta(int alpha);

//Conversion de TETA en ms (servomoteur)
float voiles_teta_to_ms(float teta);

//Calcul du rapport cyclique
float voiles_rapport_cyclique (float MS);

//conversion pour fixer CompareValue selon le rapport cyclique
float rapport_cyclique_to_comparevalue(float RC);

//récupère la copmare value et l'utilise avec f° LL
int voiles_compare(int compare);

#endif

