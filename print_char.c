#include "main.h"

/**
 * print_char - prints a single character
 * @ap: va_list
 * @mod: modifiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: 1 Always
 */
int print_char(va_list ap, char *mod, char *buffer, int *len_ptr)
{
	char c;

	c = va_arg(ap, int);
	if (_strlen(mod))
	{
		free(mod);
	}
	return (add_to_buffer(c, buffer, len_ptr));
}
