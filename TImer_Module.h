#define START_TIMER TIMSK0|=(1<<TOIE0)
#define STOP_TIMER  TIMSK0 &= ~(1<<TOIE0)

#define SET_BIT(PORT,PIN)  PORT |= (1<<PIN)
#define CLR_BIT(PORT,PIN)  PORT &= ~(1<<PIN)

void TIMER_init();
