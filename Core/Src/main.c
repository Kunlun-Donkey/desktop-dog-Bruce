/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "oled_images.h"
#include "servo.h"
#include "usart.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init(); // 初始化 UART3

  /* USER CODE BEGIN 2 */
  OLED_Init();
  OLED_Clear();
  OLED_ShowString(0, 0, "Hello, OLED!");

  // 初始化舵机
  Servo_Init();

  // 设置舵机角度
  Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
  Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
  Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
  Servo_SetAngle(&htim2, TIM_CHANNEL_4, 180);

  printf("UART3 initialized successfully!\r\n");

  /* USER CODE BEGIN Demo */
  // 显示图片
  //OLED_ShowImage(0, 2, image_data, 128, 64);

  // 显示GIF
  // OLED_ShowGIF(gif_frames, 2, 128, 64, 500);
  /* USER CODE END Demo */

  /* USER CODE END 2 */

  /* 打印初始化完成日志 */
  printf("System initialized successfully!\r\n");

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    for (uint8_t angle = 0; angle <= 180; angle += 10) {
        // 设置舵机角度
        Servo_SetAngle(&htim2, TIM_CHANNEL_1, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_2, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_3, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_4, angle);

        // 在 OLED 上显示当前角度
        OLED_Clear();
        char angleStr[16];
        snprintf(angleStr, sizeof(angleStr), "Angle: %d", angle);
        OLED_ShowString(0, 0, angleStr);

        // 延迟一段时间
        HAL_Delay(500);
    }

    for (uint8_t angle = 180; angle > 0; angle -= 10) {
        // 设置舵机角度
        Servo_SetAngle(&htim2, TIM_CHANNEL_1, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_2, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_3, angle);
        Servo_SetAngle(&htim2, TIM_CHANNEL_4, angle);

        // 在 OLED 上显示当前角度
        OLED_Clear();
        char angleStr[16];
        snprintf(angleStr, sizeof(angleStr), "Angle: %d", angle);
        OLED_ShowString(0, 0, angleStr);

        // 延迟一段时间
        HAL_Delay(500);
    }
    /* USER CODE END WHILE */

    /* Test GPIOB0 LED, Set hight level */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

    // 打印循环日志
    printf("Main loop running...\r\n");
    HAL_Delay(1000); // 延迟 1 秒
    /* USER CODE END 3 */
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

    /** 使能 HSE 并配置 PLL */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;  // 8MHz * 9 = 72MHz
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** 配置系统时钟、AHB、APB 时钟 */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;   // APB1 最大 36MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;   // APB2 最高 72MHz

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
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

#ifdef  USE_FULL_ASSERT
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
