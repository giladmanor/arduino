#include <SoftwareSerial.h>
SoftwareSerial bluetooth(1, 2);
int l1 = 4;
int l2 = 5;
int l3 = 6;
char val;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  bluetooth.begin(115200); 
  bluetooth.print("$$$");
}

// the loop routine runs over and over again forever:
void loop() {
  
  if( bluetooth.available() )       // if data is available to read
  {
    val =  (char)bluetooth.read(); 
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);    // read it and store it in 'val'
    bluetooth.print('w');
  }
  

  if( val == 'a' )               // if 'H' was received
  {
    digitalWrite(l1, HIGH);  // turn ON the LED
  } 
  
  if( val == 'b' )               // if 'H' was received
  {
    digitalWrite(l2, HIGH);  // turn ON the LED
  } 
  
  if( val == 'c' )               // if 'H' was received
  {
    digitalWrite(l3, HIGH);  // turn ON the LED
  } 
  
  val='q';
}
