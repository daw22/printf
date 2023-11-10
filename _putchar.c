#include <unistd.h>

/**
 * _putchar - Prints a single char to stdout
 * @c: Character to print
 *
 * Return: Number of bytes printed (1 if successful, 0 otherwise)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
