
int redPin = 4;
int greenPin = 3;
int sensorPin = A3;
 
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
 
void loop()
{
 int blinkRate = analogRead(sensorPin);
 Serial.print("Deger= ");
 Serial.println(blinkRate);
 
 if(blinkRate < 100)
 {
   digitalWrite(greenPin, LOW);
   digitalWrite(redPin, HIGH);
 }
 else
 {
   digitalWrite(greenPin, HIGH);
   digitalWrite(redPin, LOW);
 }
}
