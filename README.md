🔐 Smart RFID Door Lock System
📌 Project Overview
This project implements a Smart Door Lock System using an RFID reader (EM-18), Arduino Mega, a servo motor, and a buzzer. The system unlocks a door when a valid RFID card is detected and sounds an alert for invalid attempts.

✨ Features
✅ Contactless Access using RFID technology.

🔄 Automatic Servo Lock/Unlock Mechanism.

🔊 Buzzer Alert for unauthorized access.

💡 LED Indicators for system status.

🛡️ Enhances security in homes, offices, and labs.

🛠 Components Required
Component	Quantity	Description
Arduino Mega	1	Main controller
EM-18 RFID Reader	1	125 kHz reader module
RFID Card/Tag	2+	Access cards
Servo Motor (SG90)	1	Controls door lock
Buzzer	1	Alarm for invalid access
LED (Red/Green)	2	Status indicators
Jumper Wires	-	For connections
Breadboard	1	Prototyping

📏 Hardware Setup (Size & Placement)
Component	Recommended Size/Placement
RFID Reader (EM-18)	Mount at 1.2m height for convenient scanning. Keep 5cm clearance around it.
Servo Motor	Place near door lock mechanism. Secure with M3 screws.
LED Indicators	Place near RFID reader for visibility. Use 5mm diffused LEDs.
Buzzer	Inside enclosure but with small sound hole (~5mm).
Arduino Mega	Inside a 10cm × 8cm protective case.
Wiring Clearance	Maintain 1cm gap between signal wires and power lines.

⚙️ Working Principle
Card Scan: User taps RFID card near the reader.

Authentication: Arduino checks if card UID matches stored list.

Access Granted:

Green LED blinks

Servo rotates to unlock position

Access Denied:

Red LED blinks

Buzzer sounds for 2 seconds

📷 Project Images
📌 RFID Reader Placement

📌 Internal Wiring Layout

🚀 Future Improvements
📱 Add IoT support for remote monitoring.

🔋 Use battery backup for power failures.

🔑 Store multiple user profiles in EEPROM.

📜 License
This project is licensed under the MIT License – you are free to use and modify it.
