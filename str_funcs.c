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

/**
 * reverse_string - Returns the reverse of a given string
 * @s: The string to be reversed
 *
 * Return: The reversed string
 */
char *reverse_string(char *s)
{
	char* rev;
	int len, i, j;

	len = _strlen(s);
	rev = malloc(sizeof(char) * (len + 1));
	j = 0;
	if (rev != NULL)
	{
		for (i = len - 1; i >= 0; i--)
		{
			rev[j] = s[i];
			j++;
		}
		rev[j] = '\0';
		free(s);
	}
	return (rev);
}
