/*
 * functions.c
 *
 * Created: 02/10/2020 10:01:56 PM
 *  Author: Khalid El-Meshrefy
 */ 
#include <stdio.h>
#include <avr/io.h>
#include "functions.h"
#include <util/delay.h>

int isPressedD (int pinNumber){
	if (PIND & (1<< pinNumber)){
		return 1;
	}else
	return 0;
}

void setPinD (int pinnumber) {
	PORTD |= (1<<pinnumber);

}
void resetPinD (int pinnumber){
	PORTD &= ~(1<<pinnumber);
}

void togglePinD (int  pinnumber){
	PORTD ^= (1<<pinnumber);
}

int isPressedA (int pinNumber){
	if (PINA & (1<< pinNumber)){
		return 1;
	}else
	return 0;
}

void setPinA (int pinnumber) {
	PORTA |= (1<<pinnumber);

}
void resetPinA (int  pinnumber){
	PORTA &=!(1<<pinnumber);
}

void togglePinA (int  pinnumber){
	PORTA ^=(1<<pinnumber);
}

int isPressedB (int pinNumber){
	if (PINB & (1<< pinNumber)){
		return 1;
	}else
	return 0;
}

void setPinB (int pinnumber) {
	PORTB |= (1<<pinnumber);

}
void resetPinB (int  pinnumber){
	PORTB &=!(1<<pinnumber);
}

void togglePinB (int  pinnumber){
	PORTB ^=(1<<pinnumber);
}

int isPressedC (int pinNumber){
	if (PINC & (1<< pinNumber)){
		return 1;
	}else
	return 0;
}

void setPinC (int pinnumber) {
	PORTC |= (1<<pinnumber);

}
void resetPinC (int  pinnumber){
	PORTC &=!(1<<pinnumber);
}

void togglePinC (int  pinnumber){
	PORTC ^=(1<<pinnumber);
}

char getkeypad(){
	while(1){
	setPinD(0);
	setPinD(1);
	setPinD(2);
	if (isPressedD(4))
	{
		setPinD(0);
		resetPinD(1);
		resetPinD(2);
		
		if (isPressedD(4))
		{
			
			return '1';
			
		}
		_delay_ms(40);
		resetPinD(0);
		setPinD(1);
		resetPinD(2);
		
		if (isPressedD(4))
		{
			
			return '2';
			
			
		}
		_delay_ms(40);
		
		resetPinD(0);
		resetPinD(1);
		setPinD(2);
		if (isPressedD(4))
		{
			
			return '3';
			
			
		}
		_delay_ms(40);
		
		
		
		

	}
	if (isPressedD(5))
	{
		setPinD(0);
		resetPinD(1);
		resetPinD(2);
		
		if (isPressedD(5))
		{
			
			return '4';
			
		}
		_delay_ms(40);
		resetPinD(0);
		setPinD(1);
		resetPinD(2);
		
		if (isPressedD(5))
		{
			
			return '5';
			
			
		}
		_delay_ms(40);
		
		resetPinD(0);
		resetPinD(1);
		setPinD(2);
		if (isPressedD(5))
		{
			
			return '6';
			
			
		}
		_delay_ms(40);
	}
	if (isPressedD(6))
	{
		setPinD(0);
		resetPinD(1);
		resetPinD(2);
		
		if (isPressedD(6))
		{
			
			return '7';
			
		}
		_delay_ms(40);
		resetPinD(0);
		setPinD(1);
		resetPinD(2);
		
		if (isPressedD(6))
		{
			
			return '8';
			
			
		}
		_delay_ms(40);
		
		resetPinD(0);
		resetPinD(1);
		setPinD(2);
		if (isPressedD(6))
		{
			
			return '9';
			
			
		}
		_delay_ms(40);
	}
	if (isPressedD(7))
	{
		setPinD(0);
		resetPinD(1);
		resetPinD(2);
		
		if (isPressedD(7))
		{
			
			return '*';
			
		}
		_delay_ms(40);
		resetPinD(0);
		setPinD(1);
		resetPinD(2);
		
		if (isPressedD(7))
		{
			
			return'0';
			
			
		}
		_delay_ms(40);
		
		resetPinD(0);
		resetPinD(1);
		setPinD(2);
		if (isPressedD(7))
		{
			
			return '#';
			
			
		}
		_delay_ms(40);
	}
	}
	return '-';
}



