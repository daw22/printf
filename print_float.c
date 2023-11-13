#include "main.h"

/**
 * print_float - Prints a float arg to stdout
 * @ap: The argument pointer pointing to the float to print
 * @mods: The modifiers in the format specifier string
 *
 * Return: The number of bytes printed
 */
int print_float(va_list ap, char *mods)
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
		_putchar('-');
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
			_putchar('.');
		}
		curr_digit = (num / calc_power(10, i)) % 10;
		_putchar('0' + curr_digit);
	}
	return (digits + sign + point);
}
