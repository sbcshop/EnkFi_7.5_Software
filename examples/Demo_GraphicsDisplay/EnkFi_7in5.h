#ifndef _ENKFI_7IN5_H_
#define _ENKFI_7IN5_H_

#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

#define DISPLAY_SCK_PIN   12
#define DISPLAY_MOSI_PIN  11
#define DISPLAY_CS_PIN    10
#define DISPLAY_BUSY_PIN  21 
#define DISPLAY_RST_PIN   14
#define DISPLAY_DC_PIN    13

#define GPIO_SET   1
#define GPIO_RESET 0

// Display resolution
#define ENKFI_WIDTH       800
#define ENKFI_HEIGHT      480

void ENKFI_Config(void);
uint8_t ENKFI_Init(void);
void ENKFI_SPI(uint8_t data);
void ENKFI_Clear(void);
void ENKFI_ClearRed(void);
void ENKFI_ClearBlack(void);
void ENKFI_Display_Black_Red(const uint8_t *blackimage, const uint8_t *redimage);
void ENKFI_Display_Black(const uint8_t *blackimage);
void ENKFI_Display_Red(const uint8_t *redimage);

void ENKFI_Sleep(void);

#endif
