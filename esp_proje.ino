    #include <dht.h>

    #include <SoftwareSerial.h>
     
    #define DEBUG true
    #define dht_dpin 4 // dht sensörünün bağlı olduğu pin
    SoftwareSerial esp8266(12,11); //12 TX, 11 RX
    int status=0;
    int nem=0;
    int isi=0;
    int lm35analogPin = 0; //lm35 sensörünün bağlı olduğu pin
    float sicaklik;
    float analogDeger;
    
 
    dht DHT; // dht kütüphanesindeki fonksiyonları kullanabilmek için nesne ürettik
    
    
    void setup()
    {
      Serial.begin(115200);
      esp8266.begin(115200); // your esp's baud rate might be different
      
     
      
      sendData("AT+RST\r\n",2000,DEBUG); // reset module
      sendData("AT+CWMODE=1\r\n",1000,DEBUG); // configure 
      sendData("AT+CWJAP=\"AndroidAP\",\"ltdc7198\"\r\n",5000,DEBUG);
      //sendData("AT+CWJAP=\"NetMASTER Uydunet-B768\",\"a6d69d55\"\r\n",5000,DEBUG);
      delay(3000);      
      sendData("AT+CIFSR\r\n",3000,DEBUG); 
      sendData("AT+CIPMUX=1\r\n",1000,DEBUG); 
      sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG);
      
      
    }
     
    void loop()
    {
      DHT.read11(dht_dpin);
     /* nem=DHT.humidity;
      isi=DHT.temperature;
    
        Serial.println(nem);
        Serial.println(isi); */
      
      analogDeger = analogRead(lm35analogPin);
      analogDeger = (analogDeger / 1024.0)*5000;
      sicaklik = analogDeger / 10.0;
      //Serial.println(sicaklik);
      if(esp8266.available())
      {
        
        if(esp8266.find("+IPD,"))
        {
          
         delay(1000);
     
         int connectionId = esp8266.read()-48; 
  
         String webpage = "<h1>Web Termometresi</h1><br><h1>Nem: ";
         webpage.concat(DHT.humidity);
         //webpage += nem;
         //webpage.concat(nem);
         webpage+="<h1>Sicaklik  ";
         //webpage.concat(isi);
         webpage.concat(DHT.temperature);
         //webpage += isi;
         webpage+=" C </h1>"; 
         webpage+="<h1>Sicaklik LM35  "; 
         webpage.concat(sicaklik);
         webpage+=" C </h1>"; 
         webpage+="<br><a href=\"?pin=on\"><button><h1>Ac/Kapat</h1></button></a>";
         
         
         String cipSend = "AT+CIPSEND=";
         cipSend += connectionId;
         cipSend += ",";
         cipSend +=webpage.length();
         cipSend +="\r\n";
         
         sendData(cipSend,1000,DEBUG);
         sendData(webpage,1000,DEBUG);
     
         String closeCommand = "AT+CIPCLOSE="; 
         closeCommand+=connectionId; // append connection id
         closeCommand+="\r\n";
         
         sendData(closeCommand,3000,DEBUG);
         delay(1000);
        }
      }
    }
     
     
 
    String sendData(String command, const int timeout, boolean debug)
    {
        String response = "";
        
        esp8266.print(command);
        
        long int time = millis();
        
        while( (time+timeout) > millis())
        {
          while(esp8266.available())
          {
            
            
            char c = esp8266.read();
            response+=c;
          }  
        }
        
        if(debug)
        {
 //         Serial.print("---");
          Serial.print(response);
 //         Serial.println("---");
          int a=response.indexOf(":GET /?pin=on");
          Serial.print("-0-0-0-0-0-----a=");
          Serial.println(a);
          if(a>0){
            pinMode(3, OUTPUT);
            if(status==0){
              digitalWrite(3,HIGH);
              status=1;
            }else{
              digitalWrite(3,LOW);
              status=0;
              }
          }
        }
        
        return response;
    }
     

     
