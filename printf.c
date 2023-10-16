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
	va_list ap;
	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			
			if (*format == 'c')
			{
				int c = va_arg(ap, int);
				write(1, &c, 1);
				counter++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(ap, char *);
				if (s != NULL)
				{
					while (*s != '\0')
					{
						write(1, s, 1);
						s++;
						counter++;
					}
				}
				else
				{
					write(1, "(null)", 6);
					counter += 6;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);
				char numStr[12];
				snprintf(numStr, sizeof(numStr), "%d", num);
				write(1, numStr, strlen(numStr));
				counter += strlen(numStr);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				counter++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				counter += 2;
			}
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
