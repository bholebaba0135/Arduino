//Code for making the LED blink//
void setup()
{
  pinMode(12, OUTPUT);// To initialize pin 12 as the OUTPUT pin//
}

void loop()
{
  digitalWrite(12, HIGH);// HIGH mean on//
  delay(1000); //In the code, time is taken in milliseconds.//
  digitalWrite(12, LOW);// LOW means off//
  delay(1000); 
}