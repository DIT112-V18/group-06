#include <Smartcar.h>
//Initialize sensor pin value
int LEFT_SENSORPIN = 5;
int CENTER_SENSORPIN = 6;
int RIGHT_SENSORPIN=  7;

//Initialize different motor pin value
int leftMotorForwardPin = 8;
int leftMotorBackwardPin = 10;
int leftMotorSpeedPin = 9;
int rightMotorForwardPin = 12;
int rightMotorBackwardPin = 13;
int rightMotorSpeedPin = 11;

BrushedMotor leftMotor(leftMotorForwardPin,leftMotorBackwardPin, leftMotorSpeedPin);

BrushedMotor rightMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin);

DifferentialControl control(leftMotor, rightMotor);

SimpleCar car(control);

void setup()
{
   //start serial
  Serial.begin(9600);
  //define pin modes
  pinMode(LEFT_SENSORPIN,INPUT);
  pinMode(CENTER_SENSORPIN,INPUT);
  pinMode(RIGHT_SENSORPIN,INPUT);
  car.setSpeed(30);
}
 
void loop()
{// read input from sensors
  byte l=digitalRead(LEFT_SENSORPIN);
  byte c=digitalRead(CENTER_SENSORPIN);
  byte r=digitalRead(RIGHT_SENSORPIN);

  if(l == 1 && c == 0 && r == 1){
    car.setAngle(0);
    car.setSpeed(20);
  }else if(l == 0 && c == 0 && r == 1){
    car.setAngle(-90);
    car.setSpeed(30);
  }else if(l == 0 && c == 1 && r == 1){
    car.setAngle(-90);
    car.setSpeed(30);
  }else if(l == 1 && c == 0 && r == 0){
    car.setAngle(90);
    car.setSpeed(30);
  }else if(l == 1 && c == 1 && r == 0){
    car.setAngle(90);
    car.setSpeed(30);
  }else if(l == 1 && c == 1 && r == 1){
    
  }else if(l == 0 && c == 0 && r == 0){
    car.setAngle(0);
    car.setSpeed(0);
  }
}
