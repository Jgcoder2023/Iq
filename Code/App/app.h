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

//  任务队列的结构体
typedef struct
{
	u8 runFlag;				 // 0不运行   1运行
	u16 timer;				 // 计时器
	u16 itvTime;			 // 任务运行间隔时间
	void (*pTaskHook)(void); // 运行的任务函数
} TaskInfo;

void App(void);
void task_Run(void);
uint16_t GetCounter(void);

#endif