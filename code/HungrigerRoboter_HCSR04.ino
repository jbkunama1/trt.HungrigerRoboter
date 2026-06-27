#include <Servo.h>

const int trigPin  = 7;
const int echoPin  = 6;
const int servoPin = 9;
const int THRESHOLD_CM = 10;
const int MOUTH_CLOSED = 0;
const int MOUTH_OPEN   = 70;

Servo mouth;

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  long distance = duration / 58;
  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  mouth.attach(servoPin);
  mouth.write(MOUTH_CLOSED);
  Serial.begin(9600);
}

void loop() {
  long distance = measureDistance();
  if (distance > 0 && distance < THRESHOLD_CM) {
    mouth.write(MOUTH_OPEN);
    delay(600);
    mouth.write(MOUTH_CLOSED);
    delay(600);
  } else {
    mouth.write(MOUTH_CLOSED);
  }
  delay(100);
}
