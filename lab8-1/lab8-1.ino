#include <avr/io.h>
#include <avr/interrupt.h>

ISR (INT1_vect)//interput oluşturulması için kullanılan fonksiyon
{
  PORTD^=(1<<4);
    //interrupt olduğunda 4 numaralı pin high ise low -low ise high
}

int main(void)
{

    DDRD &= ~(1 << DDD3);//D PORT 3 NUMARALI GİRİŞ
    DDRD |= (1 << DDD4);// D POT 4 NUMARALI PİN ÇIKIŞ
    
    PORTD |= (1 << PORTD3); //3 NUMARALI PİN HIGH
    PORTD |= (1 << PORTD4);//4 NUMARALI PİN HIGH

    EICRA |= (1 << ISC11);    //BURADA HARİCİ KESME İÇİN INT1 PARAMETRESİ
    EICRA &= ~(1 << ISC10);   //ALÇALAN KENAR TETİKLEME OLACAK
  
    EIMSK |= (1 << INT1);     //INT 1 HIGH DEĞER UYGULADIM

    sei();                    // İNTERRUPT KONTROL SAĞLAYAN FONKSİYON

    while(1)
    {
      //  BOŞ BİR LOOP BİŞE YAPILMADI İSTENİLDİĞİ GİBİ
    }
}
