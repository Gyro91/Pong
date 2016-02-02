
unsigned long press;
unsigned long current;
int state = 0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(57600);
    pinMode(A5, INPUT);
    pinMode(11, INPUT);
    current = millis();
}


void testButton(int button, int state) 
{
  int ledstate;
  
  ledstate = digitalRead(button);
  if (ledstate == state) {
      press = millis();
      
      Serial.println(press - current);
      while(digitalRead(button) == state)
      current =  millis();  
  }
}


void loop() {

  testButton(A5, LOW);
  

}
