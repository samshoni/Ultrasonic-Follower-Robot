Line Following Robot (Arduino + IR Sensors)
📌 Overview
This project is a 2-IR sensor line following robot built using Arduino.
It follows a black line on a white surface by continuously adjusting motor movement based on infrared sensor readings.

The project is part of my learning journey in robotics and embedded systems.

🛠 Components Used
Arduino Uno / Nano (or compatible microcontroller)

2 × IR line tracking sensors (left & right)

2 × DC geared motors

Motor driver module (L298N / L293D)

Robot chassis (with caster wheel)

Battery pack (4xAA or Li-ion)

Jumper wires & connectors

⚙ Circuit Connections
Component	Arduino Pin
Left IR Sensor	D9
Right IR Sensor	D8
Left Motor EN	D11
Left Motor IN1	D7
Left Motor IN2	D6
Right Motor EN	D10
Right Motor IN1	D5
Right Motor IN2	D4

(You can modify pin numbers in the code as needed.)

📜 How It Works
The left and right IR sensors detect the color of the surface.

Black line → Sensor outputs LOW
White surface → Sensor outputs HIGH

Based on sensor readings:

Both LOW → Move forward

Left LOW, Right HIGH → Turn left

Right LOW, Left HIGH → Turn right

Both HIGH → Stop