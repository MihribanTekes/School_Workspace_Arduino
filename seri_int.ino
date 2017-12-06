void setup() {
  //14010011008 - Mihriban Tekeş
  // put your setup code here, to run once:
  Serial.begin(9600);

}
int gelen=0;
char bytegelen;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) { 
    gelen = 0;
    while(1) { 
      bytegelen = Serial.read();
      if (bytegelen == '\n') break;
      if (bytegelen == -1) continue;
      gelen *= 10;  
      gelen = ((bytegelen - 48) + gelen);
    }
    Serial.println(gelen);
  }

}
