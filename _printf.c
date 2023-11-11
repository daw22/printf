#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf
 *
 * Return:
 */
int _printf(const char *format, ...)
{
	int bytes_printed;
	va_list ap;
	int i;

	va_start(ap, format);
	bytes_printed = 0;
	i = 0;
	while (format[i] && format != NULL)
	{
		if (format[i] == '%')
		{
			char c;

			c = format[i + 1];
			if (c == '%')
			{
				_putchar('%');
				bytes_printed += 1;
			}
			else
			{
				struct funcs_and_mods f_and_m;

				f_and_m = get_func_and_mods(format, i + 1);
				i += _strlen(f_and_m.mods);
				bytes_printed += f_and_m.func(ap, f_and_m.mods);

			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			bytes_printed += 1;
		}
		i++;
	}
	va_end(ap);
	return (bytes_printed);
}

int main(void)
{
        printf("%d\n", _printf("ab%%cd%+-cBC%sD\n", 'A', "HELLO"));
        return (0);
}
