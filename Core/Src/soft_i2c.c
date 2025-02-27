#include "soft_i2c.h"
#include "gpio.h"

#define SDA_HIGH() HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET)
#define SDA_LOW()  HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_RESET)
#define SCL_HIGH() HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET)
#define SCL_LOW()  HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_RESET)
#define SDA_READ() HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin)

void Soft_I2C_Delay(void) {
    for (volatile int i = 0; i < 100; i++);
}

void Soft_I2C_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configure SDA and SCL pins as open-drain
    GPIO_InitStruct.Pin = SDA_Pin | SCL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(SDA_GPIO_Port, &GPIO_InitStruct);

    SDA_HIGH();
    SCL_HIGH();
}

void Soft_I2C_Start(void) {
    SDA_HIGH();
    SCL_HIGH();
    Soft_I2C_Delay();
    SDA_LOW();
    Soft_I2C_Delay();
    SCL_LOW();
}

void Soft_I2C_Stop(void) {
    SDA_LOW();
    SCL_HIGH();
    Soft_I2C_Delay();
    SDA_HIGH();
    Soft_I2C_Delay();
}

void Soft_I2C_Write(uint8_t data) {
    for (int i = 0; i < 8; i++) {
        if (data & 0x80) {
            SDA_HIGH();
        } else {
            SDA_LOW();
        }
        data <<= 1;
        SCL_HIGH();
        Soft_I2C_Delay();
        SCL_LOW();
        Soft_I2C_Delay();
    }
    SDA_HIGH();
    SCL_HIGH();
    Soft_I2C_Delay();
    SCL_LOW();
}

uint8_t Soft_I2C_Read(uint8_t ack) {
    uint8_t data = 0;
    SDA_HIGH();
    for (int i = 0; i < 8; i++) {
        SCL_HIGH();
        Soft_I2C_Delay();
        data = (data << 1) | SDA_READ();
        SCL_LOW();
        Soft_I2C_Delay();
    }
    if (ack) {
        SDA_LOW();
    } else {
        SDA_HIGH();
    }
    SCL_HIGH();
    Soft_I2C_Delay();
    SCL_LOW();
    SDA_HIGH();
    return data;
}
