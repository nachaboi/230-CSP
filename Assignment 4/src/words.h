#ifndef __WORDS_H
#define __WORDS_H
#include <stdio.h>
#include "wset.h"

void wordfreq(WordSet *ws, FILE *file);
void wordfreq_fast(WordSet *ws, FILE *file);
char *words_next_word(FILE *file);

#endif
