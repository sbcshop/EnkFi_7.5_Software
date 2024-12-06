/* Onboard E-paper Display Demo */
#include "EnkFi_7in5.h"
#include "Graphics.h"
#include <stdlib.h>

void setup()
{
  Serial.begin(115200); // initialize Serial communication
  printf("EnkFi 7in5 Display Demo\r\n");
  ENKFI_Config(); // initialize pin configuration for E-paper

  printf("E-paper Init and Clear\r\n");
  ENKFI_Init();
  ENKFI_Clear();
  delay(500);

  //Create a new image cache named IMAGE_BW and fill it with white
  uint8_t *blackImg, *redImg;
  uint16_t Imagesize = ((ENKFI_WIDTH % 8 == 0) ? (ENKFI_WIDTH / 8 ) : (ENKFI_WIDTH / 8 + 1)) * ENKFI_HEIGHT;
  if ((blackImg = (uint8_t *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while(1);
  }
  
  if ((redImg = (uint8_t *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for red memory...\r\n");
    while(1);
  }
 
  Graphics_NewImage(blackImg, ENKFI_WIDTH, ENKFI_HEIGHT , 0, WHITE);
  Graphics_NewImage(redImg, ENKFI_WIDTH, ENKFI_HEIGHT , 0, WHITE);

  printf("Select Image...\r\n");
  //Select Image
  Graphics_SelectImage(blackImg);
  Graphics_Clear(WHITE);
  Graphics_SelectImage(redImg);
  Graphics_Clear(WHITE);

  printf("Draw Black Image...\r\n");
  //1.Create Graphics as black image
  Graphics_SelectImage(blackImg);
  //Graphics_Clear(WHITE);
  Graphics_DrawPoint(20, 100, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  Graphics_DrawPoint(20, 120, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Graphics_DrawLine(20, 100, 200, 200, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
  Graphics_DrawRectangle(200, 200, 700, 400, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Graphics_DrawString_EN(200, 400, "SBComponents", &Font24, BLACK, WHITE);

  printf("Draw Red Image...\r\n");
  //2.Create Graphics as red image
  Graphics_SelectImage(redImg);
  //Graphics_Clear(WHITE);
  Graphics_DrawCircle(500, 140, 100, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Graphics_DrawCircle(210, 95, 40, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Graphics_DrawLine(85, 95, 300, 95, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Graphics_DrawString_EN(10, 20, "Hello world", &Font12, WHITE, BLACK);

  printf("Display Image \r\n");
  ENKFI_Display_Black_Red(blackImg, redImg);
  
  //ENKFI_Clear();
  printf("Sleep...\r\n");
  ENKFI_Sleep();
  free(blackImg);
  free(redImg);
  blackImg = NULL;
  redImg = NULL;
}

void loop()
{
  //
}
