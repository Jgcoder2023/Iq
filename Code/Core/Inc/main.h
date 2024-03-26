/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
void SystemClock_Config(void);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW3_Pin GPIO_PIN_0
#define SW3_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_1
#define SW2_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_2
#define SW1_GPIO_Port GPIOA
#define RES_Pin GPIO_PIN_0
#define RES_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_1
#define DC_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_2
#define CS_GPIO_Port GPIOB
#define BLK_Pin GPIO_PIN_10
#define BLK_GPIO_Port GPIOB
#define INT_Pin GPIO_PIN_5
#define INT_GPIO_Port GPIOB
#define Run_Pin GPIO_PIN_9
#define Run_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
