# Arduino-smart-house
# Arduino Smart House Project

## Overview

The Arduino Smart House Project is a home automation system that leverages an Arduino microcontroller, sensors, and actuators to automate lighting, ventilation, and window control. The system also features Bluetooth connectivity for remote operation via a smartphone or other compatible devices.

## Features

- **Lighting Control**: Automatically adjusts house lights based on ambient light levels.
- **Ventilation Management**: Turns on the ventilator when the temperature exceeds a specified threshold.
- **Window Automation**: Opens or closes windows based on temperature and humidity conditions.
- **Bluetooth Remote Control**: Provides remote control over the system with commands for lighting, ventilation, and window operations.

## Components Used

### Hardware

1. **Sensors**:
   - DHT11 (Temperature and Humidity Sensor)
   - Light Sensor (Photoresistor)
2. **Actuators**:
   - LED (Simulates house lighting)
   - Servo Motor (Window control)
   - Relay (Ventilator control)
3. **Communication**:
   - HC-05 Bluetooth Module
4. **Microcontroller**:
   - Arduino Board

### Software

- Arduino IDE for programming and uploading code to the Arduino.

## Circuit Diagram

Include a clear circuit diagram showing connections between the Arduino, sensors, actuators, and Bluetooth module.

## Installation and Usage

1. **Setup Hardware**:
   - Connect all sensors, actuators, and the Bluetooth module as per the circuit diagram.
   - Ensure power supply and connections are secure.

2. **Upload Code**:
   - Open the provided code in the Arduino IDE.
   - Select the correct COM port and Arduino board.
   - Upload the code to the Arduino.

3. **Operation**:
   - Use the sensors to automatically control lights, ventilation, and windows.
   - Use a Bluetooth-compatible application (e.g., Serial Bluetooth Terminal) to send commands to the Arduino.

4. **Bluetooth Commands**:
   - `L`: Toggle lights.
   - `V`: Toggle ventilator.
   - `O`: Open window.
   - `C`: Close window.
   - `T`: Receive current temperature.
   - `H`: Receive current humidity.

## Future Improvements

1. **Scalability**:
   - Add Wi-Fi support for broader connectivity.
   - Integrate additional smart home features like voice assistant compatibility.

2. **Energy Efficiency**:
   - Optimize algorithms for dynamic lighting and heating control.
   - Add solar-powered solutions for a sustainable approach.

3. **Safety Features**:
   - Include gas and smoke sensors for enhanced safety.
   - Integrate motion detection for improved security.

## License

This project is open-source and available for modification and distribution under the MIT License.

## Contributions

Contributions are welcome! Please feel free to submit issues or pull requests for improvements or new features.

