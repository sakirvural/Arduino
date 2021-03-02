int dizi[10];
int led[10]={2,3,4,5,6,7,8,9,10,11};
int sayac=0;
void setup() {
  
   for(int i=0;i<10;i++){

    pinMode(i,OUTPUT);
   }
}

void loop() {
int okunan=analogRead(A0);

 while(okunan >= 1){
   
  dizi[sayac]=okunan%2;
  okunan=okunan/2; 
  sayac++;

  
 }
 for(int x=0;x<10;x++){
    if(dizi[x]==1){
        digitalWrite(led[x],HIGH);
    }
   
  
  
 }

}
