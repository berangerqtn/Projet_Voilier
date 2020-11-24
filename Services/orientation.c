//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________
 
//               Fichier d'orientation du plateau.

#include "orientation.h"
#include "cap.h"
#include "telecommande_RF.h"
#include "math.h"


void orientation_init()
{
	int PSC_cap= 0; //régler psc du cap : précision maximale, pas de pb car ARR assez grand
	int ARR_cap= (FREQ_HORLOGE/20000)-1; //régler pour déborder après periode de T = 50us : 0.02*72000000
	cap_init(ARR_cap,PSC_cap);
	telecommandeRF_init();
}
void gerer_orientation()
{
	//int nb_pulse = 39000;
	int get_input;//variable utilisée pour le test (n'est pas nécessaire)
	
	//cap_send_to_moteur(telecommandeRF_getpwm());
	//cap_send_to_moteur(nb_pulse);
	get_input=telecommandeRF_getpwm();
	cap_send_to_moteur(get_input);
}
