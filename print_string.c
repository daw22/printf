#include "main.h"

/**
 * print_string - prints string
 * @ap: va_list
 * @mod: modifiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of chars printed
 */
int print_string(va_list ap, char *mod, char *buffer, int *len_ptr)
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
		add_to_buffer(*ptr, buffer, len_ptr);
		ptr++;
		len++;
	}
	return (len);
}
