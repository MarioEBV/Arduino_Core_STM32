/**
  ******************************************************************************
  * @file    stm32l1xx_hal_sram.h
  * @author  MCD Application Team
  * @brief   Header file of SRAM HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L1xx_HAL_SRAM_H
#define __STM32L1xx_HAL_SRAM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_ll_fsmc.h"

/** @addtogroup STM32L1xx_HAL_Driver
  * @{
  */

#if defined (STM32L151xD) || defined (STM32L152xD) || defined (STM32L162xD)

/** @addtogroup SRAM
  * @{
  */

/* Exported typedef ----------------------------------------------------------*/

/** @defgroup SRAM_Exported_Types SRAM Exported Types
  * @{
  */
/**
  * @brief  HAL SRAM State structures definition
  */
typedef enum
{
  HAL_SRAM_STATE_RESET     = 0x00,  /*!< SRAM not yet initialized or disabled           */
  HAL_SRAM_STATE_READY     = 0x01,  /*!< SRAM initialized and ready for use             */
  HAL_SRAM_STATE_BUSY      = 0x02,  /*!< SRAM internal process is ongoing               */
  HAL_SRAM_STATE_ERROR     = 0x03,  /*!< SRAM error state                               */
  HAL_SRAM_STATE_PROTECTED = 0x04   /*!< SRAM peripheral NORSRAM device write protected */

}HAL_SRAM_StateTypeDef;

/**
  * @brief  SRAM handle Structure definition
  */
typedef struct
{
  FSMC_NORSRAM_TypeDef           *Instance;  /*!< Register base address                        */

  FSMC_NORSRAM_EXTENDED_TypeDef  *Extended;  /*!< Extended mode register base address          */

  FSMC_NORSRAM_InitTypeDef       Init;       /*!< SRAM device control configuration parameters */

  HAL_LockTypeDef               Lock;       /*!< SRAM locking object                          */

  __IO HAL_SRAM_StateTypeDef    State;      /*!< SRAM device access state                     */

  DMA_HandleTypeDef             *hdma;      /*!< Pointer DMA handler                          */

}SRAM_HandleTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/** @defgroup SRAM_Exported_Macros SRAM Exported Macros
  * @{
  */

/** @brief Reset SRAM handle state
  * @param  __HANDLE__ SRAM handle
  * @retval None
  */
#define __HAL_SRAM_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SRAM_STATE_RESET)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup SRAM_Exported_Functions
 *  @{
 */

/** @addtogroup SRAM_Exported_Functions_Group1
 *  @{
 */

/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_SRAM_Init(SRAM_HandleTypeDef *hsram, FSMC_NORSRAM_TimingTypeDef *Timing, FSMC_NORSRAM_TimingTypeDef *ExtTiming);
HAL_StatusTypeDef HAL_SRAM_DeInit(SRAM_HandleTypeDef *hsram);
void              HAL_SRAM_MspInit(SRAM_HandleTypeDef *hsram);
void              HAL_SRAM_MspDeInit(SRAM_HandleTypeDef *hsram);

void              HAL_SRAM_DMA_XferCpltCallback(DMA_HandleTypeDef *hdma);
void              HAL_SRAM_DMA_XferErrorCallback(DMA_HandleTypeDef *hdma);

/**
  * @}
  */

/** @addtogroup SRAM_Exported_Functions_Group2
 *  @{
 */

/* I/O operation functions  *****************************************************/
HAL_StatusTypeDef HAL_SRAM_Read_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pDstBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pSrcBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pDstBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pSrcBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize);

/**
  * @}
  */

/** @addtogroup SRAM_Exported_Functions_Group3
 *  @{
 */

/* SRAM Control functions  ******************************************************/
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Enable(SRAM_HandleTypeDef *hsram);
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Disable(SRAM_HandleTypeDef *hsram);

/**
  * @}
  */

/** @addtogroup SRAM_Exported_Functions_Group4
 *  @{
 */

/* SRAM State functions *********************************************************/
HAL_SRAM_StateTypeDef HAL_SRAM_GetState(SRAM_HandleTypeDef *hsram);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* STM32L151xD || STM32L152xD || STM32L162xD */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L1xx_HAL_SRAM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
