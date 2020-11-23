
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "data.h"
#include <stdio.h>
#include <string.h>

//Configuration des périphériques utilisés USART3 et GPIOA
void DATA_init(void);

//Envoi du message lié à la situation critique de chavirement du bateau
void envoi_roulis(char*message);

//Envoi du message lié au faible niveau de batterie de l'appareil
void envoi_batterie(char* message);

//Envoi du message général du projet.
void affichage_3sec(int tension, char* message);

//Fonction globale de gestion de toutes les fonctions liées à l'envoi d'informations appelée dans le main.
void affichage_background(int roulis, int tension, int batterie);



#endif
