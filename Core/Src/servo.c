/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-27 20:15:31
 * @LastEditors: Mr.Luo keman_ljl@163.com
 * @LastEditTime: 2025-03-21 15:35:24
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

    // 设置舵机初始角度
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 180);
}

void Servo_SetAngle(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t angle) {
    // 将角度转换为 PWM 占空比
    // 对应 1 MHz 时钟，周期为 20 ms (20000 us)，最小脉宽 0.5 ms，最大脉宽 2.5 ms
    uint32_t pulse = (angle * 2000 / 180) + 500; // 调整为 1 MHz 时钟
    __HAL_TIM_SET_COMPARE(htim, Channel, pulse); // 设置 PWM 占空比
}
