
/*
HC-SR04
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 
Trig to Arduino pin 12
*/

const int trigPin = 13;
const int echoPin = 12;

// set up variables for distance and duration of sound;

long duration;
int distance;


// L298N motor controller code
//PWM controler 1 and 2 are motorSpeed pins
//motor forward or reverse are in1 and in2 for all motors
//PWM connects to jumpered on both sides 1st pin 
//on pins are 1234 8967 respectively

// motor A 
int motorSpeedA = 10;
int motorAin1 = 9;
int motorAin2 = 8;

// motor B
int motorSpeedB = 5;
int motorBin1 = 7;
int motorBin2 = 6;

//setup pins for devices

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorSpeedA, OUTPUT);
  pinMode(motorSpeedB, OUTPUT);
  pinMode(motorAin1, OUTPUT);
  pinMode(motorAin2, OUTPUT);
  pinMode(motorBin1, OUTPUT);
  pinMode(motorBin2, OUTPUT);
}



// setup driving functions

void forward(){

  digitalWrite(motorAin1, LOW);
  digitalWrite(motorAin2, HIGH);
  analogWrite(motorSpeedA, 80);  
   
}

void reverse(){
 
  digitalWrite(motorAin1, HIGH);
  digitalWrite(motorAin2, LOW);
  analogWrite(motorSpeedA, 100); 
  
}

void stopmotors(){

  digitalWrite(motorAin1, LOW);
  digitalWrite(motorAin2, LOW);  
  digitalWrite(motorBin1, LOW);
  digitalWrite(motorBin2, LOW);
    
    
}

void rightForward(){
  
  digitalWrite(motorAin1, LOW);
  digitalWrite(motorAin2, HIGH);
  analogWrite(motorSpeedA, 100);
  digitalWrite(motorBin1, LOW);
  digitalWrite(motorBin2, HIGH);
  analogWrite(motorSpeedB, 100);
 
}

void leftForward(){
  
  digitalWrite(motorAin1, LOW);
  digitalWrite(motorAin2, HIGH);
  analogWrite(motorSpeedA, 100);
  digitalWrite(motorBin1, HIGH);
  digitalWrite(motorBin2, LOW);
  analogWrite(motorSpeedB, 100);

 
}

void rightReverse(){
  
  digitalWrite(motorAin1, HIGH);
  digitalWrite(motorAin2, LOW);
  analogWrite(motorSpeedA, 100);
  digitalWrite(motorBin1, LOW);
  digitalWrite(motorBin2, HIGH);
  analogWrite(motorSpeedB, 100);
 
}

void leftReverse(){
  
  digitalWrite(motorAin1, HIGH);
  digitalWrite(motorAin2, LOW);
  analogWrite(motorSpeedA, 100);
  digitalWrite(motorBin1, HIGH);
  digitalWrite(motorBin2, LOW);
  analogWrite(motorSpeedB, 100);

 
}


// begin drive logic

void loop() {

  // begin echo pin !ping the world! numbers in Miliseconds
  //turn off 2 mili
 
digitalWrite(trigPin, LOW);
delayMicroseconds(2); 

 //turn on 10 mili

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

 //shut off echo pin again

digitalWrite(trigPin, LOW);  
 
 //Read echo pin

duration = pulseIn(echoPin, HIGH);

 //calc distance in centimeters
 //speed of sound 340 miliseconds
 //0.034 cm a milisecond
 // time is distance divided by speed
 //distance in cm is receive time multipled by .034 and divided by 2
 //you divide by 2 because the distance is goes from object back to receiver 
 //so twice as long for the sound to bounce

distance= duration*0.034/2;
 
// actual brain logic commented to diagnose all movement 

if (distance < 8) {  // if less than 4 cms
  
    stopmotors(); 
    delay(400);
    reverse();
    delay(4000);
    rightForward();
    delay(4000);
    
}
  else {
    
    forward();
    delay(500);
    
  }

  
}
/*

old test code to verify motor directions work

forward();
delay(400);
stopmotors();
delay(20);
rightForward();
delay(400);
stopmotors();
delay(20);
leftForward();
delay(400);
stopmotors();
delay(20);
reverse();
delay(400);
stopmotors();
delay(20);
rightReverse();
delay(400);
stopmotors();
delay(20);
leftReverse();
delay(400);
stopmotors();
delay(20);

}

*/




