#include "string.h"

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

char *strcat(char *dest, const char *src)
{
	return strncat(dest,src,strlen(src));
}

char * strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}

static void swap(char* a, char* b)
{
 char temp = *a;
 *a = *b;
 *b = temp;
}

/* A utility function to reverse a string  */
void reverseStr(char str[], int length) 
{ 
    int start = 0; 
    int end = (str[length - 1] == '\n') ? length - 2 : length - 1;
    while (start < end) 
    { 
        swap(&str[start], &str[end]); 
        start++; 
        end--; 
    } 
} 

// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverseStr(str, i); 
  
    return str; 
}

void strClear(char* src)
{
	for(size_t i = 0; i < strlen(src);i++)
		src[i] = '\0';
}