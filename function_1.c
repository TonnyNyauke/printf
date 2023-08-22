#include "main.h"

/**
 * print_int - Converts and prints an integer value
 * @types: List of arguments containing the integer to print
 * @buffer: Buffer to store the formatted output
 * @flags: Formatting flags
 * @width: Minimum width for formatting
 * @precision: Precision for formatting
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Converts and prints an integer as binary
 * @types: Variadic arguments list
 * @buffer: Buffer for output (unused)
 * @flags: Flags for formatting (unused)
 * @width: Width for formatting (unused)
 * @precision: Precision for formatting (unused)
 * @size: Size specifier (unused)
 *
 * Return: Number of characters printed
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	/* Convert the integer n to binary representation */
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	/* Print the binary representation */
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
