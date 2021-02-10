#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "words.h"
#include "wset.h"

#define MAXBUF 500

/**
 * The make_string function will allocate a new C string given a
 * buffer of characters and its length. It is the responsibility of
 * the caller of this function to deallocate the string.
 */
static char *make_string (char buffer[], int length) {
  char *str = (char *)(malloc(length+1));
  assert(str != NULL);
  memcpy(str, buffer, length);
  str[length] = '\0';
  return str;
}

/**
 * The words_next_word function returns the next word from standard
 * input. A word is a sequence of characters that are A-Z, a-z, or
 * 0-9. Any other character is a non-word character and is used to
 * delimit words.
 */
char *words_next_word(FILE *file) {
  char buf[MAXBUF];
  int counter = 0;
  // TODO: The implementation of this function is simple. You must use
  // the fgetc() function to retrieve the next character from the
  // provided file. If the character is an alphanumeric character
  // (a-z,A-Z,0-9) then it is a word character and should be added to
  // the character buffer `buf`. You keep iterating, reading
  // characters from standard input, until you reach a non-word
  // character. If you do you must call the `make_string` function to
  // create a new string from your character buffer `buf` and return
  // the new string as a result of this function.
  //
  // HINTS: 
  //  (0) Read the documentation for fgetc (e.g., $ man fgetc).
  //  (1) Pay attention to leading non-word characters, i.e., skip any non-word
  //      characters before accumulating word characters.
  //  (2) Handle EOF and the last word correctly.
  //  (3) Read the result of fgetc() into an int, for proper EOF testing.
  while(true) {
    char temp = fgetc(file);
    int temp2 = temp;
    // if(isalnum(temp2)) {
    if(isalnum(temp) && temp2 != -1) {
      buf[counter] = temp;
      counter++;
    }
    else if(counter == 0 && temp2 != -1) {

    }
    else {
      if(counter == 0 && temp2 == -1) {
        return NULL;
      }
      return (make_string(buf, counter));
    }
  }
}

/**
 * wordfreq populates the given WordSet with words from the given file.
 */
void wordfreq(WordSet *ws, FILE *file) {
  // TODO: In this function you need to write a loop that reads the
  // next word in the given file and use the wset_add() function
  // to add the word to the provided word set.

  while(true) {
    char* temp = words_next_word(file);
    if(temp!=NULL) {
      printf("YOOO");
      wset_add(ws, temp);

    }
    else {
      return;
    }
  }
}

/**
 * wordfreq_fast populates the given WordSet with words from the given file.
 * It calls wset_add_fast to attempt to add words faster.
 */
void wordfreq_fast(WordSet *ws, FILE *file) {
  // TODO: In this function you need to write a loop that reads the
  // next word in the given file and use the wset_fast_add() function
  // to add the word to the provided word set.

  while(true) {
    char* temp = words_next_word(file);
    if(temp!=NULL) {
      wset_fast_add(ws, temp);
    }
    else {
      return;
    }
  }
}

