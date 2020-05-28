//BASE
#include <SoftwareSerial.h>

char c = ' ';


void setup() {
  
Serial.begin(9600);
Serial.println("Arduino is ready");

Serial3.begin(38400);
//Serial2.begin(38400);
Serial.println("Serial started");
}

void loop() {
 
if(Serial3.available())
//if(Serial2.available())
{
 c = Serial3.read();
//c = Serial2.read();
  Serial.write(c);
}

if(Serial.available())
{
  c = Serial.read();
  Serial.write(c);
Serial3.write(c);
//Serial2.write(c);
}  

}
