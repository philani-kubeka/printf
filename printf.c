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
 * _printf - function that produces output according to format
 *
 * @format: format character
 * @...: arguments
 * Return: character printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char *str;
	va_list ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			counter += write_char(1, *format);
		}
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
