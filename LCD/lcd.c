/*
 * functions.c
 *
 * Created: 02/10/2020 10:01:56 PM
 *  Author: Khalid El-Meshrefy
 */ 
#include <stdio.h>
#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>



void lcd_cmd(char cmd){
	LCD_DATA=cmd;
	ctrl &=~ (1<<RS);// access to command register
	ctrl |=(1<<EN); // fire the enable
	_delay_ms(100);
	ctrl &=~ (1<<EN);
	
	
}
void lcd_cmd4bit(char cmd){
	LCD_DATA &=0x0F;
	LCD_DATA |=(0xF0 &cmd) ;
	ctrl &=~ (1<<RS);// access to command register
	ctrl |=(1<<EN); // fire the enable
	_delay_us(1);
	ctrl &=~ (1<<EN);
	
	_delay_us(200);
		LCD_DATA &=0x0F;
		LCD_DATA |=(cmd <<4) ;
		ctrl &=~ (1<<RS);// access to command register
		ctrl |=(1<<EN); // fire the enable
		_delay_us(1);
		ctrl &=~ (1<<EN);
		
		_delay_ms(2);
		
	
}
int count=0;
void lcd_init(int mode){
	//data direction
	//lcd_data_out
	//ctrl_pins_outputs

	//data mode
	if (mode==4)
	{
		
			lcd_write_dir=0xF0; // Half of PORT C AS OUTPUT

			ctrl_dir |=(1<<RS) |(1<<EN);
		lcd_cmd(0x28); // initiate lcd  for 4bit mode
		lcd_cmd4bit(0x0C); // display on cursor off
		lcd_cmd4bit(0x01); // clear screen
		lcd_cmd4bit(0x06); // cursor increment
		lcd_cmd4bit(0x0E);
		
	}else{
					lcd_write_dir=0xFF; //PORT C AS OUTPUT
			ctrl_dir |=(1<<RS) |(1<<EN);
		lcd_cmd(0x38);  // initiate lcd  for 8bit mode
		lcd_cmd(0x0C); // display on cursor off
		lcd_cmd(0x01); // clear screen
		lcd_cmd(0x06); // cursor increment
		lcd_cmd(0x0E); //Display ON, cursor blinking
	}
	
	
}
void lcd_write(char data){
	LCD_DATA=data;
	ctrl |=(1<<RS);
	ctrl |=(1<<EN);
	_delay_ms(100);
	ctrl &=~ (1<<EN);
	count++;
	
	return ;
	
	
}
void lcd_write4bit(char data){
	LCD_DATA &=0x0F;
	LCD_DATA |=(0xF0 &data) ;
	ctrl |= (1<<RS);// access to command register
	ctrl |=(1<<EN); // fire the enable
	_delay_ms(100);
	ctrl &=~ (1<<EN);
	
	LCD_DATA &=0x0F;
	LCD_DATA |=(data <<4) ;
	ctrl |= (1<<RS);// access to command register
	ctrl |=(1<<EN); // fire the enable
	_delay_ms(100);
	ctrl &=~ (1<<EN);
	
	
}
void lcd_write_str4bit(char string[]){
	for (int i=0;string[i]!='\0';i++){
		if (i==16){
			lcd_cmd4bit(0xC0);
			count++;
			}
					LCD_DATA &=0x0F;
					LCD_DATA |=(0xF0 &string[i]) ;
					ctrl |= (1<<RS);// access to command register
					ctrl |=(1<<EN); // fire the enable
				   _delay_us(1);
					ctrl &=~ (1<<EN);
					_delay_us(200);
					LCD_DATA &=0x0F;
					LCD_DATA |=(string[i]<<4) ;
					ctrl |= (1<<RS);// access to command register
					ctrl |=(1<<EN); // fire the enable
					_delay_us(1);
					ctrl &=~ (1<<EN);
		}
		
		
	}
	
	void lcd_write_str(char string[]){
		for (int i=0;string[i]!='\0';i++){
			if (i==16){
				lcd_cmd(0xC0);
				count++;
			}
			LCD_DATA =string[i];
			ctrl |= (1<<RS);// access to command register
			ctrl |=(1<<EN); // fire the enable
			_delay_ms(100);
			ctrl &=~ (1<<EN);
		}
		
		
	}


void lcd_clear(){
	_delay_ms(24);
	lcd_cmd(0x01);
	_delay_ms(24);
	count=0;
	
}
void lcd_goto_xy(int x , int y ){
	if (y==1 )
	{
		lcd_cmd(0x80);
		count=0;
	
		for (int i=count; i<x ;i++){
		lcd_cmd(0x14); //move right
	}
	for (int i=count; i>x; i--){
		lcd_cmd(0x10); // move left
	}
}
else if (y==2)
{
	count=0;
	lcd_cmd(0xC0);
	
	
	for (int i=count; i<x; i++){
		lcd_cmd(0x14);  // move right
	}
	for (int i=count; i>x; i--){
		lcd_cmd(0x10); // move left 
	}
}else{
	return;
}

}

void lcd_goto_xy_noshift(int x , int y){
	if (y==1 && x<16)
	{
		lcd_cmd(0x80 |y);
	
	
	}
	else if (y==2 && x<16)
	{
		
		lcd_cmd(0xC0 | y);
		
		
		}else{
			lcd_clear();
	   lcd_write_str("No enough columns");
	}

}

void lcd_write_num( unsigned int x){
	/*char txt [20];
	int value =x;
for (int i=0; value %10 !=0;i++){
	txt[i]=value %10;
	LCD_DATA=txt[i];
    ctrl |=(1<<RS);
	ctrl |=(1<<EN);
	_delay_ms(100);
	ctrl &=~ (1<<EN);
    count++;
	value=value/10;*/
	char strNum[40];
	itoa(x,strNum,10);
	lcd_write_str(strNum);
	
}
void lcd_write_num4bit( unsigned int x){
	/*char txt [20];
	int value =x;
for (int i=0; value %10 !=0;i++){
	txt[i]=value %10;
	LCD_DATA=txt[i];
    ctrl |=(1<<RS);
	ctrl |=(1<<EN);
	_delay_ms(100);
	ctrl &=~ (1<<EN);
    count++;
	value=value/10;*/
	char strNum[40];
	itoa(x,strNum,10);
	lcd_write_str4bit(strNum);
	
}

void lcd_clear4bit(){
		_delay_ms(24);
		lcd_cmd4bit(0x01);
		_delay_ms(24);
		count=0;
		
	
}


