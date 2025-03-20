#include "servo.h"
#include "tim.h"
#include "action.h" // 包含 action.h，移除重复定义

// 定义全局回调结构体实例
ActionCallbacks actionCallbacks;

/* 
description: add the servo actions

*/


void Action_relaxed_getdowm(void)
{
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 20);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 20);
    HAL_Delay(80);
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 160);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 160);
}

void Action_upright(void)//站立
{
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    HAL_Delay(80);
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);

    // if (WeiBa == 1)
    // {
    //     Action_Mode = 9;
    // }
}

void Action_upright2(void)//站立
{
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    HAL_Delay(80);
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);

    // if (WeiBa == 1)
    // {
    //     Action_Mode = 9;
    // }
}

void Action_getdowm(void)//趴下
{
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 20);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 20);
    HAL_Delay(80);
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 20);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 20);

    // if (WeiBa == 1)
    // {
    //     Action_Mode = 9;
    // }
}

void Action_sit(void)//坐下
{
    Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    HAL_Delay(80);
    Servo_SetAngle(&htim2, TIM_CHANNEL_3, 20);
    Servo_SetAngle(&htim2, TIM_CHANNEL_4, 20);

    // if (WeiBa == 1)
    // {
    //     Action_Mode = 9;
    // }
}

void Action_advance(void)//前进
{

    // while (Action_Mode == 4)
    // {
    //     PAnumbers = Chongfunumber;
    //     while ((PAnumbers || Sustainedmove) && Action_Mode == 4)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 45);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 135);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;

    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 45);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 135);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 4) break;

    //         PAnumbers--;
    //     }
    //     if (Sustainedmove != 1 && Action_Mode == 4)
    //         Action_Mode = 2;
    // }
}

void Action_back(void)//后退
{
    // while (Action_Mode == 5)
    // {
    //     PAnumbers = Chongfunumber;
    //     while ((PAnumbers || Sustainedmove) && Action_Mode == 5)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 135);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 45);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;

    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 135);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 45);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 5) break;

    //         PAnumbers--;
    //     }
    //     if (Sustainedmove != 1 && Action_Mode == 5)
    //         Action_Mode = 2;
    // }
}

void Action_Lrotation(void)//向左旋转
{
    // while (Action_Mode == 6)
    // {
    //     PAnumbers = Chongfunumber;
    //     PAnumbers = PAnumbers + Chongfunumber;
    //     while ((PAnumbers || Sustainedmove) && Action_Mode == 6)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 6) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 6) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 6) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 6) break;

    //         PAnumbers--;
    //     }
    //     if (Sustainedmove != 1 && Action_Mode == 6)
    //         Action_Mode = 2;
    // }
}

void Action_Rrotation(void)//向右旋转
{
    // while (Action_Mode == 7)
    // {
    //     PAnumbers = Chongfunumber;
    //     PAnumbers = PAnumbers + Chongfunumber;
    //     while ((PAnumbers || Sustainedmove) && Action_Mode == 7)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 7) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 45);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 135);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 7) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 7) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //         HAL_Delay(SpeedDelay);
    //         if (Action_Mode != 7) break;

    //         PAnumbers--;
    //     }
    //     if (Sustainedmove != 1 && Action_Mode == 7)
    //         Action_Mode = 2;
    // }
}

void Action_Swing(void)//摇摆
{
    // uint16_t SwingNumber = SwingRepeatnumber;
    // while (SwingNumber && Action_Mode == 8)
    // {
    //     for (uint8_t i = 30; i < 150; i++)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //         HAL_Delay(SwingDelay);
    //         if (Action_Mode != 8) break;
    //     }
    //     if (Action_Mode != 8) break;
    //     for (uint8_t i = 150; i > 30; i--)
    //     {
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //         HAL_Delay(SwingDelay);
    //         if (Action_Mode != 8) break;
    //     }
    //     if (Action_Mode != 8) break;

    //     SwingNumber--;
    // }
    // for (uint8_t i = 30; i < 90; i++)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //     HAL_Delay(SwingDelay);
    //     if (Action_Mode != 8) break;
    // }
    // if (Action_Mode == 8)
    //     Action_Mode = 2;
}

void Action_SwingTail(void)//摇尾巴
{
    // uint16_t SwingTailNumber = 3;
    // HAL_Delay(60);
    // while (SwingTailNumber && Action_Mode == 9)
    // {
    //     for (uint8_t i = 30; i < 150; i++)
    //     {
    //         WServo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //         HAL_Delay(SwingDelay);
    //         if (Action_Mode != 9) break;
    //     }
    //     if (Action_Mode != 9) break;
    //     for (uint8_t i = 150; i > 30; i--)
    //     {
    //         WServo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //         HAL_Delay(SwingDelay);
    //         if (Action_Mode != 9) break;
    //     }
    //     if (Action_Mode != 9) break;
    //     SwingTailNumber--;
    // }
    // HAL_Delay(60);
}

void Action_JumpU(void)//向前跳
{
    // if (TiaoTurn == 0)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 140);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 35);
    //     HAL_Delay(SpeedDelay);

    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 140);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 35);
    //     HAL_Delay(SpeedDelay + 80);

    //     Action_Mode = 2;
    //     TiaoTurn = 1;
    // }
    // else
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 140);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 35);
    //     HAL_Delay(SpeedDelay);

    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 140);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 35);
    //     HAL_Delay(SpeedDelay + 80);

    //     Action_Mode = 2;
    //     TiaoTurn = 0;
    // }
}

