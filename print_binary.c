#include "main.h"

/**
 * print_binary - convets unsigned it to binary and print it
 * @ap: va_list
 * @mods: modifier string
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: number of printed charactres
 */
int print_binary(va_list ap, char *mods, char *buffer, int *len_ptr)
{
	unsigned int un, i, tmp, len, allocated = 0;
	char *str;
	/** until handling modifiers **/
	char c = mods[0];

	c = c;
	/** **/

	un = va_arg(ap, unsigned int);
	tmp = un;
	len = 1;
	if (un == 0)
	{
		add_to_buffer('0', buffer, len_ptr);
		return (len);
	}
	while (tmp / 2)
	{
		len++;
		tmp /= 2;
	}

	str = malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		allocated = 1;
		for (i = len - 1; un > 0; i--)
		{
			str[i] = (un % 2) + '0';
			un = un / 2;
		}
		for (i = 0; i < len; i++)
			add_to_buffer(str[i], buffer, len_ptr);
	}
	free(str);
	return (allocated ? len : 0);
}
