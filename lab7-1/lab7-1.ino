 #include "LM35DZ.h"
 #include "SSD.h"
 LM35DZ sensor(A0);
 SSD sol7Segment(9,10,11,12,13,A1,A2);
 SSD sag7Segment(2,3,4,5,6,7,8);
 
 int derece,sag,sol;
void setup() {
 
  Serial.begin(9600);
}

void loop() {

  derece=sensor.ReadTemperature(5);
  Serial.println(derece);
  sol=derece/10;
  sag=derece%10;

  sol7Segment.LightNumber(sol);
  sag7Segment.LightNumber(sag);
  delay(1000);
}
