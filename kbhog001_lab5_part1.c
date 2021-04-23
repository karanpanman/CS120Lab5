/*	Author: Karan Bhogal
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #the 5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;	
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;	
	unsigned int check;

    /* Insert your solution below */
    while (1) {
	tmpA = ~PINA;
	check = 0;
	if ( (tmpA & 0x70) == 0x30 ){
		check = 1;
	}
	tmpA = tmpA & 0x0F;

	if (tmpA == 0){
                tmpC = 0x40;
        }
	else if ( tmpA <= 2 ){
		tmpC = 0x60;
	}
	else if (tmpA <= 4 ){
		tmpC = 0x70;
	}
	else if (tmpA <= 6) {
		tmpC = 0x38;
	}
	else if (tmpA <= 9) {
		tmpC = 0x3C;
	}
	else if (tmpA <= 12) {
		tmpC = 0x3E;
	}
	else if (tmpA <= 15) {
		tmpC = 0x3F;
	}
	
	if ( check == 1 ){
		tmpC = tmpC | 0x80;
	}
 	
	PORTC = tmpC;
    }
    return 1;
}
