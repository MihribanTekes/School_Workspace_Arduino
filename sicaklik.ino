
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12,11,5,4,3,2);
int lm35analogPin = 0;
float sicaklik;
float analogDeger;
 
 
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop(){
  
  analogDeger = analogRead(lm35analogPin);
  analogDeger = (analogDeger / 1024.0)*5000;
  
  sicaklik = analogDeger / 10.0;
  
  lcd.setCursor(0,0);
  lcd.print("Sicaklik: ");
  lcd.setCursor(0,1);
  lcd.print(sicaklik);
  lcd.setCursor(6,1);
  lcd.print(" C derece");
  
  Serial.print("Sıcaklık: ");
  Serial.print(sicaklik);
  Serial.println(" C derece");
  delay(2000);
  
}
