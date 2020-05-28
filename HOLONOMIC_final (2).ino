#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(10, 11);
int inM11 = 47;
int inM12 = 49 ;
int pwmM1 = 7; //100

int inM31 = 27;
int inM32 = 29;
int pwmM3 = 6; //300

int inM21 = 51;
int inM22 = 53;
int pwmM2 = 5; //100

int inM41 = 35;
int inM42 = 37;
int pwmM4 = 8; //300

void setup() {

  pinMode(inM31, OUTPUT);
  pinMode(inM32, OUTPUT);
  pinMode(pwmM3, OUTPUT);

  pinMode(inM11, OUTPUT);
  pinMode(inM12, OUTPUT);
  pinMode(pwmM1, OUTPUT);

 pinMode(inM21, OUTPUT);
  pinMode(inM22, OUTPUT);
  pinMode(pwmM2, OUTPUT);

  pinMode(inM41, OUTPUT);
  pinMode(inM42, OUTPUT);
  pinMode(pwmM4, OUTPUT);
  Serial.begin(9600);
  ps2.begin(9600); 

}

void loop() {
if((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<=120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>=0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)<132))  //Forward  (Right Up)
   {
    //FORWARD 
    digitalWrite(inM31 , HIGH);
    digitalWrite(inM32 , LOW);
    digitalWrite(inM11 , HIGH);
    digitalWrite(inM12 , LOW);
    digitalWrite(inM21 , LOW);
    digitalWrite(inM22 , HIGH);
    digitalWrite(inM41 , LOW);
    digitalWrite(inM42 , HIGH);
    analogWrite(pwmM3 , 70);
    analogWrite(pwmM1 , 70);
    analogWrite (pwmM2,70);
    analogWrite (pwmM4,70);
    Serial.println("FORWARD");
    
  }


if((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>=132)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<=255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)<132))       //Backward  (Right Down)
  { 
    digitalWrite(inM31 , LOW);
    digitalWrite(inM32 , HIGH);
    digitalWrite(inM11 , LOW);
    digitalWrite(inM12 , HIGH);
    digitalWrite(inM21 , HIGH);
    digitalWrite(inM22 , LOW);
    digitalWrite(inM41 , HIGH);
    digitalWrite(inM42 , LOW);
    analogWrite(pwmM3 , 70);
    analogWrite(pwmM1 , 70);
    analogWrite (pwmM2,70);
    analogWrite (pwmM4,70);
    Serial.println("BACKWARD");
        
  }

if((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 132)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<132))    //Right (Right Right)
{ 
    digitalWrite(inM31 , LOW);
    digitalWrite(inM32 , HIGH);
    digitalWrite(inM11 , HIGH);
    digitalWrite(inM12 , LOW);
    digitalWrite(inM21 , HIGH);
    digitalWrite(inM22 , LOW);
    digitalWrite(inM41 , LOW);
    digitalWrite(inM42 , HIGH);
    analogWrite(pwmM3 , 70);
    analogWrite(pwmM2 , 70);
    analogWrite(pwmM4 , 70);
    analogWrite(pwmM1 , 70);
    Serial.println("RIGHT");

 }

if((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)>=0)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)<=120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<132))     //Left (Right Left)
  { 
    digitalWrite(inM31 , HIGH);
    digitalWrite(inM32 , LOW);
    digitalWrite(inM11 , LOW);
    digitalWrite(inM12 , HIGH);
    digitalWrite(inM21 , LOW);
    digitalWrite(inM22 , HIGH);
    digitalWrite(inM41 , HIGH);
    digitalWrite(inM42 , LOW);
    analogWrite(pwmM3 , 70);
    analogWrite(pwmM2 , 70);
    analogWrite(pwmM4 , 70);
    analogWrite(pwmM1 , 70);
    Serial.println("LEFT");
  }
else if((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)<132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>120)&&(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<132))    //Stops
 {
    digitalWrite(inM31 , HIGH);
    digitalWrite(inM32 , HIGH);
    digitalWrite(inM11 , HIGH);
    digitalWrite(inM12 , HIGH);
    digitalWrite(inM21 , HIGH);
    digitalWrite(inM22 , HIGH);
    digitalWrite(inM41 , HIGH);
    digitalWrite(inM42 , HIGH);
    

 }
}

