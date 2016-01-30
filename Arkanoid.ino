
#include "Arkanoid.hpp"
// Colours
#define BLUE 0, 0, 7
#define BLACK 0, 0, 0
#define RED 7, 0, 0

// Constants for the matrix
#define CLK 8  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// Buttons
#define BFIRE 11
#define BLEFT 12
#define BRIGHT 13

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
MapGame mg;
int START = 0;


class GraphicHandler {
  int ledstate1, ledstate2, ledstate3;
  unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;

public:
  void drawVaus() {
      matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
          mg.vaus.lastR, matrix.Color333(BLUE));
  }
  void deleteVaus() {
      matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
          mg.vaus.lastR, matrix.Color333(BLACK));
  }
  void buttonsAction(int ledstate1, int ledstate2, int ledstate3)
  {
    if (ledstate1 == HIGH) {
        deleteVaus();
        mg.moveVaus(LEFT);
        drawVaus();
        ledstate1 = false;
    }
    if (ledstate2 == HIGH) {
        deleteVaus();
        mg.moveVaus(RIGHT);
        drawVaus();
        ledstate2 = false;
    }

    if (ledstate3 == HIGH) {
        START = 1;
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(BLACK));
        mg.moveBall();
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(RED));
        delay(50);
    }
  }
  
  void update()
  { 
    unsigned long currentMillis, currentMillis2;
    currentMillis2 = currentMillis = millis();
    if ((currentMillis - previousMillis) >= 50) {
        previousMillis = currentMillis;
        ledstate1 = digitalRead(BLEFT);
        ledstate2 = digitalRead(BRIGHT);
        ledstate3 = digitalRead(BFIRE); 
        buttonsAction(ledstate1, ledstate2, ledstate3);
    }
    
    else if (START == 1 && (currentMillis2 - previousMillis2) >= 100) {
        previousMillis2 = currentMillis2;
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(BLACK));
        mg.moveBall();
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(RED));
    }
    
 
  }
};


void setup()
{
  matrix.begin();
  pinMode(BFIRE, INPUT);
  pinMode(BLEFT, INPUT);
  pinMode(BRIGHT, INPUT);
  matrix.drawLine(mg.vaus.x, mg.vaus.lastL, mg.vaus.x, 
      mg.vaus.lastR,matrix.Color333(BLUE));
  matrix.drawPixel(mg.ball.x, mg.ball.y, 
      matrix.Color333(RED));
  
}

GraphicHandler gh;
void loop() 
{
  
  gh.update();
 
}
