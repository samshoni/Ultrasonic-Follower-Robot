Smart Door Lock System (RFID + Servo + LED) using Arduino Mega
📌 Project Overview
This project is a smart door locking system that uses an RFID reader to authenticate users.
When an authorized RFID card is scanned, the servo motor rotates to unlock the door and the LED indicates the status.
If an unauthorized card is scanned, the LED shows an error signal, and the door remains locked.

This system can be used for homes, offices, and restricted areas where secure access is required.

🛠️ Components Used
Arduino Mega 2560

EM-18 RFID Reader Module

125kHz RFID Card/Tag (2 units)

SG90 Servo Motor

LED (Any color, used for status indication)

Jumper Wires

Breadboard

5V Power Supply

⚙️ Features
✅ RFID-based authentication
✅ Servo-controlled door lock
✅ LED status indication
✅ Easy to customize authorized card IDs
✅ Low-cost and beginner-friendly




💻 How It Works
The RFID reader scans the RFID card/tag.

The Arduino checks the card’s unique ID against stored IDs.

If the ID matches:

Servo rotates to unlock position.

LED turns green (or ON).

After a short delay, the servo returns to the locked position.

If the ID does not match:

LED blinks or stays red.

Door remains locked.

🖥️ Arduino Code
The Arduino code includes:

RFID reading logic using SoftwareSerial.

Servo motor control.

LED status control.

Authorized card ID storage.

(Include the code in your code folder or inline in GitHub.)

📷 Project Images
(Add your real project photos here)
Example:


Upload the Arduino code to the Mega 2560 board.

Open the Serial Monitor to check RFID card IDs.

Replace the IDs in the code with your authorized card IDs.

Scan the RFID card to unlock the door.

📄 License
This project is licensed under the MIT License — feel free to use and modify.