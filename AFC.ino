#include<Servo.h>
Servo myServo1;

const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;
const int stepPin = 3; 
const int dirPin = 4; 

void setup()
{
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myServo1.attach(12);
}


void loop() {
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 'a':
      SetTheBlade();
      break;
    case 'b':
      CleanTheBlade();
      break;
    case 'c':
      Retract();
      break;
  }  
}

void SetTheBlade()
{
  int i=0;
  while(i==0){
  digitalWrite(dirPin,HIGH); 
  for(int x = 0; x < 10000 ;x++) {
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<=10)
  { 
   x=20000;
   i++;
   }}
}}


void CleanTheBlade()
{
  myservo1.write(0);
  delay(1000);
  digitalWrite(dirPin,HIGH); 
  for(int x = 0; x < 10000 ;x++) {
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500);
  }
  digitalWrite(dirPin,LOW);
  for(int x = 0; x < 10000 ;x++) {
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500);
   }
}

void Retract()
{
  myServo1.write(180);
  delay(1000);
}
