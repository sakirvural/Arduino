#include <avr/io.h>

int sayac=0;
int main(){

DDRB |=(1<<5);//13 port açmak
PORTB |= (1<<5);//13 port ışık yanar
TCCR1B |= ((1<<CS12)|(1<<CS10));//portları ayarladık

while(1){

if(TCNT1>=62500 && sayac==0){//4 sn yanacak ve  sönecek
TCNT1=0;
PORTB ^=(1<<5);
sayac=1;//sayac 1 yaptık
}
if(TCNT1>=62500 && sayac==1){//4 sn bekleme süresi 
TCNT1=0;//0 ladık
sayac=2;  // sayac 2 yaptık
}

if(TCNT1>=46875 && sayac==2){//3 sn bekleme süresi 
TCNT1=0;
sayac=0;  //tekrar yanmaya devam etmesi için sayaç 0ladık
PORTB ^=(1<<5);//led  yanacak burada
}
 



  
}
}
