//Lsc08 Auto Bot code
const float Kp = 5;   // Kp value that you have to change
//const float Kd = 2;   // Kd value that you have to change
const float Ki = 0.01;
const int setPoint = 35;    // Middle point of sensor array
const int baseSpeed = 70;    // Base speed for your motors
const int maxSpeed = 90;   // Maximum speed for your motors

const byte rx = 0;    // Defining pin 0 as Rx
const byte tx = 1;    // Defining pin 1 as Tx
const byte serialEn = 2;    // Connect UART output enable of LSA08 to pin 2
const byte jp = 3;   // Connect JPULSE of LSA08 to pin 4

int cnt=0;
int flag=0;
int inA1=22;
int inA2=23;
int inB1=26;
int inB2=27;

int dirA1=24;
int dirA2=25;
int dirB1=28;
int dirB2=29;

int pwmA=7;
int pwmB=8;
void setup() {
  pinMode(serialEn,OUTPUT);   
  pinMode(jp,INPUT);   
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  for(int i=22;i<=29;i++) {
  pinMode(i,OUTPUT);
}
    digitalWrite(dirA1, HIGH);
    digitalWrite(dirA2, HIGH);
    digitalWrite(dirB1, HIGH);
    digitalWrite(dirB2, HIGH);

    


  digitalWrite(serialEn,HIGH);
  Serial.begin(9600);

}
void stopp();
void forward(int);
float lastError = 0;    

void loop() {
 
  digitalWrite(serialEn,LOW);   
  while(Serial.available() <= 0);   
  int positionVal = Serial.read();    
  digitalWrite(serialEn,HIGH);    
 const byte jpulse= digitalRead(jp);

 if(jpulse == LOW && cnt==0 && flag==0)
      {
         digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
        forward(positionVal);
        Serial.println("First");
        
//        delay(100);
      }
  else if(jpulse == HIGH && cnt==0 && flag==0)
      {
         digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
        forward(positionVal);
        cnt=1;
        Serial.println("Second");
        delay(100);
        //delay(1000);
      }
 else if(jpulse == HIGH && cnt ==1 && flag==0)
      {
         digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
       forward(positionVal);
       

       Serial.println("Third");
//       delay(100);
        
      }
   else if(jpulse == LOW && cnt ==1)
      {
         digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
       forward(positionVal);
       cnt=2; 
       Serial.println("Fourth");
//       delay(100);
      }    
 else if(jpulse==HIGH && cnt ==2)
      {
        flag=1;
        stopp();
        Serial.println("Fifth");
        //delay(100);
       
//        Serial.println("stopped888888");
      }
    //Serial.println(flag);
 else if(jpulse==LOW && cnt ==2 && flag==1)
      {
        stopp();
        Serial.println("Sixth");
       // delay(100);
//        Serial.println("stopped");
      }

  
 else if(positionVal == 255) {
    stopp();
    Serial.println("Seventh");
    //delay(100);
  
}

  else {
    forward(positionVal);
    Serial.println("Eighth");
    //delay(100);

}
}
void stopp(){
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, HIGH);
//analogWrite(pwm1, 0);
//analogWrite(pwm2, 0);
}

void forward(int positionVal){
  
  float error = positionVal - setPoint;   
    // float der = error - lastError;
    float integral = integral + error;
    float motorSpeed = Kp * error + Ki * integral;   
    lastError = error;    
  
    float pwmA1 = baseSpeed - motorSpeed;
    float pwmB1 = baseSpeed +motorSpeed;
    
  
    if(pwmA1 > maxSpeed) 
    pwmA1 = maxSpeed;
    if(pwmB1 > maxSpeed) 
    pwmB1 = maxSpeed;
   
    if(pwmA1 < 0) 
    pwmA1 = 0;
    if(pwmB1 < 0) 
    pwmB1 = 0;
    
   
    
    analogWrite(pwmA,pwmA1);
    analogWrite(pwmB,pwmB1);
    
    //Serial.println(pwmA1);
    delay(10);
  }



