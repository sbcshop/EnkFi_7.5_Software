#include "EnkFi_7in5.h"


void ENKFI_Config(void)
{
    pinMode(DISPLAY_BUSY_PIN,  INPUT);
    pinMode(DISPLAY_RST_PIN , OUTPUT);
    pinMode(DISPLAY_DC_PIN  , OUTPUT);
    
    pinMode(DISPLAY_SCK_PIN, OUTPUT);
    pinMode(DISPLAY_MOSI_PIN, OUTPUT);
    pinMode(DISPLAY_CS_PIN , OUTPUT);

    digitalWrite(DISPLAY_CS_PIN , HIGH);
    digitalWrite(DISPLAY_SCK_PIN, LOW);
}

/******************************************************************************
function:
      SPI read and write
******************************************************************************/
void ENKFI_SPI(uint8_t data)
{
    //SPI.beginTransaction(spi_settings);
    digitalWrite(DISPLAY_CS_PIN, GPIO_RESET);

    for (int i = 0; i < 8; i++)
    {
        if ((data & 0x80) == 0) digitalWrite(DISPLAY_MOSI_PIN, GPIO_RESET); 
        else                    digitalWrite(DISPLAY_MOSI_PIN, GPIO_SET);

        data <<= 1;
        digitalWrite(DISPLAY_SCK_PIN, GPIO_SET);     
        digitalWrite(DISPLAY_SCK_PIN, GPIO_RESET);
    }

    //SPI.transfer(data);
    digitalWrite(DISPLAY_CS_PIN, GPIO_SET);
    //SPI.endTransaction(); 
}

static void ENKFI_Reset(void)
{
    digitalWrite(DISPLAY_RST_PIN, 1);
    delay(200);
    digitalWrite(DISPLAY_RST_PIN, 0);
    delay(2);
    digitalWrite(DISPLAY_RST_PIN, 1);
    delay(200);
}

/******************************************************************************
function :  send command
parameter:
     Reg : Command register
******************************************************************************/
static void ENKFI_SendCommand(uint8_t Reg)
{
    digitalWrite(DISPLAY_DC_PIN, 0);
    digitalWrite(DISPLAY_CS_PIN, 0);
    ENKFI_SPI(Reg);
    digitalWrite(DISPLAY_CS_PIN, 1);
}

/******************************************************************************
function :  send data
parameter:
    Data : Write data
******************************************************************************/
static void ENKFI_SendData(uint8_t Data)
{
    digitalWrite(DISPLAY_DC_PIN, 1);
    digitalWrite(DISPLAY_CS_PIN, 0);
    ENKFI_SPI(Data);
}

/******************************************************************************
function :  Wait until the busy_pin goes LOW
parameter:
******************************************************************************/
void ENKFI_WaitUntilIdle(void)
{
    Serial.print("e-Paper busy\r\n");
    unsigned char busy;
  do  {
    ENKFI_SendCommand(0x71);
    busy = digitalRead(DISPLAY_BUSY_PIN);
    busy =!(busy & 0x01);        
  }while(busy);
  delay(200);      
    
    
    Serial.print("e-Paper busy release\r\n");
    
}


/******************************************************************************
function :  Turn On Display
parameter:
******************************************************************************/
static void ENKFI_TurnOnDisplay(void)
{
    ENKFI_SendCommand(0x12);     //DISPLAY REFRESH
    delay(100);         //!!!The delay here is necessary, 200uS at least!!!
    ENKFI_WaitUntilIdle();
}

