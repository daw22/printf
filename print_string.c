#include "main.h"

/**
 * print_string - prints string
 * @ap: va_list
 * @mod: modifiers
 *
 * Return: number of chars printed
 */
int print_string(va_list ap, char *mod)
{
	char *s;
	char *ptr;
	int len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	ptr = s;
	if (_strlen(mod))
	{
		free(mod);
	}
	len = 0;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
		len++;
	}
	return (len);
}
