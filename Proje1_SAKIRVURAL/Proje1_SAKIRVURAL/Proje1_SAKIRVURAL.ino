//değişkenlerimi belirlediğim yer
int dizi[4],farkdizi[4],tabandizi[4][4],
    girisLedpin[5]={2,7,8,9,10},cikisLedpin[6]={3,4,5,6,11,12},
    sayac=0,
    taban=0,
    MaxSayi=0,
    MinSayi=0,
    fark=0;

void rasgeleSayi()//rasgele sayi üretme yeri
{
  for(int x=0;x<4;x++)
  {
  dizi[x]=random(1,16);
  }

}

void taban2lik()//taban çevirme  işlevi 4 tane  rasgele sayi için
{
  for(int i=0;i<4;i++)
    {
    sayac=0;
    taban=dizi[i];
    while(taban>=1)
        {
        tabandizi[i][sayac]=taban%2;//2boyutlu dizimizin içine attık
        taban=taban/2;
        sayac++;
        }
    } 
}

void ledYak()//ledlerimizi yaktık
{
    for(int i=0;i<4;i++)
      {
         for(int j=0;j<4;j++)
              {
           digitalWrite(j+3,tabandizi[i][j]);//3.ledden başla 6. ledde dahil olmak üzere yak
              }
           delay(5000);
           digitalWrite(3,LOW);
           digitalWrite(4,LOW);
           digitalWrite(5,LOW);
           digitalWrite(6,LOW);
           delay(1000);
      }
}

void Farki()//max ve min sayi bulup bunun farkını 2lik tabana çevirme
{
  MaxSayi=max(dizi[0],dizi[1]);
  MaxSayi=max(MaxSayi,dizi[2]);
  MaxSayi=max(MaxSayi,dizi[3]);

  MinSayi=min(dizi[0],dizi[1]);
  MinSayi=min(MinSayi,dizi[2]);
  MinSayi=min(MinSayi,dizi[3]);
 
  fark=MaxSayi-MinSayi;
  int s=0;
  while(fark>=1)
      {
      farkdizi[s]=fark%2;
      fark=fark/2;
      s++;
      }    
 
}

void yakSondur()//tüm ledleri 1'er saniye aralıkla yakıp söndürme 10 sn boyunca
{
  int toggle=1;
  for(int i=0;i<10;i++)
  {
    if(toggle)//yaksın
    {
      for(int j=0;j<4;j++)
       {
      digitalWrite(cikisLedpin[j],HIGH);
       }
    delay(1000);
    toggle=0;
    }
    else//söndürsün
    {
      for(int j=0;j<4;j++)
       {
      digitalWrite(cikisLedpin[j],LOW);
       }
    delay(1000);  
    toggle=1;
    }
  }
     
}
void Kontrol()//kullanıcığın girdiği 2lik taban doğruysa yeşil yak yanlışsa eğer kırmızı ledi yak
{
   if(digitalRead(7)==farkdizi[0] &&  digitalRead(8)==farkdizi[1] &&  digitalRead(9)==farkdizi[2] &&  digitalRead(10)==farkdizi[3])
        {
          digitalWrite(11,HIGH);
          delay(2000);
        }
        else
        {
          digitalWrite(12,HIGH);
          delay(2000);
        }
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);  
  
}

void setup()
{
 //GİRİŞ PİNLERİ
 for(int i=0;i<5;i++)
 {
  pinMode(girisLedpin[i],INPUT);
 }
 
 //ÇIKIŞ PİNLERİ
 for(int j=0;j<6;j++)
 {
 pinMode(cikisLedpin[j],OUTPUT);
 }
  
 
  randomSeed(analogRead(0));//RASGELE SAYI SIFIRLA
}

void loop(){

  if(digitalRead(2)==HIGH)//BAŞLAT BUTON BASILINCA
  {
    
  rasgeleSayi();//rasgele sayi üret
  
  taban2lik();//rasgele sayiyi 2lik taban çevir
  
  ledYak(); //2lik tabanları ledlerle göster
   
  Farki();//Max ve Min bulup farkını alıp 2lik tabana çevirme
  
  yakSondur();//1 er saniye aralıkla tüm ledleri yakıp söndürme
  
  Kontrol();//Kullanıcı giriş kontrol ettik
     
  }
}
