#define LDR A0
const int LED = 13;
float value = 0;
void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED , OUTPUT );
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}
void loop()
{
  value = analogRead(LDR);
  value = (3.3 * value) / 1023;
  Serial.println(value);
  if (value < 1.2){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(500);
}
