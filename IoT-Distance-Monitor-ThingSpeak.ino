#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

// Replace with your actual Wi-Fi credentials
const char* ssid = "MURUVELLIL";
const char* password = "shoni6052m";

// Replace with your ThingSpeak channel details
unsigned long myChannelNumber = 3030876; // <-- Your Channel ID
const char * myWriteAPIKey = "C20R0X5C97JB4Q9W"; // <-- Your Write API Key

WiFiClient client;

#define trigPin D5
#define echoPin D6

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Send the data to ThingSpeak (Field 1)
  ThingSpeak.setField(1, distance);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (x == 200) {
    Serial.println("Data sent to ThingSpeak successfully.");
  } else {
    Serial.print("Error sending data: ");
    Serial.println(x);
  }

  delay(20000); // ThingSpeak requires at least 15 sec delay between updates
}
