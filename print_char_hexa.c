#include "main.h"

/**
 * print_char_hexa - Prints a non-printable char in hexa representation
 * @c: The character to print (to add to the buffer)
 * @buffer: The buffer holding the characters until printing
 * @len_ptr: A pointer to an integer holding the number of chars in buffer
 *
 * Return: The number of chars printed (added to buffer)
 */
int print_char_hexa(char c, char *buffer, int *len_ptr)
{
	unsigned int len = 0, i = 3;
	char *hexa;
	char *digits = "0123456789ABCDEF";

	hexa = malloc(sizeof(char) * 4);
	if (hexa != NULL)
	{
		hexa[len++] = '\\';
		hexa[len++] = 'x';
		if (c < 16)
		{
			hexa[len++] = '0';
		}
		while (c > 0)
		{
			hexa[i] = digits[c % 16];
			c /= 16;
			len++;
			i--;
		}
		for (i = 0; i < len; i++)
		{
			add_to_buffer(hexa[i], buffer, len_ptr);
		}
	}
	free(hexa);
	return (len);
}
