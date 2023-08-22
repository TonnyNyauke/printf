#include "main.h"

/**
 * get_size - Calculate the size modifier for formatting.
 * @format: The format string to analyze.
 * @i: A pointer to the current index in the format string.
 *
 * Return: The calculated size modifier value.
 */
int get_size(const char *format, int *i)
{
	int current_index = *i + 1;
	int size = 0;

	if (format[current_index] == 'l')
		size = S_LONG;
	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_index - 1;
	else
		*i = current_index;
	return (size);
}
