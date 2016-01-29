
#include "Arkanoid.hpp"
// Colours
#define BLUE 0, 0, 7
#define BLACK 0, 0, 0

// Constants for the matrix
#define CLK 8  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// Buttons
#define BFIRE 12
#define BLEFT 11
#define BRIGHT 13

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
MapGame mg;

int ledstatus = 0;

void setup()
{
  matrix.begin();
  pinMode(BFIRE, INPUT);
  pinMode(BLEFT, INPUT);
  pinMode(BRIGHT, INPUT);
  matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR,matrix.Color333(BLUE));
  
}

void loop() 
{
  matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR,matrix.Color333(BLUE));
    ledstatus = digitalRead(BRIGHT);   // lettura dell'ingresso
 if (ledstatus == HIGH) {               // controlla se il pulsante è premuto
    
    matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR, matrix.Color333(BLACK));
    mg.moveVaus(RIGHT);
    matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR, matrix.Color333(BLUE));
    delay(200);
  }
   ledstatus = digitalRead(BLEFT);   // lettura dell'ingresso
 if (ledstatus == HIGH) {               // controlla se il pulsante è premuto
    matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR, matrix.Color333(BLACK));
    mg.moveVaus(LEFT);
    matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR, matrix.Color333(BLUE));
    delay(200);
  }


 
}
