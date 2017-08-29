
int pb1 = 8;
int pb2 = 9;
int led1 = 5;
int led2 = 6;

int buttonState1, buttonState2, led1state, led2state;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pb1, INPUT);
  pinMode(pb2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState1 = digitalRead(pb1);
  buttonState2 = digitalRead(pb2);
  led1state = digitalRead(led1);
  led2state = digitalRead(led2);

  if (buttonState2 == LOW)
    digitalWrite(led2, !led2state);

  if (buttonState1 == LOW)
    digitalWrite(led1, !led1state);



  if (buttonState1 == LOW && buttonState2 == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  //digitalWrite(led_debug, HIGH);

}//end
