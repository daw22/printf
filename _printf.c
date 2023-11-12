#include "main.h"

/**
 * _printf - custom implementation of c printf function
 * @format: format string
 *
 * Return: number of bytes printed (int)
 */
int _printf(const char *format, ...)
{
	int i = 0, bytes_printed = 0;
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
				_putchar('%');
				bytes_printed += 1;
			}
			else
			{
				struct funcs_and_mods f_and_m;

				f_and_m = get_func_and_mods(format, i + 1);
				i += _strlen(f_and_m.mods);
				bytes_printed += f_and_m.func(ap, f_and_m.mods);
				if (f_and_m.func == null_func)
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
				}
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
/**
*int main(void)
*{
*       _printf("%d\n", _printf("ab%%cd%+-cBC%sD\n", 'A', "HELLO"));
*        _printf("%d\n", _printf("ab%%cd%+-kBC%sD\n", "HELLO"));
*	_printf("%+-.k: asdf\n");
*	_printf("%k\n", 5);
*	_printf("123%-+c::%..s::\n", '4', "567");
*        return (0);
*}
**/
