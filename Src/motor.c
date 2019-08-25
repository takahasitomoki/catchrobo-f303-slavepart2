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
 * ���W�����[�^
-----------------------------------------------*/
static void CoordinateSetDirection(float);
/*
 * �w�肳�ꂽduty��Ń��[�^����
 * @param	spd_duty : duty��B-1 ~ 1
 * @return
 */
int CoordinateSetDuty(float duty){
	uint16_t pwm = 0;

	//-1 ~ 1�ɐ���
	if(duty  !=MOTOR_BRAKE){
		duty = fmax(fminf(duty,1),-1);
	}
	//��]������ݒ�
	CoordinateSetDirection(duty);

	//Duty��̐�Βl���Ƃ�ƂƂ��ɁADUTY��𐧌�����
	if(duty != MOTOR_BRAKE){
		duty = fabsf(duty);//*COORDINATE_DUTY_LIMIT;
//		pwm = duty * (float)(COORDINATE_TIM_FREQ / COORDINATE_PWM_FREQ);
		pwm = duty * 1000;

	}
	//�e�`�����l���ɃR���y�A�}�b�`�l��ݒ�
	__HAL_TIM_SET_COMPARE(&COORDINATE_TIM_HANDLER, PWM_TIM_CH, 	pwm);

	//�߂�l�Ƃ���PWM�̒l�i0~1000�j��Ԃ�
	return pwm;
}

/*
 * duty�̐������烂�[�^�̉�]�������w��
 * @param	duty_r, duty_theta, duty_z, duty_hand : �e����duty��
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
 * �^�C�}ENABLE
 * @param
 * @return
 */
void CoordinateEnable(void) {
	CoordinateSetDuty(0);
	HAL_TIM_PWM_Start(&COORDINATE_TIM_HANDLER, PWM_TIM_CH);
}

/*
 * �^�C�}DISABLE
 * @param
 * @return
 */
void CoordinateDisable(void) {
	CoordinateSetDuty(0);
	HAL_TIM_PWM_Stop(&COORDINATE_TIM_HANDLER, PWM_TIM_CH);
}


