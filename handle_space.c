#include "main.h"

/**
 * handle_space - Handles the space modifier
 * @n: The number to be printed
 * @mods: The modifiers
 * @buffer: The buffer holding the chars to be printed
 * @len_ptr: Current length of the buffer
 *
 * Return: 1 if a space is added to the buffer (space modifier present)
 * or 0 otherwise
 */
int handle_space(int n, char *mods, char *buffer, int *len_ptr)
{
	int len = 0;

	if (n >= 0)
	{
		if (_strchr(mods, ' ') && !_strchr(mods, '+'))
		{
			len += add_to_buffer(' ', buffer, len_ptr);
			free(mods);
		}
	}
	return (len);
}
