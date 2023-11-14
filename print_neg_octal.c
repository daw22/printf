#include "main.h"

/**
 * print_neg_octal - Prints a negative number in octal
 * @num: The negative number to print
 * @buffer: The buffer to store the characters until printing
 * @len_ptr: A pointer to an int holding the number of chars in buffer
 *
 * Return: The number of bytes printed (8 for now)
 */
int print_neg_octal(int num, char *buffer, int *len_ptr)
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
		add_to_buffer('3', buffer, len_ptr);
		for (i = 0; i < (10 - len); i++)
		{
			add_to_buffer(octal_digits[7], buffer, len_ptr);
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
			add_to_buffer(octal[i], buffer, len_ptr);
		}
	}
	free(octal);
	return (allocated ? 11 : 0);
}
