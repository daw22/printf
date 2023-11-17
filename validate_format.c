#include "main.h"

/**
 * validate_format - Checks if the format string given for _printf is invalid
 * @format: The format string
 *
 * Return: void
 */
void validate_format(const char *format)
{
	if (format == NULL || (format[0] == '%' && !format[1]))
	{
		exit(1);
	}
}
