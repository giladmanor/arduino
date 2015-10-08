#include <SoftwareSerial.h>
char val;
int v;
int inputShift = 4;
int outputShift = 9;
String states = "";
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7};

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  for(int i=inputShift;i<inputShift+4;i++){
    pinMode(i, OUTPUT);
  }
  for(int i=outputShift;i<outputShift+4;i++){
    pinMode(i, INPUT);
  }
}

void loop() // run over and over
{
  delay(500);
  states = "";
  for(int i = 0; i<8;i++){
    states+= digitalRead(analog_pins[i]);
    
//    if(false && digitalRead(analog_pins[i])>500){
//      states+="o";
//    }else{
//      states+="c";
//    }
  }
  mySerial.println(states+"#");
  
  if (mySerial.available()){
    val = mySerial.read(); 
    for(int i=inputShift;i<inputShift+4;i++){
      digitalWrite(i, LOW);
    }
    mySerial.println(val-65);
    open(val);
  }else{
    val=-1;
  }
}

void open(char val){
  digitalWrite(val-65+inputShift, HIGH);
  delay(1000);
  digitalWrite(val-65+inputShift, LOW);
}
