#include <REGX52.H>

#define BEEP_PORT P1
#define BEEP_PIN  0

void delay(unsigned int t)
{
    while(t--)
        ;
}

void beep()
{
    BEEP_PORT |= (1 << BEEP_PIN);
    delay(500);   
    BEEP_PORT &= ~(1 << BEEP_PIN);
    delay(500);   
}

void main()
{
    while(1)
    {
        beep();  
    }
}
