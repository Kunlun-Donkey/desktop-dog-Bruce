/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-02-26 10:55:42
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-02-26 20:28:06
 * @FilePath: \desktop-dog-Bruce\Core\Inc\oled.h
 * @Description: oled.h
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
void OLED_ShowImage(uint8_t x, uint8_t y, const uint8_t *image, uint8_t width, uint8_t height);
void OLED_ShowGIF(const uint8_t **frames, uint8_t frame_count, uint8_t width, uint8_t height, uint16_t delay);

#ifdef __cplusplus
}
#endif

#endif /* __OLED_H__ */
