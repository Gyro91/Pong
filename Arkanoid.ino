
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

class GraphicHandler {
  int ledstate1, ledstate2, ledstate3;
  unsigned long previousMillis = 0;

public:

  void update()
  { 
    unsigned long currentMillis;
    currentMillis = millis();
    if ((currentMillis - previousMillis) >= 100) {
        previousMillis = currentMillis;
        ledstate1 = digitalRead(BLEFT);
        ledstate2 = digitalRead(BRIGHT);
    }
    
    if (ledstate1 == HIGH) {
        matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
            mg.vaus.lastR, matrix.Color333(BLACK));
        mg.moveVaus(LEFT);
        matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
            mg.vaus.lastR, matrix.Color333(BLUE));
        ledstate1 = false;

    }
    if (ledstate2 == HIGH) {
        matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
            mg.vaus.lastR, matrix.Color333(BLACK));
        mg.moveVaus(RIGHT);
        matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
            mg.vaus.lastR, matrix.Color333(BLUE));
        ledstate2 = false;
    }
    
  }
};


void setup()
{
  matrix.begin();
  pinMode(BFIRE, INPUT);
  pinMode(BLEFT, INPUT);
  pinMode(BRIGHT, INPUT);
  matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, mg.vaus.lastR,matrix.Color333(BLUE));
  
}

GraphicHandler gh;
void loop() 
{
  
  gh.update();
 
}
