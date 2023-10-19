#include "main.h"

/**
 * address - writes address of variables to console
 * @args: variable of va_list, used to store Arguments passed
 * @addr: Address
 * Return: lenght of address
 */
int address(__attribute__((unused))va_list args, void *addr)
{
	char string[32];
	int length;

	length = sprintf(string, "%p", addr);
	return (write(1, string, length));
}
