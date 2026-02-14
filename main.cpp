#include <Servo.h>

// Pin definitions
const int RAIN_SENSOR_ANALOG = A0;
const int RAIN_SENSOR_DIGITAL = 2;
const int SERVO_PIN = 9;

// Servo object
Servo clothesBar;

// Servo positions
const int POSITION_OUTSIDE = 0;    // Clothes outside (sunny)
const int POSITION_PROTECTED = 90; // Clothes hidden under roof

// Rain detection threshold (adjust based on your sensor)
const int RAIN_THRESHOLD = 500;

// State variables
bool isRaining = false;
bool clothesProtected = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize rain sensor pin
  pinMode(RAIN_SENSOR_DIGITAL, INPUT);
  
  // Attach and initialize servo
  clothesBar.attach(SERVO_PIN);
  clothesBar.write(POSITION_OUTSIDE);
  clothesProtected = false;
  
  Serial.println("Rain Detection Clothes Protector Started!");
  Serial.println("Clothes are OUTSIDE");
}

void loop() {
  // Read rain sensor (both analog and digital)
  int rainAnalogValue = analogRead(RAIN_SENSOR_ANALOG);
  int rainDigitalValue = digitalRead(RAIN_SENSOR_DIGITAL);
  
  // Determine if it's raining
  // Digital sensor: LOW = rain detected, HIGH = no rain
  isRaining = (rainDigitalValue == LOW) || (rainAnalogValue > RAIN_THRESHOLD);
  
  // Print sensor readings
  Serial.print("Analog: ");
  Serial.print(rainAnalogValue);
  Serial.print(" | Digital: ");
  Serial.print(rainDigitalValue);
  Serial.print(" | Status: ");
  
  if (isRaining) {
    Serial.print("RAIN DETECTED! ");
    
    // Move clothes to protected position
    if (!clothesProtected) {
      Serial.println("Moving clothes INSIDE...");
      clothesBar.write(POSITION_PROTECTED);
      clothesProtected = true;
      delay(1000); // Wait for servo to complete movement
    } else {
      Serial.println("Clothes already protected");
    }
    
  } else {
    Serial.print("No rain. ");
    
    // Move clothes back outside
    if (clothesProtected) {
      Serial.println("Moving clothes OUTSIDE...");
      clothesBar.write(POSITION_OUTSIDE);
      clothesProtected = false;
      delay(1000); // Wait for servo to complete movement
    } else {
      Serial.println("Clothes already outside");
    }
  }
  
  delay(1000); // Check every second
}