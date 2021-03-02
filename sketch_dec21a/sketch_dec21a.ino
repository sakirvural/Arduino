#include <avr/io.h>
#include <util/delay.h>
int sayac=0;
int anlik=1,anlik2=1,anlik3=1;
int dk,s1,s2;
int Saniye2(int sayi){
  switch(sayi){ //saniye
    case 0:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap 
      PORTB &=~(1<<2);
      break;
    
    case 1:
      PORTD &=~(1<<4);
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD &=~(1<<7);
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB &=~(1<<2);
      break;
    
    case 2:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD &=~(1<<6);
      PORTD |=(1<<7); //7. pini yani d yı 1 yap  
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB &=~(1<<1); 
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 3:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
       
    case 4:
      PORTD &=~(1<<4); 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD &=~(1<<7);
      PORTB &=~(1<<0); 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 5:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap
      PORTD &=~(1<<5); 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD |=(1<<7); //7. pini yani d yı 1 yap  
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB &=~(1<<0);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 6:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD &=~(1<<5); 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 7:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD &=~(1<<7); 
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB &=~(1<<2);
      break;
      
    case 8:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 9:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB &=~(1<<0); 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
  }
}

int Saniye1(int sayi)
{
  switch(sayi)
  { //saniye1 
    case 0:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB &=~(1<<2); 
      break;
    
    case 1:
      PORTD &=~(1<<4);
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD &=~(1<<7);
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB &=~(1<<2);
      break;
    
    case 2:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD &=~(1<<6);
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap  
      PORTB |=(1<<0); //8. pini yani e yı 1 yap
      PORTB &=~(1<<1);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 3:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
       
    case 4: 
      PORTD &=~(1<<4);
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD &=~(1<<7);
      PORTB &=~(1<<0); 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 5:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD &=~(1<<5);
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap
      PORTB &=~(1<<0);  
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
  }
  
}

int Dakika(int sayi){
  switch(sayi){ //saniye
   case 0:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap 
      PORTB &=~(1<<2);
      break;
    
    case 1:
      PORTD &=~(1<<4);
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD &=~(1<<7);
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB &=~(1<<2);
      break;
    
    case 2:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD &=~(1<<6);
      PORTD |=(1<<7); //7. pini yani d yı 1 yap  
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB &=~(1<<1); 
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 3:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
       
    case 4:
      PORTD &=~(1<<4); 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD &=~(1<<7);
      PORTB &=~(1<<0); 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap
      break;
      
    case 5:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap
      PORTD &=~(1<<5); 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD |=(1<<7); //7. pini yani d yı 1 yap  
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB &=~(1<<0);
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 6:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD &=~(1<<5); 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 7:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap
      PORTD &=~(1<<7); 
      PORTB &=~(1<<0);
      PORTB &=~(1<<1);
      PORTB &=~(1<<2);
      break;
      
    case 8:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB |=(1<<0); //8. pini yani e yı 1 yap 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
      
    case 9:
      PORTD |=(1<<4); //4. pini yani a yı 1 yap 
      PORTD |=(1<<5); //5. pini yani b yı 1 yap 
      PORTD |=(1<<6); //6. pini yani c yı 1 yap 
      PORTD |=(1<<7); //7. pini yani d yı 1 yap 
      PORTB &=~(1<<0); 
      PORTB |=(1<<1); //9. pini yani f yı 1 yap
      PORTB |=(1<<2); //10. pini yani g yı 1 yap 
      break;
  }
}


int bekleme(){
  
  
 if(TCNT1>=15625){
  TCNT1=0; 
   anlik=0;
 }
 
}

int ledYakma(){
          dk=9;//DAKKA
            for(dk ; dk>=0; dk--){
              s1=5;//SN1
              for(s1;s1>=0;s1--){
                s2=9;//SN2
                for(s2;s2>=0;s2--){
                  anlik=1;//WHİLE SÜREKLİ YAKMAK İÇİN
                  anlik2=1;//DURAKLMA İÇİN
                  while(anlik!=0){//ledleri yakmak için
                    
                   if((PIND&(1<<2))){//RESETLEMEK İÇİN
                    dk=9;
                    s1=5;
                    s2=9;
                    TCNT1=0;
                   }

                   if((PIND&(1<<3))){//DURAKLATMA İŞLEMİ
                    TCNT1=0;
                    while(anlik2!=0){//ledleri yakıp söndürmek için
                      //LEDLERİ YAKMA ÖNCELİKLE
                    PORTD&=0x00;//PORTLARI 0LA
                    PORTB&=0x00;
                    PORTB|=0x08;//13 PİN
                    Dakika(dk);
                   
                    _delay_ms(1);
                    PORTD&=0x00;//PORTLARI 0LA
                    PORTB&=0x00;
                    PORTB|=0x10;//12 PİN
                    Saniye1(s1);
                   
                    _delay_ms(1);
                    PORTD&=0x00;
                    PORTB&=0x00;
                    PORTB|=0x20;//11 PİN
                    Saniye2(s2);
                    _delay_ms(1);
                    //LEDLERİ SÖNDÜRME 1 SN
                    if(TCNT1>=15625){
                      anlik3=1;
                    TCNT1=0; 
                    while(anlik3!=0){//söndürme
                    PORTD&=0x00;//HEPSİNİ SÖNDÜR
                    PORTB&=0x00;
                    if((PIND&(1<<3))){//çıkma kontrolu
                      anlik2=0;//BASILIRSA BEKLETMEDEN ÇIK
                    }
                    if(TCNT1>=15625){//1SN GEÇİNCE SÖNDÜRME WHİLE ÇIK YAKMA WHİLE GEÇ
                    TCNT1=0;
                    anlik3=0; 
                    }
                    
                    }
                    
                    }
                    
                      
                    }
                   }
                  
                   PORTD&=0x00;
                   PORTB&=0x00;
                   PORTB|=0x08;
                   Dakika(dk);
                   
                   _delay_ms(1);
                   PORTD&=0x00;
                   PORTB&=0x00;
                   PORTB|=0x10;
                   Saniye1(s1);
                   
                   _delay_ms(1);
                   PORTD&=0x00;
                   PORTB&=0x00;
                   PORTB|=0x20;
                   Saniye2(s2);
                   _delay_ms(1);
                   bekleme();
                   
                  }
                 
                     
                 
                }
              }
            }
                
}

int main(){
  DDRD &=~(1<<2); //sıfırlama butonu
  DDRD &=~(1<<3); //3. pini çıkış yaptık , çalısıp durdurma butonu
  DDRD |= (1<<4); //4. pin
  DDRD |= (1<<5); //5. pin 
  DDRD |= (1<<6); //6. pin
  DDRD |= (1<<7); //7. pin 
  DDRB |= (1<<0); //8. pini çıkış olarak  ayarla
  DDRB |= (1<<1); //9. pini çıkış olarak  ayarla
  DDRB |= (1<<2); //10. pini çıkış olarak  ayarla
  DDRB |=(1<<3); //dakika1 11.pin 
  DDRB |=(1<<4); //saniye1 12. pin
  DDRB |=(1<<5); //saniye2 13. pin
  TCCR1B |= ((1<<CS12) | (1<<CS10));
  
  while(1){

    ledYakma();

  }
}
