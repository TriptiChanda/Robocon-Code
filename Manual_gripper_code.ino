  
const int pwm = 6 ;  
const int in_1 = 8 ;
const int in_2 = 9 ;

 

void setup()
{
pinMode(pwm,OUTPUT) ;   
pinMode(in_1,OUTPUT) ;  
pinMode(in_2,OUTPUT) ;
}

void loop()
{

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,60) ;




delay(300) ;     


digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(3000) ;


digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
analogWrite(pwm,60);
delay(300) ;


digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(3000) ;
 }

