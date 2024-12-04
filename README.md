# EnkFi 7.5" Software
<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/Main_Banner_3.png?v=1729493200" />

The EnkFi series, **powered** by the **ESP32 S3 WROOM**, offers versatile **e-paper display** options in **[2.9”](https://shop.sb-components.co.uk/products/enkfi-epaper-display-board-based-on-esp32-s3-wroom-1?variant=41443707846739), [4.2”](https://shop.sb-components.co.uk/products/enkfi-epaper-display-board-based-on-esp32-s3-wroom-1?variant=41443707879507), [5.83”](https://shop.sb-components.co.uk/products/enkfi-epaper-display-board-based-on-esp32-s3-wroom-1?variant=41443707912275), and [7.5”](https://shop.sb-components.co.uk/products/enkfi-epaper-display-board-based-on-esp32-s3-wroom-1?variant=41443707945043)** sizes, catering to diverse application needs. These displays feature a wide viewing angle of over 170 degrees and utilize bistable technology, ensuring no power consumption when the screen is not refreshed, making them highly energy-efficient. The black-white-red color scheme protects the eyes by eliminating blue light and radiation. With built-in WiFi and BLE capabilities, the EnkFi series is ideal for IoT-based projects, providing robust connectivity.

This GitHub provides getting started instructions to use EnkFi 7.5" E-Paper.

### Features
- EnkFi series powered by **ESP32 S3 WROOM-1**
- **2.9”, 4.2”, 5.83” and 7.5”** E-paper display options available to cater specific applications needs.
- Wide viewing angle **(>170 degrees)** and bistable technology.
- No power usage while the screen is not refreshed, making it energy-efficient.
- **Black-White-Red** color scheme for eye protection - no blue light and no radiation.
- Inbuilt **WiFi/BLE capabilities** makes it perfect choice for IoT based projects
- Both **Serial UART** and **Native(D+/D-)** as Type C interface with Reset and Boot buttons available for programming purpose
- Status LED to indicate board power and battery charging 
- Battery connector and charge management facility for portable use case.
- GPIOs breakout as standard JST-SH-1MM-8 pin connector for additional peripheral interfacing 
- Onboard SDcard connector best for data logging based projects.
- **DS3231 RTC** module to keep track and use for real time capturing prototype.
- There is a buzzer which can be used to add audio alerts for your project.
- Four Programmable buttons for adding extra control features

## Specification:
- **Microcontroller**  : ESP32-S3 series of SoCs having Xtensa® dual-core 32-bit LX7 microprocessor
- **Connectivity** : 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE)
- **Memory** : Flash up to 16 MB, PSRAM up to 8 MB
- **Board Supply Voltage** : 5V 
- **Operating Pin Voltage** : 3.3V 
- **GPIOs connector** : JST-SH-1MM-8 pin
- **RTC module**: DS3231 
- **Coin Cell Holder** : Supports CR1220 3V Battery
- **Battery Connector** : Supports 3.7V Lithium ion battery  
- **Battery Charge Management** : MCP73831
- **RGB LED** : WS2812B
- **Working Temperature** : 0°C ~ +40°C 
- **E-Paper Display** =>
  - **E-paper Size** : 7.5"
  - **Resolution** : 800x480
  - **Color** : Red, Black and White
  - **Interface** : SPI
  - **Driver** : UC8179



<!--
## Getting Started with EnkFi 7.5" Board
### Pinout
<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/esp32_Pin.png?v=1718797005" />

- (1) Serial Servo connector
- (2) Header 2.5” input (6~8.4V DC) 
- (3) DC Jack Input (6~8.4V DC)
- (4),(5), (6) Programmable Buttons 
- (7) Boot Button
- (8) Type C for Programming/Power
- (9) Reset Button
- (10) TFT 1.14” Display
- (11) ESP32 S3 microcontroller module
- (12) Power Status LED
- (13) & (14) GPIOs and Power breakout

  
### Interfacing Details

 - _Serial Servo Bus Pins:_
   * Servo connector having +ve[6~8.4VDC], -ve[GND] and Signal pin. 
   * Serial Servo Signal pins breakout into UART RXD and TXD to connect with ESP32 UART pins,
     
     | ESP32 | Servo | Description | 
     |---|---|---|
     | TXD0/GPIO43 | Servo Bus RXD | UART communication pin |
     | RXD0/GPIO44 | Servo Bus TXD | UART communication pin |
  
