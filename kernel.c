#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "string.h"
#include "VGA_Text_mode.h"
 
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
	#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
	#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	terminal_writestring("Passed#1Word !\n");
	terminal_writestring("Passed#2Word !\n");
	terminal_writestring("Passed#3Word !\n");
	terminal_writestring("Passed#4Word !\n");
	terminal_writestring("Passed#5Word !\n");

	for(int i = 0; i <5; i++) // Write in Height
	{
		for(char j = 0; j < 80;j++) // Write in width
		{
			terminal_putchar('z');
		}
	}
	
	for(int i = 0; i <5; i++)
	{
		for(char j = 0; j < 80;j++)
		{
			terminal_putchar('B');
		}
	}
	
	for(int i = 0; i <5; i++)
	{
		terminal_writestring("Cool !\n");
	}

	for(int i = 0; i <5; i++) // [BUG] @ i < 6 
	{
		for(char j = 0; j < 80;j++)
		{
			terminal_putchar('C');
		}
	}
	terminal_newline();
	terminal_writestring("Passed#6 !\n");
	for(int i = 0; i <5; i++)
	{
		for(char j = 0; j < 80;j++)
		{
			terminal_putchar('D');
		}
	}
	terminal_newline(); // [BUG]
}	
