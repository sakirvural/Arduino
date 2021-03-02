int ledpin[12]={2,3,4,5,6,7,8,9,10,11,12,13};

void setup() {
  
for (int n =0;n<12;n++){
    pinMode(ledpin[n],OUTPUT);
}

}

void loop() {
   
 for (int i=0;i<12;i++){
  
digitalWrite(ledpin[i],HIGH);
delay(100);
digitalWrite(ledpin[i],LOW);
}

delay(100);

 for (int y=11;y>=0;y--){
 
digitalWrite(ledpin[y],HIGH);
delay(100);
digitalWrite(ledpin[y],LOW);
}

}
