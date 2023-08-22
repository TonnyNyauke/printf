#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_string - Prints a string argument.
 * @types: List of arguments containing the string to be printed.
 * @buffer: Unused buffer array.
 * @flags: Formatting flags (unused in this function).
 * @width: Minimum width of the printed field.
 * @precision: Maximum number of characters to print.
 * @size: Size specifier (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
	}
	if (precision >= 6)
		str = "      ";
	}

	while (str[length] != '\0')
		length++;

		if (precision >= 0 && precision < length)
			length = precision;

		if (width > length)
		{
			if (flags & F_MINUS)
			{
				write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
			else
			{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
	}

	return (write(1, str, length));
}
