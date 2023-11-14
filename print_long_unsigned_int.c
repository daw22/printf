#include <stdio.h>
#include "main.h"

/**
 * print_long_unsigned_int - implementation of 'u' conversion specifier
 * @ap: va_list
 * @mods: modfiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of characters printed
 */
int print_long_unsigned_int(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	unsigned long int n, tmp;
	int i, len, digit;

	n = va_arg(ap, unsigned long int);
	mods = mods;
	free(mods);
	len = 1;
	tmp = n;
	while (tmp / 10)
	{
		len++;
		tmp /= 10;
	}

	for (i = len - 1; i >= 0 ; i--)
	{
		digit = n / calc_long_power(10, i);
		add_to_buffer(digit + '0', buffer, len_ptr);
		n -= digit * calc_long_power(10, i);
	}

	return (len);
}
