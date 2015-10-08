#include <SoftwareSerial.h>
int d1 = 4;
int d2 = 5;
int d3 = 6;
int d4 = 7;
char val;
int delayH=50;
int delayL=50;
int i=0;
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

}

void loop() // run over and over
{
  if (mySerial.available()){
    val = mySerial.read(); 
    mySerial.println(val);
  }

  switch (val) {
  case 'a':    // your hand is on the sensor
    delayH = delayH + 100;

    break;
  case 'c':    // your hand is close to the sensor
    if(delayH>0){
      delayH = delayH - 100;    
    }

    break;
  case 'b':    // your hand is a few inches from the sensor
    delayL = delayL + 100;

    break;
  case 'd':    // your hand is nowhere near the sensor
    if(delayL>0){
      delayL = delayL - 100;
    }
    break;
  } 


  digitalWrite(d1, HIGH);
  
  digitalWrite(d1, LOW);
  


  delay(50);
  val='q'; 

}






