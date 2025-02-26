//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________
//
// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger
//
//_______________________COUCHES  PERIPHS________________________
// 
//               Fichier de driver du module RF.

//RESOLUTION DU PWM RECU DE LA TELECOMMANDE : 12 000 
//LE -20 vient de notre volonté de stabiliser autour de la valeur 
//centrale, et ainsi ne pas avoir d'effet rebond lorsque la commande 
//est positionnée au centre.

#include "telecommande_RF.h"

//Initialiser le timer sur lequel sera branché le module RF 
void telecommandeRF_init()
{
  LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	LL_GPIO_InitTypeDef My_LL_GPIO_Init_Struct;
	
	// Validation horloge locale du Timer 4 et du GPIO B
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	
	//Paramètres par défaut du GPIOB.
	LL_GPIO_StructInit(&My_LL_GPIO_Init_Struct);
	LL_GPIO_Init(GPIOB, &My_LL_GPIO_Init_Struct);
	
	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_7,LL_GPIO_MODE_FLOATING);
	
	
	LL_TIM_StructInit(&My_LL_Tim_Init_Struct); //on met les parametre de timer par défaut
	My_LL_Tim_Init_Struct.Prescaler=3-1; //On regle pour avoir la def la plus haute possible : CCR2 compte jusqu'a max 65535 pdt 2 ms (sur 16 bits)
	My_LL_Tim_Init_Struct.Autoreload=0xFFFF; //On le met au max pour etre sur que ce soit bien le CCR qui remette a 0
	LL_TIM_Init(TIM4, &My_LL_Tim_Init_Struct);

	LL_TIM_IC_InitTypeDef My_LL_Tim_IC_Struct; //On va mtn s'occuper des input channel	
	My_LL_Tim_IC_Struct.ICActiveInput=LL_TIM_ACTIVEINPUT_DIRECTTI;
	My_LL_Tim_IC_Struct.ICPolarity=LL_TIM_IC_POLARITY_RISING;
	My_LL_Tim_IC_Struct.ICFilter=LL_TIM_IC_FILTER_FDIV1;
	My_LL_Tim_IC_Struct.ICPrescaler=LL_TIM_ICPSC_DIV1;
	
	LL_TIM_IC_Init(TIM4, LL_TIM_CHANNEL_CH1, &My_LL_Tim_IC_Struct);
	
 
	LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH1);
	LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH2);
	
	/*On va se brancher sur TI1 : pas eu le temps de bien comprendre cette partie 
	j'ai essayé avec les lib LL et directement avec les opérations sur les bits
	comme expliqué p315 du RM0008:
	TIM4->CCMR1=TIM_CCMR1_CC1S_0;
	TIM4->CCER=(0<<TIM_CCER_CC1P_Pos);
	TIM4->CCMR1=TIM_CCMR1_CC2S_1;
	TIM4->CCER=(1<<TIM_CCER_CC2P_Pos);
	TIM4->SMCR=(100<<TIM_SMCR_SMS_Pos);
	TIM4->CCER=(1<<TIM_CCER_CC1E_Pos);
	TIM4->CCER=(1<<TIM_CCER_CC2E_Pos);*/
 	
	//Ecriture du Bit CC1S dans le registre CCR1
	LL_TIM_IC_SetActiveInput(TIM4,LL_TIM_CHANNEL_CH1,LL_TIM_ACTIVEINPUT_DIRECTTI);
	
	//Ecrire CC2s Bits a 10  sur Tim4_CCMR1 register (TI1 selected) 
	LL_TIM_IC_SetActiveInput(TIM4,LL_TIM_CHANNEL_CH2,LL_TIM_ACTIVEINPUT_INDIRECTTI);
	
	LL_TIM_IC_SetPolarity(TIM4,LL_TIM_CHANNEL_CH2,LL_TIM_IC_POLARITY_FALLING);
	
	//Choix du trigger : TI1FP1
	LL_TIM_SetTriggerInput(TIM4,LL_TIM_TS_TI1FP1);
	
	//On passe en slave mode
	LL_TIM_SetSlaveMode(TIM4,LL_TIM_SLAVEMODE_RESET);
	
	LL_TIM_EnableCounter(TIM4);

}


//Voir RM008 p315 explication pour l'input + 
int telecommandeRF_getpwm()
{
	int Nbr_Pas_Etat_Haut;
	//int Nbr_Pas_Totaux;
	
	
	Nbr_Pas_Etat_Haut=(TIM4->CCR2); //On récupère pas la bonne info en réel? Pb d'init? les deux channels ne sont pas branchés sur TI1?
	//Nbr_Pas_Totaux=(TIM4->CCR1);
	
	return Nbr_Pas_Etat_Haut; //Valeur min = 0.001* 72 000 000/Prescaler+1 =24000 et Valeur max = 0.002 * 72 000 000/Prescaler+1 =48 000
	//On divise Nbr_Pas_Etat_Haut pas le nbr de pas totaux si besoin?
}
