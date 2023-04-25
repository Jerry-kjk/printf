#include "main.h"

/**
 * bnten - function to handle numbers of base not 10.
 * @num: number.
 * @ctr: symbol.
 * @base: base of the number.
 * Return: pointer to the converted number string.
 */

char *bnten(int num, char ctr, unsigned int *base)
{
	struct 
	{
		char ctr;
		unsigned int base;
	}
	conversions[] =
	{
		{'u', 10},
		{'o', 8},
		{'b', 2},
		{'x', 16},
		{'X', 16}
	};
	char *ptr = NULL;
	unsigned int i;

	for (i = 0; i < sizeof(conversions) / sizeof(conversions[0]); i++)
	{
		if (ctr == conversions[i].ctr)
		{
			*base = conversions[i].base;
			break;
		}
	}
	if (i == sizeof(conversions) / sizeof(conversions[0]))
	{
		return NULL;
	}
	ptr = num_converter(num, base);
	return (ptr);
}

/**
 * print_num - afunction that print numbers.
 * @arg: argument.
 * @length: length.
 * @ctr: character of the format specifier.
 * Return: length.
 */

int print_num(va_list arg, int *length, char ctr)
{
	int num, count;
	unsigned int base = 10;
	char *ptr = NULL;

	switch (ctr)
	{
		case 'd':
		case 'i':
			num = va_arg(arg, int);
			if (num < 0)
			{
				num *= -1;
				_putchar('-');
				*length += 1;
			}
			ptr = num_converter(num, &base);
			break;
		case 'u':
		case 'o':
		case 'b':
		case 'x':
		case 'X':
			num = va_arg(arg, unsigned int);
			ptr = bnten(num, ctr, &base);
			break;
		default:
			return -1;
	}
	if (!ptr)
		return -1;
	count = count_digits(num, &base);
	out_num(ptr, count, length);
	return (*length);
}
