/*
 * robotstate.h
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */

#ifndef ROBOTSTATE_H_
#define ROBOTSTATE_H_


#include <math.h>
#include "stm32f3xx_hal.h"
#include "struct.h"



//円筒座標系
typedef struct {
	float r;
	float theta;
	float z;
} struct_cyl;
extern struct_cyl poscyl;
extern struct_cyl refcyl;

//直行座標系
typedef struct {
	float x;
	float y;
	float z;
} struct_rec;
extern struct_rec posrec;
extern struct_rec refrec;

//プロトタイプ宣言
int TestPos(float);


#endif /* ROBOTSTATE_H_ */
