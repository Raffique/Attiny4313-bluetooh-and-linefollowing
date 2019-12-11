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
    
    // OC1A, OC1B outputs
	DDRB |= (1<<PB4)|(1<<PB3);
	// TOP, set for 50Hz (20ms)
	ICR1 = 20000;
	// Center outputs (1.5ms)
	OCR1A = 1500;
	OCR1B = 1500;
	// Timer 1 fast PWM mode 14 
	// Clear on compare, set at TOP
	// /8 prescaler
	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS11);
    
    sei();
    
    while(1){
    
    }
    
    return 0;
    

}

void steering(byte direction){
    
    switch(direction){
            
        case 0b10000001:
		case 0b11000011:
        case 0b11100111:
            
			break;
			
		case 0b10000111:
			break;
            
		case 0b00001111:
			break;
			
		case 0b11000111:
			break;
            
		case 0b10000011:
			break;
			
		case 0b11100001:
            break;
            
		case 0b11110000:
			break;
			
		case 0b11100011:
			break;
            
		case 0b11000001:
			break;
			
		case 0b00111111:
		case 0b01111111:
			break;
            
		case 0b11111100:
		case 0b11111110:
			break;
            
		case 0b11111111:
			break;
			
		case 0b00000000:
			break;
            
		case 0b00000111:
			break;
		
		case 0b00000011:
		case 0b00000001:
			break;
            
		case 0b11100000:
			break;
            
		case 0b11000000:
		case 0b10000000:
			break;
            
		default:
            break;
    
            
    }
}
