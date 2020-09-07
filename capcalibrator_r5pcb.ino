/*
 

  
*/
// Include the AccelStepper library:
#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 4
#define stepPin 3
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

int led5Pin = 5;    // LED5 connected to digital pin 5
int led6Pin = 6;    // LED6 connected to digital pin 6
int led7Pin = 7;    // LED7 connected to digital pin 7
int led8Pin = 8;    // LED8 connected to digital pin 8
int openlimit = 20;  // open limit switch connected to pin 20
int closedlimit = 21;  // open limit switch connected to pin 20

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setMaxSpeed(20000);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(20),openlimit,FALLING);  //  function for creating external interrupts at pin20 on Falling (HIGN to LOW);
  attachInterrupt(digitalPinToInterrupt(21),closedlimit,FALLING);  //  function for creating external interrupts at pin21 on Falling (HIGN to LOW);
}

void loop() {
  // fade in from min to max in increments of 1 ADU:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led5Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
  }

  // fade out from max to min in increments of 1 ADU:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led5Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
  }
  // fade in from min to max in increments of 1 ADU:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led6Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
  }

  // fade out from max to min in increments of 1 ADU:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led6Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
}
// fade in from min to max in increments of 1 ADU:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led7Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
  }

  // fade out from max to min in increments of 1 ADU:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led7Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
}
// fade in from min to max in increments of 1 ADU:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led8Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
  }

  // fade out from max to min in increments of 1 ADU:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) {
    // sets the value (range from 0 to 255):
    analogWrite(led8Pin, fadeValue);
    // wait for 2 milliseconds to see the dimming effect
    delay(2);
}
// Set the current position to 0:
  stepper.setCurrentPosition(0);

  // Run the motor forward at 8000 steps/second until the motor reaches 240000 steps (3/4 revolutions):
  // insert code here to set pin 2 low to enable the stepper driver ;
  while(stepper.currentPosition() != 0)
  {
    stepper.setSpeed(10000);
    stepper.runSpeed();
  }
// insert code here to set pin 4 high to disenable the stepper driver ;
  delay(1000);

 

  // Run the motor backwards at 8000 steps/second until the motor reaches position 0 (3/4 revolution):
   // insert code here to set pin 2 low to enable the stepper driver ;
  while(stepper.currentPosition() != 108000) 
  {
    stepper.setSpeed(-10000);
    stepper.runSpeed();
  }

  delay(1000);
// insert code here to set pin 2 high to disenable the stepper driver ;
 
  }
