#include <avr/io.h>

int main(){

DDRB |=(1<<5);
PORTB &=~(1<<5);

TCCR1B|=((1<<CS12)|(1<<CS10));

while(1){

  TCNT1=49911;
  while((TIFR1&(1<<TOV1))==0);
  TIFR1|=(1<<TOV1);
  PORTB^=(1<<5);
}

  return 0;
}
