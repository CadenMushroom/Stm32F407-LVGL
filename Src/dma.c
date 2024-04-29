/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
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

/* Includes ------------------------------------------------------------------*/
#include "dma.h"
#include "lv_port_disp.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
DMA_HandleTypeDef hdma_memtomem_dma2_stream7;

/**
  * Enable DMA controller clock
  * Configure DMA for memory to memory transfers
  *   hdma_memtomem_dma2_stream7
  */
void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* Configure DMA request hdma_memtomem_dma2_stream7 on DMA2_Stream7 */
  hdma_memtomem_dma2_stream7.Instance = DMA2_Stream7;
  hdma_memtomem_dma2_stream7.Init.Channel = DMA_CHANNEL_0;
  hdma_memtomem_dma2_stream7.Init.Direction = DMA_MEMORY_TO_MEMORY;
  hdma_memtomem_dma2_stream7.Init.PeriphInc = DMA_PINC_ENABLE;
  hdma_memtomem_dma2_stream7.Init.MemInc = DMA_MINC_ENABLE;
  hdma_memtomem_dma2_stream7.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  hdma_memtomem_dma2_stream7.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  hdma_memtomem_dma2_stream7.Init.Mode = DMA_NORMAL;
  hdma_memtomem_dma2_stream7.Init.Priority = DMA_PRIORITY_LOW;
  hdma_memtomem_dma2_stream7.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
  hdma_memtomem_dma2_stream7.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
  hdma_memtomem_dma2_stream7.Init.MemBurst = DMA_MBURST_INC8;
  hdma_memtomem_dma2_stream7.Init.PeriphBurst = DMA_MBURST_INC8;
  if (HAL_DMA_Init(&hdma_memtomem_dma2_stream7) != HAL_OK)
  {
    Error_Handler();
  }

  /* DMA interrupt init */
  /* DMA2_Stream7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

	HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream7, HAL_DMA_XFER_CPLT_CB_ID, LVGL_LCD_FSMC_DMA_pCallback);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

