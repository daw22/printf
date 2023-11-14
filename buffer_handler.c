#include "main.h"

/**
 * add_to_buffer - Adds a character to be printed to the buffer
 * @c: The character to add to the buffer
 * @buffer: The buffer to add c to
 * @len_ptr: A pointer to the length of the buffer (how many chars are inside)
 *
 * Return: The number of chars added to buffer (1 if successful)
 */
int add_to_buffer(char c, char *buffer, int *len_ptr)
{
	buffer[*len_ptr] = c;
	*len_ptr += 1;
	if (*len_ptr == 1024)
	{
		print_buffer(buffer, *len_ptr);
		*len_ptr = 0;
	}
	return (1);
}

/**
 * print_buffer - Prints contents of a number of bytes of a buffer to stdout
 * @buffer: The buffer containing the chars to print
 * @len: The number of bytes of buffer to print
 *
 * Return: The number of bytes printed (len)
 */
int print_buffer(char *buffer, int len)
{
	return (write(1, buffer, len));
}
