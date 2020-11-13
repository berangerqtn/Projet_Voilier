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
	LL_GPIO_InitTypeDef My_LL_GPIO_Init_Struct;
	
	// Validation horloge locale du Timer 4 et du GPIO B
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	
	//Paramètres par défaut du GPIOB.
	LL_GPIO_StructInit(&My_LL_GPIO_Init_Struct);
	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_FLOATING);

	
	LL_TIM_StructInit(&My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	LL_TIM_Init(TIM4, &My_LL_Tim_Init_Struct);

	LL_TIM_IC_InitTypeDef My_LL_Tim_IC_Struct; //On va mtn s'occuper des input channel	
//On va brancher sur TI1 et le STM récupère les infos dans les channel
	LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH1);
	LL_TIM_IC_SetPolarity (TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING); 
	
	LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH2); //On va brancher sur T1 et le STM récupère les infos dans les channel
	LL_TIM_IC_SetPolarity (TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_FALLING);

	
}


//Voir RM008 p315 explication pour l'input + 
int telecommandeRF_getpwm()
{
	int DutyCycle;
	int Period;
		
	//Ecriture du Bit CC1S dans le registre CCR1
	TIM4->CCMR1=TIM_CCMR1_CC1S_0;
	TIM4->CCER=(0<<TIM_CCER_CC1P_Pos);
	TIM4->CCMR1=TIM_CCMR1_CC2S_1;
	TIM4->CCER=(1<<TIM_CCER_CC2P_Pos);
	TIM4->SMCR=(100<<TIM_SMCR_SMS_Pos);
	TIM4->CCER=(1<<TIM_CCER_CC1E_Pos);
	TIM4->CCER=(1<<TIM_CCER_CC2E_Pos);
	
	DutyCycle=TIM4->CCR2;
	Period=TIM4->CCR1;
	
	return DutyCycle*Period;
	
}
