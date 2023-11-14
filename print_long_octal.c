#include "main.h"

/**
 * print_long_octal - Prints the octal form of a number arg
 * @ap: The argument pointer pointing to the number to be printed in octal
 * @mods: The modifiers given in the format string of _printf
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of chars printed
 */
int print_long_octal(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	long int num;
	unsigned int i, len;
	char octal_digits[] = "01234567";
	char *octal;

	num = va_arg(ap, long);
	mods = mods;
	free(mods);
	i = 0;
	len = 0;
	if (num == 0)
	{
		add_to_buffer('0', buffer, len_ptr);
		return (1);
	}
	if (num < 0)
	{
		return (print_long_neg_octal(-1 * num, buffer, len_ptr));
	}
	octal = malloc(sizeof(char) * 1);
	if (octal != NULL)
	{
		while (num > 0)
		{
			octal[i] = octal_digits[num % 8];
			num /= 8;
			i++;
			len++;
			octal = _realloc(octal, i, i + 1);
		}
		octal[i] = '\0';
		octal = reverse_string(octal);
		for (i = 0; i < len; i++)
		{
			add_to_buffer(octal[i], buffer, len_ptr);
		}
	}
	free(octal);
	return (len);
}
