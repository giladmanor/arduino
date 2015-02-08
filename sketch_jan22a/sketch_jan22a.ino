#include <Servo.h>
int l1 = 4;
int l2 = 5;
int l3 = 6;
char val;
Servo servo1;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  //pinMode(1,OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  Serial.begin(9600); 
  servo1.attach(8);
}

// the loop routine runs over and over again forever:
void loop() {
  
  if( Serial.available() )       // if data is available to read
  {
    val = Serial.read(); 
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);    // read it and store it in 'val'
    Serial.write('w');
    delay(50);
  }
  
  
  
  
  if( val == 'a' )               // if 'H' was received
  {
    digitalWrite(l1, HIGH);  // turn ON the LED
    servo1.write(45);
  } 
  
  if( val == 'b' )               // if 'H' was received
  {
    digitalWrite(l2, HIGH);  // turn ON the LED
    servo1.write(90);
  } 
  
  if( val == 'c' )               // if 'H' was received
  {
    digitalWrite(l3, HIGH);  // turn ON the LED
    servo1.write(135);
  } 
  
  val='q';
}