- _Display interfacing with ESP32_
    | ESP32 | Display | Function |
    |---|---|---|
    | IO12 | LCD_CLK | Clock pin of SPI interface for Display|
    | IO11 | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO10 | LCD_CS | Chip Select pin of SPI interface|
    | IO13 | LCD_DC| Data/Command (MISO) pin of SPI interface|
    | IO14 | LCD_RST | Display Reset pin |
    | IO9  | BL | Backlight of display|
  
- _Buttons Interfacing_
    | ESP32 | Hardware | Function |
    |---|---|---|
    |IO0 | BOOT |Boot button |
    |IO4 | BT1 | Programmable Button |
    |IO5 | BT2 | Programmable Button |
    |IO6 | BT3 | Programmable Button |
  
- _GPIOs Breakout_
  
  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |DM   | I/O/T | RTC_GPIO20, GPIO20, U1CTS, ADC2_CH9, CLK_OUT1, _**USB_D+**_ |
  |DP   | I/O/T | RTC_GPIO19, GPIO19, U1RTS, ADC2_CH8, CLK_OUT2, _**USB_D-**_ |
  |GND  | P     | Supply Ground |
  |5V   | P     | Positive Supply, 5V |
  |3V3  | P     | Positive Supply, 3.3V |
  |GP8  | I/O/T | RTC_GPIO8, _**GPIO8**_ , TOUCH8, ADC1_CH7, SUBSPICS1  |  

  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |GP1  | I/O/T | RTC_GPIO1, _**GPIO1**_, TOUCH1, ADC1_CH0  |
  |GP2  | I/O/T | RTC_GPIO2, _**GPIO2**_, TOUCH2, ADC1_CH1  |
  |GP42 | I/O/T | _**MTMS**_ , GPIO42  |
  |GP41 | I/O/T | _**MTDI**_ , GPIO41, CLK_OUT1 |
  |GP39 | I/O/T | _**MTCK**_ , GPIO39, CLK_OUT3, SUBSPICS1 |
  |GP38 | I/O/T | _**GPIO38**_ , FSPIWP, SUBSPIWP  |

  *I-INPUT, O-OUTPUT, P-POWER & T-HIGH IMPEDENCE
  
### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
     
### 2. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/Serial_Servo_ESP32_Software/blob/main/libraries.zip) provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/Serial_Servo_ESP32_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on Serial Servo ESP32.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">
   - Checkout other examples below and build your own custom program codes using those references.

-->

## Resources
  * [Schematic](https://github.com/sbcshop/EnkFi_7.5_Hardware/blob/main/Design%20Data/EnkFi%207.5%20Sch.PDF)
  * [Hardware Files](https://github.com/sbcshop/EnkFi_7.5_Hardware)
  * [Step File](https://github.com/sbcshop/EnkFi_7.5_Hardware/blob/main/Mechanical%20Data/Enkfi_7in5.STEP)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)
       

## Related Products  
  
  * [EnkPi Series E-Paper - 2.9", 4.2", 5.83" & 7.5"](https://shop.sb-components.co.uk/products/enkpi?_pos=1&_psq=enkpi&_ss=e&_v=1.0)

    ![EnkPi Series](https://shop.sb-components.co.uk/cdn/shop/products/3_aa603116-9e0f-4af5-a42e-14273f8fc865.png?v=1683625804&width=150)

  * [2.7" E-paper HAT for Raspberry Pi](https://shop.sb-components.co.uk/products/2-7inch-e-paper-hat-board)

    ![2.7" E-paper Hat](https://shop.sb-components.co.uk/cdn/shop/products/2.7-inche-paperHATforRaspberryPi.png?v=1670333988&width=150)

  * [Universal E-Paper HAT for Pico](https://shop.sb-components.co.uk/products/universal-e-paper-hat-for-pico)

    ![Universal E-Paper HAT for Pico](https://shop.sb-components.co.uk/cdn/shop/products/5cd1c711f78614141d3566a656c3e04b_original.png?v=1672636474&width=150)

  * [1.54" E-Paper Breakout](https://shop.sb-components.co.uk/products/1-54-inch-e-paper-breakout)

    ![1.54" E-Paper Breakout](https://shop.sb-components.co.uk/cdn/shop/products/01_9f49bed0-cb5e-4a14-bd4c-3f79ab7a9b88.png?v=1677068419&width=150)
  
  * [E-Paper Display](https://shop.sb-components.co.uk/products/e-paper-display)

    ![E-Paper Display](https://shop.sb-components.co.uk/cdn/shop/files/01_d513b796-f1b2-4929-ae1f-4fc4282b42d2.jpg?v=1683613062&width=150)


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
