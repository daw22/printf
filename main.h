#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/** util functions **/
int _strlen(char *);
char *_strchr(char *, char);
char *reverse_string(char *);
void *_realloc(void *, unsigned int, unsigned int);

/** prototypes **/
int _putchar(char);
struct funcs_and_mods find_func(const char *, int);
struct funcs_and_mods get_func_and_mods(const char *, int);
char *extract_mods(const char *, int *);
int (* get_func(const char *, int))(va_list, char *);
int print_char(va_list, char *);
int print_string(va_list, char *);
int print_integer(va_list, char *);
int print_hexa_lower(va_list, char *);
int print_hexa_upper(va_list, char *);
int print_binary(va_list, char *);
int null_func(va_list, char *);

/** structs **/

/**
 * struct types_and_funcs - represents a specifier and its handler
 * @spec: the format specifier
 * @func: pointer to the handler function
 *
 * Description: represents a format specifier and a pointer
 * to a function that handles this specifier
 */
struct types_and_funcs
{
	char spec;
	int (*func)(va_list, char *);
};

/**
 * struct funcs_and_mods - represents function pointer and the modifiers
 *
 * @func: pointer to handler function
 * @mods: mods string
 *
 * Description: represents a function pointer to be called and
 * the modifiers to passs the function
 */
struct funcs_and_mods
{
	int (*func)(va_list, char *);
	char *mods;
};

#endif
