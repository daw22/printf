#include "main.h"

/**
 * print_short_integer - Prints a short using only _putchar
 * @ap: The argument pointer pointing to the int to be printed
 * @mods: The modifiers in the format string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of chars printed (including minus sign if there is one)
 */
int print_short_integer(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	short n;
	int digits;
	unsigned int num;
	int i;
	unsigned int sign;
	int curr_digit;
	void *p;

	n = va_arg(ap, int);
	p = (void *)mods;
	p = p;
	free(p);
	sign = 0;
	if (n < 0)
	{
		add_to_buffer('-', buffer, len_ptr);
		sign += 1;
		num = n * -1;
	}
	else
	{
		num = +n;
	}
	digits = get_digits(num);
	for (i = digits - 1; i >= 0; i--)
	{
		curr_digit = (num / calc_power(10, i)) % 10;
		add_to_buffer('0' + curr_digit, buffer, len_ptr);
	}
	return (digits + sign);
}