/******************************************************************************
function :  Initialize the e-Paper register
parameter:
******************************************************************************/
uint8_t ENKFI_Init(void)
{
    ENKFI_Reset();

    // ENKFI_SendCommand(0x06);
    // ENKFI_SendData(0x17);
    // ENKFI_SendData(0x17);
    // ENKFI_SendData(0x38);
    // ENKFI_SendData(0x17);

    ENKFI_SendCommand(0x01);     //POWER SETTING
    ENKFI_SendData(0x07);
    ENKFI_SendData(0x07);    //VGH=20V,VGL=-20V
    ENKFI_SendData(0x3f);    //VDH=15V
    ENKFI_SendData(0x3f);    //VDL=-15V

    ENKFI_SendCommand(0x04); //POWER ON
    delay(100);
    ENKFI_WaitUntilIdle();

    ENKFI_SendCommand(0X00);     //PANNEL SETTING
    ENKFI_SendData(0x0F);   //KW-3f   KWR-2F BWROTP 0f BWOTP 1f

    ENKFI_SendCommand(0x61);         //tres
    ENKFI_SendData(0x03);    //source 800
    ENKFI_SendData(0x20);
    ENKFI_SendData(0x01);    //gate 480
    ENKFI_SendData(0xE0);

    ENKFI_SendCommand(0X15);
    ENKFI_SendData(0x00);

    ENKFI_SendCommand(0X50);     //VCOM AND DATA INTERVAL SETTING
    ENKFI_SendData(0x11);
    ENKFI_SendData(0x07);

    ENKFI_SendCommand(0X60);     //TCON SETTING
    ENKFI_SendData(0x22);

    ENKFI_SendCommand(0x65);  // Resolution setting
    ENKFI_SendData(0x00);
    ENKFI_SendData(0x00);//800*480
    ENKFI_SendData(0x00);
    ENKFI_SendData(0x00);
  
    return 0;
}

/******************************************************************************
function :  Clear screen
parameter:
******************************************************************************/
void ENKFI_Clear(void)
{
    uint16_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

    uint16_t i;
    ENKFI_SendCommand(0x10);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0xff);

    }
    ENKFI_SendCommand(0x13);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0x00);

    }
    ENKFI_TurnOnDisplay();
}

void ENKFI_ClearRed(void)
{
    uint16_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

    uint16_t i;
    ENKFI_SendCommand(0x10);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0xff);

    }
    ENKFI_SendCommand(0x13);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0xff);

    }
    ENKFI_TurnOnDisplay();
}

void ENKFI_ClearBlack(void)
{
    uint16_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

    uint16_t i;
    ENKFI_SendCommand(0x10);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0x00);

    }
    ENKFI_SendCommand(0x13);
    for(i=0; i<Width*Height; i++) {
        ENKFI_SendData(0x00);

    }
    ENKFI_TurnOnDisplay();
}

/******************************************************************************
function :  Sends the image buffer in RAM to e-Paper and displays
parameter:
******************************************************************************/

void ENKFI_Display_Black_Red(const uint8_t *black_img, const uint8_t *red_img)
{
    uint32_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

 //send black data
    ENKFI_SendCommand(0x10);
    for (uint32_t j = 0; j < Height; j++) {
        for (uint32_t i = 0; i < Width; i++) {
            ENKFI_SendData(black_img[i + j * Width]);
        }
    }
    ENKFI_SendCommand(0x92); 

    //send red data
    ENKFI_SendCommand(0x13);
    for (uint32_t j = 0; j < Height; j++) {
        for (uint32_t i = 0; i < Width; i++) {
            ENKFI_SendData(~red_img[i + j * Width]);
        }
    }
    ENKFI_TurnOnDisplay();
}


void ENKFI_Display_Black(const uint8_t *black_img)
{
    uint32_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

 //send black data
    ENKFI_SendCommand(0x10);
    for (uint32_t j = 0; j < Height; j++) {
        for (uint32_t i = 0; i < Width; i++) {
            ENKFI_SendData(black_img[i + j * Width]);
        }
    }
    //ENKFI_SendCommand(0x92); 

    ENKFI_TurnOnDisplay();
}

void ENKFI_Display_Red(const uint8_t *red_img)
{
    uint32_t Width, Height;
    Width =(ENKFI_WIDTH % 8 == 0)?(ENKFI_WIDTH / 8 ):(ENKFI_WIDTH / 8 + 1);
    Height = ENKFI_HEIGHT;

  //send red data
    ENKFI_SendCommand(0x13);
    for (uint32_t j = 0; j < Height; j++) {
        for (uint32_t i = 0; i < Width; i++) {
            ENKFI_SendData(~red_img[i + j * Width]);
        }
    }
    ENKFI_TurnOnDisplay();
}

/******************************************************************************
function :  Enter sleep mode
parameter:
******************************************************************************/
void ENKFI_Sleep(void)
{
    ENKFI_SendCommand(0X02);   //power off
    ENKFI_WaitUntilIdle();
    ENKFI_SendCommand(0X07);   //deep sleep
    ENKFI_SendData(0xA5);
}
