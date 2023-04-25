#include "main.h"

/**
 * hex_converter - a function that converts numbers into hexadecimal string.
 * @x: integer.
 * @y: base.
 * @ctr: determine uppercase or lowercase letters.
 * Return: Pointer to the hexadecimal string.
 */

char *hex_converter(unsigned int x, unsigned int *y, char ctr)
{
	char *ptr = NULL;
	int count;
	const char *array;

	if (ctr  == 'x')
		array = "0123456789abcdef";
	else if (ctr == 'X')
		array = "0123456789ABCDEF";
	else
		return (NULL);
	count = count_digits(x, y);
	ptr = malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[count] = '\0';

	while (count--)
	{
		ptr[count] = array[x % *y];
		x /= *y;
	}
	return (ptr);
}
