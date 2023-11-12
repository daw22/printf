#include "main.h"

/**
 * print_integer - Prints an integer using only _putchar
 * @ap: The argument pointer pointing to the int to be printed
 * @mods: The modifiers in the format string
 *
 * Return: The number of chars printed (including minus sign if there is one)
 */
int print_integer(va_list ap, char *mods)
{
	int n;
	int digits;
	unsigned int num;
	int i;
	unsigned int sign;
	int curr_digit;

	n = va_arg(ap, int);
	(void *)mods;
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
	digits = get_digits(num);
	for (i = digits - 1; i >= 0; i--)
	{
		curr_digit = (num / calc_power(10, i)) % 10;
		_putchar('0' + curr_digit);
	}
	return (digits + sign);
}
