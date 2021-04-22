#ifndef _SUBSTRING_H
#define _SUBSTRING_H

#include <stdlib.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int not_in(int *arr, int len, int q);
int str_match(char const *str, char const *word);
int full_match(char const *s, char const **words, int nb_words, int word_len);


#endif /* _SUBSTRING_H; */
