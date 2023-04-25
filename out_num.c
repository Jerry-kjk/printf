#include "main.h"

/**
 * out_num - function that prints a number.
 * @ptr: number in char array format.
 * @count: number of indexes.
 * @length: variable that holds the number.
 * Return: number of characters.
 */

int out_num(char *ptr, int count, int *length)
{
	while (count--)
	{
		_putchar(*ptr++ + '0');
		(*length)++;
	}
	return (*length);
}
