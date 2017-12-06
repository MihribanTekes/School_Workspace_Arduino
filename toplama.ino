
  int a;
  int b;
  int toplam;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  if( Serial.available() >0)
  {
    a = Serial.read();
    a=a-48;
  toplam = toplam+a;
  Serial.println(toplam);
    delay(1000);
   
  }
  
  
}
