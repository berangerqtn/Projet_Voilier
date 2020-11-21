//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________
 
//               Fichier d'orientation du plateau.

#include "orientation.h"
#include "cap.c"
#include "telecommande_RF.c"


void gerer_orientation()
{
	double PSC_cap= round(RESOLUTION_CAP * FREQ_HORLOGE); //régler psc du cap;
	double ARR_cap= PERIODE_PWM * FREQ_HORLOGE  * PSC_cap; //régler pour avoir periode de 20 ms
	
	
	telecommandeRF_init();
	cap_init(PSC_cap, ARR_cap);
	//cap_send_to_moteur(telecommandeRF_getpwm(), PSC_cap);
	cap_send_to_moteur(0.0017, PSC_cap);
	
}
