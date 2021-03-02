int sure;
int mesafe;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,INPUT); 
 Serial.begin(9600);
}
void loop() {
  
 digitalWrite(8,HIGH);
 delayMicroseconds(1000);
 digitalWrite(8,LOW);

sure=pulseIn(9,HIGH);
mesafe=(sure/2)/29.1;
Serial.print("Cisme olan uzaklık =");
Serial.println(mesafe);
Serial.println("----------------------");
 if(mesafe>=8){
  digitalWrite(3,HIGH);
  
 }
 else{
  digitalWrite(3,LOW);
 }
  if(mesafe<=8){
  digitalWrite(4,HIGH);
  
 }
 else{
  digitalWrite(4,LOW);
 }
  
}
