# 🤖 Hungriger Roboter – AB2: Tinkercad‑Programmierung

## Ziel

Programmiere den Arduino so, dass der HC‑SR04 den Abstand misst und der Servo den Mund öffnet und schließt.

## Beispiel‑Code

```cpp
#include <Servo.h>

const int trigPin  = 7;
const int echoPin  = 6;
const int servoPin = 9;

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
  mouth.write(0);
  Serial.begin(9600);
}

void loop() {
  long distance = measureDistance();

  if (distance > 0 && distance < 10) {
    mouth.write(70);
    delay(600);
    mouth.write(0);
    delay(600);
  } else {
    mouth.write(0);
  }

  delay(100);
}
```
