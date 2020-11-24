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

<<<<<<< Updated upstream
void gerer_orientation()
{
	int PSC_cap= 23-1; //régler psc du cap : précision maximale pour ARR_max = 0xFFFF
	int ARR_cap= 0.02*(FREQ_HORLOGE/PSC_cap+1)-1; //régler pour déborder après periode de T = 20 ms : 0.02*72000000/PSC_cap+1
	int nb_pulse = 29000;
	
	telecommandeRF_init();
	cap_init(ARR_cap, PSC_cap);
	//cap_send_to_moteur(telecommandeRF_getpwm(), PSC_cap);
	cap_send_to_moteur(nb_pulse);
=======

void orientation_init()
{
	int PSC_cap= 0; //régler psc du cap : précision maximale pour ARR_max = 0xFFFF
	int ARR_cap= (FREQ_HORLOGE/20000)-1; //régler pour déborder après periode de T = 50 m=us : 0.02*72000000/PSC_cap+1
	cap_init(ARR_cap,PSC_cap);
	telecommandeRF_init();
}
void gerer_orientation()
{
	//int nb_pulse = 39000;
	int get_input;//variable utilisée pour le test sur la nucleo
	
	//cap_send_to_moteur(telecommandeRF_getpwm());
	//cap_send_to_moteur(nb_pulse);
	get_input=telecommandeRF_getpwm();
	cap_send_to_moteur(get_input);
>>>>>>> Stashed changes
}
