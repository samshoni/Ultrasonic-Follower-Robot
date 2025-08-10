// Motor pins
int enableRightMotor = 10;
int rightMotorPin2 = 4;
int rightMotorPin1 = 5;

int enableLeftMotor = 11;
int leftMotorPin2 = 6;
int leftMotorPin1 = 7;

#define MOTOR_SPEED 180

// Ultrasonic pins
#define TRIG_PIN 2
#define ECHO_PIN 3

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 15 && distance < 40) {  // Follow within range
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  else if (distance <= 15 && distance > 0) {  // Too close
    rotateMotor(0, 0);
  }
  else {  // No object
    rotateMotor(0, 0);
  }

  delay(100);
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 20000); // Timeout ~20ms
  if (duration == 0) return -1; // No reading
  return duration * 0.034 / 2;
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}
