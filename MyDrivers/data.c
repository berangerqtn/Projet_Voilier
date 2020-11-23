//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES PERIPHS_________________________

//   Fichier driver de linterface USART de communication avec le
//   Paneau d'affichage

#include "data.h"

void DATA_USART_init(void)
{
	//Activtation Horloge
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART3);	
	LL_USART_RequestExitMuteMode(USART3); //Active l'USART 
	
	LL_USART_InitTypeDef My_LL_Usart;
	LL_USART_StructInit(&My_LL_Usart); //Valeurs par défaut de l'USART
	
	LL_USART_Init(USART3, &My_LL_Usart);
	
	LL_USART_Enable(USART3);

}


void DATA_GPIO_init(void)
{
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_11, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_11, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_11, LL_GPIO_SPEED_FREQ_LOW);
	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_2, LL_GPIO_MODE_ALTERNATE);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_2, LL_GPIO_SPEED_FREQ_MEDIUM);
	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_9, LL_GPIO_MODE_ALTERNATE);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_9, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_9, LL_GPIO_SPEED_FREQ_LOW);
}

void DATA_USART_send(char*message)
{
	//On active le Pin 11 quand on doit envoyer.On met le 
	LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_11);
	
	int i=0;
	while(*(message+i)!='\0')
	{
		while (LL_USART_IsActiveFlag_TXE(USART3)!=1)
		{
			//On attend que le flag soit actif <=> le registre est vide
		}

		LL_USART_TransmitData8(USART3,*(message+i));
		i++;
		
	}
	LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_11);
}
