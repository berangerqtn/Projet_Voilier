
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "data.h"
#include <stdio.h>
#include <string.h>

//Configuration des p�riph�riques utilis�s USART3 et GPIOA
void DATA_init(void);

//Envoi du message li� � la situation critique de chavirement du bateau
void envoi_roulis(char*message);

//Envoi du message li� au faible niveau de batterie de l'appareil
void envoi_batterie(char* message);

//Envoi du message g�n�ral du projet.
void affichage_3sec(int tension, char* message);

//Fonction globale de gestion de toutes les fonctions li�es � l'envoi d'informations appel�e dans le main.
void affichage_background(int roulis, int tension, int batterie);



#endif
