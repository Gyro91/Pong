
#include "Arkanoid.hpp"

#define CLK 8 
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3


MapGame mp;
int buttonpin1=11; // assegno 8 alla variabile intera buttonpin
int buttonpin2=12;
int buttonpin3=13;
int ledstatus=0;

void setup() {
  mp.matrix.begin();
  pinMode(buttonpin1 , INPUT);
  pinMode(buttonpin2 , INPUT);
  pinMode(buttonpin3 , INPUT);

  
}

void loop() {
  // do nothing
    ledstatus = digitalRead(buttonpin1);   
 if (ledstatus == HIGH) {               
    mp.matrix.drawCircle(10, 10, 10, matrix.Color333(0, 0, 7));
    delay(500);
  }
  
}
