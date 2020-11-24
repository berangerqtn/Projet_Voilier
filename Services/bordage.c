//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________

//   Fichier de programmation du bordage et de l'antichavirement

#include "bordage.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h"


int alpha;
float teta1;
float MS;
float Rapport_Cyclique;
int compare_value;
	

void bordage_conf_IO(void)
{
	//Réglage du Timer et GPIO lié à la girouette
	Girouette_Conf((180-1), 1);
	
	//Réglage du timer et GPIO lié à la gestion des voiles
	voiles_conf((400-1),(3600-1));

}

void bordage_border_voiles(int alpha,int *info_voiles){
	
	teta1=voiles_alpha_to_teta(alpha);
	MS=voiles_teta_to_ms(teta1);
	Rapport_Cyclique=voiles_rapport_cyclique(MS);
	compare_value=rapport_cyclique_to_comparevalue(Rapport_Cyclique);
  voiles_compare((int)compare_value);
	*info_voiles=100;
}

void bordage_lacher_voiles(int *info_voiles){
	
	MS=voiles_teta_to_ms(90);
	Rapport_Cyclique=voiles_rapport_cyclique(MS);
	compare_value=rapport_cyclique_to_comparevalue(Rapport_Cyclique);
  voiles_compare((int)compare_value);
	*info_voiles=0;
}


void set_index()
{
	while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5)==0)
	{
			
	}
	Enable_Counter();
	
}
void Bordage_Background(int *info_roulis, int *info_voiles, int*info_batterie){
		
	
	//valeur 40 à modifier en fonction des tests en réel
	//while ((roulis_get(10)<40) && (roulis_get(11)<40)){
		alpha=get_alpha(TIM3);
		bordage_border_voiles(alpha,info_voiles);
		*info_roulis=30;
	//}
	
	//bordage_lacher_voiles(info_voiles);
	*info_roulis=50;
	
}
