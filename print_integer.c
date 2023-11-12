#include "main.h"

/**
 * get_digits - Counts and returns the number of digits in a number
 * @n: The integer whose digits are counted
 *
 * Return: The number of digits of n
 */
int get_digits(int n)
{
	int count;

	count = 0;
	do {
		count++;
		n /= 10;
	} while (n != 0);
	return (count);
}

/**
 * calc_power - Calculates and returns one number to the power of another
 * @base: The base
 * @exp: The exponent
 *
 * Return: base ^ exp or base ** exp
 */
int calc_power(int base, int exp)
{
	int result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

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
