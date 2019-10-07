#include <avr/io.h>
#include "TImer_Module.h"

void TIMER_Initialize()
{
    //SET_BIT(DDRD,PD7); //
    TCNT0 =0x00; // enables timer 0
    TCCR0A=0x00; //
    TCCR0B |= ((1<<CS00)|((1<<CS01)));
    //CLR_BIT(PORTD,PD7);
}



