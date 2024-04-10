/*
 * Distance-Responsive LED with Nicla Vision and VL53L1X Sensor
 * This sketch demonstrates how to use the AMS VL53L1X time-of-flight (ToF) sensor with the Nicla Vision board
 * to create a distance-responsive LED lighting effect. Depending on the distance measured by the sensor,
 * an RGB LED changes colors and blink rates.
 * 
 * Ensure your Nicla Vision board's firmware is up to date before running this sketch.
 * 
 * Dependencies: VL53L1X library for distance measurement.
 * 
 * Workshop Training Session by [Your Name]
 * [Your Event/Workshop Name]
 * [Date]
 */

#include "VL53L1X.h"

// Initialize the VL53L1X proximity sensor
VL53L1X proximity;

// Variables to manage LED blinking and sensor reading
bool blinkState = false;
unsigned long lastBlinkTime = 0;
const int readingThresholdClose = 200; // Threshold for close distance (in mm)
const int readingThresholdMedium = 500; // Threshold for medium distance (in mm)

void setup() {
  Serial.begin(115200); // Start serial communication
  Wire1.begin(); // Start I2C communication
  Wire1.setClock(400000); // Use 400 kHz I2C speed for faster communication with the sensor

  // Initialize LED pins
  pinMode(LEDB, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  
  // Attempt to initialize the VL53L1X sensor
  proximity.setBus(&Wire1);
  if (!proximity.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1); // Halt execution if sensor is not found
  }

  // Configure the sensor for long distance mode
  proximity.setDistanceMode(VL53L1X::Long);
  proximity.setMeasurementTimingBudget(10000); // Set time budget for measurements
  proximity.startContinuous(10); // Start continuous measurement with minimal delay
}

void loop() {
  int reading = proximity.read(); // Read the current distance
  Serial.println(reading); // Output the reading to the Serial monitor

  // Calculate the time elapsed since the last LED toggle
  if (millis() - lastBlinkTime >= max(100, reading)) { // Ensure at least a 100ms delay
    blinkState = !blinkState; // Toggle the blink state
    lastBlinkTime = millis(); // Update the time of the last blink

    // Adjust the LED states based on the distance measured by the sensor
    if (reading < readingThresholdClose) {
      // Close distance: Red and Blue LEDs
      digitalWrite(LEDR, blinkState ? HIGH : LOW);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, blinkState ? HIGH : LOW);
    } else if (reading < readingThresholdMedium) {
      // Medium distance: Green and Blue LEDs
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, blinkState ? HIGH : LOW);
      digitalWrite(LEDB, blinkState ? HIGH : LOW);
    } else {
      // Far distance: Cycle through Red, Green, and Blue LEDs
      digitalWrite(LEDR, blinkState ? HIGH : LOW);
      digitalWrite(LEDG, blinkState ? HIGH : LOW);
      digitalWrite(LEDB, blinkState ? HIGH : LOW);
    }
  }
}

// Additional functions such as breathingEffect() and exclamationFlasher() can be utilized
// to further enhance the interactive experience based on specific workshop activities.


void breathingEffect() {
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
  // Simulate a "breathing" effect by toggling the red LED on and off slowly
  digitalWrite(LEDR, HIGH);
  delay(1000);  // Adjust delay for desired breathing effect speed
  digitalWrite(LEDR, LOW);
  delay(1000);  // Adjust delay for desired breathing effect speed
}

void exclamationFlasher() {
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
  // Flash the LED in a pattern that mimics the exclamation noise
  for (int i = 0; i < 2; i++) {  // Repeat the sequence 2 times
    digitalWrite(LEDR, HIGH);
    delay(50);
    digitalWrite(LEDR, LOW);
    delay(50);
  }
}
