#include "main.h"

/**
 * print_rot13_string - Prints a string arg in rot13 encoding
 * @ap: The argument pointer pointing to the string to be printed
 * @mods: The modifiers extracted from the format string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of bytes printed
 */
int print_rot13_string(va_list ap, char *mods, char *buffer, int *len_ptr)
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
				add_to_buffer(rot[j], buffer, len_ptr);
				break;
			}
		}
		if (j == 52)
		{
			add_to_buffer(s[i], buffer, len_ptr);
		}
	}
	return (len);
}
