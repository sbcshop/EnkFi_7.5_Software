/* Onboard E-paper Display Demo */
#include "EnkFi_7in5.h"
#include "imgData.h"
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

  printf("Display Image \r\n");
  ENKFI_Display_Black_Red(img_black, img_red);
  ENKFI_Display_Black(img_black);
  ENKFI_Display_Red(img_red);
  delay(2000);
  
  //ENKFI_Clear();
  printf("Sleep...\r\n");
  ENKFI_Sleep();
}

void loop()
{
  //
}
