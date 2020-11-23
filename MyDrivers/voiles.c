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


void timer_voiles_conf(int Arr, int Psc)
{
	//Configuration du GPIOA pour la commande du ServoMoteur
	//Configuration du Pin8 (sortie STM32 en PWM) en output alternate
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_8,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_8,LL_GPIO_MODE_ALTERNATE);
	
	//Configuration du LL_TIM_OCMODE_PWM
	//TIM1, PA8, attention mettre MOE (Master Output Enable) à 1
	
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	//Validation de l'horloge
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
	
	// chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=Arr; //=400 (20ms avec 20pts par ms)
	My_LL_Tim_Init_Struct.Prescaler=Psc; //=3600 (freqCLK/freq impuls)(72MHz/20kHz=3600)
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;
	
	LL_TIM_Init(TIM1,&My_LL_Tim_Init_Struct);
	
	//MOE mis à 1
	LL_TIM_EnableAllOutputs(TIM1);
	
	//TIM1 en sortie PWM
	LL_TIM_OC_SetMode(TIM1,LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
}


//Conversion de ALPHA reçu du capteur en TETA pour les voiles
float voiles_alpha_to_teta(int alpha)
{
	float teta;
	
	if (alpha>0 && alpha<45)
	{
		teta =0.0;
	}
	else if (alpha>=45 && alpha<180)
	{
		teta= ((2.00/3.00)*(float)alpha)-30.00;
	}
	return teta;
}

//Conversion de TETA en ms pour déterminer la durée d'impulsion
float voiles_teta_to_ms(float teta)
{
    //1ms => 90°, 2ms => 0°
		//résolution 20pts par ms et 90° par ms => 4,5° par ms
		return ((-teta/90.00)+2.00);
}

//Calcul du rapport cyclique
float voiles_rapport_cyclique (float MS)
{
	return((MS/20.00)*100.0);
}

//conversion pour fixer CompareValue selon le rapport cyclique
float rapport_cyclique_to_comparevalue(float RC)
{
	return(4.0*RC);
}


//récup le compare value et compare avec le signal
int voiles_compare(int compare)
{
	LL_TIM_OC_SetCompareCH1(TIM1, compare);
}

