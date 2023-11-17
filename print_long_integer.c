#include "main.h"

/**
 * print_long_integer - Prints an integer using only _putchar
 * @ap: The argument pointer pointing to the int to be printed
 * @mods: The modifiers in the format string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of chars printed (including minus sign if there is one)
 */
int print_long_integer(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	long int n;
	int digits;
	unsigned long num;
	int i;
	unsigned int sign;
	int curr_digit;
	void *p;

	n = va_arg(ap, long);
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
	digits = get_long_digits(num);
	for (i = digits - 1; i >= 0; i--)
	{
		curr_digit = (num / calc_long_power(10, i)) % 10;
		add_to_buffer('0' + curr_digit, buffer, len_ptr);
	}
	return (digits + sign);
}
