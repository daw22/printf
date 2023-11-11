#include <stdio.h>
#include "main.h"

/**
 * _strlen - Returns the length of a null terminated string
 * @s: The string whose length is returned
 *
 * Return: The length of s
 */
int _strlen(char *s)
{
	int len;
	char *ptr;

	len = 0;
	ptr = s;
	while (s != NULL && *ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}

/**
 * _strchr - Returns a pointer to the first occurence of a char in a str
 * @str: The string in which we search
 * @c: The character we are searching
 *
 * Return: A pointer to the first occurence of c in str
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
