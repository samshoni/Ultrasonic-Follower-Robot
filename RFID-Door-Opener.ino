#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Pins
#define SS_PIN 53    // SDA
#define RST_PIN 5
#define SERVO_PIN 7
#define LED_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo doorServo;

// Authorized UID: 6D 6B B8 21
byte allowedUID[4] = {0x6D, 0x6B, 0xB8, 0x21};

const int openAngle = 90;
const int closedAngle = 0;
const unsigned long openMillis = 3000; // keep door open for 3s

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  doorServo.attach(SERVO_PIN);
  doorServo.write(closedAngle);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("RFID Door Lock ready. Place your card near the reader.");
}

void loop() {
  // Wait for a new card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Print scanned UID
  Serial.print("Scanned UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) Serial.print(" 0");
    else Serial.print(" ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Check authorization
  if (checkUID()) {
    Serial.println("Access Granted ✅");
    accessGranted();
  } else {
    Serial.println("Access Denied ❌");
    accessDenied();
  }

  mfrc522.PICC_HaltA(); // stop reading this card
  delay(300);           // small debounce before next read
}

// Actions
void accessGranted() {
  digitalWrite(LED_PIN, HIGH);      // steady LED
  doorServo.write(openAngle);       // open
  unsigned long start = millis();
  while (millis() - start < openMillis) {
    // keep open; avoid re-trigger by waiting while card present
    if (!mfrc522.PICC_IsNewCardPresent()) { /* continue */ }
    delay(10);
  }
  doorServo.write(closedAngle);     // close
  digitalWrite(LED_PIN, LOW);
}

void accessDenied() {
  // blink LED 3 times quickly
  for (int i = 0; i < 3; ++i) {
    digitalWrite(LED_PIN, HIGH);
    delay(180);
    digitalWrite(LED_PIN, LOW);
    delay(150);
  }
}

// compare first 4 bytes (typical MIFARE UID length)
bool checkUID() {
  if (mfrc522.uid.size < 4) return false;
  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != allowedUID[i]) return false;
  }
  return true;
}
