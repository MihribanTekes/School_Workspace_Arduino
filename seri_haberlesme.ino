String isim;
int yas;
float boy;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   Serial.println("isminizi giriniz:");
   while(Serial.available()==0)
   {
    
   }

   isim = Serial.readString();

   Serial.println("Kac yasindasiniz");
   while(Serial.available()==0)
   {
       
   }

   yas = Serial.parseInt();

   Serial.println("boyunuz?");
   while(Serial.available()==0)
   {
       
   }

   boy = Serial.parseFloat();

   Serial.print("Adiniz:");
   Serial.println(isim);
   Serial.print("Yasiniz:");
   Serial.println(yas);
   Serial.print("Boyunuz:");
   Serial.println(boy);

   
}
