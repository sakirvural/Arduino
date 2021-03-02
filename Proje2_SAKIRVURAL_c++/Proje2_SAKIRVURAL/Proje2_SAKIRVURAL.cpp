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


//dijitlerin yand��� yer
void calistir(){
	if(TCNT1 != bekle){//4MS BEKLEME
		//Portlar� 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x20;//13 P�N D2 A�
		sure(dakika); //dakika fonksiyon atma PORT 13
	}
	bekle = TCNT1 + 62;//4 ms gecikme �retmek i�in
	if(TCNT1 != bekle){
		//Portlar� 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x10;//12 P�N D3 A�
		sure(saniye2);//saniye2 fonksiyon atma PORT 12
		
	}
	bekle = TCNT1 + 62;//4 ms gecikme �retmek i�in
	if(TCNT1 != bekle){
		//Portlar� 0lama
		PORTD &=0x00;
		PORTB &=0x00;
		PORTB|=0x08;//11 P�N D4
		sure(saniye1);//saniye1 fonksiyon atma PORT 11
	}
	bekle = TCNT1 + 62;//4 ms gecikme �retmek i�in0 lama
}

void azaltma(){//her sn azaltma i�lemi
	TCNT1=0;
	PIND=0x00;
	saniye1--;

	if(saniye1==-1){//0 dan sonra -1 olunca sn sa� k�sm�n� 9la
		saniye1=9;
		saniye2--;

		if(saniye2==-1){//0 dan sonra -1 gelince sn sol k�sm�n� 5le
			
			saniye2=5;
			dakika--;
			
			if(dakika==-1){////0 dan sonra -1 gelince dakika k�sm�n� 9le
				dakika=9;
				
			}
			
		}

	}
	
}
void reset(){//resetleme i�lemi
	TCNT1=0;
	saniye1=9;
	saniye2=5;
	dakika=9;
}
void beklet(){//bekletme i�in yan�p s�nme
	
	cik=0;
	TCNT1=0;
	PIND=0x00;
	//�nce 1 sn yak
	while(cik!=1){
		//dijitlerin yand��� fonksiyon
		calistir();
		//resetle ve beklet
		if((PIND&(1<<2))){
			reset();
		}
		//cikis kontrol et
		if((PIND&(1<<3))){
			if(buton==1){//BUTON 1 E��T M� D�YE KONTROL ED�YORUM �UNKU GER� SAYARKEN BEKLET BASTI�IMIZDA BUTON ANLIK OLARAK TEKRAR �ALI�MASIN D�YE
				buton=2;//DEVAM ETT���NDE TEKRAR BEKLEMEYE MARUZ KALMASIN
				cik=1;
				TCNT1=0;
			}
			
		}
		
		//1sn s�nd�rme i�lemi
		if(TCNT1>=15625 && sayac==0){  //1 SN SONRA S�ND�RME
			buton=1;
			sayac=1;
			TCNT1=0;//zaman� 0la
			while(sayac!=0){
				//resetle ve beklet
				if((PIND&(1<<2))){
					reset();
				}
				//cikis kontrol et
				if((PIND&(1<<3))){
					if(buton==1){
						buton=2;//DEVAM ETT���NDE TEKRAR BEKLEMEYE MARUZ KALMASIN
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
	TCCR1B |= ((1<<CS12)|(1<<CS10));//portlar� ayarlad�k

	while(1){
		//SEVENSEGMENT YAKMA
		calistir();

		//reset buton kontrol 2.pim
		if((PIND&(1<<2))){
			reset();
		}
		//1 sn aral�kla yak�p s�nd�rme duraklatma i�lemi 3.pin
		else if((PIND&(1<<3))){
			if(buton==0)
			beklet();
		}
		//1sn azalt i�lemi
		else{
			if(TCNT1>=15625){
				buton=0;
				azaltma();
			}
			
		}

	}
}
