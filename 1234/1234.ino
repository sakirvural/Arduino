#include "SSD.h"
SSD display(4, 5, 6, 7, 8,9,10);
void setup()
{
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    
}

void loop()
{
   
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    
  
    display.LightNumber(2);
      delay(3);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);

    display.LightNumber(3);
     delay(3);
  digitalWrite(11,LOW);
    digitalWrite(12,LOW);
   digitalWrite(13,HIGH);
   
    
    display.LightNumber(4);
   delay(3);
    
   
   
    
    

}
