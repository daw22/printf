#include "main.h"

/**
 * print_octal - Prints the octal form of a number arg
 * @ap: The argument pointer pointing to the number to be printed in octal
 * @mods: The modifiers given in the format string of _printf
 *
 * Return: The number of chars printed
 */
int print_octal(va_list ap, char *mods)
{
	int num;
	unsigned int i, len;
	char octal_digits[] = "01234567";
	char *octal;

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
		return (print_neg_octal(-1 * num));
	}
	octal = malloc(sizeof(char) * 1);
	if (octal != NULL)
	{
		while (num > 0)
		{
			octal[i] = octal_digits[num % 8];
			num /= 8;
			i++;
			len++;
			octal = _realloc(octal, i, i + 1);
		}
		octal[i] = '\0';
		octal = reverse_string(octal);
		for (i = 0; i < len; i++)
		{
			_putchar(octal[i]);
		}
	}
	free(octal);
	return (len);
}
