#include <avr/io.h>

const int PinOut = 6;

int main(void) {
  DDRD |= 1<<DDD6;
  TIMSK0 |= (1<<OCIE0A); //Enable Timer
  TCCR0B |= (1<<CS02 | 1<<CS00); //set the prescaler to divide the clock by 1024
  TCCR0A |= (1<<COM0A0 | 1<<WGM01); //WGM01 bit to 1, we set the Timer0 waveform generation mode to CTC (Clear Timer on Compare)
  TCNT0 = 0;
  OCR0A = 77;
  sei();
  while(1)
  {

  }
}

ISR(TIMER2_COMPA_vect) 
{

}
