#include "main.h"

/**
 * is_printable - a function that evaluates if char is printable.
 * @c: char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - a function that appends ascci in
 * hexadecimal code to buffer.
 * @buffer: Array of characters.
 * @i: Index.
 * @ascii_code: ASSCI CODE.
 * Return: 3 (success).
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - a function that verifies if a char is a digit.
 * @c: Char to be evaluated.
 * Return: 1 if c is a digit, 0 otherwise.
 */

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * convert_size_number - a function that casts a number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type.
 * Return: Casted value.
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsgnd - a function that casts a number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type.
 * Return: Casted value.
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
