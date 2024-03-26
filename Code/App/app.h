#ifndef __App_H__
#define __App_H__

#include "main.h"
#include "string.h"
#include "stdlib.h"

extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_i2c1_rx;
extern DMA_HandleTypeDef hdma_i2c1_tx;

extern DMA_HandleTypeDef hdma_i2c1_rx;
extern DMA_HandleTypeDef hdma_i2c1_tx;

extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim4;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

//  ������еĽṹ��
typedef struct
{
	u8 runFlag;				 // 0������   1����
	u16 timer;				 // ��ʱ��
	u16 itvTime;			 // �������м��ʱ��
	void (*pTaskHook)(void); // ���е�������
} TaskInfo;

void App(void);
void task_Run(void);
uint16_t GetCounter(void);

#endif