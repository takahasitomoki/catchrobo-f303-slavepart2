/*
 * robotstate.c
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */

#include "robotstate.h"
#include "motor.h"


//������Duty��Ń��[�^�[�𓮂���
int TestPos(float Duty){
//	float Duty = -0.8f;
	int pwm = 0;

	pwm = CoordinateSetDuty(Duty);
	return pwm;

}

