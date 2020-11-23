#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f1xx_ll_system.h" 
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f103xb.h" 
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"


//Configuation du timer, en mode codeur incr�mental
void Girouette_Conf(int Arr, int Psc);

//R�cup�ration de l'angle alpha de la girouette
int get_alpha(TIM_TypeDef *Timer);

//Gestion du z�ro m�canique, qd repasse par z�ro alors calibrage OK
void girouette_IT_index(void);

void girouette_IT_conf(void);

//Redirection
void EXTI9_5_IRQHandler(void);


#endif
