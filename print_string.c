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
	ptr = s;
	if (_strlen(mod))
	{
		free(mod);
	}
	len = 0;
	if (s != NULL)
	{
		while (*ptr)
		{
			_putchar(*ptr);
			ptr++;
			len++;
		}
	}
	else
	{
		exit(139);
	}
	return (len);
}
