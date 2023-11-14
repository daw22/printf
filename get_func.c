#include "main.h"

/**
 * get_normal_func - Extracts a normal (no length specifier) function
 * @spec: The specifier for which a function is searched
 *
 * Return: The appropriate function to handle the specifier
 */
int (*get_normal_func(char spec))(va_list, char *, char *, int *)
{
	int i = 0;
	int (*func)(va_list, char *, char *, int *) = null_func;
	T_and_F normal_t_and_f[] = {
		{'c', print_char}, {'s', print_string}, {'b', print_binary},
		{'d', print_integer}, {'i', print_octal_hexa},
		{'x', print_hexa_lower}, {'X', print_hexa_upper},
		{'o', print_octal}, {'f', print_float}, {'p', print_pointer},
		{'u', print_unsigned_int}, {'r', print_rev_string},
		{'R', print_rot13_string}, {'S', print_string_hexa}
	};
	while (i < 14)
	{
		if (spec == normal_t_and_f[i].spec)
		{
			func = normal_t_and_f[i].func;
			break;
		}
		i++;
	}
	return (func);
}

/**
 * get_long_func - Extracts a long ('l' length specifier) function
 * @spec: The specifier for which a function is searched
 *
 * Return: The appropriate function to handle the specifier
 */
int (*get_long_func(char spec))(va_list, char *, char *, int *)
{
	int i = 0;
	int (*func)(va_list, char *, char *, int *) = null_func;
	T_and_F long_t_and_f[] = {
		{'d', print_long_integer}, {'i', print_long_octal_hexa},
		{'u', print_long_unsigned_int}, {'o', print_long_octal},
		{'x', print_long_hexa_lower}, {'X', print_long_hexa_upper}
	};
	while (i < 6)
	{
		if (spec == long_t_and_f[i].spec)
		{
			func = long_t_and_f[i].func;
			break;
		}
		i++;
	}
	return (func);
}

/**
 * get_short_func - Extracts a short ('h' length specifier) function
 * @spec: The specifier for which a function is searched
 *
 * Return: The appropriate function to handle the specifier
 */
int (*get_short_func(char spec))(va_list, char *, char *, int *)
{
	int i = 0;
	int (*func)(va_list, char *, char *, int *) = null_func;
	T_and_F short_t_and_f[] = {
		{'d', print_short_integer}, {'i', print_short_octal_hexa},
		{'u', print_short_unsigned_int}, {'o', print_short_octal},
		{'x', print_short_hexa_lower}, {'X', print_short_hexa_upper}
	};
	while (i < 6)
	{
		if (spec == short_t_and_f[i].spec)
		{
			func = short_t_and_f[i].func;
			break;
		}
		i++;
	}
	return (func);
}
