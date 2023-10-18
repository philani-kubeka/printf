#include "main.h"

/**
 * _putchar - prints charcters
 * @character: character
 * Return: 1 on sucess
*/
int _putchar(char character)
{
	return (write(1, &character, 1));
}
