#include "SSD.h"
SSD segment(2,3,4,5,6,7,8);
int analogGiris,volt,D2,D3,D4;
float V;

void goster(int sayi,int sol,int orta,int sag, int nokta){
digitalWrite(9,sol);//D2
digitalWrite(10,orta);//D3
digitalWrite(11,sag);//D4
digitalWrite(12,nokta); 
segment.LightNumber(sayi);

}
void setup() { 
 Serial.begin(9600);   
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
        
}
void loop() {
  analogGiris=analogRead(A0);  

  V = analogGiris*(5.0/1023.0);  
  Serial.println(V);  
  volt=V*100;//3 basamaklı hale getirdim
  
  D2=volt/100;// SOL
  D3=(volt%100)/10;//ORTA
  D4=volt%10;//SAĞ
  goster(D2,1,0,0,1);
  delay(50);
  
  goster(D3,0,1,0,0);
  delay(50);

  goster(D4,0,0,1,0);
  delay(50);

}  
