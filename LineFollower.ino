#define IR_SENSOR_RIGHT 8
#define IR_SENSOR_LEFT 9
#define MOTOR_SPEED 180

// Right motor pins
int enableRightMotor = 10;
int rightMotorPin2 = 4;
int rightMotorPin1 = 5;

// Left motor pins
int enableLeftMotor = 11;
int leftMotorPin2 = 6;
int leftMotorPin1 = 7;

void setup() {
  // Set PWM frequency for motor control (approx 7812.5 Hz)
  TCCR0B = TCCR0B & B11111000 | B00000010;

  // Set motor pins as output
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // Set IR sensor pins as input
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  rotateMotor(0, 0);  // Initially stop motors
}

void loop() {
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    // Both sensors on black line - move forward
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    // Right sensor off line, left sensor on line - turn left
    rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    // Left sensor off line, right sensor on line - turn right
    rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
  }
  else {
    // Both sensors off line - stop
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Control right motor direction and speed
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  }
  else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
  else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Control left motor direction and speed
  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  }
  else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }
  else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // Set motor speed using PWM (analogWrite)
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}
