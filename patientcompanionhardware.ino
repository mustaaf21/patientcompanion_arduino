//joystick
int xValue = A0;
int yValue = A1;

//wetness sensor 
const int sensor_pin = A3;

//ultrasonic sensor
int trigPin = 45;
int echoPin = 47;
int duration;
float distance;
int usValue;

//led 
int led = 10;
int speaker  = 11;

//motor driver 
int input1 = 2;
int input2 = 3;
int input3 = 4;
int input4 = 5;
int enA = 6;
int enB = 7;



void setup() {
 Serial.begin(9600);
 //motors
 pinMode(input1, OUTPUT);
 pinMode(input2, OUTPUT);
 pinMode(input3, OUTPUT);
 pinMode(input4, OUTPUT); 
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 pinMode(xValue, INPUT);
 pinMode(yValue, INPUT);
 pinMode(led, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(f, INPUT);
 pinMode(b, INPUT);
 pinMode(r, INPUT);
 pinMode(l, INPUT);
 pinMode(s, INPUT);
}

void loop() {
 xValue = analogRead(A0);  
 yValue = analogRead(A1);
 usValue = 0;
 Serial.print(xValue,DEC);
 Serial.print(",  ");
 Serial.print(yValue,DEC);
 Serial.print("\n");
 
// ultrasonic sensor 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance");
Serial.println(distance);
Serial.print("\n");
delayMicroseconds(2000);

float moisture_percentage;
int sensor_analog;
sensor_analog = analogRead(sensor_pin);
moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
Serial.print (sensor_analog);
Serial.print("Moisture Percentage = ");
Serial.print(moisture_percentage);
Serial.print("\n\n");
if (sensor_analog <= 800){
  Serial.print (" Error The Seat is wet ");
  digitalWrite(led, HIGH);
  digitalWrite(speaker,HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  digitalWrite(speaker,LOW);
  delay(1000);
  digitalWrite(led,HIGH);
  digitalWrite(speaker,HIGH);
  delay(500);
  digitalWrite(led, LOW);
  digitalWrite(speaker,LOW);
  delay(500);
}



if (distance<=100){
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input3,LOW);
  digitalWrite(input4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(led, HIGH);
  delayMicroseconds(2000);
  digitalWrite(led,LOW);
  delayMicroseconds(20000);
  Serial.print("stop");
}

//Manual control 
else{ 
 if (xValue >= 500 && yValue >= 490 ){ // stop 

  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input3,LOW);
  digitalWrite(input4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(led, HIGH);
 }
 else if ( yValue <= 100 ){ // forward

  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input3,HIGH);
  digitalWrite(input4,LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(led, LOW);
 }
 else if ( yValue >= 1000  ){ // backward

  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);
  digitalWrite(input3,LOW);
  digitalWrite(input4,HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(led, LOW);
 }
 else if ( xValue <= 100  ){ // LEFT

  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input3,HIGH);
  digitalWrite(input4,LOW);
  analogWrite(enA, 100);
  analogWrite(enB, 0);
  digitalWrite(led, LOW);
}
 else if ( xValue >= 1000 ){ // RIGHT

  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input3,HIGH);
  digitalWrite(input4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 150);
  digitalWrite(led, LOW);  
}
 else {
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input3,LOW);
  digitalWrite(input4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(led, HIGH);
 }

}

}
