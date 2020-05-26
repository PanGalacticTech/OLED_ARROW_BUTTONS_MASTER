
/*  Menu System Build for SSD1306 OLED Displays

     Nagivation via

     UP / DOWN

     LEFT / RIGHT

     ENTER / BACK

     Buttons


    All buttons are pulled down with 1k resistor and read HIGH when pushed


*/





//--------------------------------------------------### OLED Variables & Settings ###--------------------------
#include "globals.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//~~~~~>> BMP280 Temp / Pressure Sensor <<~~~~~~~~
#include <Adafruit_BMP280.h>


Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();
//~~~~~>> BMP280 Temp / Pressure Sensor <<~~~~~~~~

#include <Fonts/FreeMonoBold12pt7b.h >
#include <Fonts/FreeSansBold12pt7b.h >
#include <Fonts/FreeSansBold9pt7b.h >

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//#define OLED_ADDR   0x3C
//Adafruit_SSD1306 display(-1);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Oled Pins

// SDA = A4;
// SLC = A5;




// ~~~~~~~~~~~~ Button Input Pins ~~~~~~~~~~~~~~~~~~

// < ~ Button Inputs ~ >
const uint8_t        buttonUP  = 15;
const uint8_t      buttonDOWN  = 4;
const uint8_t      buttonLEFT  = 5;
const uint8_t    buttonRIGHT  = 18;
const uint8_t    buttonENTER  = 19;
const uint8_t     buttonBACK  = 23;


const uint8_t  buttonPins[6] = {buttonUP, buttonDOWN, buttonLEFT, buttonRIGHT, buttonENTER, buttonBACK};

const uint8_t  numberofbuttons = 6;  // variable for number of button inputs




// >>>>>>>>>>>>>>>>>>>> Void Setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void setup() {

  Serial.begin(115200);



  OLEDsetupSimple();



  // Set up button Input Pins
  for (int i = 0; i < numberofbuttons; i++) {
    pinMode(buttonPins[i], INPUT);
  }



  // display.setFont();
  display.setTextColor(1, 0);
}



// >>>>>>>>>>>>>>>>>>>> Void Loop <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void loop() {
  

buttonRead();
buttonControl();
itemSelect();

staticMenu();
oledUpdate();
  
}
