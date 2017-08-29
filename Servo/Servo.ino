#include <Servo.h>

Servo s1;

void setup() {
  s1.attach(9);
}
void loop() {
  delay(1000);
  s1.write(30);
  delay(1000);
  s1.write(150);
}
