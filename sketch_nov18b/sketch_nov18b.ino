int led[]={2,3,4,5,6,7,8,9,10,11};
void setup() {
for(int i=0;i<10;i++){

  pinMode(i,OUTPUT);
}

}

void loop() {
  int deger,i=0;
  int k[10];
  deger=analogRead(A0);
  while(deger >=1){

    i++;
    k[i]=deger%2;
    deger=deger/2;
    
  }
for(int j=0;j<10;j++)
for( i=i;i>0;i--)
digitalWrite(led[j],k[i]);
}
