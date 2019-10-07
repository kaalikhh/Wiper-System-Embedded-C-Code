#include <avr/io.h>
#include "PWM_module.h"

void PWM_Initialize()
{
    SET_BIT(DDRD,PD6); // PD6 (OC0A)output
    TCNT0 =0x00;  // give access to timer and counter
    TCCR0A |= ((1<<WGM00)|(1<<WGM01)|(1<<COM0A1)); // enabled the mode and effect
    TCCR0B |= ((1<<CS00)|((1<<CS01))); //clock and WGM02
}
