#include "oled.h"
#include "i2c.h"

// Send command to OLED
static void OLED_Write_Command(uint8_t command) {
    uint8_t data[2] = {0x00, command};
    HAL_I2C_Master_Transmit(&hi2c1, OLED_I2C_ADDRESS, data, 2, HAL_MAX_DELAY);
}

// Send data to OLED
static void OLED_Write_Data(uint8_t data) {
    uint8_t data_array[2] = {0x40, data};
    HAL_I2C_Master_Transmit(&hi2c1, OLED_I2C_ADDRESS, data_array, 2, HAL_MAX_DELAY);
}

void OLED_Init(void) {
    // Initialization sequence for SSD1306
    OLED_Write_Command(0xAE); // Display off
    OLED_Write_Command(0x20); // Set Memory Addressing Mode
    OLED_Write_Command(0x10); // 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    OLED_Write_Command(0xB0); // Set Page Start Address for Page Addressing Mode,0-7
    OLED_Write_Command(0xC8); // Set COM Output Scan Direction
    OLED_Write_Command(0x00); // ---set low column address
    OLED_Write_Command(0x10); // ---set high column address
    OLED_Write_Command(0x40); // --set start line address
    OLED_Write_Command(0x81); // --set contrast control register
    OLED_Write_Command(0xFF);
    OLED_Write_Command(0xA1); // --set segment re-map 0 to 127
    OLED_Write_Command(0xA6); // --set normal display
    OLED_Write_Command(0xA8); // --set multiplex ratio(1 to 64)
    OLED_Write_Command(0x3F); //
    OLED_Write_Command(0xA4); // 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    OLED_Write_Command(0xD3); // -set display offset
    OLED_Write_Command(0x00); // -not offset
    OLED_Write_Command(0xD5); // --set display clock divide ratio/oscillator frequency
    OLED_Write_Command(0xF0); // --set divide ratio
    OLED_Write_Command(0xD9); // --set pre-charge period
    OLED_Write_Command(0x22); //
    OLED_Write_Command(0xDA); // --set com pins hardware configuration
    OLED_Write_Command(0x12);
    OLED_Write_Command(0xDB); // --set vcomh
    OLED_Write_Command(0x20); // 0x20,0.77xVcc
    OLED_Write_Command(0x8D); // --set DC-DC enable
    OLED_Write_Command(0x14); //
    OLED_Write_Command(0xAF); // --turn on oled panel
}

void OLED_Clear(void) {
    for (uint8_t i = 0; i < 8; i++) {
        OLED_Write_Command(0xB0 + i); // Set page address
        OLED_Write_Command(0x00); // Set low column address
        OLED_Write_Command(0x10); // Set high column address
        for (uint8_t j = 0; j < 128; j++) {
            OLED_Write_Data(0x00);
        }
    }
}

void OLED_Display_On(void) {
    OLED_Write_Command(0x8D); // Set DC-DC enable
    OLED_Write_Command(0x14); //
    OLED_Write_Command(0xAF); // Display ON
}

void OLED_Display_Off(void) {
    OLED_Write_Command(0x8D); // Set DC-DC disable
    OLED_Write_Command(0x10); //
    OLED_Write_Command(0xAE); // Display OFF
}

void OLED_Set_Pos(uint8_t x, uint8_t y) {
    OLED_Write_Command(0xB0 + y);
    OLED_Write_Command(((x & 0xF0) >> 4) | 0x10);
    OLED_Write_Command((x & 0x0F) | 0x01);
}

void OLED_ShowChar(uint8_t x, uint8_t y, char chr) {
    // Implement character display function
}

void OLED_ShowString(uint8_t x, uint8_t y, char *chr) {
    // Implement string display function
}
