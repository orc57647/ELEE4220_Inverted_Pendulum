//Code for Motors on Inverted Pendulum

// Motor Bottom Left
const int motor_BL_R = 13; // White Wire into Pin 2 of L293, Associated with Red Motor Wire
const int motor_BL_B = 12; // Green Wire into Pin 7 of L293, Associated with Black Motor Wire

// Motor Bottom Right
const int motor_BR_R = 11; // Red Wire into Pin 15 of L293, Associated with Red Motor Wire
const int motor_BR_B = 10; // Yellow Wire into Pin 10 of L293, Associated with Black Motor Wire

// Motor Top Left
const int motor_TL_R = 4; // Wire into IN1 of L298N, Associated with Red Motor Wire
const int motor_TL_B = 5; // Wire into IN2 of L298N, Associated with Black Motor Wire

// Motor Top Right
const int motor_TR_R = 7; // Wire into IN3 of L298N, Associated with Red Motor Wire
const int motor_TR_B = 6; // Wire into IN4 of L298N, Associated with Black Motor Wire

void setup() 
{
  //Set pins as outputs to move motor
  pinMode(motor_BL_R, OUTPUT);
  pinMode(motor_BL_B, OUTPUT);
  
  pinMode(motor_BR_R, OUTPUT);
  pinMode(motor_BR_B, OUTPUT);
  
  pinMode(motor_TL_R, OUTPUT);
  pinMode(motor_TL_B, OUTPUT);
  
  pinMode(motor_TR_R, OUTPUT);
  pinMode(motor_TR_B, OUTPUT);

//This code will test the motor to see which color does which

  // Turn motor Counter Clockwise(Forward) for 2 seconds 
  digitalWrite(motor_BL_R, HIGH);
  digitalWrite(motor_BL_B, LOW);
  digitalWrite(motor_BR_R, HIGH);
  digitalWrite(motor_BR_B, LOW);
  digitalWrite(motor_TL_R, HIGH);
  digitalWrite(motor_TL_B, LOW);
  digitalWrite(motor_TR_R, HIGH);
  digitalWrite(motor_TR_B, LOW);
  delay(500); // time in ms, 2000 ms = 2 sec

  // Turn motor Clockwise(Backwards) for 2 seconds 
  digitalWrite(motor_BL_R, LOW);
  digitalWrite(motor_BL_B, HIGH);
  digitalWrite(motor_BR_R, LOW);
  digitalWrite(motor_BR_B, HIGH);
  digitalWrite(motor_TL_R, LOW);
  digitalWrite(motor_TL_B, HIGH);
  digitalWrite(motor_TR_R, LOW);
  digitalWrite(motor_TR_B, HIGH);
  delay(500); // time in ms, 2000 ms = 2 sec

   // Stop Motors from moving 
  digitalWrite(motor_BL_R, LOW);
  digitalWrite(motor_BL_B, LOW);
  digitalWrite(motor_BR_R, LOW);
  digitalWrite(motor_BR_B, LOW);
  digitalWrite(motor_TL_R, LOW);
  digitalWrite(motor_TL_B, LOW);
  digitalWrite(motor_TR_R, LOW);
  digitalWrite(motor_TR_B, LOW);
}

void loop() 
{
  

}
