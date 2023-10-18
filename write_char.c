#include "main.h"

/**
 * char_write - writes characters
 * @args: variable of va_list, used to store Arguments passed
 * @character: Character passed as argument
 * Return: 1 on sucess
*/
int char_write(__attribute__((unused))va_list args, char character)
{
	return (write(1, &character, 1));
}
