#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: string that is passed.
 * Return: length of string.
 */

int _printf(const char *format, ...)
{
	int length = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					length++;
					break;
				case 's':
					length += fputs(va_arg(args, char *), stdout);
					break;
				default:
					length += 2;
					break;
			}
		}
		else
		{
			length += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (length);
}
