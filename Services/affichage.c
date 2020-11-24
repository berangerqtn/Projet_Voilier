//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________

//    Fichier de programmation de l'affichage des informations

#include "affichage.h"

//Initialisation des périphériques liés à l'envoie de message via l'USART
void DATA_init()
{
	DATA_USART_init();
	DATA_GPIO_init();
}

//Envoi du message en cas de situation critique de chavirement (angle de roulis > 40°)

void envoi_roulis(char* message)
{
	{
		message="Attention, Angles de roulis supérieur 40°, voiles déployées";
		DATA_USART_send(message);
	}
}

//fonction d'envoi du message en cas de perte de batterie. Prête à être employée, non implémentée parce que pas de gestion de de la batterie dans cette version du soft.

void envoi_batterie(char* message)
{
	{
		message="Attention, Batterie faible (charge inférieure à 20%)";
		DATA_USART_send(message);
	}
}

//Fcontion d'affichage qui devait théoriquement envoyer l'heure toutes les trois secondes ainsi que le taux de bordage des toiles.
void affichage_3sec(int tension, char* message)
{
	int tmax=250;
	int taux_tension=tension*100/tmax;
	
	sprintf(message,"Les voiles sont tendues à %d\n",taux_tension);
	DATA_USART_send(message);
	
}

//fonction appelée dans le main qui permet de gérer toutes nos sources de messages potentielles. L'envoi classique n'est pas effectué toutes les trois secondes faute de temps pour implémenter un chronomètre.

void affichage_background(int roulis, int tension,int batterie)
{
	char*message;
	affichage_3sec(tension,message);
	if (roulis>40)
		envoi_roulis(message);
	if (batterie<20)
		envoi_batterie(message);
	
}
