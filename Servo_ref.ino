#include <Cytron_PS2Shield.h>
#include <SoftwareSerial.h> 
#include<Servo.h>

Cytron_PS2Shield ps2(10,11);
Servo myservo1;
Servo myservo2;
int flag1 = 0;
int flag2 = 0;

void setup() {
   Serial.begin(9600);
   Serial1.begin(9600);
   ps2.begin(9600);
myservo1.attach(9);
myservo2.attach(11);
}

void loop() {
  if ((ps2.readButton(PS2_SQUARE) == 0) && (ps2.readButton(PS2_TRIANGLE) == 1))
  flag1 = 1;
  if ((ps2.readButton(PS2_SQUARE) == 0)  && flag1 == 1)
  {
    myservo1.write(80);
    delay(1000);
    flag1=0;
  }

  if ((ps2.readButton(PS2_TRIANGLE) == 0) )
  flag2 = 1;

if((ps2.readButton(PS2_SQUARE) == 1) && flag2 == 1)
  {
    myservo2.write(0);
    delay(1000);
    flag2=0;
  }
    if ((ps2.readButton(PS2_SQUARE) == 1) && (ps2.readButton(PS2_TRIANGLE) == 1) && flag1==0 && flag2==0)
    {
      myservo1.write(0);
      myservo2.write(80);

      delay(1000);
    }

}
