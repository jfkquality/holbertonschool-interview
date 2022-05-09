#ifndef _SUBSTRING_H
#define _SUBSTRING_H

#include <stdlib.h>
#include <string.h>

enum word_status
{
	WORD_DEFAULT, WORD_FOUND, WORD_NOT
};

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
