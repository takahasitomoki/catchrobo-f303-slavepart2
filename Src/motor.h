/*
 * motor.h
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */

#ifndef MOTOR_H_
#define MOTOR_H_

//#include "math.h"
#include "stm32f3xx_hal.h"
#include "struct.h"



/*-----------------------------------------------
 * 座標軸DCモータ(r, theta, z)
-----------------------------------------------*/
void CoordinateSetPosXYZ(void);
void CoordinateSetPosRTZ(void);
int CoordinateSetDuty(float duty);
void CoordinateEnable(void);
void CoordinateDisable(void);

//座標軸DCモータタイマハンドラ
#define COORDINATE_TIM_HANDLER		htim2

//PWM周波数
#define COORDINATE_PWM_FREQ			10000

//タイマ周波数
#define COORDINATE_TIM_FREQ			8000000

//Duty比のリミット
#define COORDINATE_DUTY_LIMIT		0.55f

//モータPWMチャンネル
#define PWM_TIM_CH				TIM_CHANNEL_1


//DCモータ回転方向GPIO
#define MOTOR_R_1_PORT				GPIOA
#define MOTOR_R_1_PIN				GPIO_PIN_5
#define MOTOR_R_2_PORT				GPIOA
#define MOTOR_R_2_PIN				GPIO_PIN_6


//モータブレーキ
#define MOTOR_BRAKE					1000000


#endif /* MOTOR_H_ */
