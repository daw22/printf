#include "main.h"

/**
 * print_nil - prints (nil)
 * Return: 5
 */
int print_nil(char *buffer, int *len_ptr)
{
	char *p = "(nil)";

	while (*p)
	{
		add_to_buffer(*p, buffer, len_ptr);
		p++;
	}
	return (5);
}
/**
 * print_pointer - prints memory address in hexadeciaml
 * @ap: va_list
 * @mods: format modifiers
 *
 * Return: number of characters printed
 */
int print_pointer(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	int i, len = 1;
	char *hex, *p;
	long int num, tmp;
	void *add;

	mods = mods;
	add = va_arg(ap, void *);
	if (add == NULL)
	{
		return (print_nil());
	}
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
		add_to_buffer(*p, buffer, len_ptr);
		p++;
	}
	free(hex);
	return (len + 2);
}
