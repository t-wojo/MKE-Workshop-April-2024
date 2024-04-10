# Distance-Responsive LED with Nicla Vision and VL53L1X

## Project Overview

This project demonstrates creating a distance-responsive LED effect using the Nicla Vision board and VL53L1X Time-of-Flight (ToF) sensor. An RGB LED changes its color and blink rate based on the measured distance, offering a dynamic way to visualize sensor readings.

![niclafront](https://docs.arduino.cc/static/868c8ff65997388c7d8ba0386108ade0/d9ed5/arch-top.png)

![niclaback](https://docs.arduino.cc/static/79f6c8e6e9f4021a4d12b223af728dca/d9ed5/arch-bot.png)

### Features

- Utilizes the VL53L1X sensor for accurate distance measurements.
- Dynamic LED color and blink rate changes based on proximity.
- Leverages Nicla Vision's powerful STM32H747AII6 Dual Arm® Cortex®-M7/M4 processor.
- Designed for educational purposes, perfect for workshops and training sessions.

## Getting Started

### Prerequisites

- Arduino Nicla Vision Board
- VL53L1X ToF sensor
- Micro USB cable
- OpenMV IDE, Arduino IDE 1.8.10+/2.0+, or Arduino Web Editor

### Hardware and Software Setup

1. Ensure your Nicla Vision firmware is up to date. Follow the instructions in the Nicla Vision User Manual for firmware updates.
2. Install required libraries (`VL53L1X`) via the Library Manager in your chosen IDE.

## Installation and First Use

1. Clone this repository or download the source code.
2. Open the Arduino sketch (`DistanceResponsiveLED.ino`) in the Arduino IDE or OpenMV IDE.
3. Connect the Nicla Vision board to your computer via a Micro USB cable.
4. Select the correct board and port in your IDE.
5. Upload the sketch to the Nicla Vision board.

## Usage

https://docs.arduino.cc/tutorials/nicla-vision/user-manual/
Power on the Nicla Vision board after uploading the sketch. Move an object closer and further away from the VL53L1X sensor. Observe how the RGB LED changes its color and blink rate in response to the distance.

## Advanced Features

- **Wi-Fi® Connectivity**: Leverage the onboard Wi-Fi® module to send collected data to the Arduino® Cloud or third-party services.
- **Machine Learning**: Utilize the onboard camera and sensors for asset tracking, object recognition, and predictive maintenance using the Machine Learning Tools add-on integrated into the Arduino Cloud.
- **Bluetooth® Low Energy**: Explore Bluetooth® Low Energy functionalities for wireless communication.

## Board Architecture Overview

The Nicla Vision combines a powerful STM32H747 Dual Arm® Cortex® processor with a 2MP color camera, smart 6-axis motion sensor, integrated microphone, and distance sensor, packed into a tiny footprint. This robust architecture supports a wide range of applications from simple sensor nodes to advanced machine learning projects.

## Pinout and Sensor Details

- **Camera**: GC2145 Color rolling shutter image sensor.
- **Microcontroller**: Dual-core STM32H747, including an Arm® Cortex®-M7 running at 480 MHz and an Arm® Cortex®-M4 running at 240 MHz.
- **Onboard Sensors**: Advanced IMU (LSM6DSOX), Time-of-Flight distance sensor (VL53L1CBV0FY), Digital Microphone (MP34DT05).
- **Connectivity**: Murata® LBEE5KL1DX-883 module for Wi-Fi® and Bluetooth®.

## Contributing

Contributions are welcome! Please refer to the `CONTRIBUTING.md` file for more information on how you can contribute to this project.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgments

- VL53L1X library for providing an easy interface to the sensor.
- The Arduino and Nicla Vision community for support and resources.
- Christopher Mendez and the authors of the Nicla Vision User Manual for detailed documentation on the hardware and software features.

## Support

For additional support, visit the [Nicla Vision Help Center](https://support.arduino.cc/hc/en-us), join discussions in the [Arduino Forum](https://forum.arduino.cc/index.php?board=125.0), or contact [Arduino Support](https://www.arduino.cc/en/contact-us).
