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
#include "usart.h"
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
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB5 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PC1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

}

/* USER CODE BEGIN 2 */
#define LED_G_PORT   GPIOB
#define LED_G_PIN    GPIO_PIN_5

#define LED_B_PORT   GPIOB
#define LED_B_PIN    GPIO_PIN_13

#define MSW_CFG      GPIOC
#define MSW_CFG_PIN  GPIO_PIN_1

#define MSW_TAMPER      GPIOA
#define MSW_TAMPER_PIN  GPIO_PIN_3

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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch(GPIO_Pin)
  {
  case MSW_CFG_PIN:
    sf.msw_cfg = true;
      u1_print_str_rtc("MSW-CFG Pressed.\n");
    break;
    
  case MSW_TAMPER_PIN:
    sf.msw_tmp = true;
      u1_print_str_rtc("MSW-TAMPER Pressed.\n");
    break;
    
    default:
      u1_print_str_rtc("Undefined Pin Intp!\n");
      break;
  }
}
/* USER CODE END 2 */
