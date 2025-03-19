/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-27 20:15:31
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-03-19 09:17:18
 * @FilePath: \desktop-dog-Bruce\Core\Src\servo.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
    // 对应 8 MHz 时钟，周期为 20 ms (20000 us)，最小脉宽 0.5 ms，最大脉宽 2.5 ms
    uint32_t pulse = (angle * 2000 / 180) + 1000; // 调整为 8 MHz 时钟
    __HAL_TIM_SET_COMPARE(htim, Channel, pulse);
}
