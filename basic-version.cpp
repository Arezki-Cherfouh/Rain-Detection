#include <Servo.h>

const int SENSOR_PIN = A0; // Middle pin of your slider
const int SERVO_PIN  = 9;  // Orange wire of your servo

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Start at 0 degrees
  Serial.begin(9600); // So you can see the sensor values
}

void loop() {
  int waterLevel = analogRead(SENSOR_PIN);
  
  // Print value to the Serial Monitor (bottom of screen)
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  if (waterLevel > 500) {
    myServo.write(90); // Move 90 degrees when "wet"
  } else {
    myServo.write(0);  // Back to start when "dry"
  }

  delay(15); // Smooths out the simulation
}
