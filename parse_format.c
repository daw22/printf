#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * parse_format
 *
 *
 *
int (* parse_format(char *format, va_list ap))(va_list)
{
	int count;
	char *ptr;
	int (* func)(va_list);

	count = 0;
	ptr = format;
	while (*ptr)
        {
                if (*ptr == '%')
                {
                        int i;

                        i = 0;
                        while (i < 2)
                        {
                                if (*(ptr + 1) == t_and_f[i].spec)
                                {
                                        func = t_and_f[i].func;
                                        ptr++;
                                        break;
                                }
                                i++;
                        }
                }
                else
                {
                        _putchar(*ptr);
			count += 1;
                }
                ptr++;
        }
	return (count);
}
*/
int print_char(va_list ap, char *mod)
{
	printf("%s\n", mod);
	free(mod);
	return (98);
}

int print_string(va_list ap, char *mod)
{
        printf("%s\n", mod);
        free(mod);
        return (98);
}
/**
 * find_func
 *
 */
struct funcs_and_mods find_func(const char *format, int ind)
{
	char valid_mods[] = ".+-";
	char specs[] = "cs";
	char *mods = NULL;
	int (*func)(va_list, char *);
	struct types_and_funcs t_and_f[] = {
		{'c', print_char},
		{'s', print_string}
	};
	int i;
	int j;

	i = ind;
	while (format[i] && strchr(valid_mods, format[i]))
	{
		i++;
	}
	if (strchr(specs, format[i]) && (ind < i))
	{
		mods = malloc(sizeof(char) * (i - ind + 2));
		if (mods != NULL)
		{
			j = 0;
			while (ind < i)
			{
				mods[j] = format[ind];
				ind++;
				j++;
			}
			mods[j] = '\0';
		}
	}
	printf("%s\n", mods);
	i = 0;
	while (i < 3)
	{
		if (format[ind] == t_and_f[i].spec)
		{
			func = t_and_f[i].func;
			break;
		}
		i++;
	}
	struct funcs_and_mods f_and_m;
	f_and_m.func = func;
	f_and_m.mods = mods;
	return (f_and_m);
}
