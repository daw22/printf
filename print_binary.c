#include "main.h"

/**
 * print_binary - convets unsigned it to binary and print it
 * @ap: va_list
 * @mods: modifier string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of printed charactres
 */
int print_binary(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	unsigned int n, i, tmp, len, hash = 0;
	char *str;

	n = va_arg(ap, unsigned int);
	tmp = n;
	len = 1;
	if (_strchr(mods, '#'))
	{
		add_to_buffer('0', buffer, len_ptr);
		add_to_buffer('b', buffer, len_ptr);
		hash += 2;
		free(mods);
	}
	if (n == 0)
	{
		add_to_buffer('0', buffer, len_ptr);
		return (len);
	}
	while (tmp / 2)
	{
		len++;
		tmp /= 2;
	}

	str = malloc(sizeof(char) * len + 1);
	if (str)
	{
		for (i = len - 1; n > 0; i--)
		{
			str[i] = (n % 2) + '0';
			n = n / 2;
		}
		for (i = 0; i < len; i++)
			add_to_buffer(str[i], buffer, len_ptr);
	}
	free(str);
	return (len + hash);
}
