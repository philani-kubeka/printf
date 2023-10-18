#include "main.h"

/**
 * lowercase_hexadecimal - writes lowercase hexadecimals to console
 * @args: variable of va_list, used to store Arguments passed
 * @number: value passed as argument
 * Return: Lenght of value, after being converted to string
*/
int lowercase_hexadecimal(__attribute__((unused))va_list args, int number)
{
	char string[64];
	int length;

	sprintf(string, "%x", number);
	length = _strlen(string);
	return (write(1, string, length));
}
