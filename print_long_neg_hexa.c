#include "main.h"

/**
 * print_long_neg_hexa - Prints a negative number in hexa
 * @num: The negative number to print
 * @digits: The hexa digits either in uppercase or lowercase
 * @buffer: The buffer to store the characters until printing
 * @len_ptr: A pointer to an int holding the number of chars in buffer
 *
 * Return: The number of bytes printed (8 for now)
 */
int print_long_neg_hexa(long num, char *digits, char *buffer, int *len_ptr)
{
	int pow = 0;
	int len = 0;
	int i, allocated = 0;
	long temp;
	char *hexa;

	while (num > calc_long_power(16, pow))
		pow++;
	num = calc_long_power(16, pow) - num;
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
		for (i = 0; i < (16 - len); i++)
		{
			add_to_buffer(digits[15], buffer, len_ptr);
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
			add_to_buffer(hexa[i], buffer, len_ptr);
		}
	}
	free(hexa);
	return (allocated ? 8 : 0);
}
