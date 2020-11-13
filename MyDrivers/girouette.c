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
void Timer_Conf(int Arr, int Psc){
	
	//Validation Horloge Locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	
	//On compte TI1 (TI2 pour le sens)
	LL_TIM_SetEncoderMode(TIM3, LL_TIM_ENCODERMODE_X2_TI1);
	
	//On règle la polarité 
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1,LL_TIM_IC_POLARITY_RISING);
	
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2,LL_TIM_IC_POLARITY_RISING);
	
}

