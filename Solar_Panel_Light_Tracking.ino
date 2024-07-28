#include "arduino_secrets.h"

/*

Light-Tracking Solar Panel Vs Stable Solar Panel
By: Kamila Moodely And Tanisha Hossain

*/


//Include the servo motor liary
#include <Servo.h>


const int SERVO = 9;
const int LDR = 5;


Servo servo;
int Val = 0;


//Set the initial angle of the servo motor
int Spoint = 110;


void setup() {
 // put your setup code here, to run once:


 Serial.begin(9600);
 servo.attach(SERVO);


 //Set the starting of the Servo Motor
 servo.write(Spoint);


}


void loop() {
 // put your main code here, to run repeatedly:


 Val = analogRead(LDR);
 Serial.print("Analog Reading: ");
 Serial.println(Val);
 Val = map(Val, 0, 1023, 0, 179);
 servo.write(Val);
 delay(50);
}