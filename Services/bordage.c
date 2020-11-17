//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//_______________________COUCHES SERVICES________________________

//   Fichier de programmation du bordage et de l'antichavirement

#include "bordage.h"
#include "girouette.h"
#include "voiles.h"
#include "roulis.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h"


void bordage_conf_IO(void){
	
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	
	//On ne se sert que du GPIOA
	
	//Configuration du Pin6 (arrivée ChannelA capteur incrémental girouette) en floating input
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_6,LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_6,LL_GPIO_MODE_FLOATING);
	
	//Configuration du Pin7 (arrivée ChannelB capteur incrémental girouette) en floating input
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_7,LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_7,LL_GPIO_MODE_FLOATING);
	
	//Configuration du Pin5 (arrivée Index capteur incrémental girouette) en floating input
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_5,LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_5,LL_GPIO_MODE_FLOATING);
	
	//Configuration du Pin8 (sortie STM32 en PWM) en output floating
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_8,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_8,LL_GPIO_MODE_FLOATING);

}

//pour TIM1 à 50hz on veut Arr=1 440 000