#include "main.h"

/**
 * print_rot13_string - Prints a string arg in rot13 encoding
 * @ap: The argument pointer pointing to the string to be printed
 * @mods: The modifiers extracted from the format string
 *
 * Return: The number of bytes printed
 */
int print_rot13_string(va_list ap, char *mods)
{
	int len, i, j;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(ap, char *);

	mods = mods;
	if (s == NULL)
	{
		s = "(ahyy)";
	}
	len = _strlen(s);
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == alpha[j])
			{
				_putchar(rot[j]);
				break;
			}
		}
		if (j == 52)
		{
			_putchar(s[i]);
		}
	}
	return (len);
}
