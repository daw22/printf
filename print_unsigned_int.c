#include "main.h"

/**
 * print_unsigned_int - implementation of 'u' conversion specifier
 * @ap: va_list
 * @mods: modfiers
 *
 * Return: number of characters printed
 */
int print_unsigned_int(va_list ap, char *mods)
{
	unsigned int n, tmp;
	int i, len, digit;

	n = va_arg(ap, int);
	mods = mods;
	len = 1;
	tmp = n;
	while (tmp / 10)
	{
		len++;
		tmp /= 10;
	}

	for (i = len - 1; i >= 0 ; i--)
	{
		digit = n / calc_power(10, i);
		_putchar(digit + '0');
		n -= digit * calc_power(10, i);
	}

	return (len);
}
