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
    DDRD = (1<<PD5) | (1<<PD4);
    DDRD &= ~(1<<PD3);
    
    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
    TCNT0 = 0;
    OCR0 = 0;
    
    UCSRB |= (1<<RXEN);
    UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);
    UCSRC = (1<<UPM1) | (1<<UPM0);
    UBBRL = MYUBRR;
    UBRRM = (MYUBRR >> 8);
    UCSRB |= (1<<RXCIE);
    
    sei();
    
    while(1){
    
    }
    
    return 0;
    

}

void steering(byte direction){
    
    switch(direction){
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
            
        case 0b00000000:
            break;
    
            
    }
}
