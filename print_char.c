#include "main.h"

/**
 * print_char - prints a single character
 * @ap: va_list
 * @mod: modifiers
 *
 * Return: 1 Always
 */
int print_char(va_list ap, char *mod)
{
	char c;

	c = va_arg(ap, int);
	if (_strlen(mod))
	{
		free(mod);
	}
	_putchar(c);
	return (1);
}
