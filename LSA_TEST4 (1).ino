
int setPoint = 35;  // Middle point of sensor array

int serialEn1 = 25;  // Connect UART output enable of LSA08 to pin 2
int jPulse1 = 23;    // Connect JPULSE of LSA08 to pin 4

int serialEn2 = 29;  // Connect UART output enable of LSA08 to pin 2
int jPulse2 = 27;    // Connect JPULSE of LSA08 to pin 4

int pwmA =0, pwmB=0;
int pwmA1=0, pwmB1=0;
int pwmA2=0, pwmB2=0;
int count=0,flag=0, flag2=0;

int dir1=13, dir2=11, dir3=9, dir4=7;       //motor directions
int pwm1=12, pwm2=10, pwm3=8, pwm4=6;       //motor pwms
float lastError1=0;
float lastError2=0;

void setup() {
pinMode(13,OUTPUT);     //D1
pinMode(12,OUTPUT);     //pwm1

pinMode(11,OUTPUT);     //D2
pinMode(10,OUTPUT);     //pwm2

pinMode(9,OUTPUT);     //D3
pinMode(8,OUTPUT);     //pwm3

pinMode(7,OUTPUT);     //D4
pinMode(6,OUTPUT);     //pwm4

Serial.begin(9600);

Serial1.begin(9600);
pinMode(serialEn1,OUTPUT);   // Setting serialEn as digital output pin
pinMode(jPulse1,INPUT);      // Setting junctionPulse as digital input pin
digitalWrite(serialEn1,HIGH);

Serial2.begin(9600);
pinMode(serialEn2,OUTPUT);   // Setting serialEn as digital output pin
pinMode(jPulse2,INPUT);      // Setting junctionPulse as digital input pin
digitalWrite(serialEn2,HIGH);



}

void loop() {

  pid(100,150,0.4, 10,0.01);
  }

void pid(int baseSpeed, int maxSpeed,float Kp, float Kd, float Ki)
{
    digitalWrite(serialEn1,LOW);         // Set serialEN to LOW to request UART data
    while(Serial1.available() <= 0);    // Wait for data to be available
    int positionVal1 = Serial1.read();   // Read incoming data and store in variable positionVal
    digitalWrite(serialEn1,HIGH);        // Stop requesting for UART data
    
    float error1 = positionVal1 - setPoint;   // Calculate the deviation from position to the set point
    float der1 = error1 - lastError1;
    float integral1 = integral1 + error1;
    float motorSpeed1 = Kp * error1 + Ki * integral1 + Kd*der1;   // Applying formula of PID
    lastError1 = error1;

    
    digitalWrite(serialEn2,LOW);         // Set serialEN to LOW to request UART data
    while(Serial2.available() <= 0);    // Wait for data to be available
    int positionVal2 = Serial2.read();   // Read incoming data and store in variable positionVal
    digitalWrite(serialEn2,HIGH);        // Stop requesting for UART data
    
    float error2 = positionVal2 - setPoint;   // Calculate the deviation from position to the set point
    float der2 = error2 - lastError2;
    float integral2 = integral2 + error2;
    float motorSpeed2 = Kp * error2 + Ki * integral2 + Kd*der2;   // Applying formula of PID
    lastError2 = error2;

    if(positionVal1 == 255 && positionVal2 == 255) {      //no line
      analogWrite(pwm1,0);         
      analogWrite(pwm2,0);    
      analogWrite(pwm3,0);         
      analogWrite(pwm4,0);         
     }
    
else{
      digitalWrite(dir2, HIGH);
      digitalWrite(dir4, LOW);
      digitalWrite(dir1, HIGH);
      digitalWrite(dir3, LOW);

     
    
      pwmA1 = baseSpeed - motorSpeed1;
      pwmB1 = baseSpeed + motorSpeed1;
      
      pwmA2 = baseSpeed + motorSpeed2;
      pwmB2 = baseSpeed - motorSpeed2;

      pwmA = ((pwmA1 + pwmA2)/2);
      pwmB = ((pwmB1 + pwmB2)/2);
      // If the speed of motor exceed max speed, set the speed to max speed
      if(pwmA > maxSpeed) 
      pwmA = maxSpeed;
      if(pwmB > maxSpeed) 
      pwmB = maxSpeed;
      
      // If the speed of motor is negative, set it to minimum
      if(pwmA <= 0) 
      pwmA = 2;
      if(pwmB <= 0) 
      pwmB = 2;
      
      analogWrite(pwm1,pwmA);         
      analogWrite(pwm2,pwmA);    
      analogWrite(pwm3,pwmB);         
      analogWrite(pwm4,pwmB);  
    }

    
      Serial.print("pwm1");
      Serial.print(pwmA);
      Serial.print("pwm2");
      Serial.print(pwmA);
      Serial.print("pwm3");
      Serial.print(pwmB);
      Serial.print("pwm4");
      Serial.println(pwmB);
      Serial.println();

}


