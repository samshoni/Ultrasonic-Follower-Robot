Ultrasonic Follower Robot
This project is an Arduino-based robot that uses an ultrasonic sensor to detect and follow an object in front of it. The robot moves forward when the object is within range, stops if it’s too close, and can also be extended to take turns.

📌 Features
Follows an object in front using distance measurement.

Stops automatically if the object is too close.

Uses a DC motor driver to control motor movement.

Adjustable detection range using code.

🛠 Components Used
Arduino Mega

L298N Motor Driver Module

Ultrasonic Sensor (HC-SR04)

2 DC Motors + Wheels

Chassis Frame

Jumper Wires

Battery Pack

⚡ Circuit Connections
Motor Driver to Arduino:

L298N Pin	Arduino Pin
IN1	7
IN2	6
IN3	5
IN4	4
ENA	10
ENB	11

Ultrasonic Sensor to Arduino:

HC-SR04 Pin	Arduino Pin
VCC	5V
GND	GND
Trig	2
Echo	3

📜 How It Works
The ultrasonic sensor sends out sound waves.

When the waves hit an object, they bounce back.

The Arduino measures the time taken for the echo to return and calculates the distance.

If the object is within the set range, the motors move forward.

If the object is too close, the motors stop.