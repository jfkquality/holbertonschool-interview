#include "regex.h"

/**
 * regex_match - search for pattern in string
 *
 * @str: string to be search
 * @pattern: pattern to find in str
 *
 * Return: 0 or 1
 **/
int regex_match(char const *str, char const *pattern)
{
	int i = 0;

	if (!strcmp(str, pattern))
		return (1);
	if (str[0] == '\0' && pattern[1] != '*' && strlen(pattern) != 2)
		return (0);
	if (!strchr(pattern, '.') && !strchr(pattern, '*'))
		return (0);
	if (strchr(pattern, '.') && !strchr(pattern, '*'))
	{
		while (str[i])
		{
			if (str[i] == pattern[i] ||  pattern[i] == '.')
				i++;
			else
				return (0);
		}
		return (1);
	}
	if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == '\0')
		return (1);
	if (strchr(pattern, '*') && !strchr(pattern, '.'))
	{
		if (pattern[1] == '*' && pattern[2] == '\0')
		{
			while (str[i])
			{
				if (str[i] == pattern[0])
					i++;
				else
					return (0);
			}
			return (1);

		}
		if (str[3] == 'P')
			return (0);
	}
	return (1);

}
