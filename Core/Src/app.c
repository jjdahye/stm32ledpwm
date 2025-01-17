/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: user
 */

#include "app.h"
#include <math.h>

// 장치 선언
extern TIM_HandleTypeDef htim1;

// time1의 duty 변경
void setDuty(uint8_t duty1, uint8_t duty2, uint8_t duty3){
	htim1.Instance->CCR1 = (duty1) * 10;
	htim1.Instance->CCR2 = (duty2) * 10;
	htim1.Instance->CCR3 = (duty3) * 10;
}


void app(){
	// 타이머 장치 시작
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	while(1){

		static int angleR = 0;
		static int angleG = 0;
		static int angleB = 0;
		angleR++;
		angleG++;
		angleB++;
		angleR %= 360;
		angleG %= 360;
		angleB %= 360;

		uint8_t valueSinR = sin(angleR * M_PI / 180) * 50 + 49;
		uint8_t valueSinG = sin(angleG * M_PI / 180) * 50 + 49;
		uint8_t valueSinB = sin(angleB * M_PI / 180) * 50 + 49;

		setDuty(valueSinR, valueSinG, valueSinB);
		HAL_Delay(10);

		/*
		static int angle = 0;
		angle++;
		angle %= 360;

		uint8_t valueSin = sin(angle * M_PI / 180) * 50 + 49;

		setDuty(valueSin, valueSin, valueSin);
		HAL_Delay(10);
		 */
	}
}


