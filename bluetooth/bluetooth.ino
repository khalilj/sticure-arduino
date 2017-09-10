// bluetooth
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

// noise detection sensor
int sensorPin = 13; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

// flame detection sensor
int fsensorPin = A0; // select the input pin for the LDR
int fsensorValue = 0; // variable to store the value coming from the sensor

// collision detection sensor
int csensorPin = 8; // select the input pin for the potentiometer
int csensorValue = 0; // variable to store the value coming from the sensor

void setup ()
{
Serial.begin (9600);
// bluetooth serial
mySerial.begin(38400);
}

void handleEvent(int e) {
  switch(e) {
    case 0:
      mySerial.print('F');
      Serial.println("Fire");
      break;
    case 1:
      mySerial.print('G');
      Serial.println("Gun shot");
      break;
    case 2:
//      mySerial.print('C');
//      Serial.println("Crash");
      break;
  }
  delay(1000);
}
void loop ()
{
  // flame detection sensor
  fsensorValue = analogRead(fsensorPin);
  if (fsensorValue < 100)
  {
    //Serial.println("Fire Detected");
    handleEvent(0);
    //delay(1000);
  }


  // noise detection sensor
  sensorValue = digitalRead (sensorPin);
  if(sensorValue == 1 ){
    //Serial.println("Gun shot Detected");
    handleEvent(1);
  }else{
    //digitalWrite (ledPin, LOW);
    delay (sensorValue);
  }

  // collision detection sensor
  csensorValue = digitalRead (csensorPin);
  if(csensorValue == 1 ){
    //Serial.println("Collision Detected");
    handleEvent(2);
  }else{
    delay (csensorValue);
  }
}

