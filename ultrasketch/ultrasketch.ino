// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int led1 = 7 , led2 = 6, led3 = 5;
int dist;

int step1 = 45, step2 = 30, step3 = 15;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(300);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping_median(5);
  // unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  dist = uS / US_ROUNDTRIP_CM;
  Serial.print("Ping: ");
  Serial.print(dist); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  if (dist < step3)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (dist >= step3 && dist < step2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if (dist >= step2 && dist < step1)
  {
    digitalWrite(led1, HIGH);
  }

  if (dist < 1 || dist > step1) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

}
