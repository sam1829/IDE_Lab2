/*
Title: UART Driver
Description: Main function to put characters 
Authors: Susan Margevich
Date: 1/23/2019

Some of the contents are obtained by the courtesy of the material provided by Freescale Semiconductor, Inc.
Copyright (c) 2014, Freescale Semiconductor, Inc.
All rights reserved.
*/

#include<stdio.h>
#include "MK64F12.h"
#define BAUD_RATE 9600      //default baud rate 
#define SYS_CLOCK 20485760 //default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)
#define CHAR_COUNT 37      //change this to modify the max. permissible length of a sentence

void put(char *ptr_str);
void uart_init(void);
uint8_t uart_getchar(void);
void uart_putchar(char ch);

int main()
{
	
	uart_init();
	
	char char_buffer[CHAR_COUNT] = {0};
	int i = 0;
	
	put("Please enter your characters below: \r\n");
	
	while(1)
	{
		char_buffer[i] = uart_getchar();
		if(i < CHAR_COUNT)
		{
			uart_putchar(char_buffer[i]);
			i++;
		}
		else if(char_buffer[i] == '\r')
		{
			put("\n\r");
			i = 0;
		}
	}	
}  

void put(char *ptr_str)
{
	while(*ptr_str)
		uart_putchar(*ptr_str++);
}
