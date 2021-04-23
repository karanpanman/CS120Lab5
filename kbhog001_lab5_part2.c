/*	Author: Karan Bhogal
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LA_States { Wait, S1, Inc, S2, Dec, Reset } State;

void LED_latch()
{
unsigned char tmpA = ~PINA;
 switch(State) {
   case Wait:
	
	if (tmpA == 0x03) {
		State = Reset;
	}
	else if (tmpA == 0x01){
		State = S1;
	}
	else if (tmpA == 0x02){
                State = S2;
        }
	else {
		State = Wait;
	}
	break;
  
   case S1:
	if (tmpA == 0x02){
		State = S2;
	}
	else if (tmpA == 0x00){
		State = Wait;
	}
	else {
		State = Inc;
	}
	break;

   case Inc:
	if (tmpA == 0x03){
                State = Reset;
        }
        else if (tmpA == 0x02){
                State = S2;
        }
	else if (tmpA == 0x01){
		State = Inc;
	}
        else{
                State = Wait;
        }
	break;

   case S2:
	if (tmpA == 0x01){
		State = S1;
	}
	else if (tmpA == 0x00){
                State = Wait;
        }
	else {
		State = Dec;
	}
	break;

   case Dec:
        if (tmpA == 0x03){
                State = Reset;
        }
        else if (tmpA == 0x02){
                State = Dec;
        }
        else if (tmpA == 0x01){
                State = S1;
        }
        else{
                State = Wait;
        }
	break;

   default:
	State = Wait;
	break;
  } //transitions

  switch(State){
   case Wait:
	break;

   case S1:
	if (PORTC < 0x09){
		PORTC = PORTC + 1;
	}
	break;

   case Inc:
	break;
   
   case S2:
	if (PORTC > 0x00){
		PORTC = PORTC - 1;
	}
	break;

   case Dec:
	break;

   case Reset:
	PORTC = 0x00;
	break;

   default:
	break;
   }
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	PORTC = 0x07;	
	State = Wait;
    /* Insert your solution below */

    while (1) {
	LED_latch();
    }
    return 1;
}
