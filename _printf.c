#include "main.h"

/**
 * _printf - custom implementation of c printf function
 * @format: format string
 *
 * Return: number of bytes printed (int)
 */
int _printf(const char *format, ...)
{
	int i = 0, bytes = 0, len = 0;
	va_list ap;
	char *buffer = malloc(sizeof(char) * 1024);

	va_start(ap, format);
	while (format[i] && format != NULL && buffer != NULL)
	{
		if (format[i] == '%')
		{
			char c = format[i + 1];

			if (c == '%')
				bytes += add_to_buffer('%', buffer, &len);
			else
			{
				struct funcs_and_mods f_and_m;

				f_and_m = get_func_and_mods(format, i + 1);
				i += _strlen(f_and_m.mods);
				bytes += f_and_m.func(ap, f_and_m.mods, buffer,
						      &len);
				if (f_and_m.func == null_func)
				{
					bytes += add_to_buffer(format[i],
							       buffer, &len);
					bytes += add_to_buffer(format[i + 1],
								   buffer,
								   &len);
				}
			}
			i++;
		}
		else
			bytes += add_to_buffer(format[i], buffer, &len);
		i++;
	}
	print_buffer(buffer, len);
	va_end(ap);
	free(buffer);
	return (bytes);
}
