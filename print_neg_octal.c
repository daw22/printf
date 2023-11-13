#include "main.h"

/**
 * print_neg_octal - Prints a negative number in octal
 * @num: The negative number to print
 *
 * Return: The number of bytes printed (8 for now)
 */
int print_neg_octal(int num)
{
	int pow = 0;
	int len = 0;
	int i, allocated = 0;
	int temp;
	char *octal, *octal_digits = "01234567";

	while (num > calc_power(8, pow))
		pow++;
	num = calc_power(8, pow) - num;
	temp = num;
	while (temp > 0)
	{
		temp /= 8;
		len++;
	}
	octal = malloc(sizeof(char) * (len + 1));
	if (octal != NULL)
	{
		allocated += 1;
		_putchar('3');
		for (i = 0; i < (10 - len); i++)
		{
			_putchar(octal_digits[7]);
		}
		i = 0;
		while (num > 0)
		{
			octal[i] = octal_digits[num % 8];
			num /= 8;
			i++;
		}
		octal[i] = '\0';
		octal = reverse_string(octal);
		for (i = 0; i < len; i++)
		{
			_putchar(octal[i]);
		}
	}
	free(octal);
	return (allocated ? 11 : 0);
}
