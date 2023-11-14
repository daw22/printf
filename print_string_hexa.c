#include "main.h"

/**
 * print_string_hexa - prints string with non-printable chars as \x + their hexa
 * @ap: va_list
 * @mod: modifiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of chars printed
 */
int print_string_hexa(va_list ap, char *mod, char *buffer, int *len_ptr)
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
		if ((*ptr > 0 && *ptr < 32) || *ptr > 126)
		{
			len += print_char_hexa(*ptr, buffer, len_ptr);
		}
		else
		{
			len += add_to_buffer(*ptr, buffer, len_ptr);
		}
		ptr++;
	}
	return (len);
}
