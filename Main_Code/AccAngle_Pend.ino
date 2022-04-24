#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

MPU6050 mpu;

int16_t accX, accY;
float accAngle;

void setup() {  
  mpu.initialize();
  Serial.begin(9600);
}

void loop() {  
  
  accX = mpu.getAccelerationX();
  accY = mpu.getAccelerationY();

  Serial.println("-------------------------------------------");
  Serial.print("accX = "); Serial.print(accX);
  Serial.print(" | accY = "); Serial.println(accY);
  
  accAngle = atan2(accX, accY)*RAD_TO_DEG;
  if(isnan(accAngle));
  else
    Serial.print("Angle of Acceleration is: ");
    Serial.print(accAngle); Serial.println( "°");
  Serial.println("-------------------------------------------");
  
  delay(5000); //Delay is in milliseconds. so 3000 ms is 3 sec
}
