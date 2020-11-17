//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________
 
//               Fichier d'orientation du plateau.

#include "orientation.h"
#include "cap.c"
#include "telecommande_RF.c"


int orientation()
{
	int sens; 
	
	telecommandeRF_init();
	telecommandeRF_getpwm();
	
	
}