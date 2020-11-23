//_______________________________________________________________
//                         PROJET PERIPH
//_______________________________________________________________

// LAXAGUE Léa CONVERT Florian LERAT Baptiste QUINTANA Béranger

//___________________________GIROUETTE___________________________


#include "girouette.h"

#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_tim.h" 
#include "stm32f1xx_ll_rcc.h"


//Configuation du timer, en mode codeur incrémental
void Girouette_Conf(int Arr, int Psc)
{
	
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	
	//Validation Horloge Locale
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	
	// chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=Arr;
	My_LL_Tim_Init_Struct.Prescaler=Psc;
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;
	
	LL_TIM_Init(TIM3,&My_LL_Tim_Init_Struct);
	
	//On compte TI1 (TI2 pour le sens)
	LL_TIM_SetEncoderMode(TIM3, LL_TIM_ENCODERMODE_X2_TI1);
	
	//On règle la polarité 
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1,LL_TIM_IC_POLARITY_RISING);
	
	LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);
	LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2,LL_TIM_IC_POLARITY_RISING);
	

	//Configuration du GPIO.
	
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
	
}


//Récupération de l'angle alpha de la girouette

int get_alpha(TIM_TypeDef * Timer)
{
	return LL_TIM_GetCounter(Timer);
}


//Gestion du zéro mécanique, qd repasse par zéro alors calibrage OK
void girouette_IT_index(void){
	
    LL_GPIO_AF_SetEXTISource(LL_GPIO_AF_EXTI_PORTA, LL_GPIO_AF_EXTI_LINE5);

    AFIO->EXTICR[2] |= AFIO_EXTICR2_EXTI5_PA;

    EXTI->IMR |= EXTI_IMR_MR5_Msk;
    EXTI->RTSR |= EXTI_RTSR_TR5_Msk;
}

void girouette_IT_conf(void){
    NVIC->IP[23]=2<<4;
    NVIC->ISER[0]=1<<23;
}

//redirection
void EXTI9_5_IRQHandler(void){
    //CNT A ZERO
    LL_TIM_SetCounter(TIM3, 0);
    //enlever le pin de pending ?
    EXTI->PR |= EXTI_PR_PR5_Msk; 
}


