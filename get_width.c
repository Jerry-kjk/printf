#include "main.h"

/**
 * get_width - a function that calculates the width for printing.
 * @format: Formatted string.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int curr_i;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (width);
}
