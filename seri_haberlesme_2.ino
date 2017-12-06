void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)
  {
     Serial.print("bagli degil");
    }
 
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.available(); //port üstünde veri kontrolu veri varsa fonk. degeri 0 dan buyuk
  
  //byte a = Serial.read();
  
  if( Serial.available() > 0)
  { char gelen = Serial.read();
    char* tut = gelen;
    char x[gelen.length] = gelen;

   int i;
   while(tut != NULL)
   {
    int al = tut.toInt();
    Serial.println(al);
    tut++;
   }

   for(i=0; i<gelen.length; i++)
   {
    int d = x[i].toInt();
    Serial.println(d);
   }
    
      
    
    //Serial.print(gelen);
    //Serial.println("merhaba");
    
    }
  //Serial.println("Merhaba");
  delay(1000);

}
