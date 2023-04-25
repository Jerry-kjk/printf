#include "main.h"

/**
 * switch_num - function that holds the switch statement.
 * @arg: va_list argument.
 * @symbol: the letter.
 * @length: variable that holds the number of char printed.
 * Return: number of characters.
 */

int switch_num(va_list arg, char symbol, int length)
{
	switch (symbol)
	{
		case 'b':
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			print_num(arg, &length, symbol);
			break;
		default:
			putchar('%');
			putchar(symbol);
			length += 2;
	}
	return (length);
}

/**
 * switch_char - function that holds the switch statement.
 * @arg: va_list argument.
 * @symbol: the letter.
 * @length: variable that holds the number of char printed.
 * Return: number of characters.
 */

int switch_char(va_list arg, char symbol, int length)
{
	switch (symbol)
	{
		case 'c':
		case 's':
		case 'r':
		case 'R':
			print_string(arg, &length, symbol);
			break;
		case '%':
			putchar('%');
			length++;
			break;
		default:
			putchar('%');
			putchar(symbol);
			length += 2;
	}
	return (length);
}
