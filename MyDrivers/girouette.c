//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//___________________________GIROUETTE___________________________


#include "girouette.h"

#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_tim.h" 
#include "stm32f1xx_ll_rcc.h"


//Configuation du timer, en mode codeur incrémental
void Timer_Girouette_Conf(int Arr, int Psc)
{
	
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	
	//Validation Horloge Locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	
	// chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=Arr;
	My_LL_Tim_Init_Struct.Prescaler=Psc;
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;
	
	LL_TIM_Init(TIM3,&My_LL_Tim_Init_Struct);
	
	//On compte TI1 (TI2 pour le sens)
	LL_TIM_SetEncoderMode(TIM3, LL_TIM_ENCODERMODE_X2_TI1);
	
	//On règle la polarité 
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1,LL_TIM_IC_POLARITY_RISING);
	
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2,LL_TIM_IC_POLARITY_RISING);
	
}


//Récupération de l'angle alpha de la girouette

int get_alpha(TIM_TypeDef * Timer)
{
	return LL_TIM_GetCounter(Timer);
}




