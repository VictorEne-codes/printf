#include "main.h"

/**
 * find_strlen - finds the length of strings
 * @c: input
 *
 * Return: int
 */

int find_strlen(char *c)
{
	int i;

	for (i = 0; c[i] != 0; i++)
		;
	return (i);
}

/**
 * find_strlens - finds the length of strings
 * @c: input
 *
 * Return: int
 */

int find_strlens(const char *c)
{
	int i;

	for (i = 0; c[i] != 0; i++)
		;
	return (i);
}
