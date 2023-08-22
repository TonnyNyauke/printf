#include "main.h"

/**
 * print_buffer - Writes the contents of the buffer to the standard output.
 * @buffer: The buffer containing characters to be printed.
 * @buffer_index: A pointer to the current index in the buffer.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}

/**
 * _printf - Custom implementation of printf function.
 * @format: The format string.
 * @...: Additional arguments depending on format.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printd = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);

			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printd = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printd == -1)
				return (-1);
			printed_chars += printd;
		}
	}

	print_buffer(buffer, &buffer_index);
	va_end(list);
	return (printed_chars);
}
