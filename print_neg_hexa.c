#include "main.h"

/**
 * print_neg_hexa - Prints a negative number in hexa
 * @num: The negative number to print
 * @digits: The hexa digits either in uppercase or lowercase
 *
 * Return: The number of bytes printed (8 for now)
 */
int print_neg_hexa(int num, char *digits)
{
	int pow = 0;
	int len = 0;
	int i, allocated = 0;
	int temp;
	char *hexa;

	while (num > calc_power(16, pow))
		pow++;
	num = calc_power(16, pow) - num;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	hexa = malloc(sizeof(char) * (len + 1));
	if (hexa != NULL)
	{
		allocated += 1;
		for (i = 0; i < (8 - len); i++)
		{
			_putchar(digits[15]);
		}
		i = 0;
		while (num > 0)
		{
			hexa[i] = digits[num % 16];
			num /= 16;
			i++;
		}
		hexa[i] = '\0';
		hexa = reverse_string(hexa);
		for (i = 0; i < len; i++)
		{
			_putchar(hexa[i]);
		}
	}
	free(hexa);
	return (allocated ? 8 : 0);
}
