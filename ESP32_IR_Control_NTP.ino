#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <IRremote.h>

// Replace with your network credentials
const char* ssid     = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000); // UTC time, update every 60 seconds

// Define IR send pin and command
const int irPin = 2;
IRsend irsend(irPin);
unsigned long irCommand = "Enter IR HEX Command"; // Replace with Your IR HEX Command

void setup(){
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTPClient
  timeClient.begin();

  // Initialize IR send
  irsend.begin();
}

void loop() {
  // Update time
  timeClient.update();

  // Get formatted time
  String formattedTime = timeClient.getFormattedTime();
  Serial.println(formattedTime);

  // Get hours and minutes
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();

  // Check if it's 10:00 PM or 6:00 AM
  if ((currentHour == 22 && currentMinute == 0) || (currentHour == 6 && currentMinute == 0)) {
    // Send IR command
    irsend.sendNEC(irCommand, 32);
    Serial.println("Sent IR command to TV");

    // Wait for a minute
    delay(60000);
  }

  // Delay before next loop iteration
  delay(1000);
}
