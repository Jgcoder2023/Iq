#include "app.h"
#include <stdio.h>
#include "display.h"

#define TaskMaxNum 5 // 定义最大任务数量
static TaskInfo task[TaskMaxNum] = {
    {0, 10, 10, task_Key},
    {0, 50, 50, task_Led},
    {0, 100, 100, task_Lcd},
    {0, 500, 500, task_Max30102},
    {0, 1000, 1000, task_Run},
};

// 1秒任务
void task_Run(void) {
    HAL_GPIO_TogglePin(Run_GPIO_Port, Run_Pin);
}

void App(void) {

    LCD_Init(); // LCD初始化
    LCD_Fill(0, 0, LCD_W, LCD_H, WHITE);

    Max30102_reset();
    MAX30102_Config();
    DisplayInit(DpSelectIQ);

    HAL_Delay(200);  //延时初始化相关外设

    //最后开启心跳定时器
    HAL_TIM_Base_Start_IT(&htim3);

    while (1) {
        for (u8 i = 0; i < TaskMaxNum; i++) {
            if (task[i].runFlag == 1) {
                task[i].pTaskHook(); // 运行任务
                task[i].runFlag = 0; // 解除标志
            }
        }
    }
}

// 时钟1ms心跳   给时钟中断使用
void TaskHeartBeat(void) {
    for (u8 i = 0; i < TaskMaxNum; i++) {
        if (task[i].timer > 0 && task[i].runFlag == 0) {
            task[i].timer--;
            if (task[i].timer == 0) {
                task[i].timer = task[i].itvTime;
                task[i].runFlag = 1;
            }
        }
    }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        TaskHeartBeat();
    }
}

//获取定时器节拍
uint16_t GetCounter(void){
    return __HAL_TIM_GET_COUNTER(&htim3);
}

// // 外部中断
// void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//     if (GPIO_Pin == INT_Pin) {
//         INT_FLAG = 1;
//     }
// }