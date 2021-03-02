int deger;
 float Volt;
void setup() {
  Serial.begin(9600);
}

void loop() {

  deger=analogRead(A0);
  Volt=(5.0/1023.0)*deger;

  Serial.println(Volt);
  delay(1000);
}
