#include "main.h"

/**
 * print_pointer - prints memory address in hexadeciaml
 * @ap: va_list
 * @mods: format modifiers
 *
 * Return: number of characters printed
 */
int print_pointer(va_list ap, char *mods)
{
	int i, len = 1;
	char *hex, *p;
	long int num, tmp;
	void *add;

	mods = mods;
	add = va_arg(ap, void *);
	num = (long int) add;
	tmp = num;
	while (tmp / 16)
	{
		len++;
		tmp /= 16;
	}
	hex = malloc(sizeof(char) * len + 3);
	if (hex != NULL)
	{
		hex[0] = '0';
		hex[1] = 'x';
		for (i = len + 1; i > 1; i--)
		{
			int r = num % 16;
			char c = (r < 10) ? ('0' + r) : ('a' + r - 10);

			hex[i] = c;
			num /= 16;
		}
	}
	p = hex;
	while (*p)
	{
		_putchar(*p);
		p++;
	}
	free(hex);
	return (len + 2);
}
