#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f1xx_ll_system.h" 
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f103xb.h" 
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"


//Configuation du timer, en mode codeur incrémental
void Girouette_Conf(int Arr, int Psc);

//Se lance lorsque la girouette se set_up
void Enable_Counter(void);

//Récupération de l'angle alpha de la girouette
int get_alpha(TIM_TypeDef *Timer);



#endif
