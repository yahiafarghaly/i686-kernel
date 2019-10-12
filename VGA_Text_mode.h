
#ifndef __VGA_TEXT_MODE_H__
#define __VGA_TEXT_MODE_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "string.h"

/* Hardware text mode color constants. */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

extern void terminal_initialize(void);
extern void terminal_writestring(const char* data);
extern void terminal_setcolor(uint8_t color);
extern void terminal_putchar(char c);
extern void terminal_newline();

#endif /*__VGA_TEXT_MODE_H__*/