#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char*, ...);
/** util functions **/
int _strlen(char *);
char *_strchr(char *, char);
char *reverse_string(char *);
void *_realloc(void *, unsigned int, unsigned int);
int calc_power(int, int);
long calc_long_power(int, int);
int get_digits(int);
int get_long_digits(long int);
int add_to_buffer(char, char *, int *);
int print_buffer(char *, int);

/** prototypes **/
int _putchar(char);
struct funcs_and_mods find_func(const char *, int);
struct funcs_and_mods get_func_and_mods(const char *, int);
char *extract_mods(const char *, int *);
int (*get_func(const char *, int))(va_list, char *, char *, int *);
int (*get_normal_func(char))(va_list, char *, char *, int *);
int (*get_long_func(char))(va_list, char *, char *, int *);
int (*get_short_func(char))(va_list, char *, char *, int *);
int print_char(va_list, char *, char *, int *);
int print_string(va_list, char *, char *, int *);
int print_integer(va_list, char *, char *, int *);
int print_unsigned_int(va_list, char *, char *, int *);
int print_hexa_lower(va_list, char *, char *, int *);
int print_neg_hexa(int, char *, char *, int *);
int print_hexa_upper(va_list, char *, char *, int *);
int print_float(va_list, char *, char *, int *);
int print_binary(va_list, char *, char *, int *);
int print_octal_hexa(va_list, char *, char *, int *);
int print_octal(va_list, char *, char *, int *);
int print_neg_octal(int, char *, int *);
int print_rev_string(va_list, char *, char *, int *);
int print_rot13_string(va_list, char *, char *, int *);
int null_func(va_list, char *, char *, int *);
int print_pointer(va_list, char *, char *, int *);
int print_string_hexa(va_list, char *, char *, int *);
int print_char_hexa(char, char *, int *);
int null_func(va_list, char *, char *, int *);

int print_long_integer(va_list, char *, char *, int *);
int print_long_octal_hexa(va_list, char *, char *, int *);
int print_long_unsigned_int(va_list, char *, char *, int *);
int print_long_octal(va_list, char *, char *, int *);
int print_long_neg_octal(long, char *, int *);
int print_long_hexa_lower(va_list, char *, char *, int *);
int print_long_hexa_upper(va_list, char *, char *, int *);
int print_long_neg_hexa(long, char *, char *, int *);

int print_short_integer(va_list, char *, char *, int *);
int print_short_octal_hexa(va_list, char *, char *, int *);
int print_short_unsigned_int(va_list, char *, char *, int *);
int print_short_octal(va_list, char *, char *, int *);
int print_short_hexa_lower(va_list, char *, char *, int *);
int print_short_hexa_upper(va_list, char *, char *, int *);
/** structs **/

/**
 * struct types_and_funcs - represents a specifier and its handler
 *
 * @spec: the format specifier
 * @func: pointer to the handler function
 *
 * description: represents a format specifier and a pointer
 * to a function that handles this specifier
 */
struct types_and_funcs
{
	char spec;
	int (*func)(va_list, char *, char *, int *);
};
typedef struct types_and_funcs T_and_F;
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
	int (*func)(va_list, char *, char *, int *);
	char *mods;
};

#endif
