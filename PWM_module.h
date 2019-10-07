#define SET_PWM_VALUE(value)  OCR0A = value

#define SET_BIT(PORT,PIN)  PORT |= (1<<PIN)
#define CLR_BIT(PORT,PIN)  PORT &= ~(1<<PIN)

void PWM_init();
