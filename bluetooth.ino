#include <SoftwareSerial.h>  //  Seri Haberleşme kütüphanesini ekledik
SoftwareSerial BTSerial(12, 11); // RX, TX  // BT için ayrıca bir Seri Haberleşme pini tanımladık
void setup() {
Serial.begin(9600);
Serial.println("Enter AT commands:");
BTSerial.begin(9600);  //BT Seri haberleşmesini 9600 ile başlattık*
}
void loop()
{
if (BTSerial.available())
Serial.write(BTSerial.read());
if (Serial.available())
BTSerial.write(Serial.read());
}
