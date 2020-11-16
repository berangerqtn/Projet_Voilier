//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES  PERIPHS________________________

//   Fichier de driver du déploiement des voiles.

#include "voiles.h"
#include "stm32f1xx_ll_gpio.h"

int voiles_init()
{

}

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

int voiles_teta_to_ms(int teta)
{
    
}