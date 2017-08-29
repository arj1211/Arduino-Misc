
int led1 = 13;
int led2 = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(10);

  digitalWrite(led1,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
  delay(100);

  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led2,LOW);
  delay(100-10);
  

}
