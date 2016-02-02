#include "Pong.hpp"

// Colours
#define BLUE 0, 0, 7
#define BLACK 0, 0, 0
#define RED 7, 0, 0
#define GREEN 0, 7, 0
#define WHITE 255, 255, 255

// Constants for the matrix
#define CLK 8  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// Buttons
#define BLEFT1 12
#define BRIGHT1 13
#define BLEFT2 A4
#define BRIGHT2 A5

// Points for winning the match
#define FINALSCORE 5
// Acceleratio for the paddle after a button press
#define ACCEL 5
// Maximum period of a paddle
#define TPAD_MAX 60
// Minimum period of a paddle
#define TPAD_MIN 30

// Map of the Game
MapGame mg;
// RGB Matrix
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

// Actual and old Points of every player
unsigned char points_p1 = 0;
unsigned char points_p2 = 0;
unsigned char oldpoints_p1 = 0; 
unsigned char oldpoints_p2 = 0;

// Last direction of each pad
DirectionPad last_action1;
DirectionPad last_action2;


/* This function prints on screen the introduction of 
 * the game
 */
void intro() {

    matrix.setCursor(5, 9); 
    matrix.setTextSize(1);    
    matrix.setTextColor(matrix.Color333(WHITE));
    matrix.print('P');
    matrix.print('O');
    matrix.print('N');
    matrix.print('G');
    matrix.setCursor(5, 18);   // start at top left, with one pixel of spacing
    matrix.print('G');
    matrix.print('A');
    matrix.print('M');
    matrix.print('E');
    
    delay(3000);

    for (int i=0; i<RMATRIX; i++)
        for(int j=0; j<CMATRIX; j++)
            matrix.drawPixel(i, j, matrix.Color333(BLACK));
}


/* This function prints on screen the points of the players. 
 * It erases the points screen only when it's needed inorder 
 * to avoid blinking.
 */

