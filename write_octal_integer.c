#include "main.h"

/**
 * write_octal_integer - writes octal integer to console
 * @args: variable of va_list, used to store Arguments passed
 * @number: value passed as argument
 * Return: Lenght of value, after being converted to string
*/
int write_octal_integer(__attribute__((unused))va_list args, unsigned int number)
{
	char string[64];
	int length;

	length = sprintf(string, "%o", number);
	return (write(1, string, length));
}
