
int latchPin = 2; //pin 12 on shiftreg
int dataPin = 3; //pin 14 on shift reg
int clockPin = 4; //pin 11 on shift reg

int dotPin=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(dotPin,OUTPUT);
}

// shiftOut(dataPin, clockPin, MSBFIRST, 63);

void zero(int timeInMillis = 1000)
{
  // 0
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 63);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void one(int timeInMillis = 1000)
{
  // 1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 6);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void two(int timeInMillis = 1000)
{
  // 2
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 91);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void three(int timeInMillis = 1000)
{
  // 3
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 79);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void four(int timeInMillis = 1000)
{
  // 4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 102);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void five(int timeInMillis = 1000)
{
  // 5
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 109);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void six(int timeInMillis = 1000)
{
  // 6
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 125);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void seven(int timeInMillis = 1000)
{
  // 7
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 7);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void eight(int timeInMillis = 1000)
{
  // 8
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 127);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}
void nine(int timeInMillis = 1000)
{
  // 9
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 111);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}

void dot(int timeInMillis=500)
{
  digitalWrite(dotPin, HIGH);
  delay(timeInMillis);
  digitalWrite(dotPin,LOW);
  delay(timeInMillis);
}

void clearOut(int timeInMillis = 250)
{
  // --
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  delay(timeInMillis);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  nine();
  eight();
  seven();
  six();
  five();
  four();
  three();
  two();
  one();
  zero();
  clearOut();
  dot();
  dot();
}
