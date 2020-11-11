//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________
//
// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger
//
//_______________________COUCHES  PERIPHS________________________
// 
//               Fichier de driver du plateau.

#include "cap.h"

//Initialiser le timer sur lequel sera  branché le moteur CC
int cap_init (int pwm)
{
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	
	// Validation horloge locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	
	LL_TIM_StructInit(&My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	LL_TIM_Init(TIM2, &My_LL_Tim_Init_Struct);
	
	LL_TIM_OC_InitTypeDef My_LL_Tim_OC_Struct;
	LL_TIM_OC_StructInit(&My_LL_Tim_OC_Struct);
	LL_TIM_OC_Init(TIM2, LL_TIM_CHANNEL_CH1, &My_LL_Tim_OC_Struct);
	
	 LL_TIM_OC_EnablePreload (TIM2, LL_TIM_CHANNEL_CH1);
	 LL_TIM_OC_SetMode	(TIM2,LL_TIM_CHANNEL_CH1,LL_TIM_OCMODE_PWM1);
	
}


//RM008 p.318 explication pour envoyer le pwm
int cap_sendpwm(int pwm)
{
    
}