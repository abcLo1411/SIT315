// C++ code
//
int Motion = 2;
int LED = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Motion, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  
  if(digitalRead(Motion) == HIGH)
  {
    Serial.print("Motion detected, ");
    digitalWrite(LED, HIGH);
    Serial.println("LED turned on");
  }
  else
  {
    Serial.println("Motion not detected");
    digitalWrite(LED, LOW);
  }
  
  delay(1000);

}
