#include "main.h"


/**
 * null_func - does nothing
 * @ap: va_list
 * @mod: modifiers
 * @buffer: Buffer for the chars to print
 * @len_ptr: Pointer to an int holding the number of chars in buffer
 *
 * Return: 0 Always
 */
int null_func(va_list ap, char *mod, char *buffer, int *len_ptr)
{
	char c;

	(void) buffer;
	(void) len_ptr;
	ap = ap;
	c = mod[0];
	c = c;
	return (0);
}


/**
 * get_func_and_mods - gets the modifiers and handdler function
 * @format: format string
 * @ind: crrent index
 *
 * Return: struct containing modifiers string and pointer to handler function
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

/**
 * extract_mods - extracts modifiers from format string
 * @format: format string
 * @ind_ptr: pointer to current index
 *
 * Return: modifiers as a string
 */
char *extract_mods(const char *format, int *ind_ptr)
{
	char valid_mods[] = "+- #. lh";
	char valid_specs[] = "csdbxXfuiorRpS";
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

/**
 * get_func - gets the handler function for the specifier
 * @format: format string
 * @ind: current index
 *
 * Return: pointer to handler function
 */
int (*get_func(const char *format, int ind))(va_list, char *, char *, int *)
{
	int (*func)(va_list, char *, char *, int *) = null_func;

	if (format[ind - 1] == 'l')
	{
		func = get_long_func(format[ind]);
	}
	else if (format[ind - 1] == 'h')
	{
		func = get_short_func(format[ind]);
	}
	else
	{
		func = get_normal_func(format[ind]);
	}
	return (func);
}
