#ifndef __KEY_H__
#define __KEY_H__

#include "app.h"


#define MaxButtonNumber              3  //��������,����32,����u16Bit_Key_structλ��Ϊ32λ

// #define PROBE1_KEY_Port              GPIOB
// #define PROBE1_KEY_Pin               GPIO_Pin_0
#define Read_PROBE1_KEY              HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)

// #define PROBE2_KEY_Port              GPIOB
// #define PROBE2_KEY_Pin               GPIO_Pin_1
#define Read_PROBE2_KEY              HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)

// #define PROBE3_KEY_Port              GPIOB
// #define PROBE3_KEY_Pin               GPIO_Pin_2
#define Read_PROBE3_KEY              HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin)



//**********************************************************
struct u32_Bit_Key_struct
{
	u32 Bit0 : 1;
	u32 Bit1 : 1;
	u32 Bit2 : 1;
	u32 Bit3 : 1;
	u32 Bit4 : 1;
	u32 Bit5 : 1;
	u32 Bit6 : 1;
	u32 Bit7 : 1;
	u32 Bit8 : 1;
	u32 Bit9 : 1;
	u32 Bit10: 1;
	u32 Bit11: 1;
	u32 Bit12: 1;
	u32 Bit13: 1;
	u32 Bit14: 1;
	u32 Bit15: 1;
	u32 Bit16: 1;
	u32 Bit17: 1;
	u32 Bit18: 1;
	u32 Bit19: 1;
	u32 Bit20: 1;
	u32 Bit21: 1;
	u32 Bit22: 1;
	u32 Bit23: 1;
	u32 Bit24: 1;
	u32 Bit25: 1;
	u32 Bit26: 1;
	u32 Bit27: 1;
	u32 Bit28: 1;
	u32 Bit29: 1;
	u32 Bit30: 1;
	u32 Bit31: 1;
};
//*************
union u32_Bit_Key_union
{
	struct u32_Bit_Key_struct u32_Bit;
	u32 All;
};

#define  PROBE1_KEY      0//����1
#define  PROBE2_KEY      1//����2
#define  PROBE3_KEY      2//����3


void KeyInputScan(void);     //������ɨ������
void KeyValueCalculate(void);//��ֵ����
uint8_t KeyState(uint8_t KeyNumber);// ���ؼ�ֵ�ĵ�ǰ״̬
uint8_t R_KeyState(uint8_t KeyNumber);//���ؼ�ֵ��������״̬
uint8_t F_KeyState(uint8_t KeyNumber);//���ؼ�ֵ���½���״̬
uint8_t L_KeyState(uint8_t KeyNumber);//���ؼ�ֵ�ĳ���״̬
uint8_t D_KeyState(uint8_t KeyNumber);//���ؼ�ֵ�Ķ���״̬
uint8_t DC_KeyState(uint8_t KeyNumber);//˫��֮�󴥷�һ��
#endif


/**
 * 
 * ʹ��ָ��
 * 1. �ȵ��� KeyIO_Init ����io�ڳ�ʼ��
 * 2. ÿ10ms ���� KeyInputScan ���а���ɨ��
 * 3. ÿ10ms ���� KeyValueCalculate ���а���״̬����
 * 4. ���ö�Ӧ���� ���ض�Ӧ������Ӧ��״̬
 * 
*/




