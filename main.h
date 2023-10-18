#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);

int write_char(int fd, char c);
int write_str(int fd, const char *str);
int write_int(int fd, int num);
int binary(int fd, int number);

#endif
