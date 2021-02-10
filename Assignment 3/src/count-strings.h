#ifndef COUNT_STRINGS_H
#define COUNT_STRINGS_H

#include <stdio.h>

// The maximum length of a single line of input

#define LINE_MAX_CHARS 1000


// The most strings this program will search for (more are ignored)

#define MAX_STRINGS 50


// defines the <string,count> pair struct

typedef struct entry {
  char *string;
  int   count;
} Entry;


// fills in the entries of the table with the strings
// being searched for and an initial count of 0; the i'th
// entry has information about the i'th string

void prepare_table (int n, char **strings, Entry *entries);


// This reads each line of input from the given input file stream and
// searches for occurrences of each string in the entries, incrementing
// the strings' counts of their occurrences.  Argument n indicates the
// number of entries (number of strings and counts).  LINE_MAX_CHARS
// is the longest line that this function will read as a single unit.
// Note that a given string may occur more than once in a given line,
// and its occurrences may overlap.  For example, string aba occurs
// twice in the input ababa.  The function returns once it reaches
// end-of-file on the input stream.

void count_occurrences (int n, FILE *file, Entry *entries);


// This prints the n entries in order.  For each entry it prints
// the entry's string, then a colon and a space, then the entry's count
// (in decimal), then a newline.  All printing is to standard output.

void print_occurrences (int n, Entry *entries);

#endif
