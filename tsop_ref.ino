#include<SoftwareSerial.h>
int flag=0,flag1=0;
void setup() {
  // put your setup code here, to run once:
pinMode(9,INPUT); //tsop1
pinMode(11,INPUT); //tsop2
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int a=digitalRead(9);
int b=digitalRead(11);
Serial.print(a);
Serial.print(" ");
Serial.println(b);
if(a==HIGH && b==HIGH)
{
 Serial.println("TZ1");
 
}
else if(a==LOW && b==HIGH)
{
  //flag=1;
//}
//if(flag==1)
//{
  Serial.println("Tz2");
  //flag=0;
 
  
}
 if(b==LOW && a==HIGH)
{
///  flag1=2;
////}
////if(flag1==2)
////{
 Serial.println("Tz3");
//  // flag1=0;
// 
//  
}

}
