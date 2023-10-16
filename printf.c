#include "main.h"

/**
 * _printf - function that produces output according to format
 *
 * @format: format character
 * @...: arguments
 * Return: character printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char buffer[2], *str;
	va_list ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		switch (*format)
		{
			case '%':
				format++;
				switch (*format)
				{
					case 'c':
						buffer[0] = va_arg(ap, int);
						write(1, buffer, 1);
						counter++;
						break;
					case 's':
						str = va_arg(ap, char *);
						str = (str != NULL) ? str : "(null)";
						write(1, str, strlen(str));
						counter += strlen(str);
						break;
					case '%':
						write(1, "%", 1);
						counter++;
						break;
					default:
						write(1, "%", 1);
						write(1, format, 1);
						counter += 2;
				}
				break;
			default:
				write(1, format, 1);
				counter++;
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
