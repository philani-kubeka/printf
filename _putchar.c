#include "main.h"

/**
 * _putchar - prints charcters
 * @character: character
 * Return: 1 on sucess
*/
int _putchar(char character)
{
	char string[2];

	string[0] = character;
	return (write(1, string, 1));
}
