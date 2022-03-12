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
	/* If we reach the end of both strings, we are done */
	if (*s1  == '\0' && *s2 == '\0')
		return (1);

	/* Make sure that the characters after * are present */
	/* in second string. */
	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);

	/* If characters match, go to next one */
	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));

	/* If there is a *, then there are two possibilities */
	/* a) We consider current character of second string */
	/* b) We ignore current character of second string. */
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	return (0);
}
