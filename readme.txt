#####################################################################					 
#          4AE SE - Programmation de micro contrôleurs              #
#####################################################################
#  CONVERT FLORIAN, LAXAGUE LEA, LERAT BAPTISTE, QUINTANA BERANGER  #
#####################################################################

Ce projet a pour objectif de programmer l'automatisation d'un modèle
réduit de voilier. Cela passe par une appréhension des variations du
vent, mais également un contrôle du cap de bateau, le tout avec dans
l'idéal un suivi de l'état du bateau en temps réel sur un écran LCD.

Pour se faire nous passons par la mise en place d'un logiciel embarqué
sur une puce STM32. Ce travail s'inscrit dans le cadre d'un Bureau 
d'études de la formation ingénieur en automatiques et électroniques de
l'INSA Toulouse. Le détail des périphériques utilisés se trouve en 
annexe au projet, avec en parallèle un diagramme des classes faisant
état de la structure logicielle choisie par l'équipe.

En deuxième partie de ce readme, vous trouverez les informations relatives
aux librairies LL utilisées pour la mise en place de ce projet.


#############  Structuration du projet, du répertoire  #############

Structure physique des répertoire
/Inc (h "systeme")
/src (main et system_stm32f1xx.c = systeminit au boot startup)
/LLDrivers : src et inc des drivers LL utiles, ici rcc et utils
/MDK-ARM : le projet KEIL
/Services: bordage.c orientation.c affichage.c

Structure de groupes de KEIL en deux grandes parties : Se référer au 
diagramme de classe fourni dans le projet pour une meilleure apréhension
de la structuration logicielle.


Partie sources user
/User Applications : le main qui sera exécuté par le STM32
/User Services : les fonctions de services, de haut niveau, qui n'interragissent pas directement avec les périphériques
/MyDriver    soit les drivers de périphériques créés pour la gestion automatique du voilier en fonction des beosoins du cahier des charges
/Drivers/STM32f1xx_LL_Driver
/Doc

Partie système
/Drivers/CMSIS (l'init system depuis boot)
/Example/MDK-ARM contient le startup

#####################################################################
							  BORDAGE
#####################################################################
   Service : bordage.c || Périph : roulis.c, voiles.c girouette.c
#####################################################################

Cette partie du code permet d'adapter la position des voiles en fonction de la 
puissance et de l'orientation du vent. 

La girouette nous permet de récupérer ces infos qui sont ensuites traitées
par les fonctions du fichier bordage, et les informations de commande du 
servomoteur sont transmises via le GPIOA du STM32, via un signal PWM.

#####################################################################
							ORIENTATION
#####################################################################
     Service : orientation.c || Périph : cap.c, telecommandeRF.c 
#####################################################################

Ici, il s'agit de contrôler le cap du voilier en récupérant les 
informations depuis une télécommande qui émet via un module RF.
Le signal PWM ainsi reçu est ensuite traité puis retransmis au 
moteur à courant continu du contrôle du gouvernail (ici, un plateau
en rotation).

#####################################################################
							  AFFICHAGE
#####################################################################
   Service : affichage.c || Périph : data.c
#####################################################################

Ces fichiers permettent de récupérer les différentes informations liées
à l'état du bateau en temps réel, et de les envoyer via USART à un module 
externe, qui aurait du être un écran pilote par I2C, mais nous n'avons 
pas pu mettre en place cette dernière passerelle entre l'USART du STM32, 
et l'I2C de l'écran




#####################################################################
                            Librairies LL
#####################################################################

/**
  @page Templates_LL  Description of the Templates_LL example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Templates_LL/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Templates_LL example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

This projects provides a reference template through the LL API that can be used to build any firmware application.

This project LL template provides:
 - Inclusion of all LL drivers (include files in "main.h" and LL sources files in IDE environment, with option "USE_FULL_LL_DRIVER" in IDE environment)
   Note: If optimization is needed afterwards, user can perform a cleanup by removing unused drivers.
 - Definition of LEDs and user button (file: main.h)
   Note: User button name printed on board may differ from naming "user button" in code: "key button", ...
 - Clock configuration (file: main.c)

This project LL template does not provide:
 - Functions to initialize and control LED and user button
 - Functions to manage IRQ handler of user button

To port a LL example to the targeted board:
1. Select the LL example to port.
   To find the board on which LL examples are deployed, refer to LL examples list in "STM32CubeProjectsList.html", table section "Examples_LL"
   or AN4724: STM32Cube firmware examples for STM32F1 Series

2. Replace source files of the LL template by the ones of the LL example, except code specific to board.
   Note: Code specific to board is specified between tags:
         /* ==============   BOARD SPECIFIC CONFIGURATION CODE BEGIN    ============== */
         /* ==============   BOARD SPECIFIC CONFIGURATION CODE END      ============== */
         
   - Replace file main.h, with updates:
     - Keep LED and user button definition of the LL template under tags
    
   - Replace file main.c, with updates:
     - Keep clock configuration of the LL template: function "SystemClock_Config()"
     - Depending of LED availability, replace LEDx_PIN by another LEDx (number) available in file main.h
     
   - Replace file stm32f1xx_it.h
   - Replace file stm32f1xx_it.c

@par Keywords

Reference, Templates_LL

@par Directory contents 

  - Templates_LL/Inc/stm32f1xx_it.h          Interrupt handlers header file
  - Templates_LL/Inc/main.h                  Header for main.c module
  - Templates_LL/Inc/stm32_assert.h          Template file to include assert_failed function
  - Templates_LL/Src/stm32f1xx_it.c          Interrupt handlers
  - Templates_LL/Src/main.c                  Main program
  - Templates_LL/Src/system_stm32f1xx.c      STM32f1x system source file


@par Hardware and Software environment

  - This template runs on STM32F103xB devices.
    
  - This template has been tested with STM32F103RB-Nucleo RevC board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
