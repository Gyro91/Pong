// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 32x32 RGB LED matrix:
// http://www.adafruit.com/products/607

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// If your matrix has the DOUBLE HEADER input, use:
//#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
//#define LAT 9
//#define OE  10
//#define A   A3
//#define B   A2
//#define C   A1
//#define D   A0

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

int buttonpin1=11; // assegno 8 alla variabile intera buttonpin
int buttonpin2=12;
int buttonpin3=13;
int ledstatus=0;

void setup() {

  matrix.begin();
  pinMode(buttonpin1 , INPUT);
  pinMode(buttonpin2 , INPUT);
  pinMode(buttonpin3 , INPUT);
  // draw a pixel in solid white
  
}

void loop() {
  // do nothing
    ledstatus = digitalRead(buttonpin1);   // lettura dell'ingresso
 if (ledstatus == HIGH) {               // controlla se il pulsante è premuto
    matrix.drawCircle(10, 10, 10, matrix.Color333(0, 0, 7));
    delay(500);
  }
  else {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
  }

   ledstatus = digitalRead(buttonpin2);   // lettura dell'ingresso
 if (ledstatus == HIGH) {               // controlla se il pulsante è premuto
    matrix.drawRect(0, 0, 32, 32, matrix.Color333(7, 7, 0));
    delay(500);
  }
  else {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
  }

  ledstatus = digitalRead(buttonpin3);   // lettura dell'ingresso
 if (ledstatus == HIGH) {               // controlla se il pulsante è premuto
      matrix.drawLine(0, 0, 31, 31, matrix.Color333(7, 0, 0));
      matrix.drawLine(31, 0, 0, 31, matrix.Color333(7, 0, 0));
      delay(500);
  }
  else {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
  }
}
