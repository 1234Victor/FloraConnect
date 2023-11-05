#include <CapacitiveSensor.h>

// Create a capacitive sensor that uses pin 2 as the send pin and pin 4 as the receive (sensor) pin
CapacitiveSensor cs_2_4 = CapacitiveSensor(2, 4); // 1M resistor between pins 2 & 4, pin 4 is the sensor pin

//humid
#define sensorPin A0
#define powerPin 9
#define led 7

//ultra
const int trigPin = 6;
const int echoPin = 5;
// defines variables
float duration;
float distance;
int t1= -2;
int t2 = -2;
bool close = false;
bool touched = false;
int touch_count = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second

  //humid
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, LOW);

  //ultra
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  int t = touch();
  int s = soil();
  int u = ultra();

  if(t!=-2 && t1!=- 2 && t2 != -2 && t-t2 > 200 && touch_count > 10){

    
      //touched
      digitalWrite(led, HIGH);
      Serial.print("TOUCHED!\n");
      delay(1000);
      touch_count = 0;
    
  }
  else if(u < 30 && close == false){
    delay(100);
    if(u < 30 && close == false){
    //touched
      digitalWrite(led, HIGH);
      close = true;
      Serial.print("CAME!\n");
      }
  }
  else if (u > 30 && close == true){
    delay(100);
    if(u > 30 && close == true){
    close = false;
    Serial.print("LEFT!\n");
    }
  }
  else{
    digitalWrite(led, LOW);
  }

  t2 = t1;
  t1 = t;

  

  delay(200);
  touch_count++;

}

int touch(){
  int sensorValue = cs_2_4.capacitiveSensor(30); // Read the capacitive sensor value
  // Print the sensor value to the Serial Monitor
  //Serial.print("Sensor Value: ");
  //Serial.println(sensorValue);
  return sensorValue;
}

int soil() {
	digitalWrite(powerPin, HIGH);	// Turn the sensor ON
	delay(10);							// Allow power to settle
	int val = analogRead(sensorPin);	// Read the analog value form sensor
	digitalWrite(powerPin, LOW);		// Turn the sensor OFF
  //Serial.println(val);
	return val;							// Return analog moisture value
}

int ultra (){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  //Serial.print("Distance: ");
 // Serial.println(distance);
  return distance;
}
