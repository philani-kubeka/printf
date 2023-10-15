#include "main.h"

void output_buffer(char buffer[], int *buffer_index);

/**
 * _printf - function that produces output according to a format.
 *
 * @format: character
 * @...: number of arguments
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int k, output, char_output;
	int flag, size, width, buffer_index, precision;
	va_list ap;
	char buffer[BUFFER_SIZE];

	output = 0;
	char_output = 0;
	buffer_index = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buffer_index++] = format[k];

			if (buffer_index == BUFFER_SIZE)
				output_buffer(buffer, &buffer_index);
			char_output++;
		}
		else
		{
			output_buffer(buffer, &buffer_index);
			flag = get_flag(format, &k);
			size = get_size(format, &k);
			width = get_width(format, &k, ap);
			precision = get_precision(format, &i, ap);
			++k;

			output = handle_output(format, &k, ap, buffer, flag,
					width, precision, size);

			if (output == -1)
				return (-1);
			char_output += output;
		}
	}
	output_buffer(buffer, &buffer_index);

	va_end(ap);

	return (char_output);
}

/**
 * output_buffer - prints buffer if available
 *
 * @buffer: character array
 * @buffer_index: index
 */
void output_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
