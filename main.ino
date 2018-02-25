#include "src/SparkFun_TB6612.h"

#define AIN1 9
#define BIN1 11
#define AIN2 8
#define BIN2 12
#define PWMA 3
#define PWMB 5
#define STBY 10

const int offsetA = 1;
const int offsetB = 1;

Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

int blackSensor1 = 7;
int blackSensor2 = 6;
int isOneBlack = 0;
int isTwoBlack = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(blackSensor1, INPUT);
  pinMode(blackSensor2, INPUT);
  delay(5000);
}

void loop()
{
  Serial.print(digitalRead(blackSensor1));
  Serial.print("\n");

  Serial.print(digitalRead(blackSensor2));
  Serial.print("\n");

  isOneBlack = digitalRead(blackSensor1);
  isTwoBlack = digitalRead(blackSensor2);
  
  // forward(motor1, motor2, 255);  
  if (isOneBlack != 1 || isTwoBlack != 1)
  { 
    brake(motor1,motor2);
    Serial.print("BACK \n");
    back(motor1, motor2, 255);
    delay(500);
    sideStep(isOneBlack, isTwoBlack, 400);
  } else {
    Serial.print("FORWARD \n");
    forward(motor1, motor2, 255);
  }
}

void sideStep(int isOneBlack, int isTwoBlack, int duration)
{
  if (isOneBlack != 1) {
    Serial.print("Steer \n");
    left(motor1, motor2, 510);
    delay(duration);
  } else if(isTwoBlack != 1) {
    Serial.print("Steer \n");
    right(motor1, motor2, 510);
    delay(duration);
  }
}