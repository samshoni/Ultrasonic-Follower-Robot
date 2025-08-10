🤖 Ultrasonic Follower Robot
A smart robot that follows you… but keeps a safe distance!
Built using Arduino and ultrasonic sensing, this bot mimics "personal space" — just like a polite friend.



🚀 Features
Human Following Mode — Uses ultrasonic sensor to detect and follow objects in front of it.

Safe Distance Control — Automatically maintains a gap to avoid collisions.

Simple & Affordable — Built with basic, easily available components.

🛠 Components Used
Component	Quantity	Description
Arduino Mega	1	Brain of the robot
HC-SR04 Ultrasonic Sensor	1	Detects distance to target
Motor Driver (L298N)	1	Controls motors
DC Motors + Wheels	2	For movement
Chassis	1	Robot frame
Jumper Wires	—	Connections

⚙ Working Principle
Ultrasonic Sensor measures the distance to the object in front.

Arduino processes the distance and sends signals to the motor driver.

If the target is too far → robot moves forward.

If the target is too close → robot stops or moves back.

📂 Code Structure
bash
Copy code
Ultrasonic-Follower-Robot/
│
├── Ultrasonic_Follower.ino   # Arduino code
├── README.md                 # Project documentation
└── images/                   # Pictures of the robot
🎯 How to Run
Connect all components as per the wiring diagram.

Upload the Ultrasonic_Follower.ino to Arduino Mega.

Power up the robot and place an object in front — watch it follow!

💡 Future Improvements
Add obstacle avoidance for sideways movement.

Integrate with Bluetooth for remote control.

Make it follow specific people using Computer Vision.

✨ Author
Sam Shoni
