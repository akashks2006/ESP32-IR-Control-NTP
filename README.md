# ESP32 IR Remote Control with WiFi and NTP Time Synchronization
## Description:
This project demonstrates how to use an ESP32 to control an IR-enabled device (such as a TV or air conditioner) based on synchronized time from an NTP server. The ESP32 connects to a WiFi network, fetches the current time, and sends an IR command at specified times (e.g., 10:00 PM or 6:00 AM).

## Features:
- Connects to WiFi to access the internet.
- Synchronizes time using an NTP server.
- Sends IR commands at specific times using the IRremote library.

## Required Hardware:
- ESP32 board
- IR LED
- Resistor (for the IR LED, if necessary)
- WiFi network

## Configuration:
1. Replace WIFI_SSID and WIFI_PASSWORD with your network credentials.
2.  Replace Enter IR HEX Command with the IR HEX command of your device.

## Required Libraries:
- IRremote
- WiFi
- NTPClient

## How to Use:
1. Install the required libraries in your Arduino IDE.
2. Update the placeholders in the code with your WiFi credentials and IR command.
3. Upload the code to your ESP32 using the Arduino IDE.
4. Monitor the serial output to verify time synchronization and IR command transmission.
