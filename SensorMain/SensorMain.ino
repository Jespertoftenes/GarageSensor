int closedLED = A4; // define the LED pin
int openLED = A5;
int digitalPin = 3; // KY-025 digital interface
int analogPin = A0; // KY-025 analog interface
int digitalVal; // digital readings
int analogVal; //analog readings

void setup()
{
  pinMode(closedLED, OUTPUT);
  pinMode(openLED, OUTPUT);
  pinMode(digitalPin, INPUT);
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin); 
  if(digitalVal == HIGH) // if magnetic field is detected
  {
    digitalWrite(LED_BUILTIN, HIGH); // turn ON Arduino's LED
    digitalWrite(closedLED, HIGH);
    digitalWrite(openLED, LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW); // turn OFF Arduino's LED
    digitalWrite(closedLED, LOW);
    digitalWrite(openLED, HIGH);
  }

  // Read the analog interface
  analogVal = analogRead(analogPin); 
  Serial.println(analogVal); // print analog value to serial

  delay(100);
}