#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _putchar(char character);
int _strlen(const char *string);
int char_write(va_list args, char character);
int write_string(va_list args, char *string);
int write_integer(va_list args, int number);
int write_unsigned_integer(va_list args, unsigned int number);
int write_octal_integer(va_list args, unsigned int number);
int lowercase_hexadecimal(va_list args, int number);
int uppercase_hexadecimal(va_list args, int number);
int write_binary(va_list args, int number);
int address(va_list args, void *addr);

#endif
