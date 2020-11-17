//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES  PERIPHS________________________

//   Fichier de driver du déploiement des voiles.

#include "voiles.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_tim.h" 
#include "stm32f1xx_ll_rcc.h"



void timer_voiles_conf(int Arr, int Psc){
	//TIM1, PA8, attention mettre MOE (Master Output Enable) à 1
	
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	//Validation de l'horloge
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
	
	// chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=Arr; //=400 (20ms avec 20pts par ms)
	My_LL_Tim_Init_Struct.Prescaler=Psc; //
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;
	
	LL_TIM_Init(TIM1,&My_LL_Tim_Init_Struct);
	
	//MOE mis à 1
	LL_TIM_EnableAllOutputs(TIM1);
	
	//TIM1 en sortie PWM
	LL_TIM_OC_SetMode(TIM1,LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
	

	
}


int voiles_init(){

}


//Conversion de ALPHA reçu du capteur en TETA pour les voiles
float voiles_alpha_to_teta(int alpha){
	float teta;
	
	if (alpha>0 && alpha<45){
		teta =0.0;
	}
	else if (alpha>45 && alpha<180){
		teta= (2/3)*alpha;
	}
	return teta;
}


int voiles_teta_to_ms(int teta){
    
}