void showPoints() 
{
  matrix.setCursor(5, 0); 
  matrix.setTextSize(1);    
  matrix.setTextColor(matrix.Color333(GREEN));
  switch(points_p1) {
    case 0:
      matrix.print('0');
        break;
    case 1:
      if (oldpoints_p1 != points_p1) {
          matrix.setCursor(5, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('0');
          oldpoints_p1 = points_p1; 
      }
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.setCursor(5, 0); 
      matrix.print('1');
        break;
    case 2:
    if (oldpoints_p1 != points_p1) {
          matrix.setCursor(5, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('1'); 
          oldpoints_p1 = points_p1;
      }
      matrix.setCursor(5, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('2');
        break;
    case 3:
   
      if (oldpoints_p1 != points_p1) {
          matrix.setCursor(5, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('2');
          oldpoints_p1 = points_p1; 
      }
      matrix.setCursor(5, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('3');
        break;
     case 4:
     
    if (oldpoints_p1 != points_p1) {
          matrix.setCursor(5, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('3'); 
          oldpoints_p1 = points_p1;
      }
      matrix.setCursor(5, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('4');
     break;

    case 5:  
    if (oldpoints_p1 != points_p1) {
          matrix.setCursor(5, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('4'); 
          oldpoints_p1 = points_p1;
      }
      matrix.setCursor(5, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
        matrix.print('5');
         break;
  }

  matrix.setCursor(20, 0); 

  switch(points_p2) {
    case 0:
      matrix.print('0');
        break;
    case 1:
      if (oldpoints_p2 != points_p2) {
          matrix.setCursor(20, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('0');
          oldpoints_p2 = points_p2; 
      }
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.setCursor(20, 0); 
      matrix.print('1');
        break;
    case 2:
    
    if (oldpoints_p2 != points_p2) {
          matrix.setCursor(20, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('1'); 
          oldpoints_p2 = points_p2;
      }
      matrix.setCursor(20, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('2');
        break;
    case 3:
   
      if (oldpoints_p2 != points_p2) {
          matrix.setCursor(20, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('2');
          oldpoints_p2 = points_p2; 
      }
      matrix.setCursor(20, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('3');
        break;
     case 4:
     
       if (oldpoints_p2 != points_p2) {
          matrix.setCursor(20, 0);
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('3'); 
          oldpoints_p2 = points_p2;
      }
      matrix.setCursor(20, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
      matrix.print('4');
     break;

    case 5:  
    if (oldpoints_p2 != points_p2) {
          matrix.setCursor(20, 0); 
          matrix.setTextColor(matrix.Color333(BLACK));
          matrix.print('4'); 
          oldpoints_p2 = points_p2;
      }
      matrix.setCursor(20, 0); 
      matrix.setTextColor(matrix.Color333(GREEN));
        matrix.print('5');
         break;
  }

}


/* This function ends the game. It shows points and the screen of the winner. 
 * Then it blocks forever.
 *
 */
void endGame()
{    
     showPoints();
     matrix.setCursor(10, 9);  
     matrix.setTextSize(1);    
     matrix.setTextColor(matrix.Color333(WHITE));
    if (points_p1 == FINALSCORE) {
       matrix.print('P');
       matrix.print('1');
       matrix.setCursor(5, 18);   
       matrix.print('W');
       matrix.print('I');
       matrix.print('N');
       matrix.print('S');
     }
     else if(points_p2 == FINALSCORE) {
       matrix.print('P');
       matrix.print('2');
       matrix.setCursor(5, 18);   
       matrix.print('W');
       matrix.print('I');
       matrix.print('N');
       matrix.print('S');
     }
   while(1);
}

/* It's the manager of the screen. It does not use the delay in
 * order to make the system more responsive. Like a timeline scheduling
 * every 50 ms it does a polling on the buttons and eventually executes
 * the selected action.
 * And every 35 ms it updates the movement of the ball.
 * 
 * 
 */
 
class GraphicHandler {

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
  void buttonsActionP1()
  {  
    int ledstate0 = digitalRead(BLEFT1);
    int ledstate1 = digitalRead(BRIGHT1);
    
    if (ledstate0 == HIGH) {
        deletePad1();
        mg.movePad1(LEFT);
        drawPad1();
        // If the Direction is the same of the last
        // then acceleration
        if (last_action1 == LEFT) {
           if (t_pad1 > TPAD_MIN)
           t_pad1 -= ACCEL;
        }
        else t_pad1 = TPAD_MAX;
        last_action1 = LEFT;
    }   
    if (ledstate1 == HIGH) {
        deletePad1();
        mg.movePad1(RIGHT);
        drawPad1();
        if (last_action1 == RIGHT) {
          if (t_pad1 > TPAD_MIN)
            t_pad1 -= ACCEL;
        }    
        else t_pad1 = TPAD_MAX;
        last_action1 = RIGHT;
    }
    // If there's no button press, then deceleration 
     if (ledstate0 == LOW && ledstate1 == LOW)
            if(t_pad1 < TPAD_MAX)
              t_pad1 = TPAD_MAX;
    
      
  }

  void buttonsActionP2() 
  {
    // BLEFT2 and BRIGHT2 are low sensitive
    int ledstate3 = digitalRead(BLEFT2);
    int ledstate2 = digitalRead(BRIGHT2);
  
    if (ledstate3 == LOW) {
        deletePad2();
        mg.movePad2(LEFT);
        drawPad2();
        // If there's no change of direction
        // then acceleration
        if (last_action2 == LEFT ) {
           if (t_pad2 > TPAD_MIN)
           t_pad2 -= ACCEL;
        }
        else t_pad2 = TPAD_MAX;
        last_action2 = LEFT;
     
    }
    
    if (ledstate2 == LOW) { 
        deletePad2();
        mg.movePad2(RIGHT);
        drawPad2();
         if (last_action2 == RIGHT) {
          if (t_pad2 > TPAD_MIN)
            t_pad2 -= ACCEL;
        }    
        else t_pad2 = TPAD_MAX;
        last_action2 = RIGHT;
    }
    // If there's no button press, then deceleration 
      if (ledstate2 == LOW && ledstate3 == LOW)
            if(t_pad2 < TPAD_MAX)
              t_pad2 = TPAD_MAX;
      
  }
  
  void update()
  { 
    unsigned long currentMillis;   
    unsigned long previousMillis1 = 0;
    unsigned long previousMillis2 = 0;
    unsigned long previousMillis3 = 0;


    while(1) {
  
    currentMillis = millis();

    // Every t_pad1 handling PAD1
    if ((currentMillis - previousMillis1) >= t_pad1) {
         previousMillis1 = currentMillis;
         buttonsActionP1();

    }
    // Every t_pad2 handling PAD2
    if ((currentMillis - previousMillis2) >= t_pad2) {     
         previousMillis2 = currentMillis; 
         buttonsActionP2();
    }
    // Every t_ball moving the ball
    if ((currentMillis - previousMillis3) >= t_ball) {
        previousMillis3 = currentMillis;
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(BLACK));
        
        if (mg.ball.x == 1 && mg.ball.y >= mg.pad1.lastL 
            && mg.ball.y <= mg.pad1.lastR)
            drawPad1();
        else if(mg.ball.x == 30 && mg.ball.y >= mg.pad1.lastL 
            && mg.ball.y <= mg.pad1.lastR)
            drawPad2();
        
        mg.moveBall();
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
            matrix.Color333(RED));
     
     // Eventually increasing 
     if (mg.ball.x == 0) 
        points_p2++;
      else if(mg.ball.x == 31)
        points_p1++;

      if( points_p1 == FINALSCORE || points_p2 == FINALSCORE)
         endGame();

     showPoints();
     
    }
    }
   
  }
};


void setup()
{   
  // For A Random Start 
    randomSeed(analogRead(0));
    int randn = random(10);
    
    matrix.begin();
  
    pinMode(BLEFT1, INPUT);
    pinMode(BRIGHT1, INPUT);
    pinMode(BLEFT2, INPUT);
    pinMode(BRIGHT2, INPUT);
  
    //intro();
    // Draw Paddle1
    matrix.drawLine(mg.pad1.x, mg.pad1.lastL, mg.pad1.x, 
        mg.pad1.lastR,matrix.Color333(BLUE));

    // Draw Paddle2
    matrix.drawLine(mg.pad2.x, mg.pad2.lastL, mg.pad2.x, 
       mg.pad2.lastR,matrix.Color333(BLUE));

    if (randn < 5)
      // Draw Ball
      matrix.drawPixel(mg.ball.x, mg.ball.y, 
          matrix.Color333(RED));
      else {
        mg.ball.x = 30;
        matrix.drawPixel(mg.ball.x, mg.ball.y, 
             matrix.Color333(RED));
        mg.ball.dirB = S;
      }
}

GraphicHandler gh;

void loop() 
{
    gh.update();

 
}
