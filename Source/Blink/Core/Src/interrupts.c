/*
 * interupts.c
 *
 *  Created on: Apr 22, 2022
 *      Author: milan
 */
#include "config.h"

/*
 * Callback routine for external interrupt.
 * */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//Detect rising and falling edge of B1
	if(GPIO_Pin == B1_Pin)
	{
		//Start timer for debounce
		HAL_TIM_Base_Start_IT(&debounde_Timer);
		//Clear interrupt flag
		__HAL_TIM_CLEAR_FLAG(&debounde_Timer, TIM_SR_UIF);
	}
}

/*
 * Callback routine for timer interrupt.
 * */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  //Detect interrupt of timer for debounce
  if (htim == &debounde_Timer )
  {
	    //Check state after debounce_Time time
	    //If button push then turn on led and turn off timer
	    if(HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin) == GPIO_PIN_RESET)
		{

	    	 HAL_TIM_PWM_Start(&PWM_Timer, PWM_Ch);
	    	 HAL_TIM_Base_Stop_IT(&debounde_Timer);
		}
	    //If not, then turn off led and timer
		else
		{
			HAL_TIM_PWM_Stop(&PWM_Timer, PWM_Ch);
			HAL_TIM_Base_Stop_IT(&debounde_Timer);
		}
  }
}
