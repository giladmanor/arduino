#include <Stepper.h>
#include <SoftwareSerial.h>

#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
static const int outputs[] = {4,5,6,7};
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7};
SoftwareSerial mySerial(2, 3); // RX, TX

int previous = 0;
int val;

void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  for(int i=0;i<sizeof(outputs);i++){
    pinMode(outputs[i], OUTPUT);
  }
  for(int i=0;i<sizeof(analog_pins);i++){
    pinMode(analog_pins[i], INPUT);
  }
}

void loop()
{
  if (mySerial.available()){
    val = mySerial.read(); 
    
    switch (val) {
    case 'A':    // your hand is on the sensor
      digitalWrite(outputs[0], HIGH);
      break;
    case 'a':    // your hand is close to the sensor
      digitalWrite(outputs[0], LOW);
      break;
    case 'B':    // your hand is on the sensor
      digitalWrite(outputs[1], HIGH);
      break;
    case 'b':    // your hand is close to the sensor
      digitalWrite(outputs[1], LOW);
      break;
    case 'C':    // your hand is on the sensor
      digitalWrite(outputs[2], HIGH);
      break;
    case 'c':    // your hand is close to the sensor
      digitalWrite(outputs[2], LOW);
      break;
    case 'D':    // your hand is on the sensor
      digitalWrite(outputs[3], HIGH);
      break;
    case 'd':    // your hand is close to the sensor
      digitalWrite(outputs[3], LOW);
      break;
    case 'E':    // your hand is on the sensor
      stepper.step(30);
      break;
    case 'F':    // your hand is close to the sensor
      stepper.step(-30);
      break;
    } 
  }
  delay(10);
}
