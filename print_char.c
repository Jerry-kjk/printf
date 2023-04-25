#include "main.h"

/**
 * print_char - a function that prints a single character.
 * @args: list of arguments.
 * @length: pointer to the total number of characters.
 * Return: number of characters.
 */

int print_char(va_list args, int *length)
{
	char c = va_arg(args, int);

	_putchar(c);
	*length += 1;
	return (1);
}
