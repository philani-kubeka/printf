#include "main.h"

/**
 * _printf - prints strings while handling format specifiers to console
 * @format: format string
 * @...: Additional Arguments
 * Return: Lenght of string passed
*/
int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += char_write(args, va_arg(args, int));
					i++;
					break;
				case 's':
					count += write_string(args, va_arg(args, char *));
					i++;
					break;
				case 'i':
				case 'd':
					count += write_integer(args, va_arg(args, int));
					i++;
					break;
				case 'u':
					count += write_unsigned_integer(args, va_arg(args, unsigned int));
					i++;
					break;
				case 'o':
					count += write_octal_integer(args, va_arg(args, unsigned int));
					i++;
					break;
				case 'x':
					count += lowercase_hexadecimal(args, va_arg(args, unsigned int));
					i++;
					break;
				case 'X':
					count += uppercase_hexadecimal(args, va_arg(args, unsigned int));
					i++;
					break;
				case 'b':
					count += write_binary(args, va_arg(args, int));
					i++;
					break;
				case 'p':
					count += address(args, va_arg(args, void *));
					i++;
					break;
				case '%':
					count += _putchar('%');
					i++;
					break;
				default:
					_putchar(format[i]);
					count++;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
