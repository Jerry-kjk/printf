#include "main.h"

/**
 * count_digits - counts the number of digits.
 * @num: the integer.
 * @base: base of the number.
 * Return: Pointer to the address of string.
 */

int count_digits(unsigned int num, unsigned int *base)
{
	int count = 1;

	while (num >= *base)
	{
		count++;
		num /= *base;
	}
	return (count);
}

/**
 * num_converter - converts numbers into string;
 * @num: the integer.
 * @base: base of the number.
 * Return: pointer to the address of string.
 */

char *num_converter(unsigned int num, unsigned int *base)
{
	int count = count_digits(num, base);
	char *str = malloc((count + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = "0123456789abcdef"[num % *base];
		num /= *base;
	}
	return (str);
}
