int buttonPin =11;
void setup()
{
  pinMode(buttonPin, INPUT);// Initializing buttonPin as n input pin
  Serial.begin(9600);// Serial. begin(9600); passes the value 9600 to the speed parameter. This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second. That's 9600 binary ones or zeros per second, and is commonly called a baud rate
}
void loop()
{
  Serial.println(digitalRead(buttonPin));// to get output as ASCII character on monitor
  delay(1000);
}
/* We use a pull down resistor to make sure that wiggling the wire wont affect the serial output
You would have to keep the button pressed for 1 second to get 1 on the serial monitor*/