#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Timer_Module.h"
#include "PWM_module.h"

#define INTERRUPT_INIT  SREG |= (1<<7)
#define ADC_PIN	0
#define SET_BIT(PORT,PIN)  PORT |= (1<<PIN)
#define CLR_BIT(PORT,PIN)  PORT &= ~(1<<PIN)
#define READ_BIT(PORT,PIN) PORT & (1<<PIN)

uint16_t Timer_count=0;
uint16_t Adc_val=0;
volatile uint8_t index=0;

int main()
{
    uint16_t Final=0;
    //uint8_t Switch=0;

    CLR_BIT(DDRD,PD2);   // making PD2 as Input
    SET_BIT(PORTD,PD2);  //PULL UP Enabled

    TIMER_init();
    PWM_init();
    INTERRUPT_INIT;

    while(1)         // Super Loop
    {
        if(!(READ_BIT(PIND,PD2)))  // Checking whether the switch is ON or OFF
        {
            START_TIMER;  // ENABLE THE TIMER INTERRUPT
            if(index==1)   // AFTER COMPLETING 5 SEC
            {
                Final = READ_ADC(ADC_PIN);  // Read ADC value

                if(Final>25 && Final <=250)
                    SET_PWM_VALUE(63);
                else if(Final>251 && Final <=750)
                    SET_PWM_VALUE(127);
                 else if(Final>751 && Final <=1023)
                    SET_PWM_VALUE(191);
                index=0;
            }
        }
        else
        {
            STOP_TIMER;
            SET_PWM_VALUE(0);
        }
      }

    return 0;
}

ISR(TIMER0_OVF_vect)
{
    Timer_count++;
    if(Timer_count>=2930)
    {
        Timer_count=0;
        index=1;
    }
}
