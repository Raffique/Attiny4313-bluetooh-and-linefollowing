#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 8000000UL
#define BAUD 9600
#define MYUBRR F_C/16/BAUD-1

ISR(USART_RXC_vect){
    
    char RecievedByte;
    RecievedByte = UDR;

}

int main(void){

    DDRB = 0x00;
    DDRD = (1<<PD5) | (1<<PD4)
    DDRD &= ~(1<<PD3)
    
    TCCR0 = ()
    
    sei();

}
