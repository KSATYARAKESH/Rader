#include <Servo.h>. 
const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;
Servo myServo; 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(10);
}
void loop() {
  // rotates the servo motor from 0 to 180 degrees
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }
  // Repeats the previous lines from 180 to 0 degrees
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
