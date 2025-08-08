# IoT Distance Monitor with ThingSpeak Integration

![Setup Photo](photos/setup.jpg)  
*Project hardware setup*

This project uses an **ultrasonic sensor** with a **NodeMCU (ESP8266)** to measure distances and send the data to the **ThingSpeak** cloud platform for real-time monitoring.

---

## 📌 Features
- Real-time distance measurement using **HC-SR04 Ultrasonic Sensor**.
- Wi-Fi-enabled data transmission via **NodeMCU (ESP8266)**.
- Automatic data logging on **ThingSpeak**.
- Can be extended to send alerts via SMS, WhatsApp, or email if distance is below a threshold.

---

## 🛠 Hardware Used
- **NodeMCU ESP8266**
- **HC-SR04 Ultrasonic Sensor**
- Jumper Wires
- Breadboard

---

## 📡 ThingSpeak Setup
1. Create a [ThingSpeak](https://thingspeak.com/) account.
2. Create a new channel with a field named **Distance (cm)**.
3. Copy your **Write API Key**.
4. Paste the key into the Arduino code in place of `"YOUR_API_KEY"`.

---

## 🔌 Circuit Diagram
![Circuit Diagram](photos/circuit.jpg)

| HC-SR04 Pin | NodeMCU Pin |
|-------------|-------------|
| VCC         | 3.3V        |
| GND         | GND         |
| TRIG        | D1 (GPIO5)  |
| ECHO        | D2 (GPIO4)  |

> ⚠️ Powering HC-SR04 with 3.3V reduces range. Works well for short distances.

---

## 📜 Arduino Code
```cpp
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// ThingSpeak channel details
unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_API_KEY";

// Ultrasonic pins
#define TRIG_PIN D1
#define ECHO_PIN D2

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  int statusCode = ThingSpeak.writeField(channelID, 1, distance, writeAPIKey);
  if (statusCode == 200) {
    Serial.println("Data sent successfully");
  } else {
    Serial.print("Error sending data: ");
    Serial.println(statusCode);
  }

  delay(20000); // ThingSpeak update limit
}
📊 Output Example
Serial Monitor:
Distance: 44 cm
Data sent successfully


ThingSpeak Dashboard:
Real-time distance chart


🚀 Future Improvements
SMS/WhatsApp alerts when distance < threshold.

OLED display for local readings.

Buzzer alerts.

👨‍💻 Author
Sam Shoni Zacharia

GitHub: samshoni

LinkedIn: Sam Shoni Zacharia