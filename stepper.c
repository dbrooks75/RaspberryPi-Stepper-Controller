//
// stepper.c - Library for controlling stepper motors
///////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <wiringPi.h>
#include "stepper.h"

  // Motor Specs
  float degperstep = 3.6;
  int stepsperrev;
  int microstep = 1;

  // Thread Rod Specs
  int tpi = 12;
  float inchperrev;

  float inchperstep;

  //delay 4160 for bigger stepper motor, 480 steps
  int stepperdelay = 4160;


int main (void)
{

  wiringPiSetup() ;
  initGlobals();

//setMountDirection( DIRECTION_UP );
//delay(3000);
//setMountDirection( DIRECTION_DOWN );

  moveMountDown(.1);
delay(3000);
  moveMountUp(.1);
  moveMountDown(.1);
delay(3000);
  moveMountUp(.1);

  return 0 ;
}


void initGlobals()
{
  stepsperrev = (360 / degperstep) * microstep;
  inchperrev = 1.0 / tpi;
  inchperstep = inchperrev / stepsperrev;

  pinMode(STEP_PIN, OUTPUT) ;
  pinMode(DIRECTION_PIN, OUTPUT) ;
  pinMode(MOTOR_DRIVER_ACTIVE_PIN, OUTPUT) ;

  printf("Steps per revolution: %d \n", stepsperrev);
  printf("Inches per revolution: %E \n", inchperrev);
  printf("Inches per step: %E \n", inchperstep);

}



int pulsePin(int thePin, int delayMicroSec)
{

    digitalWrite (thePin, HIGH); 
    digitalWrite (thePin,  LOW); 
    delayMicroseconds(delayMicroSec);

    return 0;
}


void setMountDirection(int theDirection)
{
    printf("Direction: %d \n", theDirection);
    printf("Direction Pin: %d \n", DIRECTION_PIN);
    digitalWrite (DIRECTION_PIN, theDirection);
}

void turnMotorDriverOn()
{
  digitalWrite (MOTOR_DRIVER_ACTIVE_PIN, MOTOR_DRIVER_ON);

  //This gives the stepper driver board time to "wake up"
  delay(300);
}


void turnMotorDriverOff()
{
  digitalWrite (MOTOR_DRIVER_ACTIVE_PIN, MOTOR_DRIVER_OFF);
}


void moveMount(float inchesToMove)
{
  int i;
  int steps = inchesToMove / inchperstep;

  turnMotorDriverOn();

  for (i=0; i < steps; i++)
  {
    pulsePin(STEP_PIN, stepperdelay);
  }

  turnMotorDriverOff();

}


void moveMountUp(float inchesToMove)
{
  setMountDirection( DIRECTION_UP);
  moveMount(inchesToMove);
}


void moveMountDown(float inchesToMove)
{
  setMountDirection( DIRECTION_DOWN);
  moveMount(inchesToMove);
}


void goHome() 
{
  turnMotorDriverOn();

  setMountDirection( DIRECTION_DOWN );

  turnMotorDriverOff();

}