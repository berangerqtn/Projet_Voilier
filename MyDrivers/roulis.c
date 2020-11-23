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


// IT quand dépassement du seuil
// on reçoit une valeur analogique qu'on converti en numérique avec l'ADC

void (*ptr_roulis)(void);


int roulis_IT_conf(void (*roulis_lacher_voiles)(void), int Prio){
	ptr_roulis = roulis_lacher_voiles;
}

void ADC1_2_IRQHandler(void){
	//lâcher les voiles
	
	//rabaisser le FLAG
	LL_ADC_ClearFlag_EOS(ADC1);
	
}

int roulis_get()
{

}
