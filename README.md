🛡️ Smart Door Lock System (RFID + Servo Motor + Arduino Mega)
📌 1. Project Overview
A Smart Door Lock System that uses RFID technology to enhance security.
When an authorized RFID card/tag is scanned, the servo motor unlocks the door for a short duration, then locks it again automatically.
This system is simple, low-cost, and beginner-friendly — yet highly effective for home or office security.

🎯 2. Key Features
🔐 Secure Access – Only registered RFID cards can unlock the system.

⚡ Fast Response – Instant verification and unlocking.

🛠️ Easy Setup – Built with Arduino Mega and readily available components.

📢 Buzzer Feedback – Alerts for successful/failed scans.

🔄 Auto Lock – Door locks automatically after a short delay.

🗂️ 3. Components Used
Component	Quantity	Description
Arduino Mega	1	Main microcontroller board
EM-18 RFID Reader	1	Reads RFID card/tag
RFID Cards/Tags	2	Pre-registered for access
Servo Motor (SG90)	1	Controls door locking mechanism
Buzzer	1	Gives audio feedback
Breadboard & Jumper Wires	-	For easy connections

🖼️ 4. Working Principle
🪪 Scan Card – RFID reader detects the card/tag ID.

🧠 Verification – Arduino checks if ID matches the stored authorized IDs.

✅ Access Granted – Servo rotates to unlock position, buzzer beeps once.

⏳ Auto Lock – After delay, servo returns to lock position.

❌ Access Denied – Buzzer gives error tone if ID is not recognized.

🏗️ 5. Hardware Setup
📍 Placement Recommendations:

RFID reader near the door for easy scanning.

Servo connected to the locking latch.

Arduino inside a safe enclosure for protection.

Buzzer placed externally for clear sound alerts.

🔮 6. Future Improvements
📲 Integrate with a mobile app for remote unlocking.

🛜 Add IoT connectivity to log entry history online.

🔋 Include battery backup for uninterrupted operation.

🎥 Add a camera for face verification alongside RFID.

📸 7. Project Photos
(Add your project build photos here)

👨‍💻 8. Author
Sam Shoni 
📧 Email: samshoni10@gmail.com
🔗 GitHub: samshoni
🔗 LinkedIn: Sam Shoni
