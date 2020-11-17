//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________
 
//               Fichier d'orientation du plateau.

#include "orientation.h"

//=======
#include "telecommande_RF.c"

int orientation (pwm)
{
	cap_init(pwm);
	telecommandeRF_init();
	telecommandeRF_getpwm();
}
