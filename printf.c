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
				length += putchar(va_arg(args, int));
				break;
				case 's':
				length += puts(va_arg(args, char *));
				break;
				default:
				length += putchar('%');
				length += putchar(*format);
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
