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
#include "stdlib.h"

//Initialiser le timer sur lequel sera  branché le moteur CC
void cap_init (int ARR, int PSC)
{
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	LL_GPIO_InitTypeDef My_LL_GPIO_Init_Struct;
	
	// Validation horloge locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	
	LL_TIM_StructInit(&My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	My_LL_Tim_Init_Struct.Autoreload=ARR;
	My_LL_Tim_Init_Struct.Prescaler=PSC;
	LL_TIM_Init(TIM2, &My_LL_Tim_Init_Struct);
	
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
void cap_send_to_moteur(int pulse)
{
	TIM2->EGR = (1<<TIM_EGR_UG_Pos); 
	//LL_TIM_GenerateEvent_UPDATE(TIM2)
	
	if (pulse<(36000-RESOLUTION*10)) //36000 correspond a notre 1.5 ms
	{
		//Envoie du sens 
	  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6); 
		//Envoie de la vitesse 
		cap_generate_pwm(abs(36000-pulse));
	}
	else if (pulse > (36000+RESOLUTION*10)) //
	{
		//Envoie du sens 
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
		//Envoie de la vitesse
		cap_generate_pwm(abs(36000-pulse));
	}
		
	else //Si la télécommande est a son état 0, on arrete d'envoyer des signaux aux pins
	{
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
	}
	
}

void cap_generate_pwm(int pulsation)
{
	int valeur_ccr = pulsation;
	LL_TIM_OC_SetCompareCH2 (TIM2, valeur_ccr);
}
