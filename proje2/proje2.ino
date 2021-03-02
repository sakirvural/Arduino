#include <avr/io.h> 
#include <util/delay.h>
int saniye1=9;
int saniye2=5;
int dakika=9;
int cik=0;
int sayac=0;
int buton=0;

void saniyeD4(int saniye1)
{
  
    switch(saniye1)
    {
      case 0:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x0B;//0000 1011
      break;
      
      case 1:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x08;//0000 1000
      break;
      
      case 2:
      PORTD |= 0xB0;//1011 0000
      PORTB |= 0x0D;//0000 1101
      break;
      
      case 3:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x0C;//0000 1100
      break;
      
      case 4:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x0E;//0000 1110
      break;
      
      case 5:
      PORTD |= 0xD0;//1101 0000
      PORTB |= 0x0E;//0000 1110
      break;
      
      case 6:
      PORTD |= 0xD0;//1101 0000
      PORTB |= 0x0F;//0000 1111
      break;
      
      case 7:
      PORTD |= 0x70;//0111 0000
      PORTB |= 0x08;//0000 1000
      break;
      
      case 8:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x0F;//0000 1111
      break;
      
      case 9:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x0E;//0000 1110
      break;
      
    }
  
}

void saniyeD3(int saniye2){


switch(saniye2)
    {
      case 0:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x13;//0001 0011
      break;
      
      case 1:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x10;//0001 0000
      break;
      
      case 2:
      PORTD |= 0xB0;//1011 0000
      PORTB |= 0x15;//0001 0101
      break;
      
      case 3:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x14;//0001 0100
      break;
      
      case 4:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x16;//0001 0110
      break;
      
      case 5:
      PORTD |= 0xD0;//1101 0000
      PORTB |= 0x16;//0001 0110
      break;

    }
  
  
}

void dakikaD2(int dakika)
{
  
    switch(dakika)
    {
      case 0:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x23;//0010 0011
      break;
      
      case 1:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x20;//0010 0000
      break;
      
      case 2:
      PORTD |= 0xB0;//1011 0000
      PORTB |= 0x25;//0010 0101
      break;
      
      case 3:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x24;//0010 0100
      break;
      
      case 4:
      PORTD |= 0x60;//0110 0000
      PORTB |= 0x26;//0010 0000
      break;
      
      case 5:
      PORTD |= 0xD0;//1101 0000
      PORTB |= 0x26;//0010 0110
      break;
      
      case 6:
      PORTD |= 0xD0;//1101 0000
      PORTB |= 0x27;//0010 0111
      break;
      
      case 7:
      PORTD |= 0x70;//0111 0000
      PORTB |= 0x20;//1110 0000
      break;
      
      case 8:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x27;//0011 0111
      break;
      
      case 9:
      PORTD |= 0xF0;//1111 0000
      PORTB |= 0x26;//0010 0110
      break;
      
    }
  
}
//dijitlerin yandığı yer
void calistir(){

  dakikaD2(dakika); //dakika fonksiyon atma PORT 13
  
//Portları 0lama 
PORTD &=0x00;
PORTB &=0x00;

  saniyeD3(saniye2);//saniye2 fonksiyon atma PORT 12

//Portları 0 lama
PORTD &=0x00;
PORTB &=0x00;

saniyeD4(saniye1);//saniye1 fonksiyon atma PORT 11

//Portları 0 lama
PORTD &=0x00;
PORTB &=0x00;
  
}

void azaltma(){//her sn azaltma işlemi
TCNT1=0;
PIND=0x00;
saniye1--;

if(saniye1==-1){//0 dan sonra -1 olunca sn sağ kısmını 9la
saniye1=9;
saniye2--;

if(saniye2==-1){//0 dan sonra -1 gelince sn sol kısmını 5le
  
  saniye2=5;
  dakika--;
  
if(dakika==-1){////0 dan sonra -1 gelince dakika kısmını 9le
  dakika=9;
  
}
  
}

}
  
}

void reset(){//resetleme işlemi
  TCNT1=0;
  saniye1=9;
  saniye2=5;
  dakika=9;
}
void beklet(){//bekletme için yanıp sönme
   
    cik=0;
    TCNT1=0;
    PIND=0x00;
//önce 1 sn yak
while(cik!=1){
  //dijitlerin yandığı fonksiyon
 calistir();
  //resetle ve beklet
  if((PIND&(1<<2))){
  reset();
  }
  //cikis kontrol et
  if((PIND&(1<<3))){
    if(buton==1){
    buton=2;
    cik=1;
    TCNT1=0;
    }
    
  }
  
  //1sn söndürme işlemi
 if(TCNT1>=15625 && sayac==0){  //1 SN SONRA SÖNDÜRME
  buton=1;
  sayac++;
  TCNT1=0;//zamanı 0la
  while(sayac!=0){
   //resetle ve beklet
  if((PIND&(1<<2))){
  reset();
  }  
    //cikis kontrol et
  if((PIND&(1<<3))){
    if(buton==1){
    buton=2;
    cik=1;
    TCNT1=0; 
    }
    
  }

  PORTD &=0x00;
  PORTB &=0x00;
  if(TCNT1>=15625 && sayac==1){ //1SN SONRA TEKRAR YAKMA
   TCNT1=0;
   sayac=0;
  }
  
  }

 }
 
}
  
}


int main(){
//pinler
DDRD |=0xF0;//1111 0000
DDRB |=0xFF;//1111 1111
TCCR1B |= ((1<<CS12)|(1<<CS10));//portları ayarladık

while(1){
 
calistir();

//reset buton kontrol 2.pim
if((PIND&(1<<2))){
  reset();
}
//1 sn aralıkla yakıp söndürme duraklatma işlemi 3.pin
else if((PIND&(1<<3))){
if(buton==0)
beklet();
}
//1sn azalt işlemi
else{
if(TCNT1>=15625){
  buton=0;
  azaltma();
}
  
}

}
}
