#include<SoftwareSerial.h>
#include<Servo.h>
#include<PS2_Cytron  >
Servo myservo1;  //Gripper
Servo myservo2;  //Arm
int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
void setup() {
  // put your setup code here, to run once:
myservo1.attach(8);
myservo2.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

/* +++++++++ Gripper ++++++++ */

// Gripper closes
if(ps2.readButton(PS2_DOWN)==0)
flag1 = 1;
if( (ps2.readButton(PS2_DOWN)==1) && (flag1 == 1) )
 {
 myservo1.attach(8);
 myservo1.write(0);
 delay(1000);
 flag1 = 0;
 myservo1.detach(); 
 }

// Gripper opens
if(ps2,readButton(PS2_UP)==0)
flag2 = 1;
if( (ps2.readButton(PS2_DOWN)==1) && (flag1 == 1) )
 {
 myservo1.attach(8);
 myservo1.write(90);
 delay(1000);
 flag2 = 0;
 myservo1.detach(); 
 }

/* +++++++++ Arm ++++++++ */

// Arm at 0
if(ps2.readButton(PS2_LEFT)==0)
flag3 = 1;
if( (ps2.readButton(PS2_LEFT)==1) && (flag3 == 1) )
 {
 myservo2.attach(9);
 myservo2.write(0);
 delay(1000);
 flag3 = 0;
 myservo2.detach(); 
 }
 
// Arm moves to  90
if(ps2.readButton(PS2_RIGHT)==0)
flag4 = 1;
if( (ps2.readButton(PS2_RIGHT)==1) && (flag4 == 1) )
 {
 myservo2.attach(9);
 myservo2.write(90);
 delay(1000);
 flag4 = 0;
 myservo2.detach(); 
 }
 
 
}
