#include <Servo.h>

Servo s1;

void setup() {
  s1.attach(9);
  s1.write(0);
}

void sway(int delayInMillis, int deg)
{
  for (int i=10;i<=170;i+=deg)
  {
    s1.write(i);
    delay(delayInMillis);
  }
  delay(delayInMillis);
  for (int i=170;i>=10;i-=deg)
  {
    s1.write(i);
    delay(delayInMillis);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
sway(500,10);
}
