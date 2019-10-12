
#ifndef __STRING_H__
#define __STRING_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

extern size_t strlen(const char* str);
extern char *strcat(char *dest, const char *src);
extern char *strncat(char *dest, const char *src, size_t n);
extern char* itoa(int num, char* str, int base);
extern void reverseStr(char str[], int length);
extern void strClear(char* src);


#endif /*__STRING_H__*/