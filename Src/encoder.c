/*
 * encoder.c
 *
 *  Created on: 2019/08/23
 *      Author: tomok
 */


#include "encoder.h"

/*
 * �G���R�[�_�^�C�}ENABLE
 * @param
 * @return
 */
void EncEnable(void){
	HAL_TIM_Encoder_Start(&ENC_1_TIM_HANDLER,TIM_CHANNEL_ALL);

	//�l�����Z�b�g
	ENC_1_TIM -> CNT	= 32768;
}

/*
 * �G���R�[�_�^�C�}DISABLE
 * @param
 * @return
 */
void EncDisable(void){
	HAL_TIM_Encoder_Stop(&ENC_1_TIM_HANDLER,TIM_CHANNEL_ALL);

	//�l�����Z�b�g
	ENC_1_TIM -> CNT	= 0;
}

/*
 * �G���R�[�_�^�C�}�J�E���g�l�̍�����Ԃ�
 * @param
 * @return
 * @note	�|�C���^�n���̕ϐ��Ɋe�G���R�[�_�̍�������
 */
void EncGetData(int16_t *enc_1_buf){
	*enc_1_buf = ENC_1_TIM->CNT -32768;

	ENC_1_TIM -> CNT	= 32768;
}

