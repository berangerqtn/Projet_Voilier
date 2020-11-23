//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________

//   Fichier de programmation du bordage et de l'antichavirement

#include "bordage.h"
#include "girouette.h"
#include "voiles.h"
#include "roulis.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h"


int alpha;
float teta;
float MS;
float Rapport_Cyclique;
int compare_value;
	

void bordage_conf_IO(void)
{
	//Réglage du Timer et GPIO lié à la girouette
	Timer_Girouette_Conf((180-1), 1);
	
	//Réglage du timer et GPIO lié à la gestion des voiles
	timer_voiles_conf((400-1),(3600-1));

}

void bordage_border_voiles(int alpha){
	
	teta=voiles_alpha_to_teta(alpha);
	MS=voiles_teta_to_ms(teta);
	Rapport_Cyclique=voiles_rapport_cyclique(MS);
	compare_value=rapport_cyclique_to_comparevalue(Rapport_Cyclique);
  voiles_compare((int)compare_value);
}

void bordage_lacher_voiles(){
	
	MS=voiles_teta_to_ms(90);
	Rapport_Cyclique=voiles_rapport_cyclique(MS);
	compare_value=rapport_cyclique_to_comparevalue(Rapport_Cyclique);
  voiles_compare((int)compare_value);
}



void Bordage_Background(void){
		
	
	//valeur 40 à modifier en fonction des tests en réel
	while ((roulis_get(10)<40) && (roulis_get(11)<40)){
		alpha=get_alpha(TIM3);
		bordage_border_voiles(alpha);
	}
	
	bordage_lacher_voiles();
	
}
