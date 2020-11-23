

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "data.h"


void envoi_roulis(char*message);
void envoi_batterie(char* message);

void DATA_init();

void affichage_3sec(int tension, char* message);
void affichage_background(int roulis, int tension, int batterie);



#endif
