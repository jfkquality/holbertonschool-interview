#include "holberton.h"

/**
 * match - Compare 2 strings, one with * wildcard
 *
 * @word: word to compare to
 * @pattern: string with wildcard pattern
 * @p: pattern index
 * @c: word index
 *
 * Return: 1 if match, 0 if no match
 */

int match(const char *pattern, const char *word, int p, int c)
{
	if (pattern[p] == '\0')
	{
		if (word[c] == '\0')
			return (1);
		else
			return (0);
	} else if (pattern[p] == '*')
	{
		for (; word[c] != '\0'; c++)
		{
			if (match(pattern, word, p + 1, c))
				return (1);
		}
		return (match(pattern, word, p + 1, c));
	} else if (pattern[p] != '?' && pattern[p] != word[c])
	{
		return (0);
	}
	return (match(pattern, word, p + 1, c + 1));
}

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
	return (match(s2, s1, 0, 0));
}
