/*
 * LCD.c
 *
 * Created: 09/10/2020 12:40:10 PM
 * Author : Khalid El Meshrefy
 */ 
#include <stdio.h> //inter to array of char >>ito
#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "lcd.h"
#include "functions.h"
#include <stdlib.h>

int main(void)
{

	DDRD |=(1<<0) |(1<<1) |(1<<2);
	
	lcd_init(4);
	_delay_ms(100);
	//lcd_write_str("AMRMAGIC LDRASETELDIGITAL LOGIC");
	//	lcd_clear();
	//lcd_cmd(0x0C); trun off cursor
	/*lcd_goto_xy(1,2);
	lcd_write_str("khaled");
	lcd_goto_xy(1,1);
	lcd_write_str("khaled");
	lcd_goto_xy(7,1);
	lcd_write_num(120);
	lcd_write_str("khaled");
	lcd_goto_xy(7,2);
	lcd_write_num(12000);
	lcd_goto_xy_noshift(1,2);
	lcd_goto_xy_noshift(17,2);*/
	//lcd_write_str4bit("khaled mesho");

DDRC|=(1<<0);
PORTC|=(1<<0);
char pass [5];
int i=0;
char actpass[5]={'1','2','3','4','5'};
    /* Replace with your application code */
    while (1) 
    {
		for ( ; i<5;i++){
		
		pass[i]=getkeypad();
		lcd_write4bit('*');
				_delay_ms(200);

		}
		
		_delay_ms(50);
		if (i==5)
		{
			if (!strncmp(pass,actpass,5)){
				lcd_clear4bit();
				lcd_write_str4bit("passed !!");
			}else{
				lcd_clear4bit();
				lcd_write_str4bit("failed xx");
			}
			
		}
	
			i++;
    }
}

