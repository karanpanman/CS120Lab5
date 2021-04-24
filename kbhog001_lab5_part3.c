/* Author: Karan Bhogal
 * Lab Section: 21
 * Assignment: Lab #5  Exercise #3
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1TU-XvAZe4ZZqix-rGlCCpTzXBw4auwex/view?usp=sharing
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LA_States { S1, Wait, S2, Wait2, S3, Wait3, S4, Wait4, prewait } State;

void LED_latch()
{
unsigned char tmpA = (~PINA) & 0x01;
   switch (State){
	   
	case S1: 
		if (tmpA == 0x01){
			State = Wait;
		}
		else{
			State = S1;
		}
		break;

	case Wait:
		if (tmpA == 0x01){
			State = Wait;
		}
		else {
			State = S2;
		}
		break;

	case S2:
		if ( tmpA == 0x01){
			State = Wait2;
		}
		else {
			State = S2;
		}
		break;

	case Wait2:
		if ( tmpA == 0x01){
			State = Wait2;
		}
		else {
			State = S3;
		}
		break;

	case S3:
		if ( tmpA == 0x01 ){
			State = Wait3;
		}
		else{
			State = S3;
		}
		break;
	
	case Wait3:
		if ( tmpA == 0x01 ){
			State = Wait3;
		}
		else{
			State = S4;
		}
		break;

	case S4:
		if (tmpA == 0x01){
			State = Wait4;
		}
		else{
			State = S4;
		}
		break;

	case Wait4:
		if (tmpA == 0x01){
			State = Wait4;
		}
		else {
			State = S1;
		}
		break;

	default:
		State = S1;
		break;
   }

   switch(State){

	case S1:
		PORTB = 0x03;
		break;

	case S2:
		PORTB = 0x0C;
		break;

	case S3:
		PORTB = 0x30;
		break;

	case S4:
		PORTB = 0x0C;
		break;

	default:
		break;
   }
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	PORTB = 0x00;

	State = S1;
    /* Insert your solution below */
    while (1) {
	
	    LED_latch();
    	}
}
