//Arm
#include <PWMServo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2,3);  // 2 is Rx and 3 is Tx
 
int sensor1 = 12;        // for shuttlecock detection         
int count = 0; 
int tsop_reciever = 11;     //for releasing shuttlecock 
    
//int p=0;
PWMServo myServo;    //for  gripping shuttlecock

int flag = 0;
int cflag = 0;

void setup() {
  
Serial.begin(9600);

BT.begin(38400);

myServo.attach(9);

pinMode(sensor1, INPUT);
pinMode(tsop_reciever, INPUT);


 
 
pinMode(9,OUTPUT);

 int a = digitalRead(sensor1);
          

   if(a == HIGH)                    //no shuttlecock detected
   {
    myServo.write(0);//servo open
        flag=1;
        
   }
 
}

void loop() {

  int a = digitalRead(sensor1);
  int b = digitalRead(tsop_reciever);

 if(a == LOW)                          //shuttle gripped and motor will go in tz1
   {
   
    myServo.write(40);  //servo close
   
   flag=2; 
   }
  

   if(a == HIGH && flag == 2)
   {
   myServo.write(40);
   flag = 2;
   }


if(b == LOW)   //for releasing shuttlecock 
{
 
  cflag = 1;

}
if(b == HIGH && cflag == 1 && flag == 2)
{
  count++;
  //delay(50);
  cflag = 0;
  
  }
if(count == 8 && b==HIGH) 
{

        myServo.write(0);  //servo open
 
        flag=0;           
        count = 0;
        
}
 
Serial.print(flag);
Serial.print(" ");
Serial.print(count);
Serial.print(" ");
Serial.print(cflag);
Serial.println();



 BT.write(flag);
 

 }  

 



      
