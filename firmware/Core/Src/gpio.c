/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB5 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
#define LED_G_PORT   GPIOB
#define LED_G_PIN    GPIO_PIN_5

#define LED_B_PORT   GPIOB
#define LED_B_PIN    GPIO_PIN_13

void led_g_ctrl(uint8_t mode)
{
  switch(mode)
  {
  case 0:
      HAL_GPIO_WritePin(LED_G_PORT, LED_G_PIN, GPIO_PIN_RESET);
    break;

  case 1:
      HAL_GPIO_WritePin(LED_G_PORT, LED_G_PIN, GPIO_PIN_SET);
    break;

  case 2:
    HAL_GPIO_TogglePin(LED_G_PORT, LED_G_PIN);
    break;

  default:
    HAL_GPIO_WritePin(LED_G_PORT, LED_G_PIN, GPIO_PIN_RESET);
    break;

  }
}

void led_b_ctrl(uint8_t mode)
{
  switch(mode)
  {
  case 0:
      HAL_GPIO_WritePin(LED_B_PORT, LED_B_PIN, GPIO_PIN_RESET);
    break;

  case 1:
      HAL_GPIO_WritePin(LED_B_PORT, LED_B_PIN, GPIO_PIN_SET);
    break;

  case 2:
    HAL_GPIO_TogglePin(LED_B_PORT, LED_B_PIN);
    break;

  default:
    HAL_GPIO_WritePin(LED_B_PORT, LED_B_PIN, GPIO_PIN_RESET);
    break;

  }
}
/* USER CODE END 2 */
