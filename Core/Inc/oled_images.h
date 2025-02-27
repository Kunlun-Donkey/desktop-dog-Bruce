#ifndef __OLED_IMAGES_H__
#define __OLED_IMAGES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"



// 声明其他图片数组
extern unsigned char BMP_STAND_FACE[];
extern unsigned char BMP_FORWARD_FACE[];
extern unsigned char BMP_TURN_LEFT_FACE[];
extern unsigned char BMP_TURN_RIGHT_FACE[];
extern unsigned char BMP_SPECIAL_FACE[];
extern unsigned char BMP_SLEEP_FACE[];

#ifdef __cplusplus
}
#endif

#endif /* __OLED_IMAGES_H__ */
