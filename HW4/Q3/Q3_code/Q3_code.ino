#define LDR A0
const int LED = 9;
float value = 0;
void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED , OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

float fMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop()
{
  value = analogRead(LDR);

  value = fMap(float(value), 0, 1023, 0, 255);
  Serial.println(value);
  
  analogWrite(LED, value);
  // if (value < 1.2){
  //   analogWrite(LED, value);
  // }
  // else{
  //   analogWrite(LED, value);
  // }
  delay(100);
}
