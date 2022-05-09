#ifndef _SUBSTRING_H
#define _SUBSTRING_H

#include <stdlib.h>
#include <string.h>

/**
 * enum word_status - progress of a word in the current substring search
 * @WORD_DEFAULT: word not confirmed found or not found
 * @WORD_FOUND: word found in the substring
 * @WORD_NOT: word can't be at this point in the substring
 */
enum word_status
{
	WORD_DEFAULT, WORD_FOUND, WORD_NOT
};

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
