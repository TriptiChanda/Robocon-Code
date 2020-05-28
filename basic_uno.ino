//ARM
#include <SoftwareSerial.h>
SoftwareSerial BT(2,3); //Rx ,Tx

char c = ' ';

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Arduino is ready");

BT.begin(38400);
//BT.begin(38400);
Serial.println("Serial started");
}

void loop() {
  // put your main code here, to run repeatedly:
//if(Serial2.available())
if(BT.available())
{
  //c = Serial2.read();
    c = BT.read();
  Serial.write(c);
}

if(Serial.available())
{
  c = Serial.read();  
  Serial.write(c);   //writes on serial monitor
  //Serial2.write(c);
  BT.write(c);  //Sends to bt
}

}

