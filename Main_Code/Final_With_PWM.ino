#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

MPU6050 mpu;

// Motor Top Left
const int motor_TL_R = 3; // Wire into IN1 of L298N, Associated with Red Motor Wire. WAS 4, changed to 3
const int motor_TL_B = 5; // Wire into IN2 of L298N, Associated with Black Motor Wire WAS 5, changed to 5

// Motor Top Right
const int motor_TR_R = 9; // Wire into IN3 of L298N, Associated with Red Motor Wire WAS 6, changed to 6
const int motor_TR_B = 6; // Wire into IN4 of L298N, Associated with Black Motor Wire WAS 7, changed to 9

//initializing variables
int16_t accX, accY;
float accAngle, y;
int16_t gyroX, gyroRate;
float gyroAngle=0;
unsigned long currTime, prevTime=0, timeChange;
int motor1_speed;
int motor2_speed;
double Kp=18, Kd=6; //need to tune these values once the motors move continously 
double setpoint=2, sampleTime;
float error, output;
bool first = 1;

void setup() //setup the sensor and motors
{  
  mpu.initialize();
  Serial.begin(9600);

  pinMode(motor_TL_R, OUTPUT);
  pinMode(motor_TL_B, OUTPUT); 
  pinMode(motor_TR_R, OUTPUT);
  pinMode(motor_TR_B, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() 
{   
  sampleTime = 7; //7ms sample time to make sure that the system runs at regular intervals, as shown in 2nd video sent to groupchat on May 1st, 2022
  accX = mpu.getAccelerationX(); //accelerometer initialization
  accY = mpu.getAccelerationY(); //accelerometer initialization 
  accAngle = atan2(accX, accY)*RAD_TO_DEG; //angle calculation using accelerometer
  gyroX = mpu.getRotationX();
  gyroRate = map(gyroX, -32768, 32767, -250, 250);
  //gyroAngle = gyroAngle + (float)gyroRate*loopTime/1000;
  currTime = millis(); //obtains current time in milliseconds
  timeChange = currTime - prevTime;
  if(timeChange >= sampleTime);
  {
    if(isnan(accAngle));
    else
    {
      Serial.println("-------------------------------------------");
      Serial.print("accX = "); Serial.print(accX);
      Serial.print(" | accY = "); Serial.println(accY);
      Serial.print("Angle of Acceleration is: ");
      Serial.print(accAngle); Serial.println( "°");
      Serial.print("Angle of Gyration is: ");
      Serial.print(gyroRate); Serial.println( "°");
      Serial.println("-------------------------------------------");   
    }
    
    output = Kp*(accAngle-setpoint) + Kd*gyroRate;
    output = abs(output); //this will be the controller used for the upright robot
    constrain(output, 0, 255); //constrain motor values to be from 0 to 255 since that is the PWM limit of the motor driver
    
    if (accAngle == 0) //motors will not drive if the sensor is reading the setpoint
    {
        analogWrite(3, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(9, 0);
        //Serial.println('0');
    }
    else if (accAngle < 0) //Move Backward
    {
        analogWrite(3, output);
        analogWrite(5, output);
        analogWrite(6, output);
        analogWrite(9, output);
        digitalWrite(motor_TL_R, LOW);
        digitalWrite(motor_TL_B, HIGH);
  
        digitalWrite(motor_TR_R, LOW);
        digitalWrite(motor_TR_B, HIGH);
        //Serial.println("less than 0");
    }
    else //Move Forward (In direction of front Sticker)
    {
        analogWrite(3, output);
        analogWrite(5, output);
        analogWrite(6, output);
        analogWrite(9, output);
        digitalWrite(motor_TL_R, HIGH);
        digitalWrite(motor_TL_B, LOW);
  
        digitalWrite(motor_TR_R, HIGH);
        digitalWrite(motor_TR_B, LOW);
    }
        if(abs(accAngle)>=45) //Beyon Repair Statement, if the angle is greater than -45° or 45° the motors will stop.
    {
      digitalWrite(motor_TL_R, LOW);
      digitalWrite(motor_TL_B, LOW);
  
      digitalWrite(motor_TR_R, LOW);
      digitalWrite(motor_TR_B, LOW);
    }
  }   
}
