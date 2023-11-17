#include "main.h"

/**
 * print_hexa_lower - Prints the hexa form of a number arg
 * @ap: The argument pointer pointing to the number to be printed in hexa
 * @mods: The modifiers given in the format string of _printf
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of chars printed
 */
int print_hexa_lower(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	int num = va_arg(ap, int), hash = 0;
	unsigned int i = 0, len = 0;
	char hexa_digits[] = "0123456789abcdef";
	char *hexa;

	if (_strchr(mods, '#'))
	{
		add_to_buffer('0', buffer, len_ptr);
		add_to_buffer('x', buffer, len_ptr);
		hash += 2;
		free(mods);
	}
	if (num == 0)
		return (add_to_buffer('0', buffer, len_ptr));
	if (num < 0)
		return (hash +
			print_neg_hexa(-1 * num, hexa_digits, buffer, len_ptr));
	hexa = malloc(sizeof(char) * 1);
	if (hexa != NULL)
	{
		while (num > 0)
		{
			hexa[i] = hexa_digits[num % 16];
			num /= 16;
			i++;
			len++;
			hexa = _realloc(hexa, i, i + 1);
		}
		hexa[i] = '\0';
		hexa = reverse_string(hexa);
		for (i = 0; i < len; i++)
		{
			add_to_buffer(hexa[i], buffer, len_ptr);
		}
		free(hexa);
	}
	return (len + hash);
}
