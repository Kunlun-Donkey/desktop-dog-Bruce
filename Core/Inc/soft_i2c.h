/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-27 09:18:18
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-02-27 09:21:39
 * @FilePath: \desktop-dog-Bruce\Core\Inc\soft_i2c.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __SOFT_I2C_H__
#define __SOFT_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

// Function prototypes
void Soft_I2C_Init(void);
void Soft_I2C_Start(void);
void Soft_I2C_Stop(void);
void Soft_I2C_Write(uint8_t data);
uint8_t Soft_I2C_Read(uint8_t ack);

#ifdef __cplusplus
}
#endif

#endif /* __SOFT_I2C_H__ */
