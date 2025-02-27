#include "servo.h"
#include "tim.h"

void Servo_Init(void) {
    // 启动 PWM 输出
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

void Servo_SetAngle(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t angle) {
    // 将角度转换为 PWM 占空比
    uint32_t pulse = (angle * 2000 / 180) + 500;
    __HAL_TIM_SET_COMPARE(htim, Channel, pulse);
}
