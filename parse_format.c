#include "main.h"


/**
 * null_func - does nothing
 * @ap: va_list
 * @mod: modifiers
 *
 * Return: 0 Always
 */
int null_func(va_list ap, char *mod)
{
	char c;

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
	char valid_mods[] = "+-.";
	char valid_specs[] = "csdbxXfuiorRp";
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
int (*get_func(const char *format, int ind))(va_list, char *)
{
	int (*func)(va_list, char *);
	int i;
	T_and_F t_and_f[] = {
		{'c', print_char},
		{'s', print_string},
		{'b', print_binary},
		{'d', print_integer},
		{'i', print_octal_hexa},
		{'x', print_hexa_lower},
		{'X', print_hexa_upper},
		{'o', print_octal},
		{'f', print_float},
		{'u', print_unsigned_int},
		{'r', print_rev_string},
		{'R', print_rot13_string},
		{'p', print_pointer}
	};

	i = 0;
	while (i < 13)
	{
		if (format[ind] == t_and_f[i].spec)
		{
			func = t_and_f[i].func;
			break;
		}
		i++;
	}
	/** if no function found **/
	if (format[ind] != t_and_f[i].spec)
		return (null_func);
	return (func);
}
