#include <avr/io.h>
int sayac=0;
int main()
{ 
int sayma=0;
DDRB |= (1<<1);/* 9 numaralı pini çıkış yaptık */
PORTB |= (1<<1); /* 9 numaralı pini yakıyoruz */
TCCR1B |= (1<<CS12);  /*Timer1i 256 prescaler ile setledik */
TCCR1B |=(1<<WGM12);  /* CTC mod ayarı */
OCR1A=62500;   /* Output register ayarı */
while(1)
{  
 while((TIFR1 &(1<<OCF1A))==0);  /* timer a 1 sn bekleme atadık */
 TIFR1 |=(1<<OCF1A);   /* Interrupt bayrağı tetiklenir */
 sayac++;  /* her işlem 1 sn süreceği için sayma 10 olduğunda 10 sn geçmiş olacak */
 
  if(sayac==10)
  { 
    PORTB ^=(1<<1);    /* ledin durumunu tersine çevir */
  sayac=0;              /* sayaç sıfırlanarak 10 snlik işlem yeniden başlatılır */
  } 
}

return 0; 
 
}
