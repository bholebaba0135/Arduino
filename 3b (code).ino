int potPin =A0;
void setup()
{
  pinMode(potPin, INPUT);// Initializing potPin as n input pin
  Serial.begin(9600);// Serial. begin(9600); passes the value 9600 to the speed parameter. This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second. That's 9600 binary ones or zeros per second, and is commonly called a baud rate
}
void loop()
{
  Serial.println(analogRead(potPin));// to get output as ASCII character on monitor
  delay(1000);
}
/*potentiometer is an instrument used to measure the emf by balancing it against the potential difference
produced by a known current through a known varaible resistance.
It acts a voltage divider and by turning the knob we are changing the resistance.
The value on the serial monitor fluctuates from 0 to 1023 depending upon the resistance of the potentiometer.
