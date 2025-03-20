/*
 * @Author: luojialei luojialei@jiqid.com
 * @Date: 2025-03-20 14:23:42
 * @LastEditors: luojialei luojialei@jiqid.com
 * @LastEditTime: 2025-03-20 14:24:24
 * @FilePath: \desktop-dog-Bruce\Core\Inc\action.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef ACTION_H
#define ACTION_H

#include "stm32f1xx_hal.h"

// 定义动作回调结构体
typedef struct {
    void (*RelaxedGetDown)(void);
    void (*Upright)(void);
    void (*Upright2)(void);
    void (*GetDown)(void);
    void (*Sit)(void);
    void (*Advance)(void);
    void (*Back)(void);
    void (*LeftRotation)(void);
    void (*RightRotation)(void);
    void (*Swing)(void);
    void (*SwingTail)(void);
    void (*JumpForward)(void);
    void (*JumpBackward)(void);
    void (*Hello)(void);
    void (*Stretch)(void);
    void (*LegStretch)(void);
} ActionCallbacks;

// 声明全局回调结构体实例
extern ActionCallbacks actionCallbacks;

// 动作函数声明
void Action_relaxed_getdowm(void);
void Action_upright(void);
void Action_upright2(void);
void Action_getdowm(void);
void Action_sit(void);
void Action_advance(void);
void Action_back(void);
void Action_Lrotation(void);
void Action_Rrotation(void);
void Action_Swing(void);
void Action_SwingTail(void);
void Action_JumpU(void);
void Action_JumpD(void);
void Action_Hello(void);
void Action_stretch(void);
void Action_Lstretch(void);

// 注册回调函数
void Action_RegisterCallbacks(void);

#endif // ACTION_H
