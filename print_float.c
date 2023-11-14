#include "main.h"

/**
 * print_float - Prints a float arg to stdout
 * @ap: The argument pointer pointing to the float to print
 * @mods: The modifiers in the format specifier string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: The number of bytes printed
 */
int print_float(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	int deci_digits = 6;
	int n;
	int digits;
	unsigned int num;
	int i;
	unsigned int sign;
	int curr_digit;
	unsigned int point;

	n = (va_arg(ap, double) * calc_power(10, deci_digits + 1) + 5) / 10;
	mods = mods;
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
	point = 0;
	if (deci_digits > 0)
	{
		point++;
	}
	digits = get_digits(num);
	for (i = digits - 1; i >= 0; i--)
	{
		if (i == deci_digits - 1)
		{
			add_to_buffer('.', buffer, len_ptr);
		}
		curr_digit = (num / calc_power(10, i)) % 10;
		add_to_buffer('0' + curr_digit, buffer, len_ptr);
	}
	return (digits + sign + point);
}
