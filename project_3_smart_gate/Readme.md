# Smart Gate Controller Prototype (IR-Activated)

## Overview
This project is a hardware prototype simulating an automated, secure gate mechanism. It uses an Arduino microcontroller to decode infrared (IR) signals from a remote control and actuate a servo motor to physically open or close the gate. 

## Hardware Architecture
* **Microcontroller:** Arduino Uno
* **Actuator:** Micro Servo Motor (SG90)
* **Sensor:** IR Receiver Module (e.g., TSOP38238)
* **Input:** Standard IR Remote Control

## System Logic
1. **Signal Reception:** The IR receiver constantly listens for incoming infrared signals.
2. **Decoding:** When a button is pressed on the remote, the Arduino decodes the specific hexadecimal signal.
3. **Actuation:** 
   * If the `OPEN` hex code is received, the servo sweeps to 90 degrees.
   * If the `CLOSE` hex code is received, the servo returns to 0 degrees.
   * Invalid codes are ignored, preventing unauthorized actuation.

## Future Improvements
* Integrate an ultrasonic sensor to prevent the gate from closing if an object is detected in the path.
* Upgrade to an ESP32 to allow for Wi-Fi integration and smartphone control.

## Mechatronics Focus
This project demonstrates the core loop of mechatronics: integrating a physical mechanism (servo/gate), electronic sensors (IR receiver), and control logic (C++ firmware) into a single functional system.