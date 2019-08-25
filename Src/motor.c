/*
 * motor.c
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */


#include "math.h"
#include "motor.h"
#include "stm32f3xx_hal.h"


extern TIM_HandleTypeDef htim2;
/*-----------------------------------------------
 * 座標軸モータ
-----------------------------------------------*/
static void CoordinateSetDirection(float);
/*
 * 指定されたduty比でモータを回す
 * @param	spd_duty : duty比。-1 ~ 1
 * @return
 */
int CoordinateSetDuty(float duty){
	uint16_t pwm = 0;

	//-1 ~ 1に制限
	if(duty  !=MOTOR_BRAKE){
		duty = fmax(fminf(duty,1),-1);
	}
	//回転方向を設定
	CoordinateSetDirection(duty);

	//Duty比の絶対値をとるとともに、DUTY比を制限する
	if(duty != MOTOR_BRAKE){
		duty = fabsf(duty);//*COORDINATE_DUTY_LIMIT;
//		pwm = duty * (float)(COORDINATE_TIM_FREQ / COORDINATE_PWM_FREQ);
		pwm = duty * 1000;

	}
	//各チャンネルにコンペアマッチ値を設定
	__HAL_TIM_SET_COMPARE(&COORDINATE_TIM_HANDLER, PWM_TIM_CH, 	pwm);

	//戻り値としてPWMの値（0~1000）を返す
	return pwm;
}

/*
 * dutyの正負からモータの回転方向を指定
 * @param	duty_r, duty_theta, duty_z, duty_hand : 各軸のduty比
 * @return
 */
static void CoordinateSetDirection(float duty) {
	if (duty >= 0) {
		HAL_GPIO_WritePin(MOTOR_R_1_PORT, MOTOR_R_1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_R_2_PORT, MOTOR_R_2_PIN, GPIO_PIN_SET);
	} else if (duty < 0){
		HAL_GPIO_WritePin(MOTOR_R_1_PORT, MOTOR_R_1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MOTOR_R_2_PORT, MOTOR_R_2_PIN, GPIO_PIN_RESET);
	} else if (duty == MOTOR_BRAKE) {
		HAL_GPIO_WritePin(MOTOR_R_1_PORT, MOTOR_R_1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MOTOR_R_2_PORT, MOTOR_R_2_PIN, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(MOTOR_R_1_PORT, MOTOR_R_1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_R_2_PORT, MOTOR_R_2_PIN, GPIO_PIN_RESET);
	}
}

/*
 * タイマENABLE
 * @param
 * @return
 */
void CoordinateEnable(void) {
	CoordinateSetDuty(0);
	HAL_TIM_PWM_Start(&COORDINATE_TIM_HANDLER, PWM_TIM_CH);
}

/*
 * タイマDISABLE
 * @param
 * @return
 */
void CoordinateDisable(void) {
	CoordinateSetDuty(0);
	HAL_TIM_PWM_Stop(&COORDINATE_TIM_HANDLER, PWM_TIM_CH);
}


