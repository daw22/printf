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
 * get_long_digits - Counts and returns the number of digits in a number
 * @n: The integer whose digits are counted
 *
 * Return: The number of digits of n
 */
int get_long_digits(long int n)
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
 * calc_long_power - Calculates and returns one number to the power of another
 * @base: The base
 * @exp: The exponent
 *
 * Return: base ^ exp or base ** exp
 */
long calc_long_power(int base, int exp)
{
	long result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

/**
 * is_number - checks if a char is a number
 * @char: input char
 *
 * Return: 1 if char is a number, 0 if not
 */
int is_number(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
