#include "main.h"

/**
 * write_integer - writes integer to console
 * @args: variable of va_list, used to store Arguments passed
 * @number: value passed as argument
 * Return: Lenght of value, after being converted to string
*/
int write_integer(__attribute__((unused))va_list args, int number)
{
	char string[20];
	int length;

	length = sprintf(string, "%i", number);
	return (write(1, string, length));
}
