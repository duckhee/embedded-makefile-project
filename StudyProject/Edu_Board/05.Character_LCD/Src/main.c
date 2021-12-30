#include "main.h"
#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "CLCD.h"
#include "uart.h"

void SystemClock_Config(void);
static void MX_NVIC_Init(void);

uint8_t res[50] = "Interrupt\r\n";
uint8_t rx3_data;

int main(){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_Switch_Init();
    HAL_UART_MspInit(&huart3);
    MX_USART3_UART_Init();
    MX_NVIC_Init();
    LCD_Init();
    CLCD_Init();
    CLCD_Puts(0, 0, "Hello World");
    CLCD_Puts(0, 1, "M-Hive");
    HAL_UART_Receive_IT(&huart3, &rx3_data, 1);
    /** LED OFF */
    HAL_GPIO_WritePin(LED1_PORT, LED1_RED | LED1_BLUE | LED1_GREEN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_PORT, LED2_BLUE | LED2_GREEN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_PORT2, LED2_RED, GPIO_PIN_SET);
    LED_Test();
    HAL_GPIO_WritePin(LED1_PORT, LED1_RED | LED1_BLUE | LED1_GREEN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_PORT, LED2_BLUE | LED2_GREEN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_PORT2, LED2_RED, GPIO_PIN_SET);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    CLCD_Clear();
	  uint8_t a = 0;
	  float f = 1.234;
    uint8_t str[20] = {'\0'};
    while(1){
        sprintf(str, "%d", a++);
        /** 문자열을 복사하는 함수 */
        //sprintf(str, "%f", f);
        CLCD_Puts(0, 0, str);
        HAL_Delay(1000);
        if((a/10) == 0){
          CLCD_Clear();
        }
    }
    return 0;
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USART3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART3)
	{
		HAL_UART_Receive_IT(&huart3, &rx3_data, 1);
    HAL_UART_Transmit(&huart3, "\r\n", 1, 10);
		HAL_UART_Transmit(&huart3, &res, 50, 10);
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */