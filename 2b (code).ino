int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledLevel=0;
void setup()
{
	pinMode(switchPin, INPUT);// initializing switchPin as an INPUT pin//
	pinMode(ledPin, OUTPUT);// initializing ledPin as an OUTPUT pin//
}
boolean debounce(boolean last)// creating a function debounce to mitigate the bouncing of switch by giving enough delay for it to stabilize and then re-reading the digital signal//
{
  boolean current = digitalRead(switchPin);
  if( last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}
void loop()
{
  currentButton = debounce(lastButton);
  if (currentButton == HIGH && lastButton == LOW)
  {
   ledLevel = ledLevel+51;// I have written it such that the brightness would incress in 5 parts.//
  }
  lastButton = currentButton;
  if (ledLevel>255) ledLevel=0;// When we press the button 6th time, ledLevel would become 306 which being greater than 255 would be returned to 0// 
  analogWrite(ledPin,ledLevel);// analogWrite sets the pin to have an oscillating value which has a pulse length based on the duty cycle. The signal isn't analog at all. It just configures the digitalPin for PWM with a duty cycle(0-255) proportional to argument value//
}


  
  
	  