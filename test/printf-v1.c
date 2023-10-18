#include "main.h"

/**
 * write_char - outputs character
 *
 * @fd: fd
 * @c: character
 *
 * Return: char
 */
int write_char(int fd, char c)
{
	char buffer[2];

	buffer[0] = c;
	return (write(fd, buffer, 1));
}

/**
 * write_str - outputs string
 *
 * @fd: fd
 * @str: string
 *
 * Return: string
 */
int write_str(int fd, const char *str)
{
	return (write(fd, str, strlen(str)));
}

/**
 * write_int - outputs int
 *
 * @fd: fd
 * @num: number
 *
 * Return: integer
 */
int write_int(int fd, int num)
{
	char buffer[20];
	int len;

	len = sprintf(buffer, "%d", num);
	return (write(fd, buffer, len));
}

/**
 * binary - converts number to binary and writes it to std input
 * @fd: file descriptor
 * @number: number
 * Return: lenght of string
*/
int binary(int fd, int number)
{
	int index = 0, i, significantBits;
	char buffer[33];  /*Assuming a 32-bit integer*/

	if (number == 0)
	{
		for (i = 0; i < 32; i++)
			buffer[index++] = '0';
	}
	else
	{
		if (number < 0)
		{
			/*Invert the bits*/
			number = ~number;
			/*Add 1*/
			number++;
		}
		for (i = 31; i >= 0; i--)
		{
			if ((number >> i) & i)
			{
				significantBits = i + 1;
				break;
			}
		}
		for (i = significantBits; i >= 0; i--)
		buffer[index++] = ((number >> i) & 1) + '0';
	}
	buffer[index] = '\0';
	return write(fd, buffer, index);
}

/**
 * _printf - function that produces output according to format
 *
 * @format: format character
 * @...: arguments
 * Return: character printed
 */
int _printf(const char *format, ...)
{
	int counter = 0, num;
	char *str;
	va_list ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			counter += write_char(1, *format);
		else
		{
			format++;
				switch (*format)
				{
					case 'c':
						counter += write_char(1,  va_arg(ap, int));
						break;
					case 's':
						str = va_arg(ap, char *);
						str = (str != NULL) ? str : "(null)";
						counter += write_str(1, str);
						break;
					case '%':
						counter += write_char(1, '%');
						break;
					case 'd':
					case 'i':
							num = va_arg(ap, int);
							counter += write_int(1, num);
							break;
					case 'b':
							num = va_arg(ap, int);
							counter += binary(1, num);
							break;
					default:
						counter += write_char(1, '%');
						counter += write_char(1, *format);
				}
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
