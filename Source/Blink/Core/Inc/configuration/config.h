/*
 * config.h
 *
 *  Created on: Apr 22, 2022
 *      Author: milan
 */

#ifndef INC_CONFIGURATION_CONFIG_H_
#define INC_CONFIGURATION_CONFIG_H_

#include "config_adv.h"

/*
 * htim2 is extern variable!
 *
 * Used for PWM for led blink.
 * */
#define PWM_Timer			htim2

/*
 * Channel of PWM for led blink.
 * */
#define PWM_Ch				TIM_CHANNEL_1

/*
 * htim3 is extern variable!
 *
 * Used for debounce for switch B1
 * */
#define debounde_Timer		htim3

/*
 * File : main.c
 * Function : MX_TIM3_Init(void)
 *
 * htim3.Init.Period = debounce_Time-1;
 *
 * Description :
 * Macro for determining the debounce time.
 *
 * Warning !
 * After regenerate CubeMX need to bi update line from main.c !!!
 * */
#define debounce_Time		1000			//ms


#endif /* INC_CONFIGURATION_CONFIG_H_ */
