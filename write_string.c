#include "main.h"

/**
 * write_string - writes string to console
 * @args: variable of va_list, used to store Arguments passed
 * @string: string passed as Argument
 * Return: lenght of string on sucess
*/
int write_string(__attribute__((unused))va_list args, char *string)
{
	int length = _strlen(string);

	return (write(1, string, length));
}
