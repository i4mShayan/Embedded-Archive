// C++ code
//
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(2, 2);
  Serial.print(distance);
  Serial.println("cm");
  if (distance > 150) {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
  } else {
    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);
  }
  delay(100); // Wait for 100 millisecond(s)
}