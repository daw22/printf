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
			struct funcs_and_mods f_and_m;

			c = format[i + 1];
			if (c == '%')
			{
				_putchar('%');
				bytes_printed += 1;
			}
			else
			{
				f_and_m = find_func(format, i + 1);
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
        _printf("abcd%+-c");
        return (0);
}
