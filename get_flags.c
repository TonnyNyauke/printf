#include "main.h"

/**
 * get_flags - Calculate active flags from format string.
 * @format: The format string to analyze.
 * @i: A pointer to the current index in the format string.
 *
 * Return: The calculated active flags.
 */
int get_flags(const char *format, int *i)
{
	int j, current_index;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
		{
		if (format[current_index] == FLAGS_CHAR[j])
		{
			flags |= FLAGS_ARRAY[j];
			break;
		}
	}
	if (FLAGS_CHAR[j] == '\0')
		break;
	}
	*i = current_index - 1;

	return (flags);
}
