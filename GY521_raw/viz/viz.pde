import processing.serial.*;

// Code originally by Odis Harkins
// http://odisharkins.com/robotics/gyro-arduino-processing/

Serial myPort;       
int linefeed = 10;   // Linefeed in ASCII
int numSensors = 3;  // we will be expecting for reading data from 3 sensors
float sensors[];       // array to read the 3 values
float pSensors[];       



void setup() {
  size(820, 460, P3D);  
  // List all the available serial ports in the output pane. 
  // You will need to choose the port that the Wiring board is 
  // connected to from this list. The first port in the list is 
  // port #0 and the third port in the list is port #2. 
  println(Serial.list()); 
  
  myPort = new Serial(this, Serial.list()[0], 115200);
  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil(linefeed);
}

void draw() {
  if((pSensors != null)&&(sensors != null)) { 
    
    // now do something with the values read sensors[0] .. sensors[2]
     //First I find all my rotation angles in radians so that center screen is (0,0)
    
    //Gyro
    float rotx = (sensors[3]*PI)/180;
    float roty = (sensors[4]*PI)/180;
    float rotz = (sensors[5]*PI)/180;
    
    //Accel
    float aotx = (sensors[0]*PI)/180;
    float aoty = (sensors[1]*PI)/180;
    float aotz = (sensors[2]*PI)/180;
    //float roty = 0;
    translate(0, 20, 0);
    background(255);
    stroke(0, 0, 200);
    //line (0,20,420,20); // monitor bar
    fill(0);
    textSize(20);
    text (" G: X(" + rotx +")"+" Y("+roty+")"+" Z("+rotz+")", 0,10);
    translate(0, 20, 0);
    text (" A: X(" + aotx +")"+" Y("+aoty+")"+" Z("+aotz+")", 0,10);
    fill(0, 0, 200);
     
    translate(210, 220, 0); // center drawing start point in screen
     
    strokeWeight(1);
    stroke(50);

    line(-60, 0, 60, 0);       //
    line(0, 60, 0, -60);       // draw stationary axis lines
    line(0, 0, -60, 0, 0, 60); //
    strokeWeight(1);
    stroke(0, 150, 0);
    noFill();
    box(140);                  // draw stationary box
     
    rotatingBox(rotx,roty,rotz);
    translate(410, 0, 0);
   
    rotatingBox(aotx,aoty,aotz);
    
    
  }
}

void rotatingBox(float x, float y,float z){
  rotateX(x);  //
  rotateY(z);  // rotate drawing coordinates according to user input variables
  rotateZ(y);  //
  strokeWeight(2);
  stroke(50);
  line(-150, 0, 150, 0);       //
  line(0, 150, 0, -150);       // draw the rotating axis lines
  line(0, 0, -150, 0, 0, 150); //
  strokeWeight(2);
  stroke(255, 0, 0);
  //noFill();
  
  box(100);
  rotateX(-x);  //
  rotateY(-z);  // rotate drawing coordinates according to user input variables
  rotateZ(-y);  //
}

void serialEvent(Serial myPort) {

  // read the serial buffer:
  String myString = myPort.readStringUntil(linefeed);

  // if you got any bytes other than the linefeed:
  if (myString != null) {

    myString = trim(myString);

    // split the string at the commas
    // and convert the sections into integers:

    pSensors = sensors;
    sensors = float(split(myString, ','));

    // print out the values you got:
    
    for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      print("S " + sensorNum + ": " + sensors[sensorNum] + "\t");
    }
    
    // add a linefeed after all the sensor values are printed:
    println();
  }
}
