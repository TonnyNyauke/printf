#include "main.h"

/**
 * get_precision - Calculate the precision value for formatting.
 * @format: The format string to analyze.
 * @i: A pointer to the current index in the format string.
 * @list: The variable argument list containing
 * the arguments after the format string.
 *
 * Return: The calculated precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current_index = *i + 1;
	int precision = -1; /* Precision not allocated */

	if (format[current_index] != '.')
		return (precision);

	precision = 0;
	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_index - 1;

	return (precision);
}

