  #include <Stepper.h>
 
  #define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
  
  Stepper stepper(STEPS, 8, 10, 9, 11);
  
// this constant won't change. It's the pin number of the sensor's output:

const int pingPin = 7;


  
  void setup() {
    // initialize serial communication:
 Serial.begin(9600);
  stepper.setSpeed(10);
  }
 
 void loop() {
 ////////////////////////////////////////////////////////////////////////////// SENSOR CODE
 // establish variables for duration of the ping, and the distance result
  // in centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

 // Serial.print(cm);
 // Serial.print("cm");
 // Serial.println();

 // delay(25);
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// STEPPER CODE

if (cm < 15){

 stepper.step(642);
 delay(3000);
 stepper.step(-642);
 delay(250);
 stepper.step(0);

}

else {
 stepper.step(0);
 delay(500);
 
  }
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
  } 








/*numSteps = stepsPerRevolution * (desiredNumberOfDegrees / 360);
stepper.step(numSteps);*/

/* stepper.setSpeed(1); // 1 rpm
 stepper.step(2038); // do 2038 stOps -- corresponds to one revolution in one minute
 delay(1000); // wait for one second*/

 /* stepper.setSpeed(8);
 stepper.step(514); do 2038 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds. 90 degree = 514 steps after calibration.*/
