#include "holberton.h"

/**
 * wildcmp - Compare 2 strings, one with * wildcard
 *
 * @s1: string 1
 * @s2: string 2, with wildcard pattern
 *
 * Return: 1 if match, 0 if no match
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1  == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);

	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	return (0);
}
