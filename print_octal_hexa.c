#include "main.h"

/**
 * print_octal_hexa - handles 'i' specifier
 * @ap: va_list
 * @mods: modifiers
 *
 * Return: number of characters printed
 */
int print_octal_hexa(va_list ap, char *mods)
{
	return (print_integer(ap, mods));
}
