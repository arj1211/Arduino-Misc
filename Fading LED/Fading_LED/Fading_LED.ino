int led = 10;
int brightness = 0;
int fadeAm = 2;


void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(led, brightness);
  brightness += fadeAm;
  if (brightness <= 0 || brightness >= 15)
    fadeAm = -fadeAm;

  delay(80);

}

