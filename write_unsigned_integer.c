#include "main.h"

/**
 * write_unsigned_integer - writes unsigned integer to console
 * @args: variable of va_list, used to store Arguments passed
 * @number: value passed as argument
 * Return: Lenght of value, after being converted to string
*/
int write_unsigned_integer(__attribute__((unused))va_list args, unsigned int number)
{
	char string[64];
	int length;

	sprintf(string, "%u", number);
	length = _strlen(string);
	return (write(1, string, length));
}
