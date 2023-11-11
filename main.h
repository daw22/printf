#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _strlen(char *);
char *_strchr(char *, char);
void *_realloc(void *, unsigned int, unsigned int);
int _putchar(char);
struct funcs_and_mods find_func(const char *, int);
struct funcs_and_mods get_func_and_mods(const char *, int);
char *extract_mods(const char *, int *);
int (* get_func(const char *, int))(va_list, char *);
int print_char(va_list, char *);

struct types_and_funcs
{
	char spec;
	int (*func)(va_list, char *);
};

struct funcs_and_mods
{
	int (*func)(va_list, char *);
	char *mods;
};

#endif
