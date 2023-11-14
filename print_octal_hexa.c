#include "main.h"

/**
 * print_octal_hexa - handles 'i' specifier
 * @ap: va_list
 * @mods: modifiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of characters printed
 */
int print_octal_hexa(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	return (print_integer(ap, mods, buffer, len_ptr));
}
