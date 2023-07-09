#include <avr/io.h>
#include <avr/interrupt.h>

const int PinOut = 8;

int main(void) {
  DDRB |= 0x01; //sets the data direction register pin output

  TIMSK0 |= (1<<TOIE2);
  TCCR0B |= (1<<CS22 | 1<<CS20); //setting the TOIE2 bit to 1,  enable the Timer0 overflow interrupt
  TCCR0A = 0x00;
  TCNT0 = 178;
  sei();
  while(1)
  {
    
  }
}

ISR(TIMER0_OVF_vect)
{
  TCNT0 = 178;
  digitalWrite(PinOut, !digitalRead(PinOut)); //toggles the state of the PinOut
}
