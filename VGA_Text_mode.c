#include "VGA_Text_mode.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t *terminal_buffer;

/*!
 *  8 bits of char is following code page 437 codepoints:
 *  https://en.wikipedia.org/wiki/Code_page_437 
 * 
 * For Reference about VGA Text Mode: 
 *  https://wikivisually.com/wiki/VGA-compatible_text_mode#endnote_text_buffer_2
 * */

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t)uc | (uint16_t)color << 8;
}

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t *)0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_move_raw(size_t from_raw, size_t to_raw)
{
	size_t from_index = 0;
	size_t to_index = 0;
	for (size_t x = 0; x < VGA_WIDTH; x++)
	{
		from_index = from_raw * VGA_WIDTH + x;
		to_index = to_raw * VGA_WIDTH + x;
		terminal_buffer[to_index] = terminal_buffer[from_index];
	}
}

void terminal_clear_buffer(size_t row)
{
	for (size_t x = 0; x < VGA_WIDTH; x++)
	{
		terminal_buffer[row*VGA_WIDTH + x] = vga_entry(' ', terminal_color);
	}
}
void terminal_putchar(char c)
{
	if (c != '\n')
	{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH)
		{
			terminal_column = 0;
			++terminal_row;
		}
	}
	else
	{
		/*Handle the newline .*/
		terminal_column = 0;
		++terminal_row;
	}
	if (terminal_row > VGA_HEIGHT)
	{
		for (size_t y = 0; y < VGA_HEIGHT; y++)
		{
			terminal_move_raw(y + 1, y);
		}
		terminal_row = terminal_row - 1;
	}
}

void terminal_write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char *data)
{
	terminal_write(data, strlen(data));
}

void terminal_newline()
{
	terminal_writestring("\n");
}