#include "Pong.hpp"

// Colours
#define BLUE 0, 0, 7
#define BLACK 0, 0, 0
#define RED 7, 0, 0
#define GREEN 0, 7, 0

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
#define BLEFT1 12
#define BRIGHT1 13
#define BLEFT2 A4
#define BRIGHT2 A5


MapGame mg;
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

unsigned char START = 0;

int point1, point2;

class GraphicHandler {
  int ledstate1, ledstate2, ledstate3, ledstate4, ledstate5;
  unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;

public:
  void drawPad1() {
      matrix.drawLine(mg.pad1.x, mg.pad1.lastL, mg.pad1.x, 
          mg.pad1.lastR, matrix.Color333(BLUE));
  }
   void drawPad2() {
      matrix.drawLine(mg.pad2.x, mg.pad2.lastL, mg.pad2.x, 
          mg.pad2.lastR, matrix.Color333(BLUE));
  }
  void deletePad1() {
      matrix.drawLine(mg.pad1.x, mg.pad1 .lastL, mg.pad1.x, 
          mg.pad1.lastR, matrix.Color333(BLACK));
  }

  void deletePad2() {
      matrix.drawLine(mg.pad2.x, mg.pad2.lastL, mg.pad2.x, 
          mg.pad2.lastR, matrix.Color333(BLACK));
  }
  void buttonsAction()
  {
    if (ledstate1 == HIGH) {
        deletePad1();
        mg.movePad1(LEFT);
        drawPad1();
        ledstate1 = false;
    }
    if (ledstate2 == HIGH) {
        deletePad1();
        mg.movePad1(RIGHT);
        drawPad1();
        ledstate2 = false;
    }

    if (ledstate4 == LOW) {
        deletePad2();
        mg.movePad2(LEFT);
        drawPad2();
        ledstate1 = false;
    }
    if (ledstate5 == LOW) { //A5
        deletePad2();
        mg.movePad2(RIGHT);
        drawPad2();
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
    unsigned long currentMillis;
    currentMillis = millis();
    if ((currentMillis - previousMillis) >= 50) {
        previousMillis = currentMillis;
        ledstate1 = digitalRead(BLEFT1);
        ledstate2 = digitalRead(BRIGHT1);
        ledstate3 = digitalRead(BFIRE);
        ledstate4 = digitalRead(BLEFT2);
        ledstate5 = digitalRead(BRIGHT2); 
        buttonsAction();
    }   
    else if (START == 1 && (currentMillis - previousMillis2) >= 40) {
        previousMillis2 = currentMillis;
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
  pinMode(BLEFT1, INPUT);
  pinMode(BRIGHT1, INPUT);
  pinMode(BLEFT2, INPUT);
  pinMode(BRIGHT2, INPUT);

  // Draw Paddle1
  matrix.drawLine(mg.pad1.x, mg.pad1.lastL, mg.pad1.x, 
      mg.pad1.lastR,matrix.Color333(BLUE));

  // Draw Paddle2
     matrix.drawLine(mg.pad2.x, mg.pad2.lastL, mg.pad2.x, 
      mg.pad2.lastR,matrix.Color333(BLUE));
      
  // Draw Ball
  matrix.drawPixel(mg.ball.x, mg.ball.y, 
      matrix.Color333(RED));

}

GraphicHandler gh;


void loop() 
{
  
  gh.update();
  
 
}
