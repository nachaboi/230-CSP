#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw.h"

/**
 * The main entry point of the wordfreq program.
 */

int main (int argc, char* argv[]) {
  if (argc < 2 || argc > 3) {
    printf("usage: %s file [quiet]\n", argv[0]);
    exit(1);
  }

  // Try to open input file for reading.
  FILE *file = NULL;
  if (argc >= 2) {
    file = fopen(argv[1], "r");
    if (file == NULL) {
      printf("could not open file '%s'.", argv[1]);
      return 1;
    }
  }

  // First determine if the output should be quiet:
  int quiet = 0;
  if (argc == 3 && strcmp(argv[2], "quiet") == 0) {
    quiet = 1;
  }

  WordSet *ws = wset_new();
  wordfreq(ws, file);

  // Close the file.
  fclose(file);

  if (!quiet) {
    wset_print(ws);
  }

  wset_free(ws);
  return 0;
}
