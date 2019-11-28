#include <SoftwareSerial.h>
SoftwareSerial BTserial(1, 0 );
char data=0;
long duration;
int distance,f;
int buzzer=12;
int led = 13;
const int in1=11;
const int in2=10;
const int in3=9;
const int in4=8;
const int trigPin = 5;
const int echoPin = 4;

void setup() {
pinMode(led, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
BTserial.begin(9600);   //Sets the baud for serial data transmission       1                        
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(led, OUTPUT);
    buzz();
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
}
void loop() {
while (Serial.available() > 0)
  {
  data = Serial.read();
  Serial.println(data);
  }

       
       if(data=='1')
       {
         forward();
      }
      else if(data=='2')
      {
          backward();
      }
      else if(data=='3')
      {
         left();
      }
      else if(data=='4')
      {
        right();
      }
      else if(data=='5')
      {
        Break();
      }
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

if (distance<=2){
  buzz1();
  light();
  Break();
  data=0; 
}
}
void forward(){
  Serial.println("Forward");
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH); 
  digitalWrite(in4,LOW);
  digitalWrite(in1,LOW);
}
void backward(){
  Serial.println("Backward");
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
}
void left(){
  Serial.println("Left");
  digitalWrite(in3,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
}
void right(){
  Serial.println("Right");
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in1,LOW);  
}
void Break(){
  Serial.println("Break");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void buzz(){
  tone(buzzer,500);
  delay(200);
  noTone(buzzer);
  delay(200);
}
void buzz1(){
  tone(buzzer,700);
  delay(100);
  noTone(buzzer); 
  delay(100);
  
}
void light(){
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  
}
