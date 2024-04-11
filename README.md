## Introduction
This guide is designed to help you seamlessly set up your Arduino Pro Portenta C33, run a basic "Blinky" example, integrate with the Arduino IoT Cloud, and control the onboard RGB LED, push buttons, and display the A0 value on a gauge.

## Materials Required
- Arduino Pro Portenta C33 board
- USB-C cable
- Wi-Fi antenna
- Computer with internet access
- Arduino account

## Step-by-Step Setup

### Arduino IDE Installation
1. Download and install the latest Arduino IDE from the [Arduino Software page](https://www.arduino.cc/en/software).

### Connecting Portenta C33 and Running Blinky Example
1. Connect the Portenta C33 to your computer using the USB-C cable.
2. Open the Arduino IDE, select the Portenta C33 board under `Tools > Board`, and the appropriate COM port under `Tools > Port`.
3. Load the "Blinky" example from `File > Examples > 01.Basics > Blink` and upload it to your board. This step ensures that the IDE installs necessary drivers for the Portenta C33.

### Installing Arduino Cloud Agent
1. Install the Arduino Cloud Agent following the instructions on the [Arduino Create Agent page](https://create.arduino.cc/getting-started/plugin/installation).

### Arduino IoT Cloud Setup
1. Log in to the [Arduino IoT Cloud](https://create.arduino.cc/) and add your Portenta C33 as a new device.
2. Create a new "Thing" and add variables for the RGB LED (type int, permission "Read & Write"), push buttons (type int, permission "Read"), and the A0 value (type int, permission "Read").

### Modifying Sketch for Cloud Integration
Modify the "Blinky" sketch to include the cloud variables for the RGB LED, push buttons, and the A0 value. Here's the modified code segment:

```cpp
#include "thingProperties.h"

// Declare RGB LED color variables at the global scope
int RGB_LED_RED = 0;
int RGB_LED_GREEN = 0;
int RGB_LED_BLUE = 0;
int A0_VALUE = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500); // Wait for Serial Monitor to open

  // Initialize the built-in RGB LED pins as outputs
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // Initialize the analog pin as an input
  pinMode(A0, INPUT);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  // Read the analog voltage from A0
  A0_VALUE = analogRead(A0);

  // Control the RGB LED based on cloud variables
  analogWrite(LEDR, RGB_LED_RED);
  analogWrite(LEDG, RGB_LED_GREEN);
  analogWrite(LEDB, RGB_LED_BLUE);
}

// Functions to handle changes in the cloud variables for controlling the RGB LED
// Since your variables are already bound to the cloud properties, these handlers
// will automatically be called upon changes. Make sure these function names match
// exactly with those declared in the thingProperties.h file.
void onRGB_LED_REDChange() {
  // RGB_LED_RED is automatically updated
}

void onRGB_LED_GREENChange() {
  // RGB_LED_GREEN is automatically updated
}

void onRGB_LED_BLUEChange() {
  // RGB_LED_BLUE is automatically updated
}

void onA0_VALUEChange() {
  // A0_VALUE is automatically updated
}


```

### Dashboard and Mobile App Integration
1. Create a dashboard in the Arduino IoT Cloud and add widgets to control the RGB LED, push buttons, and display the A0 value on a gauge.
2. Download the [Arduino IoT Cloud mobile app](https://www.arduino.cc/en/software) and log in with your Arduino account to control the RGB LED, push buttons, and observe the A0 value in real-time.

### Troubleshooting Tips
- Ensure the Arduino Cloud Agent is running in the background for seamless communication between your device and the cloud.
- If encountering issues with going online or with the dashboard, double-check your network credentials and cloud variable configurations.
- Use the `setDebugMessageLevel()` function to obtain detailed debug information, aiding in troubleshooting connection or cloud sync issues.
