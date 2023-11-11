#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_char
 *
 */
int print_char(va_list ap, char *mod)
{
	char c;

	c = va_arg(ap, int);
	if (_strlen(mod))
	{
		free(mod);
	}
	_putchar(c);
	return (1);
}
/**
 * print_string
 *
 */
int print_string(va_list ap, char *mod)
{
	char *s;
	char *ptr;
	int len;

	s = va_arg(ap, char *);
	ptr = s;
	if (_strlen(mod))
	{
		free(mod);
	}
	len = 0;
	if (s != NULL)
	{
		while (*ptr)
		{
			_putchar(*ptr);
			ptr++;
			len++;
		}
	}
	return (len);
}

/**
 * get_funcs_and_mods
 *
 */

struct funcs_and_mods get_func_and_mods(const char *format, int ind)
{
	int i;
	struct funcs_and_mods f_and_m;

	i = ind;
	f_and_m.mods = extract_mods(format, &i);
	f_and_m.func = get_func(format, i);
	return (f_and_m);
}

char *extract_mods(const char *format, int *ind_ptr)
{
	char valid_mods[] = "+-.";
	char valid_specs[] = "cs";
	char *curr_mods = "";
	int i;
        int j;

        i = *ind_ptr;
        while (format[i] && _strchr(valid_mods, format[i]))
        {
                i++;
        }
        if (_strchr(valid_specs, format[i]) && (*ind_ptr < i))
        {
                curr_mods = malloc(sizeof(char) * (i - (*ind_ptr) + 1));
                if (curr_mods != NULL)
                {
                        j = 0;
                        while (*ind_ptr < i)
                        {
                                curr_mods[j] = format[*ind_ptr];
                                (*ind_ptr)++;
                                j++;
                        }
                        curr_mods[j] = '\0';
                }
        }
	return (curr_mods);
}

int (* get_func(const char *format, int ind))(va_list, char *)
{
	int (*func)(va_list, char *);
	struct types_and_funcs t_and_f[] = {
		{'c', print_char},
		{'s', print_string}
	};
	int i;

	i = 0;
	while (i < 2)
	{
		if (format[ind] == t_and_f[i].spec)
		{
			func = t_and_f[i].func;
			break;
		}
		i++;
	}
	return (func);
}
