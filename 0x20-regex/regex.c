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
	regex_t regex;
	int result;

	result = regcomp(&regex, pattern, REG_STARTEND);
	result = regexec(&regex, str, 0, NULL, 0);

	if (result == 0)
		return (1);

	return (0);
}
