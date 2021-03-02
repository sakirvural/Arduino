#include <avr/io.h>
int saniye1=9;//D4 PORT 11
int saniye2=5;//D3 PORT 12
int dakika=9;//D2 PORT 13
int cik=0;
int sayac=0;
int buton=0;
int bekle=0;
void sure(int gerisar)
{
	
	switch(gerisar)
	{
		case 0:
		PORTD |= 0xF0;//1111 0000
		PORTB |= 0x03;//0000 1011
		break;
		
		case 1:
		PORTD |= 0x60;//0110 0000
		PORTB |= 0x00;//0000 1000
		break;
		
		case 2:
		PORTD |= 0xB0;//1011 0000
		PORTB |= 0x05;//0000 1101
		break;
		
		case 3:
		PORTD |= 0xF0;//1111 0000
		PORTB |= 0x04;//0000 1100
		break;
		
		case 4:
		PORTD |= 0x60;//0110 0000
		PORTB |= 0x06;//0000 1110
		break;
		
		case 5:
		PORTD |= 0xD0;//1101 0000
		PORTB |= 0x06;//0000 1110
		break;
		
		case 6:
		PORTD |= 0xD0;//1101 0000
		PORTB |= 0x07;//0000 1111
		break;
		
		case 7:
		PORTD |= 0x70;//0111 0000
		PORTB |= 0x00;//0000 1000
		break;
		
		case 8:
		PORTD |= 0xF0;//1111 0000
		PORTB |= 0x07;//0000 1111
		break;
		
		case 9:
		PORTD |= 0xF0;//1111 0000
		PORTB |= 0x06;//0000 1110
		break;
		
	}
	
}


//dijitlerin yandýðý yer
void calistir(){
	if(TCNT1 != bekle){//4MS BEKLEME
		//Portlarý 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x20;//13 PÝN D2 AÇ
		sure(dakika); //dakika fonksiyon atma PORT 13
	}
	bekle = TCNT1 + 62;//4 ms gecikme üretmek için
	if(TCNT1 != bekle){
		//Portlarý 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x10;//12 PÝN D3 AÇ
		sure(saniye2);//saniye2 fonksiyon atma PORT 12
		
	}
	bekle = TCNT1 + 62;//4 ms gecikme üretmek için
	if(TCNT1 != bekle){
		//Portlarý 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x08;//11 PÝN D4
		sure(saniye1);//saniye1 fonksiyon atma PORT 11
	}
	bekle = TCNT1 + 62;//4 ms gecikme üretmek için0 lama
}

void azaltma(){//her sn azaltma iþlemi
	TCNT1=0;
	PIND=0x00;
	saniye1--;

	if(saniye1==-1){//0 dan sonra -1 olunca sn sað kýsmýný 9la
		saniye1=9;
		saniye2--;

		if(saniye2==-1){//0 dan sonra -1 gelince sn sol kýsmýný 5le
			
			saniye2=5;
			dakika--;
			
			if(dakika==-1){////0 dan sonra -1 gelince dakika kýsmýný 9le
				dakika=9;
				
			}
			
		}

	}
	
}
void reset(){//resetleme iþlemi
	TCNT1=0;
	saniye1=9;
	saniye2=5;
	dakika=9;
}
void beklet(){//bekletme için yanýp sönme
	
	cik=0;
	TCNT1=0;
	PIND=0x00;
	//önce 1 sn yak
	while(cik!=1){
		//dijitlerin yandýðý fonksiyon
		calistir();
		//resetle ve beklet
		if((PIND&(1<<2))){
			reset();
		}
		//cikis kontrol et
		if((PIND&(1<<3))){
			if(buton==1){//BUTON 1 EÞÝT MÝ DÝYE KONTROL EDÝYORUM ÇUNKU GERÝ SAYARKEN BEKLET BASTIÐIMIZDA BUTON ANLIK OLARAK TEKRAR ÇALIÞMASIN DÝYE
				buton=2;//DEVAM ETTÝÐÝNDE TEKRAR BEKLEMEYE MARUZ KALMASIN
				cik=1;
				TCNT1=0;
			}
			
		}
		
		//1sn söndürme iþlemi
		if(TCNT1>=15625 && sayac==0){  //1 SN SONRA SÖNDÜRME
			buton=1;
			sayac=1;
			TCNT1=0;//zamaný 0la
			while(sayac!=0){
				//resetle ve beklet
				if((PIND&(1<<2))){
					reset();
				}
				//cikis kontrol et
				if((PIND&(1<<3))){
					if(buton==1){
						buton=2;//DEVAM ETTÝÐÝNDE TEKRAR BEKLEMEYE MARUZ KALMASIN
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
	TCCR1B |= ((1<<CS12)|(1<<CS10));//portlarý ayarladýk

	while(1){
		//SEVENSEGMENT YAKMA
		calistir();

		//reset buton kontrol 2.pim
		if((PIND&(1<<2))){
			reset();
		}
		//1 sn aralýkla yakýp söndürme duraklatma iþlemi 3.pin
		else if((PIND&(1<<3))){
			if(buton==0)
			beklet();
		}
		//1sn azalt iþlemi
		else{
			if(TCNT1>=15625){
				buton=0;
				azaltma();
			}
			
		}

	}
}
