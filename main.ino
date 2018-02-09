// #include <Ultrasonic.h>

// Ultrasonic us1(3,4);
// Ultrasonic us2(5,6);

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {

//   // Serial.print("US1 in CM: ");
//   // Serial.print(us1.Ranging(1));
//   // Serial.print("\n");
//   // Serial.print("US2 in CM: ");
//   // Serial.print(us2.Ranging(1));
//   // Serial.print("\n");
//   // Serial.print("================== \n");
//   // delay(500);

// }

#include "src/SparkFun_TB6612.h"

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 4
#define BIN1 6
#define AIN2 3
#define BIN2 7
#define PWMA 2
#define PWMB 8
#define STBY 5

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor2 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor1 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int blackLine1 = 3;
int blackLine2 = 4;
int isBlack = 0;

void setup()
{
  Serial.begin(9600);
  // pinMode(blackLine1, INPUT);
  // pinMode(blackLine2, INPUT);
}


void loop()
{
//   Serial.print(digitalRead(blackLine1));
//   Serial.print("\n");

//   Serial.print(digitalRead(blackLine2));
//   Serial.print("\n");

//   delay(500);
  // isBlack = digitalRead(blackLineSensor);
  
  // forward(motor1, motor2, 255);  
  
  Serial.print(isBlack);
  Serial.print("\n");
  if (!isBlack)
  { 
    Serial.print("BACK \n");
    back(motor1, motor2, 255);
    delay(2000);
    motor2.drive(255, 2000);
    delay(200);
  } else {
    Serial.print("FORWARD \n");
    forward(motor1, motor2, 255);  
  }

  
}