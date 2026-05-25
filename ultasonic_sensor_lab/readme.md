# Ultra-Sonic Sensor Lab

## Overview
This project outlines the code, data and methods that were used to test the parameters of the HC SR04 Ultra-sonic sensor for a group project for the course MCE 102.

## Tech Stack & Hardware
*   **Language:**  Python, C++
*   **Libraries:** liquidcrystal, pandas, numpy
*   **Hardware:** Arduino Uno, HC SR04, 1602 LCD, Breadboard, Jumper wires.

## System Logic
Briefly explain the algorithm or mechanism. How does data flow? How do the physical parts move?
* The HC SR04 ultra-sonic sensor is the hardware component that is being tested.
* An arduino circuit was built with the sensor as the foundation. The LCD displays data captured by the sensor and the breadboard serves as the base for the connections.
* The arduino code controls the hardware.
* The completed circuit was used to gather data that was then compiled in a spreadsheet.
* The compiled data was analysed using the python script and the specific parameters where rated based on it. 
* Detailed information on the results and the methodology can be found in the report


## Setup / How to Run (Optional)
Provide the exact steps needed to compile or test the project.
1. Open the `.ino` file in the Arduino IDE.
2. Select the correct COM port and board type.
3. Upload the script to the microcontroller.