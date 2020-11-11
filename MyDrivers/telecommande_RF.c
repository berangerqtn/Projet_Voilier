//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________
//
// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger
//
//_______________________COUCHES  PERIPHS________________________
// 
//               Fichier de driver du module RF.

#include"telecommande_RF.h"

//Initialiser le timer sur lequel sera branché le module RF 
int telecommandeRF_init()
{
	
   LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	
	// Validation horloge locale
	LL_APB1_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
	
	LL_TIM_StructInit(&My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	LL_TIM_Init(TIM1, &My_LL_Tim_Init_Struct);
	
	/*chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=;
	My_LL_Tim_Init_Struct.Prescaler=;
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;*/
	
	LL_TIM_IC_InitTypeDef My_LL_Tim_IC_Struct; //On va mtn s'occuper des input channel	
//On va brancher sur TI1 et le STM récupère les infos dans les channel
	LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
	LL_TIM_IC_SetPolarity (TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING); 
	
	LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2); //On va brancher sur T1 et le STM récupère les infos dans les channel
	LL_TIM_IC_SetPolarity (TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_FALLING);
	
	
	
	/* Blocage IT
	LL_TIM_DisableIT_UPDATE(TIM2);
	
	
	Blocage Timer
	LL_TIM_DisableCounter(TIM2);
	*/
	
}


//Voir RM008 p315 explication pour l'input + 
int telecommandeRF_getpwm()
{

}
