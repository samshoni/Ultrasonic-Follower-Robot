<<<<<<< HEAD
# 🔐 RFID Smart Door Lock System

A secure and efficient smart door lock system powered by **Arduino Mega**, **RFID technology**, and a **servo motor**.  
This project scans RFID cards/tags to verify authorized access, unlocking the door for valid users and triggering an alert for unauthorized ones.

---

## 📸 Project Preview
![RFID System](photos/system_image.jpg)

---

## 📋 Features
- ✅ **RFID Authentication** – Only authorized cards/tags can unlock the door.
- 🔄 **Automatic Lock/Unlock** using a servo motor.
- 🚨 **Buzzer Alert** for unauthorized access attempts.
- 💡 **LED Indicators** for status feedback:
  - Green = Access Granted
  - Red = Access Denied
- 🛠 **Customizable** for adding/removing authorized cards.

---

## 🛠 Components Used
| Component | Quantity |
|-----------|----------|
| Arduino Mega | 1 |
| RFID Reader (EM-18) | 1 |
| RFID Cards/Tags | 2 |
| Servo Motor (SG90) | 1 |
| Buzzer | 1 |
| LEDs (Red & Green) | 2 |
| Breadboard & Jumper Wires | As required |

---

## ⚙️ How It Works
1. The RFID reader scans the card/tag.
2. The Arduino compares the scanned ID with pre-stored IDs.
3. If the ID matches:
   - Servo unlocks the door.
   - Green LED lights up.
4. If the ID does not match:
   - Buzzer sounds.
   - Red LED lights up.
5. The servo automatically locks after a short delay.

---

---

## 📐 Wiring Diagram
![Wiring Diagram](photos/wiring_diagram.jpg)

**Connections Table:**

| RFID Reader Pin | Arduino Mega Pin |
|-----------------|------------------|
| TX              | Pin 10           |
| VCC             | 5V               |
| GND             | GND              |

| Servo Motor Pin | Arduino Mega Pin |
|-----------------|------------------|
| Signal          | Pin 9            |
| VCC             | 5V               |
| GND             | GND              |

| LED Color | Arduino Mega Pin |
|-----------|------------------|
| Green     | Pin 6            |
| Red       | Pin 7            |

| Buzzer Pin | Arduino Mega Pin |
|------------|------------------|
| Signal     | Pin 5            |

---

## 🚀 Setup & Usage
1. Assemble the components according to the wiring diagram.
2. Upload the code to your Arduino Mega.
3. Power up the system.
4. Scan an RFID card/tag:
   - If authorized → Door unlocks for a few seconds.
   - If unauthorized → Alert is triggered.

---

## 🔮 Future Improvements
- Integrate **IoT** for remote door monitoring.
- Add a **keypad** for PIN-based entry.
- Store authorized IDs in **EEPROM** for persistence.

---

## 📜 License
This project is released under the **MIT License** – you are free to use and modify it.

---

## ✨ Author
**Sam Shoni Zacharia**  
📧 Email: samshoni10@gmail.com  
🔗 GitHub: [samshoni](https://github.com/samshoni)  
🔗 LinkedIn: [Sam Shoni](https://www.linkedin.com/in/sam-shoni-7b2b94301)
=======
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
>>>>>>> 66ace225205490e56c3077217f5aefc6899088e1
