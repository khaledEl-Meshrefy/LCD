/*
 * functions.h
 *
 * Created: 02/10/2020 10:50:49 PM
 *  Author: Khalid Elmeshrefy
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_





#endif /* FUNCTIONS_H_ */
/*
 * functions.h
 *
 * Created: 02/10/2020 10:01:27 PM
 *  Author: Khalid Elmeshrefy
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_





#endif /* FUNCTIONS_H_ */
#include <stdio.h>
#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define  RS 3
#define  EN 2
#define  ctrl PORTC
#define  LCD_DATA PORTC
#define  ctrl_dir DDRC
#define  lcd_write_dir DDRC


void lcd_cmd(char);
void lcd_cmd4bit(char);
void lcd_init(int);//initiate driver
void lcd_clear();
void lcd_clear4bit();
void lcd_write(char);
void lcd_write4bit(char);
void lcd_goto_xy(int , int );
void lcd_goto_xy_noshift(int , int );
void lcd_write_str( char [] );
void lcd_write_str4bit (char []);
void lcd_write_num( unsigned int);
void lcd_write_num4bit( unsigned int );
