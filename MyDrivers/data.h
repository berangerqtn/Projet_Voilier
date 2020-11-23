//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES PERIPHS_________________________

//   Fichier driver de linterface USART de communication avec le
//   Paneau d'affichage

#ifndef DATA_H
#define DATA_H

#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_usart.h"

// Fonction d'initialisation du périphérique USART3
void DATA_USART_init(void);
//Initialisation du GPIO
void DATA_GPIO_init(void);


//Envoi des messages 
void DATA_USART_send(char*message);

#endif
