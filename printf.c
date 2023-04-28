#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function that produces output according to a format.
 * @format: formatting.
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	int j, printed = 0, chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			j++;
			printed = handle_print(format, &j, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (chars);
}

/**
 * print_buffer - a function that prints buffer.
 * @buffer: array of characters.
 * @buff_ind: index to add character.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
