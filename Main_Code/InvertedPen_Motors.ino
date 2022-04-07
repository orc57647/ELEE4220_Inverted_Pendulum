//Code for Motors on Inverted Pendulum

// Motor Bottom left
const int motor_BL_R = 13; // White Wire into Pin 2 of L293, Associated with Red Motor Wire
const int motor_BL_B = 12; // Green Wire into Pin 7 of L293, Associated with Black Motor Wire

void setup() 
{
  //Set pins as outputs to move motor
  pinMode(motor_BL_R, OUTPUT);
  pinMode(motor_BL_B, OUTPUT);

//This code will test the motor to see which color does which

  // Turn motor Counter Clockwise(Forward) for 2 seconds 
  digitalWrite(motor_BL_R, HIGH);
  digitalWrite(motor_BL_B, LOW);
  delay(2000); // time in ms, 2000 ms = 2 sec

  // Turn motor Clockwise(Backwards) for 2 seconds 
  digitalWrite(motor_BL_R, LOW);
  digitalWrite(motor_BL_B, HIGH);
  delay(2000); // time in ms, 2000 ms = 2 sec

   // Stop Motors from moving 
  digitalWrite(motor_BL_R, LOW);
  digitalWrite(motor_BL_B, LOW);
   
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
