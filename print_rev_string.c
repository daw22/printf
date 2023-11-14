#include "main.h"

/**
 * print_rev_string - Prints a string arg in reverse
 * @ap: The argument pointer pointing to the string to be printed
 * @mods: The modifiers extracted from the format string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of bytes printed
 */
int print_rev_string(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	int len, i;
	char *s = va_arg(ap, char *);

	mods = mods;
	if (s == NULL)
	{
		s = ")llun(";
	}
	len = _strlen(s);
	for (i = len - 1; i >= 0; i--)
	{
		add_to_buffer(s[i], buffer, len_ptr);
	}
	return (len);
}
