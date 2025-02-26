/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-26 10:55:42
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-02-26 10:57:14
 * @FilePath: \desktop-dog-Bruce\Core\Inc\oled.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __OLED_H__
#define __OLED_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

// OLED I2C address
#define OLED_I2C_ADDRESS 0x78

// Function prototypes
void OLED_Init(void);
void OLED_Clear(void);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_ShowChar(uint8_t x, uint8_t y, char chr);
void OLED_ShowString(uint8_t x, uint8_t y, char *chr);

#ifdef __cplusplus
}
#endif

#endif /* __OLED_H__ */
