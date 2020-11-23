//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES  PERIPHS________________________

//   Fichier de driver du roulis.

#include "roulis.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h" 
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_adc.h"
#include "stm32f1xx_ll_utils.h"
#include "stdlib.h"
#include "time.h"


// IT quand dépassement du seuil
// on reçoit une valeur analogique qu'on converti en numérique avec l'ADC

void ADC_init () 
{

	
//Synchro de la clock de l'adc 
LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);
	
	
//LL_ADC_InitTypeDef MyLL_ADC_TypeDef;

//ADC en mode injected discontinue 
LL_ADC_INJ_InitTypeDef MyLL_ADC_Injected;
	
LL_ADC_INJ_StructInit (&MyLL_ADC_Injected);
MyLL_ADC_Injected.SequencerDiscont=LL_ADC_INJ_SEQ_DISCONT_1RANK; 
	
LL_ADC_INJ_Init(ADC1, &MyLL_ADC_Injected);
		
//Power On ADC		
ADC1->CR2 = ADC_CR2_ADON_Msk;

//Calibration ADC
LL_mDelay(LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES*(1/72000000));
ADC1->CR2 =ADC_CR2_CAL_Msk;

}
	
int roulis_get(uint32_t Channel)
{
	ADC1->CR2 = ADC_CR2_JSWSTART_Msk; //Démarre la conversion
	//Récuperer flag EOC et valeur du roulis 
}
