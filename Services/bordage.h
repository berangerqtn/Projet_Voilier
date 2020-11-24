#ifndef BORDAGE_H
#define BORDAGE_H

#include "stm32f103xb.h" 
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"
#include "voiles.h"
#include "roulis.h"
#include "girouette.h"

//Création des variables globales pour l'exécution du programme



void bordage_conf_IO(void);
void set_index(void);
void Bordage_Background(int *info_roulis, int *info_voiles, int*info_batterie);
void bordage_border_voiles(int alpha, int* info_voiles);
void bordage_lacher_voiles(int* info_voiles);

#endif
