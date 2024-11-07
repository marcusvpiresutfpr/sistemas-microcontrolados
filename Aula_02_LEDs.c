#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void SetLEDBits(uint8_t hexValue)
{
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, (hexValue & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, (hexValue & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, (hexValue & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, (hexValue & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, (hexValue & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, (hexValue & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, (hexValue & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, (hexValue & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

uint8_t displayNum[10] = {
    (0b00111111), // 0
    (0b00000110), // 1
    (0b01011011), // 2
    (0b01001111), // 3
    (0b01100110), // 4
    (0b01101101), // 5
    (0b01111101), // 6
    (0b00000111), // 7
    (0b01111111), // 8
    (0b01101111) // 9
}

int main(void)
{
  uint32_t i;
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  for (i = 0; i < 13; i++)
  {
    HAL_GPIO_WritePin(KIT_LED_GPIO_Port, KIT_LED_Pin, 0);
    HAL_Delay(25);
    HAL_GPIO_WritePin(KIT_LED_GPIO_Port, KIT_LED_Pin, 1);
    HAL_Delay(50);
  }

  HAL_GPIO_WritePin(EN_DISP1_GPIO_Port, EN_DISP1_Pin, 1); // enable display 01
  while (1)
  {

    // // Exercice 01 -----------------------------
    // for (int i = 0; i < 5; i++)
    // {
    //   SetLEDBits(0xFF);
    //   HAL_Delay(500); // atraso de 0,5s

    //   SetLEDBits(0x00);
    //   HAL_Delay(500); // atraso de 0,5s
    // }

    // // piscar 0x0f e 0xf0
    // for (int i = 0; i < 5; i++)
    // {
    //   SetLEDBits(0b00001111);
    //   HAL_Delay(500); // atraso de 0,5s

    //   SetLEDBits(0b11110000);
    //   HAL_Delay(500); // atraso de 0,5s
    // }

    // // piscar 0x0f e 0xf0
    // for (int i = 0; i < 5; i++)
    // {
    //   SetLEDBits(0xaa);
    //   HAL_Delay(500); // atraso de 0,5s

    //   SetLEDBits(0x55);
    //   HAL_Delay(500); // atraso de 0,5s
    // }

    // // Display in binnary from 0x00 to 0xFF
    // for (uint8_t i = 0x00; i <= 0xFF; i++)
    // {
    //   SetLEDBits(i);
    //   HAL_Delay(500);
    // }

    // SetLEDBits(0b00111111); // 0
    // SetLEDBits(0b00000110); // 1
    // SetLEDBits(0b01011011); // 2
    // SetLEDBits(0b01001111); // 3
    // SetLEDBits(0b01100110); // 4
    // SetLEDBits(0b01101101); // 5
    // SetLEDBits(0b01111101); // 6
    // SetLEDBits(0b00000111); // 7
    // SetLEDBits(0b01111111); // 8
    // SetLEDBits(0b01101111); // 9

    for (int i = 0; i )

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(KIT_LED_GPIO_Port, KIT_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin | LED7_Pin | LED8_Pin | EN_DISP1_Pin | EN_DISP2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EN_LEDS_GPIO_Port, EN_LEDS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : KIT_LED_Pin */
  GPIO_InitStruct.Pin = KIT_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KIT_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin LED7_Pin LED8_Pin
                           EN_DISP1_Pin EN_DISP2_Pin */
  GPIO_InitStruct.Pin = LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin | LED7_Pin | LED8_Pin | EN_DISP1_Pin | EN_DISP2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : EN_LEDS_Pin */
  GPIO_InitStruct.Pin = EN_LEDS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EN_LEDS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SW1_Pin SW2_Pin */
  GPIO_InitStruct.Pin = SW1_Pin | SW2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
