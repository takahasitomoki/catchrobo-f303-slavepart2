/*
 * encoder.c
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */


#include "encoder.h"

/*
 * エンコーダタイマENABLE
 * @param
 * @return
 */
void EncEnable(void){
	HAL_TIM_Encoder_Start(&ENC_1_TIM_HANDLER,TIM_CHANNEL_ALL);

	//値をリセット
	ENC_1_TIM -> CNT	= 32768;
}

/*
 * エンコーダタイマDISABLE
 * @param
 * @return
 */
void EncDisable(void){
	HAL_TIM_Encoder_Stop(&ENC_1_TIM_HANDLER,TIM_CHANNEL_ALL);

	//値をリセット
	ENC_1_TIM -> CNT	= 0;
}

/*
 * エンコーダタイマカウント値の差分を返す
 * @param
 * @return
 * @note	ポインタ渡しの変数に各エンコーダの差分を代入
 */
void EncGetData(int16_t *enc_1_buf){
	*enc_1_buf = ENC_1_TIM->CNT -32768;

	ENC_1_TIM -> CNT	= 32768;
}

