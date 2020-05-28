#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 4;// variable to store the servo position
int pwm = 7;

//Motor 
const int motorPin1  = 5;  
const int motorPin2  = 6;
const int motorPin3  = 8; 
const int motorPin4  = 9; 

void setup() {
  myservo.attach(0); // attaches the servo on pin 0 to the servo object
//This will run only one time.
 
   //Set pins as outputs
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   digitalWrite(8,HIGH); 
   digitalWrite(9,HIGH);
   pinMode(7,OUTPUT);
}

void loop() {

    myservo.write(90);
    delay(5000);        
   
    // waits 15ms for the servo to reach the position
   //This will run only one time.
     //Motor Control - Motor : motorPin1,motorpin2
    //This code  will turn Motor clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(pwm ,50);
    delay(2000);
    
    myservo.write(0);
    delay(5000);
        //This code will turn Motor counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(pwm ,50);
    delay(2000);
        //And this code will stop motor
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
}
