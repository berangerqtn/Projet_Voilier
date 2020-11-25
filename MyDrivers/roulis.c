//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES  PERIPHS________________________

//   Fichier de driver du roulis.

#include "roulis.h"

// IT quand dépassement du seuil
// on reçoit une valeur analogique qu'on converti en numérique avec l'ADC

void ADC_init ()
{
	//Synchro de la clock de l'adc 
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);
		
		
	//LL_ADC_InitTypeDef MyLL_ADC_TypeDef;
	
	

	//ADC en mode injected discontinue 
	LL_ADC_INJ_InitTypeDef MyLL_ADC_Injected;
		
	LL_ADC_INJ_StructInit(&MyLL_ADC_Injected);
	MyLL_ADC_Injected.SequencerDiscont=LL_ADC_INJ_SEQ_DISCONT_1RANK;  //On met les channels en discontinue? a vérifier
	MyLL_ADC_Injected.SequencerLength=LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS; //On a 2 channel dans notre groupe d'injected -> Vérifier qu'on est pas passé en mode scan
			
	LL_ADC_INJ_Init(ADC1, &MyLL_ADC_Injected);
	
	//On passe les channel dans notre groupe d'injected 
	LL_ADC_INJ_SetSequencerRanks( ADC1, LL_ADC_CHANNEL_10, LL_ADC_INJ_RANK_1); //Ch10 au rang 1
	LL_ADC_INJ_SetSequencerRanks( ADC1, LL_ADC_CHANNEL_11, LL_ADC_INJ_RANK_2); //Ch11 au rang 2
	
	//Power On ADC		
	ADC1->CR2 = ADC_CR2_ADON_Msk;

	//Calibration ADC
	LL_mDelay(LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES*(1/72000000));
	ADC1->CR2 =ADC_CR2_CAL_Msk;
}
	
int roulis_get(int num_channel)
{
	uint32_t data_roulis;
	int valeur_out;
	
	//Démarre la conversion
	ADC1->CR2 = ADC_CR2_JSWSTART_Msk; 
	ADC1->CR2 = (0<<ADC_CR2_JSWSTART_Pos); //remettre a 0 direct?
	
	//Si ca marche : on met le while dans chaque if et on read direct la bonne valeur 
	
	while (LL_ADC_IsActiveFlag_JEOS(ADC1)==0)
	{
		
	}
	

	if (num_channel == 10) 
		{
			data_roulis=LL_ADC_INJ_ReadConversionData32(ADC1, LL_ADC_INJ_RANK_1); 
			LL_ADC_ClearFlag_JEOS	(ADC1);
		}
	else if (num_channel == 11)
		{
			data_roulis=LL_ADC_INJ_ReadConversionData32(ADC1, LL_ADC_INJ_RANK_2);
			LL_ADC_ClearFlag_JEOS	(ADC1);
		}
		
		valeur_out=data_roulis; //Est ce que si je la return brut ca marche?
		
		return valeur_out;
}
