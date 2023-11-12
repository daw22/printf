#include <stdio.h>
#include "main.h"

/**
 * _printf - custom implementation of c printf function
 * @format: format string
 *
 * Return: number of bytes printed (int)
 */
int _printf(const char *format, ...)
{
	int i = 0, b_printed = 0;
	va_list ap;

	va_start(ap, format);
	while (format[i] && format != NULL)
	{
		if (format[i] == '%')
		{
			char c;

			c = format[i + 1];
			if (c == '%')
			{
				b_printed += _putchar('%');
			}
			else
			{
				struct funcs_and_mods f_and_m;

				f_and_m = get_func_and_mods(format, i + 1);
				i += _strlen(f_and_m.mods);
				b_printed += f_and_m.func(ap, f_and_m.mods);
				if (f_and_m.func == null_func)
				{
					b_printed += _putchar(format[i]);
					b_printed += _putchar(format[i + 1]);
				}
			}
			i++;
		}
		else
		{
			b_printed += _putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (b_printed);
}

/**
 *int main(void)
 *{
 *	printf("%d\n", _printf("%c%c%c %s = %d\nLet's try %s %d = %x =  * %X\n", 'T', 'h', 'e', "num", -12345, "Hexa", 123, 123, 123));
 *	printf("%d\n", printf("%c%c%c %s = %d\nLet's try %s %d = %x = %*X\n", 'T', 'h', 'e', "num", -12345, "Hexa", 123, 123, 123));
 *	return (0);
 *}
 */
