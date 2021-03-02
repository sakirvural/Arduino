int ledpin[12]={2,3,4,5,6,7,8,9,10,11,12,13};

void setup() {
  
for (int n =0;n<12;n++){
    pinMode(ledpin[n],OUTPUT);
}

}

void loop() {
for (int i=2;i<=13;i++){
digitalWrite(i,HIGH);
delay(2000);
digitalWrite(i,LOW);
delay(2000);
}

delay(2000);

for (int x=13;x>=2;x--){
digitalWrite(x,HIGH);
delay(2000);
digitalWrite(x,LOW);
delay(2000);
}

delay(2000);



}
