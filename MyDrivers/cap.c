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
	LL_TIM_InitTypeDef* My_LL_Tim_Init_Struct;
	LL_GPIO_InitTypeDef My_LL_GPIO_Init_Struct;
	
	// Validation horloge locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	
	LL_TIM_StructInit(My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	LL_TIM_Init(TIM2, My_LL_Tim_Init_Struct);
	
	//Paramètres par défaut du GPIOA.
	LL_GPIO_StructInit(&My_LL_GPIO_Init_Struct);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_2,LL_GPIO_MODE_OUTPUT); //GPIO du sens 
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_ALTERNATE); //GPIO qui envoit PWM
	
	
	LL_TIM_OC_InitTypeDef My_LL_Tim_OC_Struct;
	LL_TIM_OC_StructInit(&My_LL_Tim_OC_Struct);
	
	LL_TIM_OC_Init(TIM2, LL_TIM_CHANNEL_CH2, &My_LL_Tim_OC_Struct);
	LL_TIM_OC_SetMode	(TIM2,LL_TIM_CHANNEL_CH2,LL_TIM_OCMODE_PWM1);
	LL_TIM_OC_EnablePreload (TIM2, LL_TIM_CHANNEL_CH2);
	
	LL_TIM_OC_Init(TIM2, LL_TIM_CHANNEL_CH3, &My_LL_Tim_OC_Struct);
	LL_TIM_OC_SetMode(TIM2,LL_TIM_CHANNEL_CH3,LL_TIM_OCMODE_ACTIVE);	
	
	LL_TIM_EnableCounter(TIM2);
	
}


//RM008 p.318 explication pour envoyer le pwm
int cap_send_to_moteur(int pulse)
{
	TIM2->EGR = (1<<TIM_EGR_UG_Pos); 
	//LL_TIM_GenerateEvent_UPDATE(TIM2)
	
	if (pulse<(0.0015-RESOLUTION))
	{
		//Envoie du sens 
	  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6); //on va a gauche
		//Envoie de la vitesse 
		cap_generate_pwm();
	}
	else if (pulse> (0.0015+RESOLUTION))
	{
		//Envoie du sens 
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
		//Envoie de la vitesse
		cap_generate_pwm();
	}
		
	else 
	{
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
	}
	
}

int cap_generate_pwm()
{
}