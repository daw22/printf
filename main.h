#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>

int _putchar(char);
struct funcs_and_mods find_func(const char *, int);
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
