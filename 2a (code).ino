int switchPin = 8;
int ledPin = 13; // Normally we use pin 13 because it has its own internal LED attached to it but we can use an pin//
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;
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
  if (currentButton == LOW && lastButton == HIGH)
  {
   ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(ledPin,ledOn);
/* Initially lastButton is LOW and currentButton is LOW.
We press the button and the currentButton is HIGH and lastButton is LOW
ledOn becomes true and the LED lights up and the last Button becomes HIGH
Once we release the button, currentButton is LOW and lastButton is HIGH.
Since it didnt satisfy the if condition the ledOn doesnt invert and the LED remains lit. Also the currentButton changes to LOW.
Now, lastButton is LOW and the currentButton is LOW, so the same thing happens the debounce function just doesnt give delay as it is not needed
Now when we press the button again, the currentBUtton is HIGH and the lastButton is LOW
Since it satidfies the if condition, ledOn inverts and become false.
Now the LED turns off and the cycle repeats. */
 

  
  
	  