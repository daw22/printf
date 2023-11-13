#include "main.h"

/**
 * print_hexa_lower - Prints the hexa form of a number arg
 * @ap: The argument pointer pointing to the number to be printed in hexa
 * @mods: The modifiers given in the format string of _printf
 *
 * Return: The number of chars printed
 */
int print_hexa_lower(va_list ap, char *mods)
{
	int num;
	unsigned int i, len;
	char hexa_digits[] = "0123456789abcdef";
	char *hexa;

	num = va_arg(ap, int);
	mods = mods;
	i = 0;
	len = 0;
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		return (print_neg_hexa(-1 * num, hexa_digits));
	}
	hexa = malloc(sizeof(char) * 1);
	if (hexa != NULL)
	{
		while (num > 0)
		{
			hexa[i] = hexa_digits[num % 16];
			num /= 16;
			i++;
			len++;
			hexa = _realloc(hexa, i, i + 1);
		}
		hexa[i] = '\0';
		hexa = reverse_string(hexa);
		for (i = 0; i < len; i++)
		{
			_putchar(hexa[i]);
		}
		free(hexa);
	}
	return (len);
}