void Action_JumpD(void)//向后跳
{
    // if (TiaoTurn2 == 0)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 35);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 140);
    //     HAL_Delay(SpeedDelay);

    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 35);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 140);
    //     HAL_Delay(SpeedDelay);

    //     Action_Mode = 12;
    //     TiaoTurn2 = 1;
    // }
    // else
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 35);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 140);
    //     HAL_Delay(SpeedDelay);

    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 35);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 140);
    //     HAL_Delay(SpeedDelay);

    //     Action_Mode = 12;
    //     TiaoTurn2 = 0;
    // }
}

void Action_Hello(void)
{
    // uint16_t HelloNumber = HelloRepeatnumber;

    // Servo_SetAngle(&htim2, TIM_CHANNEL_3, 20);
    // Servo_SetAngle(&htim2, TIM_CHANNEL_4, 45);
    // HAL_Delay(80);
    // Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    // while (HelloNumber && Action_Mode == 13)
    // {
    //     if (Action_Mode != 13) break;
    //     for (int i = 0; i <= 45; i++)
    //     {
    //         if (Action_Mode != 13) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //         HAL_Delay(SwingDelay);
    //     }
    //     for (int i = 45; i > 0; i--)
    //     {
    //         if (Action_Mode != 13) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //         HAL_Delay(SwingDelay);
    //     }
    //     if (Action_Mode != 13) break;

    //     HelloNumber--;
    // }
    // if (Action_Mode == 13)
    //     Action_Mode = 2;
}

void Action_stretch(void)//伸懒腰
{
    // Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    // Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    // HAL_Delay(80);
    // for (int i = 90; i > 10; i--)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //     if (Action_Mode != 14) break;
    //     HAL_Delay(15);
    // }
    // for (int i = 10; i < 90; i++)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, i);
    //     if (Action_Mode != 14) break;
    //     HAL_Delay(15);
    // }
    // for (int i = 90; i < 170; i++)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //     if (Action_Mode != 14) break;
    //     HAL_Delay(15);
    // }

    // for (int i = 170; i > 90; i--)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //     if (Action_Mode != 14) break;
    //     HAL_Delay(15);
    // }
    // if (Action_Mode == 14)
    //     Action_Mode = 15;
}

void Action_Lstretch(void)//后腿拉伸
{
    // int breakvalue = 1;
    // int temp = 3;
    // while (breakvalue)
    // {
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 20);
    //     HAL_Delay(60);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 110);
    //     for (int i = 90; i < 180; i++)
    //     {
    //         if (Action_Mode != 15) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //         HAL_Delay(6);
    //     }
    //     while (temp && Action_Mode == 15)
    //     {
    //         for (int i = 180; i > 150; i--)
    //         {
    //             if (Action_Mode != 15) break;
    //             Servo_SetAngle(&htim2, TIM_CHANNEL_3, i);
    //             HAL_Delay(15);
    //         }
    //         temp--;
    //     }
    //     if (Action_Mode != 15) break;
    //     HAL_Delay(100);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 90);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //     if (Action_Mode != 15) break;
    //     HAL_Delay(80);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 90);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_4, 90);
    //     HAL_Delay(100);
    //     if (Action_Mode != 15) break;

    //     temp = 3;

    //     Servo_SetAngle(&htim2, TIM_CHANNEL_2, 90);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_1, 20);
    //     if (Action_Mode != 15) break;
    //     HAL_Delay(60);
    //     Servo_SetAngle(&htim2, TIM_CHANNEL_3, 110);
    //     for (int i = 90; i < 180; i++)
    //     {
    //         if (Action_Mode != 15) break;
    //         Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //         HAL_Delay(6);
    //     }
    //     while (temp && Action_Mode == 15)
    //     {
    //         for (int i = 180; i > 150; i--)
    //         {
    //             if (Action_Mode != 15) break;
    //             Servo_SetAngle(&htim2, TIM_CHANNEL_4, i);
    //             HAL_Delay(15);
    //         }
    //         temp--;
    //     }
    //     if (Action_Mode == 15)
    //         Action_Mode = 2;

    //     breakvalue = 0;
    // }
}

// 注册回调函数
void Action_RegisterCallbacks(void) {
    actionCallbacks.RelaxedGetDown = Action_relaxed_getdowm;
    actionCallbacks.Upright = Action_upright;
    actionCallbacks.Upright2 = Action_upright2;
    actionCallbacks.GetDown = Action_getdowm;
    actionCallbacks.Sit = Action_sit;
    actionCallbacks.Advance = Action_advance;
    actionCallbacks.Back = Action_back;
    actionCallbacks.LeftRotation = Action_Lrotation;
    actionCallbacks.RightRotation = Action_Rrotation;
    actionCallbacks.Swing = Action_Swing;
    actionCallbacks.SwingTail = Action_SwingTail;
    actionCallbacks.JumpForward = Action_JumpU;
    actionCallbacks.JumpBackward = Action_JumpD;
    actionCallbacks.Hello = Action_Hello;
    actionCallbacks.Stretch = Action_stretch;
    actionCallbacks.LegStretch = Action_Lstretch;
}