#include "main.h"

/**
 * write_binary - converts Argument to binary and writes binary to console
 * @args: variable of va_list, used to store Arguments passed
 * @number: value passed as argument
 * Return: Lenght of value, after being converted to string
*/
int write_binary(__attribute__((unused))va_list args, int number)
{
	int index = 0, j, i;
	char string[33], temp;
	int num = abs(number);

	if (num == 0)
		string[0] = '0';
	do {
		string[index++] = num % 2 + '0';
		num /= 2;
	} while (num > 0);
	string[index] = '\0';
	for (i = index - 1; j <= i; i--, j++)
	{
		temp = string[j];
		string[j] = string[i];
		string[i] = temp;
	}
	return (write_string(args, string));
}
