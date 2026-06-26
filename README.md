# Suraksha Glove: Gesture-Based Emergency Communication System

## Overview

Suraksha Glove is a wearable assistive communication prototype designed to enable silent emergency signaling through predefined hand gestures.

The system detects finger movements using flex sensors, processes gestures using an Arduino-based embedded system, and transmits interpreted messages wirelessly through a Bluetooth module.

## Features

* Wearable glove-based gesture detection
* Flex sensor interfacing
* Arduino-based processing
* Bluetooth wireless communication
* LCD-based gesture display
* Emergency gesture recognition

## Hardware Components

* Arduino UNO
* Flex Sensors (5)
* MPU6050 Accelerometer/Gyroscope
* HC-05 Bluetooth Module
* 16x2 LCD Display
* ESD Glove
* Resistors and jumper wires

## Working Principle

Flex sensors detect finger bending patterns. The Arduino reads sensor values, classifies predefined gestures, displays the output on LCD, and sends the message through Bluetooth to a connected device.

## Recognized Gestures

* HELP
* YES
* NO
* HELLO
* THANK YOU

## Technology Stack

* Embedded C/C++
* Arduino IDE
* Sensor Interfacing
* Bluetooth Communication
* Embedded Systems

## Future Enhancements

* Dedicated mobile application
* Secure signal interpretation
* GPS-based emergency tracking
* AI-based gesture recognition
* Improved wearable design

