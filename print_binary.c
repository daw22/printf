#include "main.h"

/**
 * print_binary - convets unsigned it to binary and print it
 * @ap: va_list
 * @mods: modifier string
 *
 * Return: number of printed charactres
 */
int print_binary(va_list ap, char *mods)
{
	unsigned int n, i, tmp, len;
	char *str;
	/** until handling modifiers **/
	char c = mods[0];

	c = c;
	/** **/

	n = va_arg(ap, unsigned int);
	tmp = n;
	len = 1;
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
	}

	for (i = 0; i < len; i++)
		_putchar(str[i]);
	free(str);
	return (len);
}
