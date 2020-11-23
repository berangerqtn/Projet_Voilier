//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________

//    Fichier de programmation de l'affichage des informations

#include "affichage.h"
#include <stdio.h>

void DATA_init()
{
	DATA_USART_init();
	DATA_GPIO_init();
}

void envoi_roulis(char* message)
{
	{
		message="Attention, Angles de roulis supérieur 40°, voiles déployées";
		DATA_USART_send(message);
	}
}

void envoi_batterie(char* message)
{
	{
		message="Attention, Batterie faible (charge inférieure à 20%)";
		DATA_USART_send(message);
	}
}

void affichage_3sec(int tension, char* message)
{
	int tmax=250;
	int taux_tension=tension*100/tmax;
	
	sprintf(message,"Les voiles sont tendues à %d\n",taux_tension);
	
}

void affichage_background(int roulis, int tension,int batterie)
{
	char*message;
	affichage_3sec(tension,message);
	if (roulis>40)
		envoi_roulis(message);
	if (batterie<20)
		envoi_batterie(message);
	
}
