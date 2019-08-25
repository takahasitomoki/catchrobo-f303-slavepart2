/*
 * encoder.h
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "stm32f3xx_hal.h"

#define ENC_1_TIM_HANDLER	htim1
#define ENC_1_TIM	TIM1

extern TIM_HandleTypeDef htim1;

//プロトタイプ宣言
void EncGetData(int16_t *);
void EncEnable(void);
void EncDisable(void);

#endif /* ENCODER_H_ */
