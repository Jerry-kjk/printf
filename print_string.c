#include "main.h"

/**
 * rev_string - a functoin that reverses a string.
 * @s: pointer to the string.
 */

void rev_string(char *s, int len)
{
	int x;
	char tmp;

	len--;
	for (x = 0; x <= len; x++, len--)
	{
		tmp = s[x];
		s[x] = s[len];
		s[len] = tmp;
	}
}

/**
 * rot13 - a function that encodes a string.
 * @s: pointer to be encoded.
 * Return: pointer.
 */

char *rot13(char *s, int len)
{
	int i, j;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < len; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (s[i] == alpha[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
	}
	return (s);
}

/**
 * print_string - a function that prints a string.
 * @arg: argument.
 * @len: the length counter.
 * @modif: modifier flags.
 * Return: number of characters.
 */

int print_string(va_list arg, int *len, char modif)
{
	int i, length = 0;
	char *string = NULL;
	char *ptr = NULL;

	string = va_arg(arg, char *);

	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (*len + 6);
	}

	for (i = 0; string[i]; i++)
		length++;

	ptr = malloc(length * sizeof(char));
	if (ptr == NULL)
		return (-1);
	for (i = 0; i < length; i++)
		ptr[i] = string[i];

	if (modif == 'r')
		rev_string(ptr, length);
	else if (modif == 'R')
		rot13(ptr, length);

	for (i = 0; ptr[i]; i++)
	{
		_putchar(ptr[i]);
	}

	*len += i;
	free(ptr);
	return (*len);
}
