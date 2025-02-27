/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-27 20:15:23
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-02-27 20:18:20
 * @FilePath: \desktop-dog-Bruce\Core\Inc\servo.h
 * @Description: servo
 */
#ifndef __SERVO_H__
#define __SERVO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

// Function prototypes
void Servo_Init(void);
void Servo_SetAngle(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t angle);

#ifdef __cplusplus
}
#endif

#endif /* __SERVO_H__ */
