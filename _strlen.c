#include "main.h"

/**
 * _strlen - counts strings
 * @string: string
 * Return: Lenght of string
*/
int _strlen(const char *string)
{
	int length;

	while (string[length] != '\0')
		length++;
	return (length);
}
