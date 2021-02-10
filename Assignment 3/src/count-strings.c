#include <stdlib.h>
#include <string.h>
#include "count-strings.h"

// fills in the entries of the table with the strings
// being searched for and an initial count of 0; the i'th
// entry has information about the i'th string
void prepare_table (int n, char **strings, Entry *entries) {
  for(int i = 0; i < n; i++) {
  	// Entry a;
  	// a.string = strings[i];
  	// a.count = 0;
  	// entries[i] = a;
    entries[i].string = strings[i];
    entries[i].count = 0;
  }

}


// This reads each line of input from the given input file stream and
// searches for occurrences of each string in the entries, incrementing
// the strings' counts of their occurrences.  Argument n indicates the
// number of entries (number of strings and counts).  LINE_MAX_CHARS
// is the longest line that this function will read as a single unit.
// Note that a given string may occur more than once in a given line,
// and its occurrences may overlap.  For example, string aba occurs
// twice in the input ababa.  The function returns once it reaches
// end-of-file on the input stream.
void count_occurrences (int n, FILE *file, Entry *entries) {
    char s [LINE_MAX_CHARS] = "cat";
    while(fgets(s, LINE_MAX_CHARS+1, file)) {
      for(int i = 0; i < n; i++) {
        char* currentsub = strstr(s, entries[i].string);
        if(currentsub != NULL) {
            entries[i].count++;
            currentsub = currentsub+1;
            while(true) {
              currentsub = strstr(currentsub, entries[i].string);
              if(currentsub != NULL) {
                entries[i].count++;
                currentsub = currentsub+1;
              }
              else{
                break;
              }
              
            } 
        } 
      }
    }

      
    
}


// This prints the n entries in order.  For each entry it prints
// the entry's string, then a colon and a space, then the entry's count
// (in decimal), then a newline.  All printing is to standard output.
void print_occurrences (int n, Entry *entries) {
  //To print one Entry, print its string, then a colon (:) and a space, and then its count (in decimal), and finally a newline.
	for(int i =0; i  < n; i++) {
		printf("%s: %d\n", entries[i].string, entries[i].count);
	}
}

